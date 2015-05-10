#include<iostream>
using namespace std;

// 合并两个已经排好序的链表
// 思路1：递归的方式，两个头结点中较小的一个是新链表的头结点；剩余的两个链表的合并过程跟前面一样；终止条件为其中一个链表遍历到了结尾
// 思路2：循环遍历链表进行合并
// 注意：需要考虑链表为空的特殊情况

struct ListNode {
	int value;
	ListNode* next;
};

ListNode* MergeTwoSortedListRecursively(ListNode* pHead1, ListNode* pHead2) {
	if(pHead1 == NULL)
		return pHead2;
	else if(pHead2 == NULL)
		return pHead1;
	ListNode* pMergeHead = NULL;
	if(pHead1->value < pHead2->value) {
		pMergeHead = pHead1;
		pMergeHead->next = MergeTwoSortedListRecursively(pHead1->next, pHead2);
	}
	else {
		pMergeHead = pHead2;
		pMergeHead->next = MergeTwoSortedListRecursively(pHead1, pHead2->next);
	}
	return pMergeHead;
}

ListNode* MergeTwoSortedListIteratively(ListNode* pHead1, ListNode* pHead2) {
	if(pHead1 == NULL)
		return pHead2;
	else if(pHead2 == NULL)
		return pHead1;

	ListNode* pMergeHead = NULL;
	if(pHead1->value < pHead2->value) {
		pMergeHead = pHead1;
		pHead1 = pHead1->next;
	}
	else {
		pMergeHead = pHead2;
		pHead2 = pHead2->next;
	}

	ListNode* pNode = pMergeHead;
	while(pHead1 != NULL && pHead2 != NULL) {
		if(pHead1->value < pHead2->value) {
			pNode->next = pHead1;
			pHead1 = pHead1->next;
		}
		else {
			pNode->next  = pHead2;
			pHead2 = pHead2->next;
		}
		pNode = pNode->next;
	}
	if(pHead1 != NULL)
		pNode->next = pHead1;
	if(pHead2 != NULL)
		pNode->next = pHead2;

	return pMergeHead;
}

int main() {
	ListNode* headNode1 = new ListNode();
	headNode1->value = 1;
	headNode1->next = new ListNode();

	headNode1->next->value = 3;
	headNode1->next->next = new ListNode();

	headNode1->next->next->value = 5;
	headNode1->next->next->next = NULL;

	ListNode* headNode2 = new ListNode();
	headNode2->value = 2;
	headNode2->next = new ListNode();

	headNode2->next->value = 4;
	headNode2->next->next = new ListNode();

	headNode2->next->next->value = 6;
	headNode2->next->next->next = NULL;

	ListNode* newNode = MergeTwoSortedListRecursively(headNode1, headNode2);

	system("pause");
	return 0;
}