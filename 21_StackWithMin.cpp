#include<iostream>
#include<stack>
#include <assert.h>
using namespace std;

// 实现一个拥有min()函数的栈，有push()/pop()/min()成员函数，且时间复杂度都为O(1)
// 思路：类中包含两个栈，一个数据栈，用于存储数据；一个辅助栈，用于存储当前最小值
//  当一个新的数入栈时，将其与栈顶当前最小元素作比较；如果小于栈顶元素，则将新的值压入，如果大于栈顶元素，则赋值一个栈顶元素值压入

template<class T>
class StackWithMin {
public:
	void pop();
	void push(const T& value);
	const T& min();
private:
	stack<T> data;
	stack<T> auxi;
};

template<class T> void StackWithMin<T>::pop() {
	assert(data.size() > 0 && auxi.size() > 0);

	data.pop();
	auxi.pop();
}

template<class T> void StackWithMin<T>::push(const T& value) {
	data.push(value);

	if(auxi.empty() || value < auxi.top())
		// 如果辅助栈是空的，或者value小于辅助栈站定制，则将value入栈
		auxi.push(value);
	else
		auxi.push(auxi.top());
}

template<class T> const T& StackWithMin<T>::min() {
	assert(data.size() > 0 && auxi.size() > 0);

	return auxi.top();
}

int main() {
	StackWithMin<int> swmt;
	swmt.push(2);
	swmt.push(3);
	swmt.push(1);

	int a = swmt.min();
	swmt.pop();
	a = swmt.min();

	swmt.pop();
	swmt.pop();
	swmt.pop();

	system("pause");
	return 0;
}