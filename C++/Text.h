#pragma once
#ifndef _TEXT_H_
#define _TEXT_H_

#include "Structure.h"
#include <iostream>
#include <unordered_map> 
#include <stack>
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
	int w(TreeNode *head);// ������������ȱ�����������������ȣ�����һhashmap������������hashmap��
};
#endif // !_TEXT_H_



