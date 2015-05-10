#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int value;
	ListNode* next;
};

// ����β���ӽ��
void AddToTail(ListNode** pHead, int value) {
	ListNode* pNew = new ListNode();
	pNew->value = value;
	pNew->next = NULL;

	// ���ͷ����ǿյ�
	if(*pHead == NULL)
		*pHead = pNew;

	// ��������β
	else {
		ListNode* pNode = *pHead;
		while(pNode->next != NULL)
			pNode = pNode->next;

		pNode->next = pNew;
	}
}

// ɾ��һ����һ��ֵΪvalue�Ľ��
void RemoveNode(ListNode** pHead, int value) {
	if(pHead == NULL || *pHead == NULL)
		return;

	ListNode* pToBeDeleted = NULL;

	// Ҫɾ���Ľ��Ϊͷ���
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

// ��β��ͷ��ӡ����
// ʹ��ջ
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
// ʹ�õݹ�ķ���
void PrintListReversely_Recursively(ListNode* pHead) {
	if(pHead != NULL) {
		if(pHead ->next != NULL) {
			PrintListReversely_Recursively(pHead->next);
		}
	}
	cout << pHead->value << endl;
}