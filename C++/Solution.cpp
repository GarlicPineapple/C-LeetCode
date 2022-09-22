#include "stdafx.h"
#include "Solution.h"


int Solution::lengthOfLongestSubstring(string s) {
	// 滑动窗口
	int n = s.length(), ans = 0;
	int start = 0;
	unordered_map<char, int> map;
	for (int end = 0; end < n; end++) {
		if (map.count(s[end]) == 0) {
			map[s[end]] = end + 1;
			ans = max(end - start + 1, ans);
		}
		else {
			start = max(map[s[end]], start);
			map[s[end]] = end + 1;
			ans = max(end - start + 1, ans);
		}
	}
	return ans;
}

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	// O(m+n)
	int m = nums1.size();
	int n = nums2.size();
	int len = m + n;
	int left = -1, right = -1;
	int aStart = 0, bStart = 0;
	for (int i = 0; i < len / 2 + 1; i++) {
		left = right;
		if (aStart < m && (bStart >= n || nums1[aStart] < nums2[bStart])) {
			right = nums1[aStart++];
		}
		else {
			right = nums2[bStart++];
		}
	}
	if ((len & 1) == 0)
		return (left + right) / 2.0;
	else
		return right;
	
	// O(log(m+n))
}

string Solution::longestPalindrome(string s) {
	// 动态规划
	int n = s.size();
	if (n < 2) {
		return s;
	}
	int begine = 0, maxL = 1;
	// 存储子串位置
	vector<vector<int>> dp(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
	}
	// 子串回文判断
	for (int L = 2; L <= n; L++) {
		for (int i = 0; i < n; i++) {
			int j = i + L - 1;
			if (j >= n) {
				break;
			}
			if (s[i] != s[j]) {
				dp[i][j] = false;
			}
			else {
				if (j - i < 3) {
					dp[i][j] = true;
				}
				else {
					dp[i][j] = dp[i + 1][j - 1];
				}
			}
			if (dp[i][j] && j - i + 1 > maxL) {
				maxL = j - i + 1;
				begine = i;
			}
		}
	}
	return s.substr(begine, maxL);
}

int Solution::maxArea(vector<int>& height) {
	int left = 0, right = height.size() - 1;
	int maxS = 0;
	while (left != right && left < right) {
		maxS = max(maxS, min(height[left], height[right]) * (right - left));
		if (height[left] < height[right]) {
			left++;
		}
		else {
			right--;
		}
		/*// 优雅
		maxS = height[left] < height[right] ? max(maxS, (right - left) * height[left++]) : max(maxS, (right - left) * height[right--]);
		*/
	}
	return maxS;
}

void Solution::Mergesort(vector<int>& arr, int l, int r) {
	if (l == r) {
		return;
	}
	int mid = l + (r - l) / 2;
	Mergesort(arr, l, mid);
	Mergesort(arr, mid + 1, r);
	Merge(arr, l, mid, r);
}
void Solution::Merge(vector<int>& arr, int l, int mid, int r) {
	vector<int> help(r - l + 1);
	int p1 = l;
	int p2 = mid + 1;
	int i = 0;
	while (p1 <= mid && p2 <= r) {
		help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p2 <= r) {
		help[i++] = arr[p2++];
	}
	while (p1 <= mid) {
		help[i++] = arr[p1++];
	}
	for (int i = 0; i < r - l + 1; i++) {
		arr[l + i] = help[i];
	}
}

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
	vector<vector<int> > res;
	int n = nums.size();
	int p1, p2;
	Mergesort(nums, 0, n - 1);
	for (int i = 0; i < n - 2; i++) {
		if (nums[i] > 0) break;
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		p1 = i + 1;
		p2 = n - 1;
		while (p1 < p2) {
			int sum = nums[i] + nums[p1] + nums[p2];
			if (sum < 0) {
				while (p1 < p2 && nums[p1] == nums[++p1]);
			}
			else if (sum > 0) {
				while (p1 < p2 && nums[p2] == nums[--p2]);
			}
			else {
				res.push_back({nums[i], nums[p1], nums[p2]});
				while (p1 < p2 && nums[p1] == nums[++p1]);
				while (p1 < p2 && nums[p2] == nums[--p2]);
			}
		}
	}
	return res;
}

