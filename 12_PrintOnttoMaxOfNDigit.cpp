#include<iostream>
using namespace std;


// 打印从1到最大的n位十进制数，比如输入3，则打印从1到999
// 本题的主要考点在大数操作，当n比较大时，其表示的最大十进制数无法用内置类型表示，需要寻找一个新的额数据结构来保存
// 思路：字符串或者字符数组，并用字符数组模拟整数加法

// 动态分配了数组后，赋初值；最后要记住释放

bool IncreNumber(char* number) {
	int length = strlen(number);
	int curTakeOver = 1;				// 当前进位，初始进位相当于1
	bool isOverFlow = false;

	for(int i=length-1; i>=0; i--) {
		int tempSum = number[i] - '0' + curTakeOver;
		if(tempSum >= 10) {
			if(i == 0)
				// 如果已经在第一位（即最高位上产生进位，说明已经到最大了
				isOverFlow = true;
			else {
				curTakeOver = 1;
				tempSum -= 10;
				number[i] = '0' + tempSum;
			}
		}
		else {
			// 如果当前不产生进位，则在当前位加1并结束循环
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


// 也可以用递归的方法，由于每一位都是取1~9，因此是1~9的全排列

void PrintOnttoMaxOfNDigitRecursively(char* number, int length, int index) {
	if(index == length - 1) {
		//终止条件，递归的位已经到达最高位
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