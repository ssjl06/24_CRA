#pragma once
#include "FlashMemoryDevice.h"
#include <stdexcept>

class ReadFailException : public std::exception {
public:
    const char* what() const override {
        return "DEVICE READ ERROR";
    }
};

class WriteFailException : public std::exception {
public:
    const char* what() const override {
        return "DEVICE WRITE ERROR";
    }
};

class DeviceDriver
{
public:
    DeviceDriver(FlashMemoryDevice *hardware);
    int read(long address);
    void write(long address, int data);

protected:
    FlashMemoryDevice *m_hardware;
};
