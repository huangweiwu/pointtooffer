#include<iostream>
#include<stack>
using namespace std;

// 用两个栈实现队列
// 思路：一个栈stack1用于存储刚入队列的元素，一个栈stack2用于存储将要出队列的元素
// 当stack2为空且有元素要出栈时，将stack1中的元素出栈并依次入stack2；如果依旧为空，则报错，队列为空

// 同时注意类模板的定义和使用

template<class T>
class CQueue {
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template<class T>
CQueue<T>::CQueue(void) {
}

template<class T>
CQueue<T>::~CQueue(void) {
}

template<class T>
void CQueue<T>::appendTail(const T& node) {
	stack1.push(node);
}

template<class T>
T CQueue<T>::deleteHead() {
	if(stack2.size() <= 0) {
		while(stack1.size() > 0) {
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if(stack2.size() <= 0) {
		throw std::exception("Invalid input.");
	}

	T head = stack2.top();
	stack2.pop();

	return head;
}

int main() {
	CQueue<int> cq;
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	cq.appendTail(a);
	cq.appendTail(b);
	cq.appendTail(c);
	cq.deleteHead();
	cq.appendTail(d);
	cq.deleteHead();
	cq.deleteHead();
	cq.deleteHead();
	cq.deleteHead();
	cq.deleteHead();

	system("pause");
	return 0;
}


// 用两个队列实现一个栈也是一样的
// 用queue1存储刚如入栈的元素，queue2存储将要出栈的元素
// 插入一个新的元素时，将其入队列queue1；弹出一个元素时，从queue2中删除，如果queue2中没有了，则将queue1中的元素依次出队列进入queue2中