#include<iostream>
using namespace std;


// ��һ����n�Ķ����Ʊ�ʾ��1�ĸ���
// ����1����һ��flag����n������λ����ʼֵΪ1��ÿ��������һλ����n���������㣻ʱ�临�Ӷ���n�Ķ�����λ�������Թ�ϵ
// ����2������n & (n - 1)��n�Ķ����Ʊ�ʾ�����ұߵ�һλ1���0����ֻҪn>0�������1����
// ����ʵ�ַ���2
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