/*
* 세 개의 숫자를 맞추는 게임
세자리 숫자를 시도할 때 마다
정답인지 아닌지 알려주며
정답을 유추할 수 있도록 힌트를 준다

* 힌트를 주는 방식
Strike / Ball의 개수를 알려준다
Ball : 정답과 일치하는 숫자의 개수
Strike : 정답과 일치하는 숫자이면서 , 위치까지 정한 숫자의 개수
*/

#include <string>
#include <stdexcept>

using std::string;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	Baseball() {}
	Baseball(string rightAnswer) : rightAnswer_{ rightAnswer } {}
	GuessResult guess(string askNums) {
		assertIllegalArguments(askNums);

		if(askNums == rightAnswer_)
			return { true, 3, 0 };

		int strikes = countStrike(askNums);
		return { false, strikes, countSame(askNums) - strikes };
	}

	int countStrike(string askNums) {
		int countSame = 0;
		for (int i = 0; i < 3; ++i)
			if (askNums[i] == rightAnswer_[i]) countSame++;
		return countSame;
	}
	int countSame(string askNums) {
		int countSame = 0;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (askNums[i] == rightAnswer_[j]) countSame++;
		
		return countSame;
	}

	void assertIllegalArguments(std::string& askNums)
	{
		if (askNums.length() != 3)
			throw std::length_error("Must be three letters!");
		for (auto letter : askNums) {
			if (letter >= '0' && letter <= '9') continue;
			throw std::invalid_argument("Must be numeric");
		}

		if (isHavingSameNumber(askNums))
			throw std::invalid_argument("Must not be same number");
	}
	bool isHavingSameNumber(std::string& askNums)
	{
		return (askNums[0] == askNums[1]
			|| askNums[0] == askNums[2]
			|| askNums[1] == askNums[2]
			);
	}
private:
	string rightAnswer_;
};