#include "DeviceDriver.h"

DeviceDriver::DeviceDriver(FlashMemoryDevice *hardware) : m_hardware(hardware)
{}

int DeviceDriver::read(long address)
{
    // TODO: implement this method properly
    int result = (int)(m_hardware->read(address));
    for (int i = 0; i < 4; ++i) {
        if ((int)(m_hardware->read(address)) != result) {
            throw ReadFailException();
        }
    }
    return result;
}

void DeviceDriver::write(long address, int data)
{
    // TODO: implement this method
    if (read(address) != 0XFF) {
        throw WriteFailException();
    }
    m_hardware->write(address, (unsigned char)data);
}