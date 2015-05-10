#include<iostream>
using namespace std;

// ��תһ������������һ��ͷ��㣬�����ת���������ͷ���
// ��Ҫ��������Ϊ�ա�����һ�������߶���һ���������
// ��ת����һ����㣬��Ҫ����ǰһ����㣬����ǰ����next��Ϊǰһ����㣨�ڸ�ֵ֮ǰ�ȱ�����ǰ����next��Ϊ��һ�������Ľ�㣩
// �������ĵ�ǰ����nextΪ��ʱ��˵���Ѿ�����β��㣬�ý�㼴�Ƿ�ת���������ͷ���

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