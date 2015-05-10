#include<iostream>
using namespace std;


// 求一个数n的二进制表示中1的个数
// 方法1：用一个flag遍历n的所有位，初始值为1，每次往右移一位并与n进行与运算；时间复杂度与n的二进制位数成线性关系
// 方法2：利用n & (n - 1)将n的二进制表示中最右边的一位1变成0，且只要n>0，则必有1存在
// 下面实现方法2
int NumberOfOne(int n) {
	int count = 0;
	while(n > 0) {
		count++;
		n = n & (n - 1);
	}
	return count;
}




int main() {
	int n = 3;
	cout << NumberOfOne(n) << endl;

	system("pause");
	return 0;
}
