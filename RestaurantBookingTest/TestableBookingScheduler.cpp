#include "../RestaurantBookingKATA/BookingScheduler.cpp"

class TestableBookingScheduler : public BookingScheduler
{
public:
	TestableBookingScheduler(int capacityPerHour, tm dateTime) 
		: BookingScheduler{ capacityPerHour }
		, dateTime{ dateTime }
	{}

	time_t getNow() override {
		return mktime(&dateTime);
	}

private:
	time_t getTime(int year, int mon, int day, int hour, int min) {
		tm result = { 0, min, hour, day, mon - 1, year - 1900, 0, 0, -1 };
		return mktime(&result);
	}
	tm dateTime;
};
