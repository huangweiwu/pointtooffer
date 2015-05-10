#include<iostream>
using namespace std;

// ����һ�����У��жϸ������Ƿ�ĳ�ö����������ĺ�������Ľ��
// ˼·����������������������õ������У�����������һλ����ǰ������п��Է�Ϊ�����֣�ǰ�벿�ֱȸ����С����벿�ֱȸ�����
//	����������򣬵ݹ��ж��������Ƿ��������Ľ��

bool VerifySequenceOfBST(int sequence[], int length) {
	if(sequence == NULL || length <= 0)
		return false;

	if(length == 1)
		return true;

	int root = sequence[length - 1];		// �ȵõ�������ֵ
	
	int i = 0;
	while(sequence[i] < root && i < length-1) {
		// �õ�ǰ�벿�ֵ���ֹλ��
		i++;
	}

	int j = i;
	for(; j<length-1; j++) {
		if(sequence[j] < root)
			// ����ڶ������д��ڱȸ��������
			return false;
	}

	// �ж��������ǲ��Ƕ���������
	bool left = true;
	if(i > 0)
		left = VerifySequenceOfBST(sequence, i);
	// �ж��������ǲ��Ƕ���������
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