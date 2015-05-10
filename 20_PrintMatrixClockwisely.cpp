#include<iostream>
using namespace std;

// ˳ʱ���ӡһ������
// ˼·������Ȧ����Ȧ��ӡ��ÿ�ε���ʼ��(startX, startY)��startX=startY
// ����ѭ��������Ϊ2*startX < cols && 2*startX < rows
// ��Ҫע����ǣ����һȦ�����˻�Ϊһ�С�һ�л���һ���㣻����forѭ���������е��жϵ���˼�����Բ���Ҫ����ж����

void Print(int number) {
	cout << number << endl;
}

void PrintMatrixInCircle(int** number, int rows, int cols, int start) {
	// ��ӡһ��Ȧ
	int endX = cols - start - 1;
	int endY = rows - start - 1;
	for(int i=start; i<=endX; i++)
		// �����Ҵ�ӡ��
		Print(number[start][i]);
	for(int i=start+1; i<=endY; i++)
		// ���ϵ��´�ӡ��
		Print(number[i][endX]);
	for(int i=endX-1; i>=start; i--)
		// ���ҵ����ӡ��
		Print(number[endY][i]);
	for(int i=endY-1; i>start; i--)
		// ���µ��ϴ�ӡ��
		Print(number[i][start]);
}


void PrintMatrixClockwisely(int** number, int rows, int cols) {
	if(number==NULL || rows<=0 || cols <=0)
		return;
	int start = 0;
	while(2*start < rows && 2*start < cols) {
		PrintMatrixInCircle(number, rows, cols, start);
		start++;
	}
}

int main() {
	int rows = 3;
	int cols = 3;

	int** number = new int*[rows];
	for(int i=0; i<rows; i++)
		number[i] = new int[cols];

	int count = 1;
	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++) {
			number[i][j] = count;
			count++;
		}

	PrintMatrixClockwisely(number, rows, cols);

	system("pause");
	return 0;
}