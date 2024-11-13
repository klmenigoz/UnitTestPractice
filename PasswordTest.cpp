/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/////////////////////////////// COUNT LEADING //////////////////////////////////////////////
TEST(PasswordTest, single_letter_password)	// single_letter password is the name of this particular unit test CASE	
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");	// "happy" test, will pass
	ASSERT_EQ(1, actual);	// asserting that actual value is 1
}

TEST(PasswordTest, null_input)	// the name of this second test case is
{
	Password my_password;
	int actual = my_password.count_leading_characters("");	// "sad" test, will not pass
	ASSERT_EQ(0, actual);	// asserting that actual value is 1
}

TEST(PasswordTest, three_letter_password)	// the name of this second test case is three letter password, asserting 1 for a not showing up a second time
{
	Password my_password;
	int actual = my_password.count_leading_characters("aAa_nonrepeating");	// "happy" test, will pass
	ASSERT_EQ(1, actual);	// asserting that actual is 2 for the repeated 'a'
}

TEST(PasswordTest, three_letter_password_repeated)	// the name of this second test case is three letter password, asserting 1 for a not showing up a second time
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaa");	// 
	ASSERT_EQ(3, actual);	// asserting that actual is 3 for the repeated 'a'
}

/////////////////////////////// MIXED CASE //////////////////////////////////////////////
TEST(PasswordTest, good_mixed_case)	
{
	Password my_password;
	int actual = my_password.has_mixed_case("Zz");	// expected usage, is mixed
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, bad_mixed_case)	
{
	Password my_password;
	int actual = my_password.has_mixed_case("ZZ");	// should not pass, not mixed case
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, bad_mixed_case_2)
{
	Password my_password;
	int actual = my_password.has_mixed_case("zz");	// should not pass, not mixed case
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, has_special)	
{
	Password my_password;
	int actual = my_password.has_mixed_case("!?wTF");	// should pass, has upper and lower but spechal chars first
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, has_special_and_space)	
{
	Password my_password;
	int actual = my_password.has_mixed_case("I am not(?) okay");	// should pass, has capitalized I
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, null_password)	
{
	Password my_password;
	int actual = my_password.has_mixed_case("");	// should not pass, not mixed case (null password)
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, number)	
{
	Password my_password;
	int actual = my_password.has_mixed_case("1234");	// should not pass, not mixed, no chars even
	ASSERT_EQ(0, actual);
}
