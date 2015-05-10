#include<iostream>
using namespace std;


// ��ӡ��1������nλʮ����������������3�����ӡ��1��999
// �������Ҫ�����ڴ�����������n�Ƚϴ�ʱ�����ʾ�����ʮ�������޷����������ͱ�ʾ����ҪѰ��һ���µĶ����ݽṹ������
// ˼·���ַ��������ַ����飬�����ַ�����ģ�������ӷ�

// ��̬����������󣬸���ֵ�����Ҫ��ס�ͷ�

bool IncreNumber(char* number) {
	int length = strlen(number);
	int curTakeOver = 1;				// ��ǰ��λ����ʼ��λ�൱��1
	bool isOverFlow = false;

	for(int i=length-1; i>=0; i--) {
		int tempSum = number[i] - '0' + curTakeOver;
		if(tempSum >= 10) {
			if(i == 0)
				// ����Ѿ��ڵ�һλ�������λ�ϲ�����λ��˵���Ѿ��������
				isOverFlow = true;
			else {
				curTakeOver = 1;
				tempSum -= 10;
				number[i] = '0' + tempSum;
			}
		}
		else {
			// �����ǰ��������λ�����ڵ�ǰλ��1������ѭ��
			number[i] = '0' + tempSum;
			break;
		}
	}

	return isOverFlow;
}

void PrintNumber(char* number) {
	int length = strlen(number);
	int i = 0;
	while(number[i] == '0' && i<=length)
		i++;
	for(; i<length; i++)
		printf("%c", number[i]);
}

void PrintOnttoMaxOfNDigit(int n) {
	if(n <= 0)
		return;

	char* number = new char[n+1];
	memset(number, '0', n);
	number[n] = '\0';
	while(!IncreNumber(number)) {
		PrintNumber(number);
		cout << endl;
	}
	
	delete []number;
}


// Ҳ�����õݹ�ķ���������ÿһλ����ȡ1~9�������1~9��ȫ����

void PrintOnttoMaxOfNDigitRecursively(char* number, int length, int index) {
	if(index == length - 1) {
		//��ֹ�������ݹ��λ�Ѿ��������λ
			PrintNumber(number);
			return;
	}
	for(int i=0; i<10; i++) {
		number[index + 1] = '0' + i;
		PrintOnttoMaxOfNDigitRecursively(number, length, index+1);
	}
}

void PrintOnttoMaxOfNDigitR(int n) {
	if(n <= 0)
		return;
	char* number = new char[n+1];
	memset(number, '0', n);
	number[n] = '\0';

	for(int i=0; i<10; i++) {
		number[0] = '0' + i;
		PrintOnttoMaxOfNDigitRecursively(number, n, 0);
	}

	delete []number;
}

int main() {
	int n = 4;
	PrintOnttoMaxOfNDigitR(n);
	
	system("pause");
	return 0;
}