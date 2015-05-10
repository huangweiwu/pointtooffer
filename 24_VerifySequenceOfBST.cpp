#include<iostream>
using namespace std;

// 输入一个序列，判断该序列是否某棵二叉搜索树的后序遍历的结果
// 思路：二叉搜索树，后序遍历得到的序列，根结点在最后一位，而前面的序列可以分为两部分，前半部分比根结点小，后半部分比根结点大
//	根据上面规则，递归判断子序列是否后序遍历的结果

bool VerifySequenceOfBST(int sequence[], int length) {
	if(sequence == NULL || length <= 0)
		return false;

	if(length == 1)
		return true;

	int root = sequence[length - 1];		// 先得到根结点的值
	
	int i = 0;
	while(sequence[i] < root && i < length-1) {
		// 得到前半部分的终止位置
		i++;
	}

	int j = i;
	for(; j<length-1; j++) {
		if(sequence[j] < root)
			// 如果第二部分中存在比根结点大的数
			return false;
	}

	// 判断左子树是不是二叉搜索树
	bool left = true;
	if(i > 0)
		left = VerifySequenceOfBST(sequence, i);
	// 判断右子树是不是二叉搜索树
	bool right = true;
	if(i < length - 1)
		right = VerifySequenceOfBST(sequence + i, length - i - 1);
	return (left && right);
}

int main() {
	int sequence[] = {7, 4, 6, 5};

	cout << VerifySequenceOfBST(sequence, 4) << endl;

	system("pause");
	return 0;
}