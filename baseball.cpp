/*
* �� ���� ���ڸ� ���ߴ� ����
���ڸ� ���ڸ� �õ��� �� ����
�������� �ƴ��� �˷��ָ�
������ ������ �� �ֵ��� ��Ʈ�� �ش�

* ��Ʈ�� �ִ� ���
Strike / Ball�� ������ �˷��ش�
Ball : ����� ��ġ�ϴ� ������ ����
Strike : ����� ��ġ�ϴ� �����̸鼭 , ��ġ���� ���� ������ ����
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
			return{ true, 3, 0 };
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