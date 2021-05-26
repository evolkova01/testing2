#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(j, normal)
{
    std::string output_text = "";

    text txt = create_text();
    txt->lst->push_back("Hello world1");
    txt->lst->push_back("Hello world2");
    txt->lst->push_back("Hello world3");
    txt->length=3;
    output_text += "H|ello world1Hello world2";
    output_text += "Hello world3";

    //захват вывода
    testing::internal::CaptureStdout();
    m(txt,0,1);
    j(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);

}


TEST(j, normal2)
{
    std::string output_text = "";

    text txt = create_text();
    txt->lst->push_back("Hello world1");
    txt->lst->push_back("Hello world2");
    txt->lst->push_back("Hello world3");
    txt->length=3;
    output_text += "Hello world1";
    output_text += "H|ello world2Hello world3";

    //захват вывода
    testing::internal::CaptureStdout();
    m(txt,1,1);
    j(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);

}


