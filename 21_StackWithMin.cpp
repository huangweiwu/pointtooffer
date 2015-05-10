#include<iostream>
#include<stack>
#include <assert.h>
using namespace std;

// ʵ��һ��ӵ��min()������ջ����push()/pop()/min()��Ա��������ʱ�临�Ӷȶ�ΪO(1)
// ˼·�����а�������ջ��һ������ջ�����ڴ洢���ݣ�һ������ջ�����ڴ洢��ǰ��Сֵ
//  ��һ���µ�����ջʱ��������ջ����ǰ��СԪ�����Ƚϣ����С��ջ��Ԫ�أ����µ�ֵѹ�룬�������ջ��Ԫ�أ���ֵһ��ջ��Ԫ��ֵѹ��

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
		// �������ջ�ǿյģ�����valueС�ڸ���ջվ���ƣ���value��ջ
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