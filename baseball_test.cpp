#include "gmock/gmock.h"
#include "baseball.cpp"

#include <stdexcept>

TEST(BaseballTS, TC1) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), std::length_error);
}

TEST(BaseballTS, TC2) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), std::invalid_argument);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}