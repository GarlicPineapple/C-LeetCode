#include "stdafx.h"
#include "PrimaryAlgo.h"
int PrimaryAlgo::removeDuplicates(vector<int>& nums) {
	int n = nums.size();
	int l = 0, r = 0;
	while (r <= n) {
		if (nums[l] == nums[r]) {
			r++;
		}
		else {
			l++;
			int mid = nums[r];
			nums[r] = nums[l];
			nums[l] = mid;
			r++;
		}
	}
	return l + 1;
}

int PrimaryAlgo::maxProfit(vector<int>& prices) {
	/*// 动态规划
	if (prices.empty() || prices.size() < 2) return 0;
	int n = prices.size();
	vector<vector<int> > dp(n, vector<int>(2));
	dp[0][0] = 0;
	dp[0][1] = -prices[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
	}
	return dp[n - 1][0];*/
	// 贪心
	if (prices.empty() || prices.size() < 2) return 0;
	int n = prices.size(),max = 0;
	for (int i = 1; i < n; i++) {
		if (prices[i] > prices[i - 1]) max = max + (prices[i] - prices[i - 1]);
	}
	return max;
}

void PrimaryAlgo::rotate_subroutine(vector<int>& nums, int l, int r) {
	while (l <= r) {
		int mid = nums[l];
		nums[l] = nums[r];
		nums[r] = mid;
		l++;
		r--;
	}
}

void PrimaryAlgo::rotate(vector<int>& nums, int k) {
	if (nums.empty() || nums.size() < 2 || k == 0) return;
	int n = nums.size();
	// 1 拷贝
	/*// 2 多次反转
	k = k % n;
	rotate_subroutine(nums, 0, n - 1);
	rotate_subroutine(nums, 0, k - 1);
	rotate_subroutine(nums, k, n - 1);*/
	// 3 环形旋转
	int hold = nums[0];
	int index = 0;
	vector<bool> visitied(n, false);
	for (int i = 0; i < n; i++) {
		index = (index + k) % n;
		if (visitied[index] == false) {
			int temp = nums[index];
			nums[index] = hold;
			hold = temp;
			visitied[index] = true;
		}
		else {
			index = (index + 1) % n;
			hold = nums[index];
			i--;
		}
	}
}

bool PrimaryAlgo::containsDuplicate(vector<int>& nums) {
	/* // 暴力解超时
	containsDuplicate_bubble_sort(nums);
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == nums[i - 1]) return true;
	}
	return false;*/
	/*// 哈希
	unordered_set<int> map;
	for (int i = 0; i < nums.size(); i++) {
		map.insert(nums[i]);
		if (map.size() < i + 1) return true;
	}
	return false;*/
	sort(nums.begin(), nums.end());
	// unique将数组中相邻的重复元素去除
	return (unique(nums.begin(), nums.end()) != nums.end());
}

void PrimaryAlgo::containsDuplicate_bubble_sort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums.size() - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}

int PrimaryAlgo::singleNumber(vector<int>& nums) {
	/*unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++) {
		if (map.count(nums[i])) {
			map[nums[i]] = map[nums[i]] + 1;
		}
		else {
			map[nums[i]] = 1;
		}
	}
	for (pair<int, int> temp : map) {
		if (temp.second == 1) return temp.first;
	}
	return 0;*/
	if (nums.size() == 1) return nums[0];
	sort(nums.begin(), nums.end());
	if (nums[0] != nums[1]) return nums[0];
	if (nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1];
	for (int i = 1; i < nums.size() - 1; i++) {
		if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) return nums[i];
	}
	return 0;
}

vector<int> PrimaryAlgo::intersect(vector<int>& nums1, vector<int>& nums2) {
	// 1 排序对比
	vector<int> res;
	if (nums1.empty() || nums2.empty()) return res;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	int l = 0, r = 0;
	while (l < nums1.size() && r < nums2.size()) {
		if (nums1[l] == nums2[r]) {
			res.push_back(nums1[l]);
			l++;
			r++;
		}
		else if (nums1[l] < nums2[r]) {
			l++;
		}
		else if (nums1[l] > nums2[r]) {
			r++;
		}
	}
	return res;
	// 2 map
}

