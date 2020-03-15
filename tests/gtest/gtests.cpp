#include "gtests.h"
#include <gtest/gtest.h>
#include "version.h"

TEST(v, tv) {
    //Arrange
    //int v = test::getVersion();
    int tv = 0;
    //Act
    ASSERT_EQ(test::getVersion(), tv);
    //Assert
}