vector<string> Solution::letterCombinations(string digits) {
	vector<string> res;
	if (digits.empty()) {
		return res;
	}
	unordered_map<char, string> map{ {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
	string respart;
	letteradd(res, map, digits, 0, respart);
	return res;
}

void Solution::letteradd(vector<string>& res, const unordered_map<char, string> &map, const string& digits, int index, string& respart) {
	if (index == digits.length()) {
		res.push_back(respart);
	}
	else {
		char digit = digits[index];
		string add = map.at(digit);
		for (int i = 0; i < add.size(); i++) {
			respart.push_back(add[i]);
			letteradd(res, map, digits, index + 1, respart);
			respart.pop_back();
		}
	}
}

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
	/*// 普通
	if (head == NULL) {
		return head;
	}
	ListNode *p = head;
	int length = 1;
	while (p->next != NULL) {
		p = p->next;
		length++;
	}
	if (length == n) {
		head = head->next;
		return head;
	}
	length = length - n;
	p = head;
	for (int i = 0; i < length - 1; i++) {
		p = p->next;
	}
	ListNode *help = p->next;
	p->next = p->next->next;
	delete help;
	return head;*/
	// 快慢指针!!!!!!快指针比慢指针快n步
	if (head == NULL) {
		return head;
	}
	ListNode *dummy = new ListNode(0, head);
	ListNode *slow = dummy;
	ListNode *fast = head;
	
	while (n != 0) {
		fast = fast->next;
		n--;
	}
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	slow->next = slow->next->next;
	ListNode *ans = dummy->next;
	delete dummy;
	return ans;
}

bool Solution::isValid(string s) {
	int n = s.size();
	if (n % 2 != 0) {
		return false;
	}
	stack<char> parentheses;
	unordered_map<char, char> map = { {')','('}, { '}', '{'}, { ']', '['} };
	for (int i = 0; i < s.size(); i++) {
		if (map.count(s[i])) {
			if (parentheses.empty() || parentheses.top() != map[s[i]]) {
				return false;
			}
			parentheses.pop();
		}
		else {
			parentheses.push(s[i]);
		}
	}
	return parentheses.empty();
}

ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode *res = new ListNode();
	ListNode *head = res;
	while (list1 != NULL && list2 != NULL) {
		if (list1->val < list2->val) {
			res->next = list1;
			res = res->next;
			list1 = list1->next;
		}
		else {
			res->next = list2;
			res = res->next;
			list2 = list2->next;
		}
	}
	while (list1 != NULL) {
		res->next = list1;
		res = res->next;
		list1 = list1->next;
	}
	while (list2 != NULL) {
		res->next = list2;
		res = res->next;
		list2 = list2->next;
	}
	return head->next;
}

vector<string> Solution::generateParenthesis(int n) {
	if (n == 0) return {};
	if (n == 1) return { "()" };
	vector<vector<string>> dp(n + 1);
	dp[0] = { "" };
	dp[1] = { "()" };
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			for (string p : dp[j])
				for (string q : dp[i - j - 1]) {
					string str = "(" + p + ")" + q;
					dp[i].push_back(str);
				}
		}
	}
	return dp[n];
}

ListNode* Solution::mergeTwoLists23(ListNode *a, ListNode *b) {
	if ((!a) || (!b)) return a ? a : b;
	ListNode *head = new ListNode(), *tail = head, *aPtr = a, *bPtr = b;
	while (aPtr && bPtr) {
		if (aPtr->val < bPtr->val) {
			tail->next = aPtr;
			aPtr = aPtr->next;
		}
		else {
			tail->next = bPtr;
			bPtr = bPtr->next;
		}
		tail = tail->next;
	}
	tail->next = (aPtr ? aPtr : bPtr);
	return head->next;
}

ListNode* Solution::mergeLists(vector<ListNode*>& lists, int l, int r) {
	if (l == r) return lists[l];
	if (l > r) return NULL;
	int mid = l + (r - l) / 2;
	return mergeTwoLists(mergeLists(lists, l, mid), mergeLists(lists, mid + 1, r));
}

ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
	/* // 自己写的
	if (lists.empty()) {
		return NULL;
	}
	ListNode *res = lists[0];
	
	int n = lists.size();
	if (n == 1) {
		return res;
	}
	for (int i = 1; i < n; i++) {
		ListNode *ans = new ListNode();
		ListNode *head = ans;
		while (res != NULL && lists[i] != NULL) {
			if (res->val < lists[i]->val) {
				ans->next = res;
				ans = ans->next;
				res = res->next;
			}
			else {
				ans->next = lists[i];
				ans = ans->next;
				lists[i] = lists[i]->next;
			}
		}
		while (res != NULL) {
			ans->next = res;
			ans = ans->next;
			res = res->next;
		}
		while (lists[i] != NULL) {
			ans->next = lists[i];
			ans = ans->next;
			lists[i] = lists[i]->next;
		}
		res = head->next;
	}
	return res;*/
	return mergeLists(lists, 0, lists.size() - 1);
}

void Solution::nextPermutation(vector<int>& nums) {
	int n = nums.size();
	int a = -1, b = -1;
	for (int i = n - 1; i > 0; i--) {
		if (nums[i - 1] < nums[i]) {
			a = i - 1;
			break;
		}
	}
	if (a == -1) {
		bubble_sort(nums, 0, n - 1);
		return;
	}
	for (int i = n - 1; i > a; i--) {
		if (nums[i] > nums[a]) {
			b = i;
			break;
		}
	}
	int help = nums[a];
	nums[a] = nums[b];
	nums[b] = help;
	bubble_sort(nums, a + 1, n - 1);
	return;
}

