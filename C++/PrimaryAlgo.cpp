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
