#include<iostream>
#include<queue>
using namespace std;

// 从上往下打印二叉树，也即分层遍历二叉树
// 思路：借助队列，先将根节点入队列；然后遍历队列的元素直至队列为空
//	队列中每输出一个元素，则将其孩子节点存入队列中

struct BinaryTreeNode {
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void PrintNumber(int number) {
	cout << number << endl;
}

void PrintBinaryTreeLevelly(BinaryTreeNode* pRoot) {
	if(pRoot == NULL)
		return;

	queue<BinaryTreeNode*> qbtn;
	qbtn.push(pRoot);
	while(!qbtn.empty()) {
		BinaryTreeNode* pNode = qbtn.front();
		PrintNumber(pNode->value);
		qbtn.pop();

		if(pNode->left)
			qbtn.push(pNode->left);
		if(pNode->right)
			qbtn.push(pNode->right);
	}
}

int main() {
	BinaryTreeNode* pRoot = new BinaryTreeNode();
	pRoot->value = 1;
	pRoot->left = new BinaryTreeNode();
	pRoot->left->value = 3;
	pRoot->right = new BinaryTreeNode();
	pRoot->right->value = 2;

	pRoot->left->left = new BinaryTreeNode();
	pRoot->left->left->value = 4;
	pRoot->left->right = new BinaryTreeNode();
	pRoot->left->right->value = 5;

	pRoot->right->left = new BinaryTreeNode();
	pRoot->right->left->value = 6;
	pRoot->right->right = new BinaryTreeNode();
	pRoot->right->right->value = 7;

	PrintBinaryTreeLevelly(pRoot);

	system("pause");
	return 0;
}