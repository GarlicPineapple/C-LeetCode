#pragma once
#ifndef _TEXT_H_
#define _TEXT_H_

#include "Structure.h"
#include <iostream>
#include <unordered_map> 
#include <stack>
#include <queue>
using namespace std;

class Text
{
public:

	bool fast_solw_pointer(ListNode *head); // ���������ָ������ж�
	//Node* copyListWithRand(Node *head); // �����ָ���������->���ԣ���ϣ��
	//Node copyListWithRand2(Node *head); // �����ָ���������->���ԣ�����
	ListNode* getLoopNode(ListNode *head); // �ж������Ƿ��л��������뻷�ڵ㣬���޻�����null
	ListNode* noLoop(ListNode* head1, ListNode *head2); // �����޻����ص�һ���ཻ�ڵ㣬�����뽻����null
	ListNode* bothLoop(ListNode* head1, ListNode* loop1, ListNode* head2, ListNode* loop2); // �����л����ص�һ���ཻ�ڵ㣬�����ཻ����null

	void OrderRecur(TreeNode *head); // �������ݹ����
	void preOrderUnRecur(TreeNode *head); // �������ǵݹ��������
	void inOrderUnRecur(TreeNode *head); // �������ǵݹ��������
	void posOrderUnRecur(TreeNode *head); // �������ǵݹ�������
	int BFS(TreeNode *head);// ������������ȱ�����������������ȣ�����һhashmap������������hashmap��

	bool isBST(TreeNode* head);// �����������ж�(����1�ݹ飬����2�ǵݹ�)�������
	bool isCBT(TreeNode* head);// ��ȫ�������ж�
	// ����DP����̬�滮���������˼·����������������ȡ��Ϣ����
	bool isBalance(TreeNode* head);// ƽ��������ж�
	BalanceReturnType Balanceprocess(TreeNode* head);// ƽ��������ݹ��ж�
	TreeNode* LowestCommonAncester(TreeNode *head, TreeNode *o1, TreeNode *o2);// �������ڵ���͹�������

};
#endif // !_TEXT_H_



