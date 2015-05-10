#include<iostream>
#include<stack>
using namespace std;

// 已知二叉树的前序和中序遍历序列，重新构建二叉树
// 思路：前序遍历可以知道根结点，中序遍历可以确定左右子树；找到根结点后，递归地构建左右子树
struct BinaryTreeNode {
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

BinaryTreeNode* BuildBinaryTreeOfPreMidHelp(int* startOfPre, int* endOfPre, int* startOfMid, int* endOfMid);

BinaryTreeNode* BuildBinaryTreeOfPreMid(int* pre, int* mid, int length) {
	if(pre == NULL || mid == NULL || length <= 0)
		return NULL;
	else
		return BuildBinaryTreeOfPreMidHelp(pre, pre + length - 1, mid, mid + length - 1);
}

BinaryTreeNode* BuildBinaryTreeOfPreMidHelp(int* startOfPre, int* endOfPre, int* startOfMid, int* endOfMid) {
	BinaryTreeNode* rootNode = new BinaryTreeNode();

	// 前序遍历的第一个结点是根结点
	rootNode->value = startOfPre[0];
	rootNode->left = rootNode->right = NULL;

	// 判断终止条件，剩下一个结点
	// 注意判断地址相等和值相等的区别
	if(startOfPre == endOfPre) {
		if(startOfMid == endOfMid && *startOfPre == *startOfMid)
			return rootNode;
		else
			throw std::exception("Invalid input.");
	}

	// 找到根结点在中序遍历序列中的位置
	int* rootMid = startOfMid;
	while(*rootMid != startOfPre[0] && rootMid != endOfMid)
		rootMid++;
	if(rootMid == endOfMid && *rootMid != startOfPre[0])
		throw std::exception("Invalid input.");

	// 构建左右子树，先求出左子树的长度
	int leftLength = rootMid - startOfMid;
	int* leftEndOfPre = startOfPre + leftLength;

	if(leftLength > 0)
		rootNode->left = BuildBinaryTreeOfPreMidHelp(startOfPre + 1, leftEndOfPre, startOfMid, rootMid - 1);
	if(leftLength < endOfPre - startOfPre)
		rootNode->right = BuildBinaryTreeOfPreMidHelp(leftEndOfPre + 1, endOfPre, rootMid + 1, endOfMid);

	return rootNode;
}

int main() {
	int pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int mid[] = {4, 7, 2, 1, 5, 3, 8, 6};

	BinaryTreeNode* root = BuildBinaryTreeOfPreMid(pre, mid, 8);
	system("pause");
	return 0;
}