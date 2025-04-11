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

class Baseball {
public:
	void guess(string askNums) {
		if (askNums.length() != 3)
			throw std::length_error("Must be three letters!");
		for (auto letter : askNums) {
			if (letter < '0' || letter > '9')
				throw std::invalid_argument("Must be numeric");
		}
	}
};