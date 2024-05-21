#pragma once
#include "DeviceDriver.h"
class Application
{
public:
	Application(DeviceDriver& driver)
		: m_driver(driver)
	{}
	void ReadAndPrint(long startAddr, long endAddr)
	{

	}
private:
	DeviceDriver& m_driver;
};
