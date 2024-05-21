#pragma once
#include "DeviceDriver.h"
#include <iostream>

class Application
{
public:
	Application(DeviceDriver& driver)
		: m_driver(driver)
	{}
	void ReadAndPrint(long startAddr, long endAddr)
	{
		for (long add = startAddr; add <= endAddr; ++add) {
			std::cout << m_driver.read(add) << std::endl;
		}
	}
	void WriteAll(unsigned char value) {
		for (long add = 0x00; add <= 0x04; ++add) {
			m_driver.write(add, value);
		}
	}
private:
	DeviceDriver& m_driver;
};
