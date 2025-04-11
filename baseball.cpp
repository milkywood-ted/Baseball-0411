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
		if (askNums.length() != 3)
			throw std::length_error("Must be three letters!");
		for (auto letter : askNums) {
			if (letter < '0' || letter > '9')
				throw std::invalid_argument("Must be numeric");
		}
	}
};