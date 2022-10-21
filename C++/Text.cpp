#include "stdafx.h"
#include "Text.h"

bool Text::fast_solw_pointer(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return true;
	}
	// ����ָ��
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	// �е��벿������
	fast = slow->next;
	slow->next = NULL;
	ListNode *change = NULL;
	while (fast != NULL) {
		change = fast->next;
		fast->next = slow;
		slow = fast;
		fast = change;
	}
	// �����ж�
	change = slow;
	fast = head;
	bool res = true;
	while (slow != NULL && fast != NULL) {
		if (slow->val != fast->val) {
			res = false;
			return res;
		}
		slow = slow->next;
		fast = fast->next;
	}
	// ������ָ�
	slow = change->next;
	change->next = NULL;
	while (slow != NULL) {
		fast = slow->next;
		slow->next = change;
		change = slow;
		slow = fast;
	}
	return res;
}

/*// ������
Node* Text::copyListWithRand(Node *head) {
	unordered_map<Node*, Node*> *map = new unordered_map<Node*, Node*>();
	Node *p = head;
	while (p != NULL) {
		map->insert(p,new Node(p->val));
		p = p->next;
	}
	p = head;
	while (p != NULL) {
		map->find(p)->second->next = map->find(p->next)->second;
		map->find(p)->second->rand = map->find(p->rand)->second;
		p = p->next;
	}
	return map->find(head)->second;
}*/

ListNode* Text::getLoopNode(ListNode *head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL) {
		return NULL;
	}
	ListNode *fast = head->next->next;
	ListNode *slow = head->next;
	while (fast->next != NULL || fast->next->next != NULL) {
		if (fast == slow) {
			return fast;
		}
		else {
			fast = fast->next->next;
			slow = slow->next;
		}
	}
	return NULL;
}

ListNode* Text::noLoop(ListNode* head1, ListNode *head2) {
	ListNode *curr1 = head1;
	ListNode *curr2 = head2;
	int n = 0;// n = ������ - ������
	while (curr1->next != NULL) {
		n++;
		curr1 = curr1->next;
	}
	while (curr2->next != NULL) {
		n--;
		curr2 = curr2->next;
	}
	if (curr1 != curr2) {
		return NULL;
	}
	curr1 = n > 0 ? head1 : head2;
	curr2 = curr1 == head1 ? head2 : head1;
	n = abs(n);
	while (n != 0) {
		n--;
		curr1 = curr1->next;
	}
	while (curr1 != curr2) {
		curr1->next;
		curr2->next;
	}
	return curr1;
}

ListNode* Text::bothLoop(ListNode* head1, ListNode* loop1, ListNode* head2, ListNode* loop2) {

	return head1;
}

void Text::OrderRecur(TreeNode *head) {
	if (head == NULL) {
		return;
	}
	//����
	OrderRecur(head->left);
	//����
	OrderRecur(head->right);
	//����
}// �������ݹ����

void Text::preOrderUnRecur(TreeNode *head) {
	if (head != NULL) {
		stack<TreeNode*> stackk;
		stackk.push(head);
		while (!stackk.empty()) {
			head = stackk.top();
			cout << head->val << endl;
			if (head->right != NULL) {
				stackk.push(head->right);
			}
			if (head->left != NULL) {
				stackk.push(head->left);
			}
		}
	}
} // �������ǵݹ��������

void Text::inOrderUnRecur(TreeNode *head) {
} // �������ǵݹ��������

void Text::posOrderUnRecur(TreeNode *head) {
} // �������ǵݹ�������

