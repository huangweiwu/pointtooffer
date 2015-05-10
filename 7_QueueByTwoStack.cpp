#include<iostream>
#include<stack>
using namespace std;

// ������ջʵ�ֶ���
// ˼·��һ��ջstack1���ڴ洢������е�Ԫ�أ�һ��ջstack2���ڴ洢��Ҫ�����е�Ԫ��
// ��stack2Ϊ������Ԫ��Ҫ��ջʱ����stack1�е�Ԫ�س�ջ��������stack2���������Ϊ�գ��򱨴�������Ϊ��

// ͬʱע����ģ��Ķ����ʹ��

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


// ����������ʵ��һ��ջҲ��һ����
// ��queue1�洢������ջ��Ԫ�أ�queue2�洢��Ҫ��ջ��Ԫ��
// ����һ���µ�Ԫ��ʱ�����������queue1������һ��Ԫ��ʱ����queue2��ɾ�������queue2��û���ˣ���queue1�е�Ԫ�����γ����н���queue2��