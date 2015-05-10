#include<iostream>
using namespace std;

// ����һ�����飬�������е������ŵ������ǰ�벿�֣�ż���ŵ�����ĺ�벿��
// ˼·��ά������ָ�룬һ���������ұ������ҵ�ż����ֹͣ��һ����������������ҵ�������ֹͣ����������ָ��ָ�������
// ����һ��ָ���ڵڶ���ָ��ĺ��棬��ֹѭ��

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

// ���ǿ���չ�ԣ�������������������Ĳ�ͬ���෽������ͬһ������¶�����ʵ��
// ��������б���ż����Ϊһ���������뺯�����У�ע�⺯����Ϊ������д��
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