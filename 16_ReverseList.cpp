#include<iostream>
using namespace std;

// 反转一个链表，输入一个头结点，输出反转后的链表的头结点
// 需要考虑链表为空、仅有一个结点或者多于一个结点的情况
// 反转其中一个结点，需要保留前一个结点，将当前结点的next赋为前一个结点（在赋值之前先保留当前结点的next作为下一个遍历的结点）
// 当遍历的当前结点的next为空时，说明已经到达尾结点，该结点即是反转后的链表的头结点

struct ListNode {
	int value;
	ListNode* next;
};

ListNode* ReverseList(ListNode* headNode) {
	if(headNode == NULL)
		return NULL;
	if(headNode->next == NULL)
		return headNode;

	ListNode* pReverseHead = NULL;
	ListNode* pNode = headNode;
	ListNode* pPrev = NULL;
	while(pNode != NULL) {
		ListNode* pNext = pNode->next;
		if(pNext == NULL)
			pReverseHead = pNode;

		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}

	return pReverseHead;
}

int main() {
	ListNode* headNode = new ListNode();
	headNode->value = 1;
	headNode->next = new ListNode();

	headNode->next->value = 2;
	headNode->next->next = new ListNode();

	headNode->next->next->value = 3;
	headNode->next->next->next = NULL;

	ReverseList(headNode);

	system("pause");
	return 0;
}