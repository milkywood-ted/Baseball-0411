#include "gmock/gmock.h"
#include "baseball.cpp"

#include <stdexcept>

class BaseballFixture : public ::testing::Test {
public:
	Baseball game{ "123" };

	void assertIllegalArgument(string arg) {
		try {
			game.guess(arg);
			FAIL();
		}
		catch (std::exception& e) {
			//PASS
		}
	}
};

TEST_F(BaseballFixture, TC1) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, TC2) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}