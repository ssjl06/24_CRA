#include "../RestaurantBookingKATA/MailSender.cpp"
#include <gmock/gmock.h>

class TestableMailSender : public MailSender {
public:
	MOCK_METHOD(void, sendMail, (Schedule*), (override));
};