#include "../RestaurantBookingKATA/BookingScheduler.cpp"
#include <gmock/gmock.h>

class TestableBookingScheduler : public BookingScheduler
{
public:
	TestableBookingScheduler(int capacityPerHour) 
		: BookingScheduler{ capacityPerHour }
	{}
	
	MOCK_METHOD(time_t, getNow, (), (override));
};
