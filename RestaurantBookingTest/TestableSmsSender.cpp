#include <iostream>
#include <gmock/gmock.h>
#include "../RestaurantBookingKATA/SmsSender.cpp"

class TestableSmsSender : public SmsSender {
public:
	MOCK_METHOD(void, send, (Schedule*), (override));
};
