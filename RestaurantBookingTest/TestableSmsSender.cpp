#include <iostream>
#include "../RestaurantBookingKATA/SmsSender.cpp"

class TestableSmsSender : public SmsSender {
public:
	void send(Schedule* schedule) override {
		std::cout << "테스트용 SmsSender class의 send 메서드 실행됨.\n";
		sendMethodIsCalled = true;
	}

	bool isSendMethodCalled() {
		return sendMethodIsCalled;
	}

private:
	bool sendMethodIsCalled;
};