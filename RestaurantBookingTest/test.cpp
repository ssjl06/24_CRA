#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../RestaurantBookingKATA/BookingScheduler.cpp"
#include "../RestaurantBookingKATA/Customer.cpp"
#include "../RestaurantBookingKATA/MailSender.cpp"
#include "../RestaurantBookingKATA/Schedule.cpp"
#include "../RestaurantBookingKATA/SmsSender.cpp"
#include "TestableSmsSender.cpp"
#include "TestableMailSender.cpp"
#include "TestableBookingScheduler.cpp"

class MockCustomer : public Customer {
public:
	MOCK_METHOD(string, getEmail, (), (override));
};

class BookingItem : public testing::Test {
protected:
	void SetUp() override {
		NOT_ON_THE_HOUR = getTime(2021, 3, 26, 9, 5);
		ON_THE_HOUR = getTime(2021, 3, 26, 9, 0);
		bookingScheduler.setSmsSender(&testableSmsSender);
		bookingScheduler.setMailSender(&testableMailSender);

		EXPECT_CALL(CUSTOMER, getEmail, (), ())
			.WillRepeatedly(testing::Return(""));
		EXPECT_CALL(CUSTOMER_WITH_MAIL, getEmail, (), ())
			.WillRepeatedly(testing::Return("test@test.com"));
		MONDAY_ON_THE_HOUR = getTime(2024, 6, 3, 17, 0);
		SUNDAY_ON_THE_HOUR = getTime(2021, 3, 28, 17, 0);
	}
public:
	tm getTime(int year, int mon, int day, int hour, int min) {
		tm result = { 0, min, hour, day, mon - 1, year - 1900, 0,0,-1 };
		mktime(&result);
		return result;
	}
	tm plusHour(tm base, int hour) {
		base.tm_hour += hour;
		mktime(&base);
		return base;
	}

	tm NOT_ON_THE_HOUR;
	tm ON_THE_HOUR;
	tm MONDAY_ON_THE_HOUR;
	tm SUNDAY_ON_THE_HOUR;
	MockCustomer CUSTOMER;
	MockCustomer CUSTOMER_WITH_MAIL;
	const int UNDER_CAPACITY = 1;
	const int CAPACITY_PER_HOUR = 3;
	BookingScheduler bookingScheduler{ CAPACITY_PER_HOUR };
	testing::NiceMock<TestableSmsSender> testableSmsSender;
	testing::NiceMock<TestableMailSender> testableMailSender;
};

TEST_F(BookingItem, 예약은_정시에만_가능하다_정시가_아닌경우_예약불가) {
	Schedule* schedule = new Schedule(NOT_ON_THE_HOUR, UNDER_CAPACITY, CUSTOMER);

	EXPECT_THROW({
		bookingScheduler.addSchedule(schedule);
		}, std::runtime_error);
}

TEST_F(BookingItem, 예약은_정시에만_가능하다_정시인_경우_예약가능) {
	Schedule* schedule = new Schedule(ON_THE_HOUR, UNDER_CAPACITY, CUSTOMER);

	bookingScheduler.addSchedule(schedule);
	
	EXPECT_EQ(true, bookingScheduler.hasSchedule(schedule));
}

TEST_F(BookingItem, 시간대별_인원제한이_있다_같은_시간대에_Capacity_초과할_경우_예외발생) {
	Schedule* schedule = new Schedule(ON_THE_HOUR, CAPACITY_PER_HOUR, CUSTOMER);

	bookingScheduler.addSchedule(schedule);
	try {
		Schedule* newSchedule = new Schedule{ ON_THE_HOUR, UNDER_CAPACITY, CUSTOMER };
		bookingScheduler.addSchedule(newSchedule);
		FAIL();
	}
	catch (std::runtime_error& e) {
		EXPECT_EQ(std::string{ e.what() }, std::string{ "Number of people is over restaurant capacity per hour" });
	}
}

TEST_F(BookingItem, 시간대별_인원제한이_있다_같은_시간대가_다르면_Capacity_차있어도_스케쥴_추가_성공) {
	Schedule* schedule = new Schedule(ON_THE_HOUR, CAPACITY_PER_HOUR, CUSTOMER);
	bookingScheduler.addSchedule(schedule);

	tm differentHour = plusHour(ON_THE_HOUR, 1);
	Schedule* newSchedule = new Schedule{ differentHour, UNDER_CAPACITY, CUSTOMER };
	bookingScheduler.addSchedule(newSchedule);

	EXPECT_EQ(true, bookingScheduler.hasSchedule(schedule));
	EXPECT_EQ(true, bookingScheduler.hasSchedule(newSchedule));
}

TEST_F(BookingItem, 예약완료시_SMS는_무조건_발송) {
	Schedule* schedule = new Schedule(ON_THE_HOUR, CAPACITY_PER_HOUR, CUSTOMER);

	EXPECT_CALL(testableSmsSender, send(schedule))
		.Times(1);

	bookingScheduler.addSchedule(schedule);
}

TEST_F(BookingItem, 이메일이_없는_경우에는_이메일_미발송) {
	Schedule* schedule = new Schedule(ON_THE_HOUR, UNDER_CAPACITY, CUSTOMER);

	EXPECT_CALL(testableMailSender, sendMail(schedule))
		.Times(0);

	bookingScheduler.addSchedule(schedule);
}

TEST_F(BookingItem, 이메일이_있는_경우에는_이메일_발송) {
	Schedule* schedule = new Schedule(ON_THE_HOUR, UNDER_CAPACITY, CUSTOMER_WITH_MAIL);
	bookingScheduler.setMailSender(&testableMailSender);

	EXPECT_CALL(testableMailSender, sendMail(schedule))
		.Times(1);

	bookingScheduler.addSchedule(schedule);
}

TEST_F(BookingItem, 현재날짜가_일요일인_경우_예약불가_예외처리) {
	TestableBookingScheduler mockScheduler(CAPACITY_PER_HOUR);
	EXPECT_CALL(mockScheduler, getNow())
		.WillRepeatedly(testing::Return(mktime(&SUNDAY_ON_THE_HOUR)));
	BookingScheduler* bookingScheduler = &mockScheduler;
	try {
		Schedule* schedule = new Schedule(ON_THE_HOUR, UNDER_CAPACITY, CUSTOMER_WITH_MAIL);
		bookingScheduler->addSchedule(schedule);
		FAIL();
	}
	catch (std::runtime_error& e) {
		EXPECT_EQ(std::string{ e.what() }, std::string("Booking system is not available on sunday"));
	}
}

TEST_F(BookingItem, 현재날짜가_일요일이_아닌경우_예약가능) {
	TestableBookingScheduler mockScheduler(CAPACITY_PER_HOUR);
	EXPECT_CALL(mockScheduler, getNow())
		.WillRepeatedly(testing::Return(mktime(&MONDAY_ON_THE_HOUR)));

	BookingScheduler* bookingScheduler = &mockScheduler;

	Schedule* schedule = new Schedule(ON_THE_HOUR, UNDER_CAPACITY, CUSTOMER_WITH_MAIL);
	bookingScheduler->addSchedule(schedule);
	EXPECT_EQ(true, bookingScheduler->hasSchedule(schedule));
}