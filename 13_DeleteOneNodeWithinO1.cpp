#include<iostream>
#include<time.h>
using namespace std;

// ��O(1)ʱ����ɾ��һ�������Ľڵ㣬����Ϊ��ѭ������
// ˼·���øý��ĺ�̽������ݴ��汾������ݣ�������̽��ɾ�����ɣ�����ý����β��㣬����Ҫ��ͷ�����ҵ���ǰ����㣬����ǰ������next����Ϊ��

struct ListNode {
	int value;
	ListNode* next;
};

bool deleteOneNode(ListNode** listHead, ListNode* toBeDeleteNode) {
	if(listHead == NULL || toBeDeleteNode == NULL) {
		throw std::exception("Invalid input.");
		return false;
	}

	// Ҫɾ���Ľڵ㲻��β���
	if(toBeDeleteNode->next != NULL) {
		ListNode* nextNode = toBeDeleteNode->next;
		toBeDeleteNode->value = toBeDeleteNode->next->value;
		toBeDeleteNode->next = toBeDeleteNode->next->next;

		delete nextNode;
		nextNode = NULL;
	}

	// ����ֻ��һ����㣬Ҫɾ���Ľڵ�պ���ͷ���
	else if(*listHead == toBeDeleteNode) {
		delete *listHead;
		*listHead = NULL;
	}

	// Ҫɾ���Ľڵ���β���
	else {
		ListNode* iterNode = *listHead;
		while(iterNode->next != toBeDeleteNode)
			iterNode = iterNode->next;
		iterNode->next == NULL;
		
		delete toBeDeleteNode;
		toBeDeleteNode = NULL;
	}

	return true;
}

int main() {
	ListNode* headNode = new ListNode();
	headNode->next = new ListNode();
	headNode->next->next = new ListNode();

	ListNode** listHead = new ListNode*();
	*listHead = headNode;

	ListNode* toBeDeleteNode = headNode->next->next;

	deleteOneNode(listHead, toBeDeleteNode);

	system("pause");
	return 0;
}