#include<iostream>
using namespace std;

// 给定一个数组，将数组中的奇数放到数组的前半部分，偶数放到数组的后半部分
// 思路：维护两个指针，一个从左往右遍历，找到偶数则停止，一个从右往左遍历，找到奇数则停止，交换两个指针指向的内容
// 当第一个指针在第二个指针的后面，终止循环

void ListOddFrontOfEven(int* pData, unsigned int length) {
	if(pData == NULL || length == 0)
		return;

	int* pBegin = pData;
	int* pEnd = pData + length - 1;
	while(pBegin < pEnd) {
		while(pBegin < pEnd && (*pBegin & 0x01) != 0)
			pBegin++;
		while(pBegin < pEnd && (*pEnd & 0x01) == 0)
			pEnd--;
		if(pBegin < pEnd) {
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

// 考虑可扩展性，即将数组分类两类数的不同分类方法，在同一个框架下都可以实现
// 将上面的判别奇偶性作为一个函数传入函数体中，注意函数作为参数的写法
void ReOrder(int* pData, unsigned int length, bool (*func)(int )) {
	if(pData == NULL || length == 0)
		return;

	int* pBegin = pData;
	int* pEnd = pData + length - 1;
	while(pBegin < pEnd) {
		while(pBegin < pEnd && !func(*pBegin))
			pBegin++;
		while(pBegin < pEnd && func(*pEnd))
			pEnd--;
		if(pBegin < pEnd) {
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int a) {
	return a & 1 == 0;
}

int main() {
	int pData[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	ReOrder(pData, 10, isEven);

	system("pause");
	return 0;
}