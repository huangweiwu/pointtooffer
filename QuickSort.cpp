#include<iostream>
using namespace std;

// ʵ�ֿ��������㷨
// ˼·��ѡ��һ����Ԫx����������л��֣���ߵ�Ԫ�ر�xС���ұߵ�Ԫ�ر�x��
// ����ʵ�֣���һ���±�i��¼��߼�����ұߵ�λ�ã���ʼֵΪstart - 1���������飬��ǰλ��Ϊj����������xС��Ԫ�أ���i++��data[i]��data[j]����

void QuickSort(int data[], int start, int end);
int Partition(int data[], int start, int end);

void QuickSort(int data[], int start, int end) {
	if(start == end)
		return;

	int index = Partition(data, start, end);
	if(index > start)
		// ע��������ж�
		QuickSort(data, start, index - 1);
	if(index < end)
		QuickSort(data, index + 1, end); 
}

int Partition(int data[], int start, int end) {
	// ע��i�Ǵ�start-1��ʼ
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