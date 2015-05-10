#include<iostream>
using namespace std;

// ����һ�����������������k�����
// ˼·1���ȱ���һ���������õ���������n���ٱ���һ���б��������n - k + 1����㼴��
// ˼·2��������ָ��p1, p2����ʼֵ��Ϊͷ��㣻p1����k-1����p2�������ߣ��ӵ�k����ʼ������ָ��ͬʱ�ߣ���p1����β���ʱ��p2��Ϊ����
//	˼·2����Ҫ����һ��

// ���ǳ����³���ԣ���Ҫ��listHead��k���м��飻ͬʱ��������������û��k�����

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