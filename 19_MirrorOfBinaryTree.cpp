#include<iostream>
#include<stack>
using namespace std;

// ��һ�ö������ľ��񣬼����к��ӽ��ģ��������Һ��ӽ�㽻��
// ˼·��ǰ��������ö������ķ�Ҷ�ӽ�㣬�����ǵ����Һ��ӽ���
// �õݹ�ķ����������ࣻҲ������ѭ���ķ���������ջ

struct BinaryTreeNode {
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void MirrorOfBinaryTreeRecursively(BinaryTreeNode* pRoot) {
	if(pRoot == NULL || (pRoot->left == NULL && pRoot->right == NULL))
		return;

	BinaryTreeNode* pNode = pRoot->left;
	pRoot->left =  pRoot->right;
	pRoot->right = pNode;

	if(pRoot->left != NULL)
		MirrorOfBinaryTreeRecursively(pRoot->left);
	if(pRoot->right != NULL)
		MirrorOfBinaryTreeRecursively(pRoot->right);
}

void MirrorOfBinaryTreeIteratively(BinaryTreeNode* pRoot) {
	if(pRoot == NULL || (pRoot->left == NULL && pRoot->right == NULL))
		return;

	stack<BinaryTreeNode*> btn;
	while(pRoot != NULL) {
		// �Ƚ����Ӵ������������Һ��ӣ�������ջ
		BinaryTreeNode* pTemp = NULL;
		pTemp = pRoot->left;
		pRoot->left =  pRoot->right;
		pRoot->right = pTemp;
		btn.push(pRoot);

		pRoot = pRoot->left;
	}

	while(!btn.empty()) {
		
		// ����һ����������������ͬ�����Ƚ�����ȫ����ջ
		pRoot = btn.top()->right;
		btn.pop();
		while(pRoot != NULL) {
			// �Ƚ����Ӵ������������Һ��ӣ�������ջ
			BinaryTreeNode* pTemp = NULL;
			pTemp = pRoot->left;
			pRoot->left =  pRoot->right;
			pRoot->right = pTemp;
			btn.push(pRoot);

			pRoot = pRoot->left;
		}
	}
}

int main() {
	BinaryTreeNode* pRoot = new BinaryTreeNode();
	BinaryTreeNode* pLeft = new BinaryTreeNode();
	BinaryTreeNode* pRight = new BinaryTreeNode();

	pRoot->value = 1;
	pLeft->value = 2;
	pRight->value = 3;

	pRoot->left = pLeft;
	pRoot->right = pRight;

	MirrorOfBinaryTreeIteratively(pRoot);

	system("pause");
	return 0;
}