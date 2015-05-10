#include<iostream>
#include<stack>
using namespace std;

// 序列A/B，按照序列A的顺序进行压栈，是否有可能按照B的顺序出栈
// 思路：借助一个栈，遍历序列A的元素，并入栈；每压入一个元素，则将与B序列中当前位置的元素与栈顶元素比较，相等则弹出
// 遍历完序列A，如果栈为空，则return true；否则return false;

bool IsPopOrder(const int* pPush, const int* pPop, int length) {
	if(pPush == NULL || pPop == NULL || length == 0)
		return false;

	stack<int> s;
	int pushIndex = 0;
	int popIndex = 0;
	while(pushIndex < length) {
		s.push(pPush[pushIndex]);
		while(!s.empty() && pPop[popIndex] == s.top()) {
			popIndex++;
			s.pop();
		}
		pushIndex++;
	}
	if(s.empty())
		return true;
	else
		return false;
}

int main() {
	int pPush[] = {1, 2, 3, 4, 5};
	int pPop[] = {4, 3, 5, 1, 2};

	cout << IsPopOrder(pPush, pPop, 5) << endl;
	
	system("pause");
	return 0;
}