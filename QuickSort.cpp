#include<iostream>
using namespace std;

// 实现快速排序算法
// 思路：选择一个主元x，对数组进行划分，左边的元素比x小，右边的元素比x大
// 具体实现：用一个下标i记录左边集合最靠右边的位置，初始值为start - 1；遍历数组，当前位置为j，当遇到比x小的元素，将i++，data[i]与data[j]交换

void QuickSort(int data[], int start, int end);
int Partition(int data[], int start, int end);

void QuickSort(int data[], int start, int end) {
	if(start == end)
		return;

	int index = Partition(data, start, end);
	if(index > start)
		// 注意这里的判断
		QuickSort(data, start, index - 1);
	if(index < end)
		QuickSort(data, index + 1, end); 
}

int Partition(int data[], int start, int end) {
	// 注意i是从start-1开始
	int i = start - 1;
	int x = data[end];
	for(int j = start; j < end; j++) {
		if(data[j] <= x) {
			i++;
			swap(data[i], data[j]);
		}
	}
	i++;
	swap(data[i], data[end]);
	return i;
}

int main() {
	int data[] = {3, 2, 4, 5, 12, 33, 4, 23, 23, 53, 3};
	QuickSort(data, 0, 10);
	for(int i=0; i<11; i++)
		cout << data[i] << endl;

	system("pause");
	return 0;
}