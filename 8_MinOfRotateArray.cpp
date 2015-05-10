#include<iostream>
using namespace std;

// ����һ���ź�����������ת���飬���ظ��������Сֵ����ת���鼴��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ��
// ˼·�����ֲ��ҷ���������ָ��start/end���ֱ�ָ�������ͷβ��ȡ�м�Ԫ��a[mid]
// ��a[mid]����a[start]����˵����С�����ں�벿�֣���a[mid]С��a[end]����˵����������ǰ�벿��
// ����ֱ�����end - start == 1����ʱend��Ϊ��СԪ�����ڵ�λ��
// start����ָ��ǰ�벿���ź������������һλ��end����ָ���벿���ź��������ĵ�һλ

int MinOfRotateArray(int a[], int length) {
	// ��������޷�������a[mid] == a[start] == a[end]�������a[mid]���ܴ���ǰ�벿���Ѿ��ź�������飬Ҳ���ܴ��ں�벿���Ѿ��ź��������
	int start = 0;
	int end = length - 1;
	int mid = start;
	
	// ���һ��ʼ���Ѿ��ź������ý���ѭ��
	while(a[start] >= a[end]) {
		if(end - start == 1) {
			// ��ֹ����
			mid = end;
			break;
		}
		mid = (start + end) / 2;
		if(a[mid] >= a[start])
			start = mid;
		else if(a[mid] <= a[end])
			end = mid;
	}
	return a[mid];
}

int MinInOrder(int a[], int start, int end) {
	int ret = a[start];
	for(int i=start+1; i<=end; i++) {
		if(ret > a[i])
			ret = a[i];
	}
	return ret;
}

int MinOfRotateArrayCorrect(int a[], int length) {
	// ���������Ǹ����󣬸��������ֻ��˳�����
	int start = 0;
	int end = length - 1;
	int mid = start;
	
	// ���һ��ʼ���Ѿ��ź������ý���ѭ��
	while(a[start] >= a[end]) {
		if(end - start == 1) {
			// ��ֹ����
			mid = end;
			break;
		}
		mid = (start + end) / 2;
		if(a[mid] == a[start] && a[mid] == a[end])
			return MinInOrder(a, start, end);
		if(a[mid] >= a[start])
			start = mid;
		else if(a[mid] <= a[end])
			end = mid;
	}
	return a[mid];
}



int main() {
	int a[] = {1, 0, 1, 1, 1};
	cout << MinOfRotateArray(a, 5) << endl;
	cout << MinOfRotateArrayCorrect(a, 5) << endl;

	system("pause");
	return 0;
}