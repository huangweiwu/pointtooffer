#include<iostream>
using namespace std;

// 输入一个链表，输出倒数第k个结点
// 思路1：先遍历一遍链表，得到链表长度n；再遍历一遍列表，输出第n - k + 1个结点即可
// 思路2：用两个指针p1, p2，初始值均为头结点；p1先走k-1步，p2不动两边；从第k步开始，两个指针同时走；当p1到达尾结点时，p2即为所求
//	思路2仅需要遍历一遍

// 考虑程序的鲁棒性，需要对listHead和k进行检验；同时兼顾如果链表长度没有k的情况

struct ListNode {
	int value;
	ListNode* next;
};

ListNode* OutputReverseKNode(ListNode** listHead, unsigned int k) {
	if(listHead == NULL || *listHead == NULL || k == 0)
		return NULL;

	ListNode* pNode1 = *listHead;
	ListNode* pNode2 = *listHead;
	int count = 1;
	while(count < k) {
		if(pNode1->next != NULL) {
			pNode1 = pNode1->next;
			count++;
		}
		else
			return NULL;
	}

	while(pNode1->next != NULL) {
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}

	return pNode2;
}

int main() {
	ListNode* headNode = new ListNode();
	headNode->value = 1;
	headNode->next = new ListNode();

	headNode->next->value = 2;
	headNode->next->next = new ListNode();

	headNode->next->next->value = 3;
	headNode->next->next->next = NULL;

	ListNode** listHead = new ListNode*();
	*listHead = headNode;

	OutputReverseKNode(listHead, 3);

	system("pause");
	return 0;
}