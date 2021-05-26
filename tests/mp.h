#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "common.h"
#include "text.h"
#include "_text.h"

TEST(mp, normal)
{
    std::string output_text = "";

       text txt = create_text();

       txt->lst->push_back("Hello world1");
       txt->lst->push_back("Hello world2");
       txt->lst->push_back("Hello world3");
       txt->length=3;
       output_text += "Hello world1";
       output_text += "Hello| world2";
       output_text += "Hello world3";
       testing::internal::CaptureStdout();
       m(txt,1,1);
       mp(txt,5);
       show(txt);
       std::string text = testing::internal::GetCapturedStdout();
       EXPECT_STREQ(text.c_str(), output_text.c_str());

       free(txt);
}


TEST(mp, negativ)
{
    std::string output_text = "";
    text txt = create_text();
    txt->lst->push_back("Hello world1");
    txt->lst->push_back("Hello world2");
    txt->lst->push_back("Hello world3");
    txt->length=3;
    output_text += "Try again";
    testing::internal::CaptureStdout();
    m(txt,1,1);
    mp(txt,-1);
    std::string text = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(text.c_str(), output_text.c_str());
     free(txt);
}
