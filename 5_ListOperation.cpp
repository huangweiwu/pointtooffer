#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int value;
	ListNode* next;
};

// 往结尾添加结点
void AddToTail(ListNode** pHead, int value) {
	ListNode* pNew = new ListNode();
	pNew->value = value;
	pNew->next = NULL;

	// 如果头结点是空的
	if(*pHead == NULL)
		*pHead = pNew;

	// 遍历至结尾
	else {
		ListNode* pNode = *pHead;
		while(pNode->next != NULL)
			pNode = pNode->next;

		pNode->next = pNew;
	}
}

// 删除一个第一个值为value的结点
void RemoveNode(ListNode** pHead, int value) {
	if(pHead == NULL || *pHead == NULL)
		return;

	ListNode* pToBeDeleted = NULL;

	// 要删除的结点为头结点
	if((*pHead)->value == value) {
		pToBeDeleted = *pHead;
		(*pHead) = (*pHead)->next;
	}

	else {
		ListNode* pNode = *pHead;
		while(pNode->next != NULL && pNode->next->value != value) {
			pNode = pNode->next;
		}

		if(pNode->next != NULL && pNode->next->value == value) {
			pToBeDeleted = pNode->next;
			pNode->next = pNode->next->next;
		}
	}

	if(pToBeDeleted != NULL) {
		delete pToBeDeleted;
		pToBeDeleted == NULL;
	}
}

// 从尾到头打印链表
// 使用栈
void PrintListReversely_Iteratively(ListNode* pHead) {
	stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while(pNode != NULL) {
		nodes.push(pNode);
		pNode = pNode->next;
	}

	while(!nodes.empty()) {
		pNode = nodes.top();
		cout << pNode->value << endl;
		nodes.pop();
	}
}
// 使用递归的方法
void PrintListReversely_Recursively(ListNode* pHead) {
	if(pHead != NULL) {
		if(pHead ->next != NULL) {
			PrintListReversely_Recursively(pHead->next);
		}
	}
	cout << pHead->value << endl;
}
