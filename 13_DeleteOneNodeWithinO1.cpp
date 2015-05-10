#include<iostream>
#include<time.h>
using namespace std;

// 在O(1)时间内删除一个给定的节点，链表为非循环链表
// 思路：用该结点的后继结点的内容代替本结点内容，并将后继结点删除即可；如果该结点是尾结点，则需要从头遍历找到其前驱结点，将其前驱结点的next域置为空

struct ListNode {
	int value;
	ListNode* next;
};

bool deleteOneNode(ListNode** listHead, ListNode* toBeDeleteNode) {
	if(listHead == NULL || toBeDeleteNode == NULL) {
		throw std::exception("Invalid input.");
		return false;
	}

	// 要删除的节点不是尾结点
	if(toBeDeleteNode->next != NULL) {
		ListNode* nextNode = toBeDeleteNode->next;
		toBeDeleteNode->value = toBeDeleteNode->next->value;
		toBeDeleteNode->next = toBeDeleteNode->next->next;

		delete nextNode;
		nextNode = NULL;
	}

	// 链表只有一个结点，要删除的节点刚好是头结点
	else if(*listHead == toBeDeleteNode) {
		delete *listHead;
		*listHead = NULL;
	}

	// 要删除的节点是尾结点
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