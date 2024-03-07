#include <gtest/gtest.h>
#include <EventHandler.h>

// Normal communication
TEST(ProcessEventTest, NormalCommunicationTest)
{
    GTEST_ASSERT_EQ(process_event(LINK_DOWN, INTERFACE_OK), SENDING_START);
    GTEST_ASSERT_EQ(process_event(SENDING_START, OK_PACKAGE_RECEIVED), SENDING_CONFIG);
    GTEST_ASSERT_EQ(process_event(SENDING_CONFIG, OK_PACKAGE_RECEIVED), KEEP_ALIVE);
    GTEST_ASSERT_EQ(process_event(KEEP_ALIVE, OK_PACKAGE_RECEIVED), KEEP_ALIVE);
}

// Link Down
TEST(ProcessEventTest, LinkDownTest)
{
    GTEST_ASSERT_EQ(process_event(SENDING_START, INTERFACE_NOK), LINK_DOWN);
    GTEST_ASSERT_EQ(process_event(SENDING_CONFIG, INTERFACE_NOK), LINK_DOWN);
    GTEST_ASSERT_EQ(process_event(KEEP_ALIVE, INTERFACE_NOK), LINK_DOWN);
    GTEST_ASSERT_EQ(process_event(LINK_DOWN, INTERFACE_NOK), LINK_DOWN);
    GTEST_ASSERT_EQ(process_event(LINK_DOWN, NOK_PACKAGE_RECEIVED), LINK_DOWN);
    GTEST_ASSERT_EQ(process_event(LINK_DOWN, OK_PACKAGE_RECEIVED), LINK_DOWN);
    GTEST_ASSERT_EQ(process_event(LINK_DOWN, TIMEOUT), LINK_DOWN);
}

// Package Error
TEST(ProcessEventTest, PackageErrorTest)
{
    GTEST_ASSERT_EQ(process_event(SENDING_START, NOK_PACKAGE_RECEIVED), SENDING_START);
    GTEST_ASSERT_EQ(process_event(SENDING_CONFIG, NOK_PACKAGE_RECEIVED), SENDING_CONFIG);
    GTEST_ASSERT_EQ(process_event(KEEP_ALIVE, NOK_PACKAGE_RECEIVED), SENDING_START);
    GTEST_ASSERT_EQ(process_event(LINK_DOWN, NOK_PACKAGE_RECEIVED), LINK_DOWN);
}

// Timeout
TEST(ProcessEventTest, TimeoutTest)
{
    GTEST_ASSERT_EQ(process_event(LINK_DOWN, TIMEOUT), LINK_DOWN);
    GTEST_ASSERT_EQ(process_event(SENDING_START, TIMEOUT), SENDING_START);
    GTEST_ASSERT_EQ(process_event(SENDING_CONFIG, TIMEOUT), SENDING_START);
    GTEST_ASSERT_EQ(process_event(KEEP_ALIVE, TIMEOUT), SENDING_START);
}

// Invalid States
TEST(ProcessEventTest, InvalidStatesTest)
{
    GTEST_ASSERT_EQ(process_event(SENDING_START, INTERFACE_OK), SENDING_START);
    GTEST_ASSERT_EQ(process_event(SENDING_CONFIG, INTERFACE_OK), SENDING_CONFIG);
    GTEST_ASSERT_EQ(process_event(KEEP_ALIVE, INTERFACE_OK), KEEP_ALIVE);
}

// Exception
TEST(ProcessEventTest, ExceptionTest)
{
    EXPECT_THROW(process_event(KEEP_ALIVE, (Events)0xff), std::logic_error);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}