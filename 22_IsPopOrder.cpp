#include<iostream>
#include<stack>
using namespace std;

// ����A/B����������A��˳�����ѹջ���Ƿ��п��ܰ���B��˳���ջ
// ˼·������һ��ջ����������A��Ԫ�أ�����ջ��ÿѹ��һ��Ԫ�أ�����B�����е�ǰλ�õ�Ԫ����ջ��Ԫ�رȽϣ�����򵯳�
// ����������A�����ջΪ�գ���return true������return false;

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