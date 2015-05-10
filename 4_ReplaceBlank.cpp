#include<iostream>
using namespace std;

// 将字符串中的空格替换成%20，length参数为字符串数组允许分配的最大空间
// 先遍历一遍数组，统计空格的个数，计算出新的字符数组的长度，从后往前填充，时间复杂度为O(n)
// 注意必须限定length，并在length范围内替换，否则会出错
void ReplaceBlank(char string[], int length) {
	if(string == NULL && length <= 0)
		return;

	// 先统计空格的个数，计算将空格替换后字符串的长度
	int originalLength = 0;			// 原字符串的长度
	int numberOfBlank = 0;			// 空格的个数
	int i = 0;
	while(string[i] != '\0') {
		if(string[i] == ' ')
			numberOfBlank++;
		originalLength++;

		i++;
	}

	int newLength = originalLength + numberOfBlank * 2;		//替换后的字符串的长度，每替换一个，字符串长度加1

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