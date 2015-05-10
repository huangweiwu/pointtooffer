#include<iostream>
using namespace std;

// 判断一棵树B是否另一棵树A的子结构
// 思路：先遍历A，找到与B的根结点一样的结点r；再判断以r为根结点的子树是不是包含和树B一样的结构
//	递归的编程方式，代码非常简单

struct BinaryTreeNode {
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	if(pRoot2 == NULL)
		// 已经在树A中找到了树B
		return true;
	if(pRoot1 == NULL)
		// 没找到数B
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