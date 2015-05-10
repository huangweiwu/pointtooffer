#include<iostream>
#include<queue>
using namespace std;

// �������´�ӡ��������Ҳ���ֲ����������
// ˼·���������У��Ƚ����ڵ�����У�Ȼ��������е�Ԫ��ֱ������Ϊ��
//	������ÿ���һ��Ԫ�أ����亢�ӽڵ���������

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