vector<int> PrimaryAlgo::plusOne(vector<int>& digits) {
	/* // 自己写的（原版）
	bool res = false;
	int n = digits.size() - 1;
 	while (!res) {
		if (digits[n] + 1 >= 10) {
			if (n == 0) {
				digits[n] = 0;
				digits.insert(digits.begin(), 1);
				res = true;
			}
			else {
				digits[n] = 0;
				n--;
				continue;
			}	
		}
		else {
			digits[n] = digits[n] + 1;
			res = true;
		}
	}
	return digits;*/
	// 自己写的（浅浅优化一下,内存消耗小了一丢丢）
	int n = digits.size() - 1;
	while (n > -1) {
		if (digits[n] == 9) {
			digits[n] = 0;
			n--;
			continue;
		}
		else {
			digits[n] = digits[n] + 1;
			return digits;
		}
	}
	digits.insert(digits.begin(), 1);
	return digits;
	/*// 只要有一个不是9就返回，效果居然比我自己写的还慢，内存消耗还大？？？啥原因
	for (int i = digits.size() - 1; i >= 0; i--) {
		if (digits[i] != 9) {
			digits[i]++;
			return digits;
		}
		else {
			digits[i] = 0;
		}
	}
	digits.insert(digits.begin(), 1);
	return digits;*/
}

void PrimaryAlgo::moveZeroes(vector<int>& nums) {
	/*// 0元素后移较好
	if (nums.empty() || nums.size() < 2) return;
	int index = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) {
			nums[index++] = nums[i];
		}
	}
	while (index < nums.size()) {
		nums[index++] = 0;
	}*/
	// 双指针
	if (nums.empty() || nums.size() < 2) return;
	int i = 0;
	for (int j = 0; j < nums.size(); j++) {
		if (nums[j] != 0) {
			int temp = nums[j];
			nums[j] = nums[i];
			nums[i] = temp;
			i++;
		}
	}
}

bool PrimaryAlgo::isValidSudoku(vector<vector<char>>& board) {
	// 位运算
	int line[9] = { 0 };
	int column[9] = { 0 };
	int cell[9] = { 0 };
	int shift = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '.') continue;
			shift = 1 << (board[i][j] - '0');
			int k = (i / 3) * 3 + j / 3;
			if ((line[j] & shift) > 0 || (column[i] & shift) > 0 || (cell[k] & shift) > 0) return false;
			line[j] = line[j] | shift;
			column[i] = column[i] | shift;
			cell[k] = cell[k] | shift;
		}
	}
	return true;
}

void PrimaryAlgo::rotate(vector<vector<int>>& matrix) {
	if (matrix.empty() || matrix.size() < 2) return;
	int n = matrix.size() - 1;
	for (int i = 0; i <= n / 2; i++) {
		for (int j = i; j < n - i; j++) {
			int temp = matrix[n - j][i];
			matrix[n - j][i] = matrix[n - i][n - j];
			matrix[n - i][n - j] = matrix[j][n - i];
			matrix[j][n - i] = matrix[i][j];
			matrix[i][j] = temp;
		}
	}
}

void PrimaryAlgo::reverseString(vector<char>& s) {
	int n = s.size();
	for (int i = 0; i < n / 2; i++) {
		int temp = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = temp;
	}
}
int PrimaryAlgo::reverse(int x) {
	int res = 0;
	while (x) {
		int t = x % 10;
		if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
		res = res * 10 + t;
		x /= 10;
	}
	return res;
}