// �����������ж�(����1�ݹ飬����2�ǵݹ�)�������
int BSTPreValue = INT_MIN;
bool Text::isBST(TreeNode* head) {
	// �ݹ�
	if (head == NULL) return true;
	bool LeftisBST = isBST(head->left);
	if (!LeftisBST) return false;
	else {
		if (head->val <= BSTPreValue) return false;
		else BSTPreValue = head->val;
	}
	return isBST(head->right);
	// �ǵݹ�
	if (head == NULL) return true;
	int BSTPreValue = INT_MIN;
	stack<TreeNode*> tree;
	while (!tree.empty() || head != NULL) {
		if (head != NULL) {
			tree.push(head);
			head = head->left;
		}
		else {
			head = tree.top();
			if (head->val <= BSTPreValue) return false;
			else BSTPreValue = head->val;
			head = head->right;
		}
	}
	return true;
}

// ��ȫ�������ж�
bool Text::isCBT(TreeNode* head) {
	// ������ȱ���
	// 1������һ�ڵ����Һ��������� false
	// 2��ĳ�ڵ�������ӣ��������㶼ΪҶ�ӽ�㡣��������false
	if (head == NULL) return true;
	queue<TreeNode*> tree;
	TreeNode *l = NULL;
	TreeNode *r = NULL;
	bool leaf = false;
	tree.push(head);
	// C++�����޷��ص�һ��Ԫ�ز�ɾ������
	while (!tree.empty()) {
		head = tree.front();
		tree.pop();
		l = head->left;
		r = head->right;
		if ((leaf && (l != NULL || r != NULL)) || (l == NULL && r != NULL)) return false;
		if (l != NULL) tree.push(l);
		if (r != NULL) tree.push(r);
		if (l == NULL || r == NULL) leaf = true;
	}
	return true;
}

// ����DP����̬�滮���������˼·����������������ȡ��Ϣ����
// ƽ��������ж�
bool Text::isBalance(TreeNode* head) {
	// ��ȡ������������Ϣ���Ƿ�ƽ�⣬�߶�
	return Balanceprocess(head).isBalance;
}
// ƽ��������ݹ��ж�
BalanceReturnType Text::Balanceprocess(TreeNode* head) {
	if (head == NULL) return BalanceReturnType(true, 0); // base
	BalanceReturnType left = Balanceprocess(head->left);
	BalanceReturnType right = Balanceprocess(head->right);
	int height = max(left.height, right.height) + 1;
	// ����ƽ�� && ����ƽ�� && ������������Ȳ�С��2
	bool Balance = left.isBalance && right.isBalance && abs(left.height - right.height) < 2;
	return BalanceReturnType(Balance, height);
}

// �������ڵ���͹�������
TreeNode* Text::LowestCommonAncester(TreeNode *head, TreeNode *o1, TreeNode *o2) {
	// �ݹ�ʹ��HashMap
	unordered_map<TreeNode*, TreeNode*> map;
	map[head] = head;
	LCAprocess(head, map);
	unordered_set<TreeNode*> set1;
	TreeNode *curr = o1;
	while (curr != map[curr]) {
		set1.insert(curr);
		curr = map[curr];
	}
	set1.insert(head);
	while (!set1.count(o2)) {
		o2 = map[o2];
	}
	return o2;
	// �ݹ鲻ʹ��HashMap
	// 1����Ϊ�����������o1��o2Ϊ��͹������ȣ���o1��o2�ϲ�Ϊ��͹�������
	if (head == NULL || head == o1 || head == o2) return head; // base
	TreeNode* left = LowestCommonAncester(head->left, o1, o2);
	TreeNode* right = LowestCommonAncester(head->right, o1, o2);
	if (left != NULL && right != NULL) {
		return head;
	}
	return left != NULL ? left : right;
}

// LowestCommonAncester�ݹ麯��
void Text::LCAprocess(TreeNode* head, unordered_map<TreeNode*, TreeNode*> fatherMap) {
	if (head->left == NULL && head->right == NULL) return; // base
	fatherMap[head->left] = head;
	fatherMap[head->right] = head;
	//fatherMap.insert(head->left, head); ʹ��insert�ᱨ������
	//fatherMap.insert(head->right, head);
	LCAprocess(head->left, fatherMap);
	LCAprocess(head->right, fatherMap);
}