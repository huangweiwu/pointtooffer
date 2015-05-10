#include<iostream>
#include<stack>
using namespace std;

// 求一棵二叉树的镜像，即将有孩子结点的，将其左右孩子结点交换
// 思路：前序遍历整棵二叉树的非叶子结点，将他们的左右孩子交换
// 用递归的方法，代码简洁；也可以用循环的方法，借助栈

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
		// 先将左孩子处理（交换左右孩子），后入栈
		BinaryTreeNode* pTemp = NULL;
		pTemp = pRoot->left;
		pRoot->left =  pRoot->right;
		pRoot->right = pTemp;
		btn.push(pRoot);

		pRoot = pRoot->left;
	}

	while(!btn.empty()) {
		
		// 弹出一个，对其右子树，同样的先将左孩子全部入栈
		pRoot = btn.top()->right;
		btn.pop();
		while(pRoot != NULL) {
			// 先将左孩子处理（交换左右孩子），后入栈
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