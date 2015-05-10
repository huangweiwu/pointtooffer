#include<iostream>
using namespace std;

// �ж�һ����B�Ƿ���һ����A���ӽṹ
// ˼·���ȱ���A���ҵ���B�ĸ����һ���Ľ��r�����ж���rΪ�����������ǲ��ǰ�������Bһ���Ľṹ
//	�ݹ�ı�̷�ʽ������ǳ���

struct BinaryTreeNode {
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	if(pRoot2 == NULL)
		// �Ѿ�����A���ҵ�����B
		return true;
	if(pRoot1 == NULL)
		// û�ҵ���B
		return false;
	if(pRoot1->value != pRoot2->value)
		return false;
	return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) && DoesTree1HaveTree2(pRoot1->right, pRoot2->right);


bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	bool result = false;
	if(pRoot1 != NULL && pRoot2 != NULL) {
		if(pRoot1->value == pRoot2->value)
			result = DoesTree1HaveTree2(pRoot1, pRoot2);
		if(!result)
			result = HasSubTree(pRoot1->left, pRoot2);
		if(!result)
			result = HasSubTree(pRoot1->right, pRoot2);
	}
	return result;
}