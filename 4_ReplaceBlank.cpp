#include<iostream>
using namespace std;

// ���ַ����еĿո��滻��%20��length����Ϊ�ַ�������������������ռ�
// �ȱ���һ�����飬ͳ�ƿո�ĸ�����������µ��ַ�����ĳ��ȣ��Ӻ���ǰ��䣬ʱ�临�Ӷ�ΪO(n)
// ע������޶�length������length��Χ���滻����������
void ReplaceBlank(char string[], int length) {
	if(string == NULL && length <= 0)
		return;

	// ��ͳ�ƿո�ĸ��������㽫�ո��滻���ַ����ĳ���
	int originalLength = 0;			// ԭ�ַ����ĳ���
	int numberOfBlank = 0;			// �ո�ĸ���
	int i = 0;
	while(string[i] != '\0') {
		if(string[i] == ' ')
			numberOfBlank++;
		originalLength++;

		i++;
	}

	int newLength = originalLength + numberOfBlank * 2;		//�滻����ַ����ĳ��ȣ�ÿ�滻һ�����ַ������ȼ�1

	if(newLength > length)
		return;

	int indexOfOrigin = originalLength - 1;
	int indexOfNew = newLength - 1;
	//string[indexOfNew--] = '\0';
	while(indexOfOrigin >= 0 && indexOfNew > indexOfOrigin) {
		if(string[indexOfOrigin] == ' ') {
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else {
			string[indexOfNew--] = string[indexOfOrigin];
		}
		indexOfOrigin--;
	}
}

int main() {
	char string[20] = "hello world!  ";
	cout << string << endl;
	ReplaceBlank(string, 20);

	cout << string << endl;
	system("pause");
	return 0;
}