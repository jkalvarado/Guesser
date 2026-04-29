/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
//TEST(GuesserTest, smoke_test)
//{
  //Guesser object("Secret");
  //ASSERT_EQ( 1+1, 2 );
//}

TEST(GuesserTest, empty_string)
{
	Guesser guess("");
	ASSERT_FALSE(guess.Guesser(string secret("")));
}

TEST(GuesserTest, over_32){
	Guesser guess("abcdefghijklmnopqrstuvwxyzabcdefghik");
	ASSERT_EQ(36, 32);
}

TEST(GuesserTest, supposed_to_locked){
	Guesser guess("Secret");
	ASSERT_FALSE(guess.match(0));
}

TEST(GuesserTest, when_right){
	Guesser guess("Hello");
	ASSERT_EQ(3, guess.distance());
}
