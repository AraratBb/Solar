#include "parser.h"
#include <gtest/gtest.h>

TEST(ParserTest, Test1) { 
	Parser pars1("https://www.google.com:443/webhp?gws_rd=ssl");
	
	cout << "Testing " << pars1.GetURL() << endl;
	ASSERT_EQ("https", pars1.GetProtocol());
	ASSERT_EQ("www.google.com", pars1.GetDomain());
	ASSERT_EQ("443", pars1.GetPort());
	ASSERT_EQ("/webhp", pars1.GetPath());
	ASSERT_EQ("gws_rd=ssl", pars1.GetQuery());
}

TEST(ParserTest, Test2) { 
	Parser pars2("https://siteactiv.ru/terminy/url-adress/");
	
	cout << "Testing " << pars2.GetURL() << endl;
	ASSERT_EQ("https", pars2.GetProtocol());
	ASSERT_EQ("siteactiv.ru", pars2.GetDomain());
	ASSERT_EQ("", pars2.GetPort());
	ASSERT_EQ("/terminy/url-adress/", pars2.GetPath());
	ASSERT_EQ("", pars2.GetQuery());
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
