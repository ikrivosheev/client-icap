#include <gtest/gtest.h>
#include "lib/url.h"

TEST(TestURL, Parse) {
    URL url = URL::from_string("icap://localhost:8000/");

    ASSERT_EQ(url.scheme(), "icap");
    ASSERT_EQ(url.host(), "localhost");
    ASSERT_EQ(url.port(), 8000);
    ASSERT_EQ(url.path(), "/");
    ASSERT_EQ(url.query(), "");
    ASSERT_EQ(url.fragment(), "");
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