void Solution::bubble_sort(vector<int>& arr, int l, int r) { 
	if (l == r) return;
	for (int i = l; i < r; i++) {
		for (int j = l; j < r - i + l; j++) {
			if (arr[j] > arr[j + 1]) {
				int change = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = change;
			}
		}
	}
}

int Solution::longestValidParentheses(string s) {
	/*// 栈
	if (s.empty()) return 0;
	int maxL = -1;
	stack<int> ans;
	ans.push(-1);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			ans.push(i);
		}
		else {
			ans.pop();
			if (ans.empty()) {
				ans.push(i);
			}
			else {
				maxL = max(maxL, (i - ans.top()));
			}
		}
	}
	return maxL;*/
	// 动态规划
	if (s.empty()) return 0;
	int maxL = 0;
	vector<int> dp(s.size(), 0);
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == ')') {
			if (s[i - 1] == '(') {
				dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
			}
			else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
				dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
			}
			maxL = max(maxL, dp[i]);
		}
	}
	return maxL;
	// 正反两遍遍历字符串：双指针
}

void Solution::search_33(vector<int>& nums, int l, int r, int& rotating) {
	if (l == r) return;
	int mid = l + (r - l) / 2;
	search_33(nums, l, mid, rotating);
	search_33(nums, mid + 1, r, rotating);
	if (rotating != 0) return;
	else {
		for (int i = l; i < r; i++) {
			if (nums[i] > nums[i + 1]) {
				rotating = i + 1;
			}
		}
	}
}

int Solution::search(vector<int>& nums, int target) {
	/*// 我奇怪的方法：先二分找旋转点，再判断
	if (nums.empty()) return -1;
	int rotating = 0;
	int index = -1;
	search_33(nums, 0, nums.size() - 1, rotating);
	if (rotating != 0) {
		if (target < nums[0]) {
			for (int i = rotating; i < nums.size(); i++) {
				if (target == nums[i]) {
					index = i;
					break;
				}
			}
		}
		else {
			for (int i = 0; i <= rotating; i++) {
				if (target == nums[i]) {
					index = i;
					break;
				}
			}
		}
	}
	else {
		for (int i = 0; i < nums.size(); i++) {
			if (target == nums[i]) {
				index = i;
				break;
			}
		}
	}
	return index;*/
	// 将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。
	//此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环.
	int n = nums.size();
	if (!n) return -1;
	if (n == 1) return nums[0] == target ? 0 : -1;
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] == target) return mid;
		if (nums[0] <= nums[mid]) {
			if (nums[0] <= target && target < nums[mid]) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		else {
			if (nums[mid] < target && target <= nums[n - 1]) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}

		}
	}
	return -1;
	
}

vector<int> Solution::searchRange(vector<int>& nums, int target) {
	vector<int> res = { -1, -1 };
	int n = nums.size();
	if (nums.empty() || nums[0] > target || nums[n - 1] < target) return res;
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] < target) l = mid + 1;
		else if (nums[mid] > target) r = mid - 1;
		else {
			if (nums[l] < target) l++;
			else if (nums[r] > target) r--;
			else break;
		}
	}
	if (l <= r) {
		res[0] = l;
		res[1] = r;
	}
	return res;
}

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target) {
	vector<int> combine;
	vector<vector<int> > ans;
	dfs(candidates, target, ans, combine, 0);
	return ans;
}

void Solution::dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int index)
{
	if (index == candidates.size()) return;
	if (target == 0) {
		ans.emplace_back(combine);
		return;
	}
	dfs(candidates, target, ans, combine, index + 1);
	if (target - candidates[index] >= 0) {
		combine.emplace_back(candidates[index]);
		dfs(candidates, target - candidates[index], ans, combine, index);
		combine.pop_back();
	}
}

int Solution::trap(vector<int>& height) {
	int ans = 0;

	return ans;
}

int Solution::findContentChildren(vector<int>& g, vector<int>& s){
	int children = 0, cookie = 0;
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	while (children < g.size() && cookie < s.size()){
		if (g[children] <= s[cookie]) children++;
		cookie++;
	}
	return  children;
}

int Solution::candy(vector<int>& ratings) {
	int size = ratings.size();
	if (size < 2) {
		return size;
	}
	vector<int> candy(size, 1);
	for (int i = 1; i < ratings.size(); i++) {
		if (ratings[i] > ratings[i - 1]) {
			candy[i] = candy[i - 1] + 1;
		}
	}
	for (int i = ratings.size() - 1; i > 0; i--) {
		if (ratings[i] < ratings[i - 1]) {
			candy[i - 1] = max(candy[i - 1], candy[i] + 1);
		}
	}
	return accumulate(candy.begin(),candy.end(),0);
}

int Solution::eraseOverlapIntervals(vector<vector<int>>& intervals) {
	int count = 0;
	//int size = intervals[0].size();
	//vector<int> inter(size, 1);
	//for (int i = 0; i < intervals[0].size; i++) {

	//}
	return count;
}