int PrimaryAlgo::firstUniqChar(string s) {
	unordered_map<char, int> map;
	for (int i = 0; i < s.size(); i++) {
		if (map.count(s[i]) == 0) {
			map[s[i]] = 0;
		}
		else {
			map[s[i]]++;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (map[s[i]] == 0) return i;
	}
	return -1;
}

bool PrimaryAlgo::isAnagram(string s, string t) {
	// 自己写的
	if (s.size() != t.size()) return false;
	unordered_map<char, int> map;
	for (int i = 0; i < s.size(); i++) {
		if (map[s[i]]) {
			map[s[i]]++;
		}
		else {
			map[s[i]] = 1;
		}
	}
	for (int i = 0; i < t.size(); i++) {
		if (map[t[i]]) {
			map[t[i]]--;
			if (map[t[i]] == 0) {
				map.erase(t[i]);
			}
		}
		else return false;
	}
	if (map.empty()) return true;
	return false;
}

bool PrimaryAlgo::isPalindrome(string s) {
	regex reg("[^0-9a-zA-Z]");
	s = regex_replace(s, reg, "");
	if (s.empty() || s.size() == 1) return true;
	int l = 0, r = s.size() - 1;
	while (l <= r) {
		if (s[l] == s[r]) {
			l++;
			r--;
		}
		else return false;
	}
	return true;
}

int PrimaryAlgo::myAtoi(string s) {
	int res = 0;
	int i = 0;
	int flag = 1;
	while (s[i] == ' ') { // 第一个判断，判断是否为空格
		i++;
	}
	if (s[i] == '-') {    // 第二个判断，判断是否为负数
		flag = -1;  // 如果判断是负数，那么把flag赋值为-1。
	}
	if (s[i] == '+' || s[i] == '-') {  // 判断除开首位后是否还有字符+和——
		i++;
	}
	while (i < s.size() && isdigit(s[i])) { // 只有同时满足小于字符串长度，并且是十进制数字字符。则进入记录
		int r = s[i] - '0';  // 这一步 数字字符 减去 '0'字符对应的十进制，那么可以得到这个数字字符本身的数字值。这点下面会有涉及知识详解。
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) { // 此处判断是否超过2的31次方和2的负31次方-1. 即INT_MAX 和 INT_MIN
			return flag > 0 ? INT_MAX : INT_MIN;  // 判断正负，正则输出INT_MAX，负责输出INT_MIN
		}
		res = res * 10 + r;   // 一位一位的存储进来，从个位到十位，百位。以此类推，所以每次乘一个10；
		i++; // 向下一位读取字符
	}
	return flag > 0 ? res : -res;  // 通过前面读取的首尾判断出来的正负之后给flag的值，用到这里的三目运算。 正 则输出正数res，负 则输出负数res。
}

int PrimaryAlgo::strStr(string haystack, string needle) {
	int index = -1;
	int hlength = haystack.length(), nlength = needle.length();
	if (nlength > hlength) return index;
	for (int i = 0; i < hlength; i++) {
		if (haystack[i] == needle[0] && (hlength - i) >= nlength) {
			index = i;
			for (int j = 0; j < nlength; j++) {
				if (haystack[i] == needle[j] && j == nlength - 1) return index; // 若最后一个字符也匹配，则返回
				if (haystack[i] != needle[j]) {
					i = index; // 若字符不匹配，则从匹配的第一个字符的下一个继续遍历
					index = -1;
					break;
				}
				i++;
			}
		}
	}
	return index;
}

string PrimaryAlgo::countAndSay(int n) {
	//return countAndSay_recursive(n); // 递归
	// 官方
	string prev = "1";
	for (int i = 2; i <= n; ++i) {
		string curr = "";
		int start = 0;
		int pos = 0;

		while (pos < prev.size()) {
			while (pos < prev.size() && prev[pos] == prev[start]) {
				pos++;
			}
			curr += to_string(pos - start) + prev[start];
			start = pos;
		}
		prev = curr;
	}

	return prev;
}

string PrimaryAlgo::countAndSay_recursive(int n) {
	if (n == 1) return "1";
	string s = countAndSay_recursive(n - 1);
	string res;
	char temp = s[0];
	int count = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == temp) count++;
		else {
			res = res + to_string(count) + temp;
			temp = s[i];
			count = 1;
		}
	}
	res = res + to_string(count) + temp;
	return res;
}

