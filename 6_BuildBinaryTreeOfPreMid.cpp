#include<iostream>
#include<stack>
using namespace std;

// ��֪��������ǰ�������������У����¹���������
// ˼·��ǰ���������֪������㣬�����������ȷ�������������ҵ������󣬵ݹ�ع�����������
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

	// ǰ������ĵ�һ������Ǹ����
	rootNode->value = startOfPre[0];
	rootNode->left = rootNode->right = NULL;

	// �ж���ֹ������ʣ��һ�����
	// ע���жϵ�ַ��Ⱥ�ֵ��ȵ�����
	if(startOfPre == endOfPre) {
		if(startOfMid == endOfMid && *startOfPre == *startOfMid)
			return rootNode;
		else
			throw std::exception("Invalid input.");
	}

	// �ҵ��������������������е�λ��
	int* rootMid = startOfMid;
	while(*rootMid != startOfPre[0] && rootMid != endOfMid)
		rootMid++;
	if(rootMid == endOfMid && *rootMid != startOfPre[0])
		throw std::exception("Invalid input.");

	// ��������������������������ĳ���
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