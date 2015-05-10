#include<iostream>
using namespace std;

// 顺时针打印一个矩阵
// 思路：从外圈到内圈打印，每次的起始点(startX, startY)，startX=startY
// 继续循环的条件为2*startX < cols && 2*startX < rows
// 需要注意的是，最后一圈可能退化为一行、一列或者一个点；不过for循环本身就有点判断的意思，所以不需要多加判断语句

void Print(int number) {
	cout << number << endl;
}

void PrintMatrixInCircle(int** number, int rows, int cols, int start) {
	// 打印一个圈
	int endX = cols - start - 1;
	int endY = rows - start - 1;
	for(int i=start; i<=endX; i++)
		// 从左到右打印行
		Print(number[start][i]);
	for(int i=start+1; i<=endY; i++)
		// 从上到下打印列
		Print(number[i][endX]);
	for(int i=endX-1; i>=start; i--)
		// 从右到左打印行
		Print(number[endY][i]);
	for(int i=endY-1; i>start; i--)
		// 从下到上打印列
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