string PrimaryAlgo::longestCommonPrefix(vector<string>& strs) {
	string res = "";
	for (int i = 0; i < strs[0].length(); i++) {
		for (int j = 0; j < strs.size(); j++) {
			if (strs[0][i] == strs[j][i] && j == strs.size() - 1) {
				res += strs[0][i];
			}
			else if (strs[0][i] != strs[j][i]) return res;
		}
	}
	return res;
}

void PrimaryAlgo::deleteNode(ListNode* node) {
	node->val = node->next->val;
	node->next = node->next->next;
}

ListNode* PrimaryAlgo::removeNthFromEnd(ListNode* head, int n) {
	/*// 双指针 - 一步
	if (head == NULL || (head->next == NULL && n == 1)) return NULL;
	ListNode *l = head;
	ListNode *r = head;
	int length = 1;
	while (r != NULL && r->next != NULL) {
		l = l->next;
		r = r->next->next;
		length += 2;
	}
	if (r == NULL) {
		length -= 1;
	}
	if ((length - n) >= length / 2) {
		length = length - n - length / 2 - 1;
		if (length == -1) return head->next;
		while (length) {
			l = l->next;
			length--;
		}
		l->next = l->next->next;
	}
	else {
		r = head;
		length = length - n - 1;
		while (length) {
			r = r->next;
			length--;
		}
		r->next = r->next->next;
	}
	return head;*/
	// 双指针 - n步
	if (head == NULL || (head->next == NULL && n == 1)) return NULL;
	ListNode *l = head;
	ListNode *r = head;
	for (int i = 0; i < n; i++) {
		r = r->next;
	}
	if (r == NULL) return head->next;
	while (r->next != NULL) {
		r = r->next;
		l = l->next;
	}
	l->next = l->next->next;
	return head;
}

ListNode* PrimaryAlgo::reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode* first = head;
	ListNode* second = head->next;
	ListNode* third = head->next->next;
	first->next = NULL;
	while (third != NULL) {
		second->next = first;
		first = second;
		second = third;
		third = third->next;
	}
	second->next = first;
	free(first);
	free(third);
	return second;
}

ListNode* PrimaryAlgo::mergeTwoLists(ListNode* list1, ListNode* list2) {
	if (list1 == NULL) return list2;
	else if (list2 == NULL) return list1;
	ListNode* list3 = new ListNode();
	ListNode* head = list3;
	while (list1 != NULL && list2 != NULL) {
		if (list1->val < list2->val) {
			list3->next = list1;
			list3 = list3->next;
			list1 = list1->next;
		}
		else {
			list3->next = list2;
			list3 = list3->next;
			list2 = list2->next;
		}
	}
	if (list1 != NULL) {
		list3->next = list1;
	}
	if (list2 != NULL) {
		list3->next = list2;
	}
	return head->next;
}

bool PrimaryAlgo::isPalindrome(ListNode* head) {
	if (head == NULL || head->next == NULL) return true;
	ListNode* slow = head;
	ListNode* fast = head;
	ListNode* temp = NULL;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	temp = slow->next;
	if (temp == fast && temp == NULL) {
		if (head->val == slow->val) return true;
		else return false;
	}
	fast = slow->next->next;
	slow->next = NULL;
	while (fast != NULL) {
		temp->next = slow;
		slow = temp;
		temp = fast;
		fast = fast->next;
	}
	temp->next = slow;
	slow = head;
	while (slow != NULL && temp != NULL) {
		if (slow->val != temp->val) return false;
		slow = slow->next;
		temp = temp->next;
	}
	return true;
}

bool PrimaryAlgo::hasCycle(ListNode *head) {
	if (head == NULL || head->next == NULL) return false;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) return true;
	}
	return false;
}

int PrimaryAlgo::maxDepth(TreeNode* root) {

}