#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "DeviceDriver.h"
#include "Application.h"

class MockFlashMemoryDeivce : public FlashMemoryDevice 
{
public:
    MOCK_METHOD(unsigned char, read, (long), (override));
    MOCK_METHOD(void, write, (long, unsigned char), (override));
};

TEST(DeviceRead, Exception) {
    MockFlashMemoryDeivce flash_device;
    EXPECT_CALL(flash_device, read)
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)4))
        ;

    DeviceDriver driver(&flash_device);
    EXPECT_THROW(driver.read(0), ReadFailException);
}

TEST(DeviceRead, Read) {
    MockFlashMemoryDeivce flash_device;
    EXPECT_CALL(flash_device, read)
        .Times(5)
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        ;

    DeviceDriver driver(&flash_device);
    EXPECT_THAT(driver.read(0), testing::Eq(5));
}

TEST(DeviceWrite, Exception1) {
    MockFlashMemoryDeivce flash_device;
    EXPECT_CALL(flash_device, read)
        .Times(5)
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        ;

    DeviceDriver driver(&flash_device);
    EXPECT_THROW(driver.write(0, 6), WriteFailException);
}

TEST(DeviceWrite, Exception2) {
    MockFlashMemoryDeivce flash_device;
    EXPECT_CALL(flash_device, read)
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)3))
        ;

    DeviceDriver driver(&flash_device);
    EXPECT_THROW(driver.write(0, 6), ReadFailException);
}

TEST(DeviceWrite, Write) {
    testing::NiceMock<MockFlashMemoryDeivce> flash_device;
    EXPECT_CALL(flash_device, read)
        .Times(10)
        .WillOnce(testing::Return((unsigned char)0XFF))
        .WillOnce(testing::Return((unsigned char)0XFF))
        .WillOnce(testing::Return((unsigned char)0XFF))
        .WillOnce(testing::Return((unsigned char)0XFF))
        .WillOnce(testing::Return((unsigned char)0XFF))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        ;

    DeviceDriver driver(&flash_device);
    driver.write(0, 5);
    EXPECT_THAT(driver.read(0), 5);
}

TEST(Application, ReadAndPrint) {
    testing::NiceMock<MockFlashMemoryDeivce> flash_device;
    EXPECT_CALL(flash_device, read)
        .Times(20)
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)5))
        .WillOnce(testing::Return((unsigned char)7))
        .WillOnce(testing::Return((unsigned char)7))
        .WillOnce(testing::Return((unsigned char)7))
        .WillOnce(testing::Return((unsigned char)7))
        .WillOnce(testing::Return((unsigned char)7))
        .WillOnce(testing::Return((unsigned char)2))
        .WillOnce(testing::Return((unsigned char)2))
        .WillOnce(testing::Return((unsigned char)2))
        .WillOnce(testing::Return((unsigned char)2))
        .WillOnce(testing::Return((unsigned char)2))
        .WillOnce(testing::Return((unsigned char)178))
        .WillOnce(testing::Return((unsigned char)178))
        .WillOnce(testing::Return((unsigned char)178))
        .WillOnce(testing::Return((unsigned char)178))
        .WillOnce(testing::Return((unsigned char)178))
        ;
    DeviceDriver driver(&flash_device);
    Application app(driver);

    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    app.ReadAndPrint(0, 3);

    std::cout.rdbuf( oldCoutStreamBuf );

    std::string expected = "5\n7\n2\n178\n";
    EXPECT_THAT(strCout.str(), testing::Eq(expected));
}

TEST(Application, WriteAll) {
    testing::NiceMock<MockFlashMemoryDeivce> flash_device;
    EXPECT_CALL(flash_device, read)
        .Times(50)
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))
        .WillOnce(testing::Return(0XFF))

        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        .WillOnce(testing::Return(89))
        ;

    DeviceDriver driver(&flash_device);
    Application app(driver);

    app.WriteAll(89);

    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    app.ReadAndPrint(0X00, 0X04);

    std::cout.rdbuf( oldCoutStreamBuf );

    std::string expected = "89\n89\n89\n89\n89\n";
    EXPECT_THAT(strCout.str(), testing::Eq(expected));
}
