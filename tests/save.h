#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include "common.h"
#include "text.h"
#include "_text.h"
using namespace std;

TEST(save_fun, multiple_lines)
{
    std::string output_text = "";
    text txt = create_text();
    txt->lst->push_back("Hello world1");
    txt->lst->push_back("Hello world2");
    txt->length=2;


    txt->cursor->position = 0;
    save(txt, "save_fun.txt");

    text txt2 = create_text();
    load(txt2, "save_fun.txt");

    EXPECT_EQ(txt->lst->size(), txt2->lst->size());

    string* txt_arr = new string[txt->lst->size()];
    string* txt2_arr = new string[txt2->lst->size()];
    copy(txt->lst->begin(), txt->lst->end(), txt_arr);
    copy(txt2->lst->begin(), txt2->lst->end(), txt2_arr);

    for(unsigned int i = 0; i < txt->lst->size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}

TEST(save_fun, one_line)
{
    text txt = create_text();
    txt->lst->push_back("Hello world1");
    txt->length=1;


    txt->cursor->position = 0;
    save(txt, "save_funn.txt");

    text txt2 = create_text();
    load(txt2, "save_funn.txt");

    EXPECT_EQ(txt->lst->size(), txt2->lst->size());

    string* txt_arr = new string[txt->lst->size()];
    string* txt2_arr = new string[txt2->lst->size()];
    copy(txt->lst->begin(), txt->lst->end(), txt_arr);
    copy(txt2->lst->begin(), txt2->lst->end(), txt2_arr);

    for(unsigned int i = 0; i < txt->lst->size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}

TEST(save_fun, empty_file)
{
    text txt = create_text();

    txt->cursor->position = 0;
    txt->length=0;
    save(txt, "save_funnn.txt");

    text txt2 = create_text();
    load(txt2, "save_funnn.txt");

    EXPECT_EQ(txt->lst->size(), txt2->lst->size());

    string* txt_arr = new string[txt->lst->size()];
    string* txt2_arr = new string[txt2->lst->size()];

    copy(txt->lst->begin(), txt->lst->end(), txt_arr);
    copy(txt2->lst->begin(), txt2->lst->end(), txt2_arr);

    for(unsigned int i = 0; i < txt->lst->size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}
