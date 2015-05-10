#include<iostream>
#include <time.h>
using namespace std;

// 实现指数函数，要全面的考虑所有的输入情况，指数为负，基数为0等情况
// 本题没有考虑大数情况
// 另外，高效的指数算法，a^n = (a^(n/2))^2

bool g_InvalidInput = false;			//全局变量

bool equals(double num1, double num2) {
	if((num1 - num2 > -0.0000001) && (num1 - num2) < 0.0000001)
		return true;
	else
		return false;
}

double PowerWithUnsignedExponent(double base, int exponent) {
	int result = 1.0;
	for(int i=0; i<exponent; i++)
		result *= base;
	return result;
}

double PowerWithUnsignedExponentMore(double base, int exponent) {
	if(exponent == 0)
		return 1.0;
	if(exponent == 1)
		return base;

	double result = PowerWithUnsignedExponentMore(base, exponent >> 1);
	result *= result;
	if(exponent & 0x01 == 1)
		result *= base;

	return result;
}

double power(double base, int exponent) {
	g_InvalidInput = false;

	if(equals(base, 0.0) && exponent < 0) {
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int) exponent;
	if(exponent < 0)
		absExponent = (unsigned int) -exponent;

	double result = PowerWithUnsignedExponentMore(base, absExponent);
	if(exponent < 0)
		result = 1 / result;

	return result;
}

int main() {
	clock_t  clockBegin, clockEnd;  
    clockBegin = clock();
	for(int i=0; i<1000000; i++)
		double a = power((double) 6, -40);
	clockEnd = clock(); 

	cout << "消耗时间：" << clockEnd - clockBegin << endl;
	system("pause");
	return 0;
}