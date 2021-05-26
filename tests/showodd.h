#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <string>
#include <iostream>
#include <sstream>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(showodd, normal)
{
    std::string output_text = "";

    text txt = create_text();
    txt->lst->push_back("Hello world1");
    txt->lst->push_back("Hello world2");
    txt->lst->push_back("Hello world3");
    txt->length=3;
    output_text += "";
    output_text += "Hello world2\n";
    output_text += "";

    //захват вывода
    testing::internal::CaptureStdout();
    showodd(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);

}

TEST(showodd, normal2)
{
    std::string output_text = "";

    text txt = create_text();
    txt->lst->push_back("Hello world1");
    txt->lst->push_back("Hello world2");
    txt->lst->push_back("Hello world3");
    txt->lst->push_back("Hello world4");
    txt->length=4;
    output_text += "";
    output_text += "Hello world2\n";
    output_text += "";
    output_text += "Hello world4\n";

    //захват вывода
    testing::internal::CaptureStdout();

    showodd(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);

}

TEST(showodd, negative)
{
    std::string output_text = "";

    text txt = create_text();

    txt->lst->push_back("");
    txt->lst->push_back("");
    txt->lst->push_back("");
    txt->length=0;
    output_text += "";
    output_text += "";
    output_text += "";

    //захват вывода
    testing::internal::CaptureStdout();
    showodd(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);



}
