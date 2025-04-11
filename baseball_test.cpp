#include "gmock/gmock.h"
#include "baseball.cpp"

#include <stdexcept>

class BaseballFixture : public ::testing::Test {
public:
	Baseball game;

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

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}