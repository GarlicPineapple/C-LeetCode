#include "stdafx.h"
#include "Text.h"

bool Text::fast_solw_pointer(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return true;
	}
	// 快慢指针
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	// 中点后半部分逆序
	fast = slow->next;
	slow->next = NULL;
	ListNode *change = NULL;
	while (fast != NULL) {
		change = fast->next;
		fast->next = slow;
		slow = fast;
		fast = change;
	}
	// 回文判断
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
	// 将链表恢复
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

/*// 有问题
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
	int n = 0;// n = 长链表长 - 短链表长
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
	//先序
	OrderRecur(head->left);
	//中序
	OrderRecur(head->right);
	//后序
}// 二叉树递归遍历

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
} // 二叉树非递归先序遍历

void Text::inOrderUnRecur(TreeNode *head) {
} // 二叉树非递归中序遍历

void Text::posOrderUnRecur(TreeNode *head) {
} // 二叉树非递归后序遍历

// 搜索二叉树判断(方法1递归，方法2非递归)中序遍历
int BSTPreValue = INT_MIN;
bool Text::isBST(TreeNode* head) {
	// 递归
	if (head == NULL) return true;
	bool LeftisBST = isBST(head->left);
	if (!LeftisBST) return false;
	else {
		if (head->val <= BSTPreValue) return false;
		else BSTPreValue = head->val;
	}
	return isBST(head->right);
	// 非递归
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

// 完全二叉树判断
bool Text::isCBT(TreeNode* head) {
	// 宽度优先遍历
	// 1、任意一节点有右孩子无左孩子 false
	// 2、某节点仅有左孩子，则后续结点都为叶子结点。不满足则false
	if (head == NULL) return true;
	queue<TreeNode*> tree;
	TreeNode *l = NULL;
	TreeNode *r = NULL;
	bool leaf = false;
	tree.push(head);
	// C++队列无返回第一个元素并删除函数
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

// 树型DP（动态规划）问题解题思路：从左树、右树获取信息解题
// 平衡二叉树判断
bool Text::isBalance(TreeNode* head) {
	// 获取左树和右树信息：是否平衡，高度
	return Balanceprocess(head).isBalance;
}
// 平衡二叉树递归判断
BalanceReturnType Text::Balanceprocess(TreeNode* head) {
	if (head == NULL) return BalanceReturnType(true, 0); // base
	BalanceReturnType left = Balanceprocess(head->left);
	BalanceReturnType right = Balanceprocess(head->right);
	int height = max(left.height, right.height) + 1;
	// 左树平衡 && 右树平衡 && 左树与右树深度差小于2
	bool Balance = left.isBalance && right.isBalance && abs(left.height - right.height) < 2;
	return BalanceReturnType(Balance, height);
}

// 返回两节点最低公共祖先
TreeNode* Text::LowestCommonAncester(TreeNode *head, TreeNode *o1, TreeNode *o2) {
	// 递归使用HashMap
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
	// 递归不使用HashMap
	// 1、分为两种情况：①o1或o2为最低公共祖先；②o1和o2上层为最低公共祖先
	if (head == NULL || head == o1 || head == o2) return head; // base
	TreeNode* left = LowestCommonAncester(head->left, o1, o2);
	TreeNode* right = LowestCommonAncester(head->right, o1, o2);
	if (left != NULL && right != NULL) {
		return head;
	}
	return left != NULL ? left : right;
}

// LowestCommonAncester递归函数
void Text::LCAprocess(TreeNode* head, unordered_map<TreeNode*, TreeNode*> fatherMap) {
	if (head->left == NULL && head->right == NULL) return; // base
	fatherMap[head->left] = head;
	fatherMap[head->right] = head;
	//fatherMap.insert(head->left, head); 使用insert会报错？？？
	//fatherMap.insert(head->right, head);
	LCAprocess(head->left, fatherMap);
	LCAprocess(head->right, fatherMap);
}