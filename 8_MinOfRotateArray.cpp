#include<iostream>
using namespace std;

// 输入一个排好序的数组的旋转数组，返回该数组的最小值（旋转数组即把一个数组最开始的若干个元素搬到数组的末尾）
// 思路：二分查找法，用两个指针start/end，分别指向数组的头尾，取中间元素a[mid]
// 若a[mid]大于a[start]，则说明最小的数在后半部分；若a[mid]小于a[end]，则说明最大的数在前半部分
// 遍历直到最后，end - start == 1，此时end即为最小元素所在的位置
// start最终指向前半部分排好序的数组的最后一位，end最终指向后半部分排好序的数组的第一位

int MinOfRotateArray(int a[], int length) {
	// 这个方法无法处理，a[mid] == a[start] == a[end]的情况，a[mid]可能处于前半部分已经排好序的数组，也可能处于后半部分已经排好序的数组
	int start = 0;
	int end = length - 1;
	int mid = start;
	
	// 如果一开始就已经排好序，则不用进入循环
	while(a[start] >= a[end]) {
		if(end - start == 1) {
			// 终止条件
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
	// 修正上面那个错误，该种情况下只能顺序查找
	int start = 0;
	int end = length - 1;
	int mid = start;
	
	// 如果一开始就已经排好序，则不用进入循环
	while(a[start] >= a[end]) {
		if(end - start == 1) {
			// 终止条件
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
