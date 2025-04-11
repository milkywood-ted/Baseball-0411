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

class Baseball {
public:
	void guess(string askNums) {
		assertIllegalArguments(askNums);
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
		if (askNums[0] == askNums[1]
			|| askNums[0] == askNums[2]
			|| askNums[1] == askNums[2]
			) {
			return true;
		}
		return false;
	}
};