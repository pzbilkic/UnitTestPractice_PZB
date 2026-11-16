/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

//NOT SURE IF DOCKER TEST in README.md WILL WORK INSIDE OF THE CPP CONTAINER , 
//I DID NOT INSTALL THE CPP CONTAINTER ON THE CSU CHICO SCHOOL 
// LOANER LAPTOP

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_case_lower_then_upper)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("aB"));
}

TEST(PasswordTest, mixed_case_upper_then_lower)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("Ab"));
}

TEST(PasswordTest, mixed_case_all_lower)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("password"));
}

TEST(PasswordTest, mixed_case_all_upper)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("PASSWORD"));
}

TEST(PasswordTest, mixed_case_empty_string)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case(""));
}

TEST(PasswordTest, mixed_case_single_lower_letter)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("z"));
}

TEST(PasswordTest, mixed_case_single_upper_letter)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("Z"));
}

TEST(PasswordTest, mixed_case_no_letters)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("1234!@#$ "));
}

TEST(PasswordTest, mixed_case_lower_with_digits_and_symbols)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("pass123!"));
}