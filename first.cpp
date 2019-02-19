 #include "libstd.h"

/* 1. Two Sum */
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     vector<int> vec;
//     map<int, int> ma;
//     map<int, int>::iterator iter;
//     for (int i = 0; i < (int)nums.size(); i++)
//     {
//         iter = ma.find(target - nums[i]);
//         if (iter == ma.end())
//         {
//             ma[nums[i]] = i;
//         }
//         else
//         {
//             vec.push_back(iter->second);
//             vec.push_back(i);
//             break;
//         }
//     }
//     return vec;
// }

// int main()
// {
//     int num[] = {2, 7, 11, 15};
//     vector<int> numbers(num, num + 4);
//     int target = 9;
//     vector<int> result = twoSum(numbers, target);
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << endl;
//     }
//     system("pause");
//     return 0;
// }

/* 2. Add Two Numbers */
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//{
//	ListNode* resList = new ListNode(0);
//	ListNode* p = resList;
//	int flag = 0;
//	while (l1 != NULL && l2 != NULL)
//	{
//		int sum = l1->val + l2->val + flag;
//		flag = 0;
//		if (sum > 9)
//		{
//			flag = 1;
//			sum -= 10;
//		}
//		p->next = new ListNode(sum);
//		p = p->next;
//		l1 = l1->next;
//		l2 = l2->next;
//	}
//	while (l1 != NULL)
//	{
//		int sum = l1->val + flag;
//		flag = 0;
//		if (sum > 9)
//		{
//			flag = 1;
//			sum -= 10;
//		}
//		p->next = new ListNode(sum);
//		p = p->next;
//		l1 = l1->next;
//	}
//	while (l2 != NULL)
//	{
//		int sum = l2->val + flag;
//		flag = 0;
//		if (sum > 9)
//		{
//			flag = 1;
//			sum -= 10;
//		}
//		p->next = new ListNode(sum);
//		p = p->next;
//		l2 = l2->next;
//	}
//	if (flag != 0)
//	{
//		p->next = new ListNode(1);
//		p = p->next;
//	}
//	return resList->next == NULL ? resList : resList->next;
//}
//
//int main()
//{
//	ListNode *list1, *list2;
//	//list1 = new ListNode(2);
//	//list1->next = new ListNode(4);
//	//list1->next->next = new ListNode(3);
//	//list2 = new ListNode(5);
//	//list2->next = new ListNode(6);
//	//list2->next->next = new ListNode(4);
//	list1 = new ListNode(5);
//	list2 = new ListNode(5);
//
//	ListNode *newList = addTwoNumbers(list1, list2);
//	int sum = 0;
//	while (newList != NULL)
//	{
//		cout << newList->val;
//		newList = newList->next;
//	}
//
//	delete newList;
//	delete list1;
//	delete list2;
//
//	system("pause");
//	return 0;
//}

/* 3. Longest Substring Without Repeating Characters */
//int lengthOfLongestSubstring(string s)
//{
//	map<int, int> ma;
//	int left = -1, res = 0;
//	int nLen = (int)s.length();
//	for (int i = 0; i < nLen; i++)
//	{
//		if (ma.count(s[i]) && ma[s[i]] > left)
//		{
//			left = ma[s[i]];
//		}
//		ma[s[i]] = i;
//		res = max(res, i - left);
//	}
//	return res;
//}
//
//int main()
//{
//	string str = "pwwkewrerer";
//	cout << lengthOfLongestSubstring(str) << endl;
//	system("pause");
//	return 0;
//}

/* 4. Median of Two Sorted Arrays */
//int auxFindMedian(vector<int>& nums1, int i, vector<int>& nums2, int j, int pos)
//{
//	if (i >= nums1.size())
//		return nums2[j + pos - 1];
//	if (j >= nums2.size())
//		return nums1[i + pos - 1];
//	if (pos == 1)
//		return min(nums1[i], nums2[j]);
//	int midLeft  = (i + pos / 2 - 1 < nums1.size()) ? nums1[i + pos / 2 - 1] : INT_MAX;
//	int midRight = (j + pos / 2 - 1 < nums2.size()) ? nums2[j + pos / 2 - 1] : INT_MAX;
//	if (midLeft > midRight)
//	{
//		return auxFindMedian(nums1, i, nums2, j + pos / 2, pos - pos / 2);
//	}
//	else
//	{
//		return auxFindMedian(nums1, i + pos / 2, nums2, j, pos - pos / 2);
//	}
//}
//
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
//{
//	int m = nums1.size();
//	int n = nums2.size();
//	int left = (m + n + 1) / 2;
//	int right = (m + n + 2) / 2;
//	return (auxFindMedian(nums1, 0, nums2, 0, left) + auxFindMedian(nums1, 0, nums2, 0, right)) / 2.0;
//}
//
//int main()
//{
//	vector<int> nums1{ 1,2 };
//	vector<int> nums2{ 3,4 };
//	cout << findMedianSortedArrays(nums1, nums2) << endl;
//	system("pause");
//	return 0;
//}

/*5. Longest Palindromic Substring */
//string longestPalindrome(string s)
//{
//	string res;
//	int nMax = 0;
//	int nLen = s.length();
//	if (nLen < 2)
//		return s;
//	for (int i = 0; i < nLen-1; i++)
//	{
//		int jl = i, jr = i;
//		while (jl >= 0 && jr < nLen && s[jl] == s[jr])
//		{
//			--jl;
//			++jr;
//		}
//		++jl; --jr;
//		if (nMax < jr - jl + 1)
//		{
//			nMax = jr - jl + 1;
//			res = s.substr(jl, nMax);
//		}
//		if (s[i] == s[i + 1])
//		{
//			jl = i, jr = i + 1;
//			while (jl >= 0 && jr < nLen && s[jl] == s[jr])
//			{
//				--jl;
//				++jr;
//			}
//			++jl; --jr;
//			if (nMax < jr - jl + 1)
//			{
//				nMax = jr - jl + 1;
//				res = s.substr(jl, nMax);
//			}
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	string strs[3] = { "s", "babad", "cbbd" };
//	for (auto &it : strs)
//		cout << longestPalindrome(it) << endl;
//	system("pause");
//	return 0;
//}

/* 7. Reverse Integer */
//int reverse(int x)
//{
//	long long res = 0;
//	while (x)
//	{
//		res = res * 10 + x % 10;
//		x /= 10;
//	}
//	return (res > INT_MAX || res < INT_MIN) ? 0 : res;
//}
//
//int main()
//{
//	cout << reverse(-120) << endl;
//	system("pause");
//	return 0;
//}

/*8. String to Integer (atoi) */
//int myAtoi(string str)
//{
//	if (str == "")
//		return 0;
//	int i = 0;
//	while (str[i] == '\0' || str[i] == ' ')
//	{
//		++i;
//	}
//	int flag = 1;
//	if (str[i] == '-')
//	{
//		flag = -1;
//		++i;
//	}
//	else if (str[i] == '+')
//	{
//		++i;
//	}
//	long long res = 0;
//	while (i < str.length())
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			res = res * 10 + str[i] - '0';
//			if (res > INT_MAX)
//			{
//				if (flag == 1)
//					return INT_MAX;
//				else
//					return INT_MIN;
//			}
//			++i;
//		}
//		else
//			break;
//	}
//	return (int)(flag * res);
//}
//
//int main()
//{
//	string strs[5] = { "42", "   -42", "4193 with words", "words and 987", "-91283472332" };
//	for (int i = 0; i < 5; i++)
//	{
//		cout << myAtoi(strs[i]) << endl;
//	}
//	system("pause");
//	return 0;
//}

/* 9. Palindrome Number */
//bool isPalindrome(int x)
//{
//	if (x < 0 || (x % 10 == 0 && x != 0))
//		return false;
//	int reverse = 0;
//	while (x > reverse)
//	{
//		reverse = reverse * 10 + x % 10;
//		x /= 10;
//	}
//	return reverse == x || reverse / 10 == x;
//}
//
//int main()
//{
//	int num = 1221;
//	if (isPalindrome(num))
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//	system("pause");
//	return 0;
//}

/*10. Regular Expression Matching */
//bool isMatch(string s, string p)
//{
//	if (p.empty())
//		return s.empty();
//	if (p.size() == 1)
//		return (s.size() == 1 && (s == p || p[0] == '.'));
//	if (p[1] != '*')
//	{
//		if (s.empty())
//			return false;
//		return ((s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)));
//	}
//	while (!s.empty() && (s[0] == p[0] || p[0] == '.'))
//	{
//		if (isMatch(s, p.substr(2)))
//			return true;
//		s = s.substr(1);
//	}
//	return isMatch(s, p.substr(2));
//}
//
//int main()
//{
//	string ss[5] = { "aa", "aa", "ab", "aab", "mississippi" };
//	string ps[5] = { "a", "a*", ".*", "c*a*b", "mis*is*p*." };
//	for (int i = 0; i < 5; i++)
//	{
//		cout << isMatch(ss[i], ps[i]) << endl;
//	}
//	system("pause");
//	return 0;
//}

/*11. Container With Most Water */
//int maxArea(vector<int>& vheight)
//{
//	int res = 0;
//	int nl = 0;
//	int nr = vheight.size() - 1;
//	while (nl < nr)
//	{
//		int height = min(vheight.at(nl), vheight.at(nr));
//		int contain = height * (nr - nl);
//		if (contain > res)
//			res = contain;
//		if (vheight.at(nl) > vheight.at(nr))
//			--nr;
//		else
//			++nl;
//	}
//	return res;
//}
//
//int main()
//{
//	vector<int> vec{ 1,8,6,2,5,4,8,3,7 };
//	cout << maxArea(vec) << endl;
//	system("pause");
//	return 0;
//}

/*12. Integer to Roman */
//string intToRoman(int num)
//{
//	string ROMAN[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
//	int nums[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
//	int tmp;
//	string res;
//	for (int i = 0; i < 13; i++)
//	{
//		tmp = num / nums[i];
//		while (tmp)
//		{
//			res += ROMAN[i];
//			tmp--;
//		}
//		num = num % nums[i];
//	}
//	return res;
//}
//
//int main()
//{
//	int nn[5] = { 3,4,9,58,1994 };
//	for (int i = 0; i < 5; ++i)
//	{
//		cout << intToRoman(nn[i]) << endl;
//	}
//	system("pause");
//	return 0;
//}

/*13. Roman to Integer*/
//int romanToInt(string s)
//{
//	map<char, int> ma{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
//	int Len = s.length();
//	int res = 0;
//	for (int i = 0; i < Len; i++)
//	{
//		if (i == Len - 1 || ma[s[i + 1]] <= ma[s[i]])
//			res += ma[s[i]];
//		else
//			res -= ma[s[i]];
//	}
//	return res;
//}
//
//int main()
//{
//	string str[2] = {"LVIII" , "MCMXCIV" };
//	for (int i = 0; i < 2; i++)
//		cout << romanToInt(str[i]) << endl;
//
//	system("pause");
//	return 0;
//}

/*14. Longest Common Prefix */
//string longestCommonPrefix(vector<string>& strs)
//{
//	if (0 == strs.size())
//		return "";
//	int nMaxLen = INT_MAX;
//	string res;
//	for (auto &it : strs)
//	{
//		if (nMaxLen > it.length())
//			nMaxLen = it.length();
//	}
//	if (0 == nMaxLen)
//		return "";
//	bool flag = true;
//	for (int i = 0; i < nMaxLen; i++)
//	{
//		for (auto &it : strs)
//		{
//			if (it[i] != strs[0][i])
//			{
//				flag = false;
//				break;
//			}
//		}
//		if (!flag)
//			break;
//		res += strs[0][i];
//	}
//	return res;
//}
//
//int main()
//{
//	vector<string> vec/*{ "flower","flow","flight" }*/;
//	cout << longestCommonPrefix(vec) << endl;
//	system("pause");
//	return 0;
//}

/*15. 3Sum */
//vector<vector<int>> threeSum(vector<int>& nums)
//{
//	vector<vector<int> > res;
//	if ((int)nums.size() < 3)
//		return res;
//	sort(nums.begin(), nums.end());
//	int sum, nFront, nLast, nLen = (int)nums.size();
//	for (int i=0; i< nLen-2; i++)
//	{
//		while (i > 0 && i < nLen - 2 && nums[i] == nums[i - 1])
//			++i;
//		sum = nums[i];
//		nFront = i + 1;
//		nLast = nLen - 1;
//		while (nFront < nLast)
//		{
//			if (sum + nums[nFront] + nums[nLast] == 0)
//			{
//				res.push_back(vector<int>{sum, nums[nFront], nums[nLast]});
//				++nFront;
//				while (nFront < nLast && nums[nFront] == nums[nFront - 1])
//					++nFront;
//			}
//			else if (sum + nums[nFront] + nums[nLast] > 0)
//			{
//				--nLast;
//				while (nFront < nLast && nums[nLast] == nums[nLast + 1])
//					--nLast;
//			}
//			else
//			{
//				++nFront;
//				while (nFront < nLast && nums[nFront] == nums[nFront - 1])
//					++nFront;
//			}
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	vector<int> vec{ -1, 0, 1, 2, -1, -4 };
//	vector<vector<int> > res = threeSum(vec);
//	for (int i = 0; i < (int)res.size(); ++i)
//	{
//		for (int j = 0; j < (int)res[i].size(); ++j)
//		{
//			cout << res[i][j] << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*17. Letter Combinations of a Phone Number */
//void auxSearch(vector<string> &res, string &digits, int cur, string strT, int nSize, string *strs)
//{
//	if (cur == nSize)
//	{
//		res.push_back(strT);
//		return;
//	}
//	for (int i = 0; i < strs[digits[cur] - '0'].size(); i++)
//	{
//		strT += strs[digits[cur] - '0'][i];
//		auxSearch(res, digits, cur+1, strT, nSize, strs);
//		strT.pop_back();
//	}
//}
//
//vector<string> letterCombinations(string digits)
//{
//	vector<string> res;
//	string tmp;
//	if (digits == "")
//		return res;
//	string strs[10] = {"","" ,"abc" ,"def",
//						"ghi", "jkl", "mno",
//						"pqrs", "tuv", "wxyz"};
//	int nSize = digits.length();
//	auxSearch(res, digits, 0, tmp, nSize, strs);
//	return res;
//}
//
//int main()
//{
//	string str = "23";
//	vector<string> res = letterCombinations(str);
//	for (auto &it : res)
//		cout << it << endl;
//	system("pause");
//	return 0;
//}

/*19. Remove Nth Node From End of List */
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//ListNode* removeNthFromEnd(ListNode* head, int n)
//{
//	if (head == nullptr)
//		return head;
//	ListNode* pre = head;
//	ListNode* cur = head;
//	for (int i = 0; i < n; i++)
//		cur = cur->next;
//	if (cur == nullptr)
//		return head->next;
//	while (cur->next)
//	{
//		pre = pre->next;
//		cur = cur->next;
//	}
//	pre->next = pre->next->next;
//	return head;
//}
//
//int main()
//{
//	ListNode *root = new ListNode(1);
//	root->next = new ListNode(2);
//	root->next->next = new ListNode(3);
//	root->next->next->next = new ListNode(4);
//	root->next->next->next->next = new ListNode(5);
//	ListNode *after = removeNthFromEnd(root, 2);
//	while (after)
//	{
//		cout << after->val << " -> ";
//		after = after->next;
//	}
//	system("pause");
//	return 0;
//}

/*20. Valid Parentheses */
//bool isValid(string s)
//{
//	map<char, char> ma{ {')', '('}, {'}', '{'}, {']', '['} };
//	stack<char> sta;
//	int len = s.length();
//	for (int i = 0; i < len; ++i)
//	{
//		switch (s[i])
//		{
//		case ')':
//			if (sta.empty() || sta.top() != ma[s[i]])
//				 return false;
//			else
//				sta.pop();
//			break;
//		case '}':
//			if (sta.empty() || sta.top() != ma[s[i]])
//				return false;
//			else
//				sta.pop();
//			break;
//		case ']':
//			if (sta.empty() || sta.top() != ma[s[i]])
//				return false;
//			else
//				sta.pop();
//			break;
//		default:
//			sta.push(s[i]);
//		}
//	}
//	return sta.empty();
//}
//
//int main()
//{
//	string strs[3] = { "()", "()[]{}", "(]" };
//	for (int i = 0; i < 3; i++)
//		cout << isValid(strs[i]) << endl;
//	system("pause");
//	return 0;
//}

/*21. Merge Two Sorted Lists */
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
//{
//	if (l1 == NULL)
//		return l2;
//	if (l2 == NULL)
//		return l1;
//	int init;
//	if (l1->val < l2->val)
//	{
//		init = l1->val;
//		l1 = l1->next;
//	}
//	else
//	{
//		init = l2->val;
//		l2 = l2->next;
//	}
//	ListNode* answer = new ListNode(init);
//	ListNode* res = answer;
//	while (l1 && l2)
//	{
//		if (l1->val < l2->val)
//		{
//			res->next = new ListNode(l1->val);
//			l1 = l1->next;
//			res = res->next;
//		}
//		else
//		{
//			res->next = new ListNode(l2->val);
//			l2 = l2->next;
//			res = res->next;
//		}
//	}
//	while (l1)
//	{
//		res->next = new ListNode(l1->val);
//		l1 = l1->next;
//		res = res->next;
//	}
//	while (l2)
//	{
//		res->next = new ListNode(l2->val);
//		l2 = l2->next;
//		res = res->next;
//	}
//	return answer;
//}
//
//int main()
//{
//	ListNode* str1 = new ListNode(1);
//	str1->next = new ListNode(2);
//	str1->next->next = new ListNode(4);
//	ListNode* str2 = new ListNode(1);
//	str2->next = new ListNode(3);
//	str2->next->next = new ListNode(4);
//	ListNode* res = mergeTwoLists(str1, str2);
//	while (res)
//	{
//		cout << res->val << " ";
//		res = res->next;
//	}
//	system("pause");
//	return 0;
//}

/*22. Generate Parentheses */
//void recurParenthesis(vector<string> &res, string &curStr, int &n, int length, int left, int right)
//{
//	if (length == 2 * n)
//	{
//		res.push_back(curStr);
//		return;
//	}
//	if (left < n)
//	{
//		curStr += '(';
//		recurParenthesis(res, curStr, n, length+1, left+1, right);
//		curStr = curStr.substr(0, curStr.length() - 1);
//	}
//	if (right < left)
//	{
//		curStr += ')';
//		recurParenthesis(res, curStr, n, length + 1, left, right + 1);
//		curStr = curStr.substr(0, curStr.length() - 1);
//	}
//}
//
//vector<string> generateParenthesis(int n)
//{
//	vector<string> res;
//	string curStr;
//	int length = 0, left = 0, right = 0;
//	if (n > 0)
//	{
//		recurParenthesis(res, curStr, n, length, left, right);
//	}
//	return res;
//}
//
//int main()
//{
//	vector<string> res = generateParenthesis(3);
//	for (auto &it : res)
//		cout << it << endl;
//	system("pause");
//	return 0;
//}

/*23. Merge k Sorted Lists */
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//struct cmp
//{
//	bool operator ()(const ListNode* A, const ListNode* B)
//	{
//		return A->val > B->val;
//	}
//};
//
//ListNode* mergeKLists(vector<ListNode*>& lists)
//{
//	priority_queue < ListNode*, vector< ListNode*>, cmp> que;
//	for (auto &it : lists)
//	{
//		if (it)
//		{
//			que.push(it);
//		}
//	}
//	if (que.empty())
//	{
//		return nullptr;
//	}
//	ListNode* res = que.top();
//	que.pop();
//	if (res->next != nullptr)
//	{
//		que.push(res->next);
//	}
//	ListNode* tail = res;
//	while (!que.empty())
//	{
//		tail->next = que.top();
//		que.pop();
//		tail = tail->next;
//		if (tail->next != nullptr)
//		{
//			que.push(tail->next);
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	vector<ListNode*> total;
//	ListNode* listNd1 = new ListNode(1);
//	listNd1->next = new ListNode(4);
//	listNd1->next->next = new ListNode(5);
//	total.push_back(listNd1);
//	ListNode* listNd2 = new ListNode(1);
//	listNd2->next = new ListNode(3);
//	listNd2->next->next = new ListNode(4);
//	total.push_back(listNd2);
//	ListNode* listNd3 = new ListNode(2);
//	listNd3->next = new ListNode(6);
//	total.push_back(listNd3);
//
//	ListNode *res = mergeKLists(total);
//	while (res != nullptr)
//	{
//		cout << res->val;
//		res = res->next;
//	}
//	system("pause");
//	return 0;
//}

/*24. Swap Nodes in Pairs */
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//ListNode* swapPairs(ListNode* head)
//{
//	if (head == nullptr)
//		return nullptr;
//	ListNode *res = new ListNode(-1);
//	ListNode *tail = res;
//	tail->next = head;
//	while (tail->next != nullptr && tail->next->next != nullptr)
//	{
//		ListNode *tmp = tail->next->next;
//		tail->next->next = tmp->next;
//		tmp->next = tail->next;
//		tail->next = tmp;
//		tail = tail->next->next;
//	}
//	return res->next;
//}
//
//int main()
//{
//	ListNode *listN = new ListNode(1);
//	listN->next = new ListNode(2);
//	listN->next->next = new ListNode(3);
//	listN->next->next->next = new ListNode(4);
//	ListNode *res = swapPairs(listN);
//	while (res)
//	{
//		cout << res->val << endl;
//		res = res->next;
//	}
//	system("pause");
//	return 0;
//}

/*26. Remove Duplicates from Sorted Array */
//int removeDuplicates(vector<int>& nums)
//{
//	if (nums.empty())
//		return 0;
//	int i = 0, j = 0;
//	for (;j < nums.size(); )
//	{
//		if (nums[i] != nums[j])
//			nums[++i] = nums[j++];
//		else
//			++j;
//	}
//	return i + 1;
//}
//
//int main()
//{
//	vector<int> vec{ 1,2,3 };
//	cout << removeDuplicates(vec) << endl;
//	system("pause");
//	return 0;
//}

/*27. Remove Element */
//int removeElement(vector<int>& nums, int val)
//{
//	int i = 0, j = nums.size();
//	while (i < j)
//	{
//		if (nums[i] == val)
//		{
//			nums[i] = nums[--j];
//		}
//		else
//		{
//			++i;
//		}
//	}
//	return j;
//}
//
//int main()
//{
//	vector<int> vec{ 3,2,2,3 };
//	cout << removeElement(vec, 2);
//	system("pause");
//	return 0;
//}

/*28. Implement strStr() */
//int strStr(string haystack, string needle)
//{
//	if (haystack == "" && needle != "")
//		return -1;
//	if (needle == "")
//		return 0;
//	int nLen = haystack.length() - needle.length();
//	for (int i = 0; i <= nLen; ++i)
//	{
//		if (haystack[i] == needle[0])
//		{
//			int k = i + 1;
//			bool flag = true;
//			for (int j = 1; j < needle.length(); ++j)
//			{
//				if (haystack[k++] != needle[j])
//				{
//					flag = false;
//					break;
//				}
//			}
//			if (flag)
//				return i;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	string haystack = "mississippi", needle = "issip";
//	cout << strStr(haystack, needle) << endl;
//	system("pause");
//	return 0;
//}

/*29. Divide Two Integers */
//int divide(int dividend, int divisor)
//{
//	long long res = 0, m = abs((long long)dividend), n = abs((long long)divisor);
//	int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
//	while (m >= n)
//	{
//		long long k = n, f = 1;
//		while ((k << 1) < m)
//		{
//			k = k << 1;
//			f = f << 1;
//		}
//		m -= k;
//		res += f;
//	}
//	if (sign == -1)
//		res *= -1;
//	if (res < INT_MIN)
//		return INT_MIN;
//	else if (res > INT_MAX)
//		return INT_MAX;
//	else
//		return res;
//}
//
//int main()
//{
//	cout << divide(-2147483647,-1) << endl;
//	system("pause");
//	return 0;
//}

/*33. Search in Rotated Sorted Array */
//int search(vector<int>& nums, int target)
//{
//	int nl = 0, nr = nums.size() - 1;
//	while (nl <= nr)
//	{
//		int nm = nl + (nr - nl) / 2;
//		if (target == nums[nm])
//			return nm;
//		else if (nums[nl] <= nums[nm])
//		{
//			if (nums[nm] >= target && nums[nl] <= target)
//				nr = nm - 1;
//			else
//				nl = nm + 1;
//		}
//		else
//		{
//			if (nums[nm] <= target && nums[nr] >= target)
//				nl = nm + 1;
//			else
//				nr = nm - 1;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	vector<int> vec{ 3,1 };
//	cout << search(vec, 1) << endl;
//	system("pause");
//	return 0;
//}

/*34. Find First and Last Position of Element in Sorted Array */
//vector<int> searchRange(vector<int>& nums, int target)
//{
//	vector<int> res{ -1, -1 };
//	if (nums.empty())
//		return res;
//	int nl = 0, nr = nums.size() - 1;
//	while (nl <= nr)
//	{
//		int nmid = nl + (nr - nl) / 2;
//		if (nums[nmid] > target)
//			nr = nmid - 1;
//		else if (nums[nmid] < target)
//			nl = nmid + 1;
//		else
//		{
//			nl = nr = nmid;
//			while ((nl - 1)>=0 && nums[nl - 1] == target)
//				--nl;
//			while ((nr + 1) < nums.size() && nums[nr + 1] == target)
//				++nr;
//			break;
//		}
//	}
//	if (nl < nums.size() && 0<=nr && nums[nl] == target)
//	{
//		res[0] = nl;
//		res[1] = nr;
//	}
//	return res;
//}
//
//int main()
//{
//	vector<int> vec{ -1};
//	vector<int> res = searchRange(vec, 2);
//	for (auto &it : res)
//		cout << it << "  ";
//	system("pause");
//	return 0;
//}

/*36. Valid Sudoku */
//bool isValidSudoku(vector<vector<char>>& board)
//{
//	if (board.empty())
//		return false;
//	set<char> rows[9];
//	set<char> cols[9];
//	set<char> subs[9];
//	int nrow = board.size(), ncol = board.at(0).size();
//	for (int i = 0; i < nrow; ++i)
//	{
//		for (int j = 0; j < ncol; ++j)
//		{
//			if (board[i][j] != '.')
//			{
//				int nind = i / 3 * 3 + j / 3;
//				if (rows[i].count(board[i][j]) || cols[j].count(board[i][j]) || subs[nind].count(board[i][j]))
//					return false;
//				else
//				{
//					rows[i].insert(board[i][j]);
//					cols[j].insert(board[i][j]);
//					subs[nind].insert(board[i][j]);
//				}
//			}
//		}
//	}
//	return true;
//}

/*38. Count and Say */
//string countAndSay(int n)
//{
//	string res = "1";
//	while (--n > 0)
//	{
//		int cnt = 1;
//		string tmp = "";
//		for (int i = 1; i < res.length(); ++i)
//		{
//			if (res[i] == res[i - 1])
//			{
//				cnt++;
//			}
//			else
//			{
//				tmp += '0' + cnt;
//				tmp += res[i - 1];
//				cnt = 1;
//			}
//		}
//		tmp += '0' + cnt;
//		tmp += res[res.size()-1];
//		res = tmp;
//	}
//	return res;
//}
//
//int main()
//{
//	cout << countAndSay(4) << endl;
//	system("pause");
//	return 0;
//}

/*41. First Missing Positive */
//int firstMissingPositive(vector<int>& nums)
//{
//	if (nums.empty())
//		return 1;
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		if (nums[i] > 0)
//		{
//			while (nums[i] > 0 && nums[i] < i + 1 && nums[i] != nums[nums[i] - 1])
//			{
//				swap(nums[i], nums[nums[i] - 1]);
//			}
//		}
//	}
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		if (nums[i] != i + 1)
//			return i + 1;
//	}
//	return nums.size() + 1;
//}
//
//int main()
//{
//	vector<int> vec{ 3,4,-1,1 };
//	cout << firstMissingPositive(vec) << endl;
//	system("pause");
//	return 0;
//}

/*42. Trapping Rain Water */
//int trap(vector<int>& height)
//{
//	if (height.size() < 3)
//		return 0;
//	int maxH = -1, index=0, area = 0;
//	for (int i = 0; i < height.size(); ++i)
//	{
//		if (height[i] > maxH)
//		{
//			maxH = height[i];
//			index = i;
//		}
//	}
//	int nH = height[0];
//	for (int i = 1; i < index; i++)
//	{
//		if (height[i] > nH)
//			nH = height[i];
//		else
//			area += (nH - height[i]);
//	}
//	nH = height[height.size() - 1];
//	for (int i = height.size() - 2; i > index; --i)
//	{
//		if (height[i] > nH)
//			nH = height[i];
//		else
//			area += (nH - height[i]);
//	}
//	return area;
//}
//
//int main()
//{
//	vector<int> vec{ 0,1,0,2,1,0,1,3,2,1,2,1 };
//	cout << trap(vec) << endl;
//	system("pause");
//	return 0;
//}

/*46. Permutations */
//void recursion(vector<vector<int>> &res, vector<int>& nums, int cur)
//{
//	if (cur == nums.size() - 1)
//	{
//		res.push_back(nums);
//		return;
//	}
//	for (int i = cur; i < nums.size(); ++i)
//	{
//		swap(nums[i], nums[cur]);
//		recursion(res, nums, cur + 1);
//		swap(nums[i], nums[cur]);
//	}
//}
//
//vector<vector<int>> permute(vector<int>& nums)
//{
//	vector<vector<int>> res;
//	recursion(res, nums, 0);
//	return res;
//}
//
//int main()
//{
//	vector<int> vec{ 1,2,3 };
//	vector<vector<int>> res = permute(vec);
//	for (auto &it : res)
//	{
//		for (auto &iter : it)
//		{
//			cout << iter << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*48. Rotate Image */
//void rotate(vector<vector<int>>& matrix)
//{
//	vector<vector<int> > tmp = matrix;
//	for (int i = 0; i < matrix.size(); ++i)
//	{
//		for (int j = 0; j < matrix[i].size(); ++j)
//		{
//			tmp[j][matrix[i].size()-i-1] = matrix[i][j];
//		}
//	}
//	for (int i = 0; i < matrix.size(); ++i)
//	{
//		for (int j = 0; j < matrix[i].size(); ++j)
//		{
//			matrix[i][j] = tmp[i][j];
//		}
//	}
//}
//
//int main()
//{
//	vector<vector<int> > vec{ {1,2,3}, {4,5,6}, {7,8,9} };
//	rotate(vec);
//	for (auto &it : vec)
//	{
//		for (auto &iter : it)
//			cout << iter << " ";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*49. Group Anagrams */
//vector<vector<string>> groupAnagrams(vector<string>& strs)
//{
//	vector<vector<string> > res;
//	map<string, multiset<string> > ma;
//	for (auto &it : strs)
//	{
//		string sortstr = it;
//		sort(sortstr.begin(), sortstr.end());
//		ma[sortstr].insert(it);
//	}
//	for (auto &it : ma)
//	{
//		vector<string> tmp;
//		for (auto &iter : it.second)
//		{
//			tmp.push_back(iter);
//		}
//		res.push_back(tmp);
//	}
//	return res;
//}
//
//int main()
//{
//	vector<string> vec{ "eat", "tea", "tan", "ate", "nat", "bat" };
//	vector<vector<string> > res = groupAnagrams(vec);
//	for (auto &it : res)
//	{
//		for (auto &iter : it)
//		{
//			cout << iter << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*50. Pow(x, n) */
//double auxPower(double x, int n)
//{
//	if (0 == n)
//		return 1;
//	double ans = auxPower(x, n / 2);
//	if (n % 2 == 1)
//		return ans * ans * x;
//	else
//		return ans * ans;
//}
//
//double myPow(double x, int n)
//{
//	if (n < 0)
//		return 1.0 / auxPower(x, -n);
//	else
//		return auxPower(x, n);
//}
//
//int main()
//{
//	vector<int> vec{ -3,-2,0,-1 };
//	cout << maxSubArray(vec) << endl;
//	cout << myPow(2.00000, -2147483648) << endl;
//	system("pause");
//	return 0;
//}

/*53. Maximum Subarray */
//int maxSubArray(vector<int>& nums)
//{
//	int res = nums[0], tmp = 0;
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		tmp += nums[i];
//		if (tmp > res)
//		{
//			res = tmp;
//		}
//		if (tmp < 0)
//		{
//			tmp = 0;
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	vector<int> vec{ -3,-2,0,-1};
//	cout << maxSubArray(vec) << endl;
//	system("pause");
//	return 0;
//}

/*54. Spiral Matrix */
//vector<int> spiralOrder(vector<vector<int>>& matrix)
//{
//	vector<int> res;
//	if (matrix.empty() || matrix[0].empty())
//		return res;
//	int m = matrix.size(), n = matrix[0].size();
//	int p = m, q = n;
//	int c = m < n ? (m + 1) / 2 : (n + 1) / 2;
//	for (int i = 0; i < c; i++, p -= 2, q -= 2)
//	{
//		for (int j = i; j < i + q; j++)
//			res.push_back(matrix[i][j]);
//		for (int j = i + 1; j < i + p; j++)
//			res.push_back(matrix[j][i + q - 1]);
//		if (p == 1 || q == 1)
//			break;
//		for (int j = i + q - 2; j >= i; --j)
//			res.push_back(matrix[i + p - 1][j]);
//		for (int j = i + p - 2; j > i; --j)
//			res.push_back(matrix[j][i]);
//	}
//	return res;
//}
//
//int main()
//{
//	vector<vector<int> > vec{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9,10,11,12} };
//	vector<int> res = spiralOrder(vec);
//	for (auto &it : res)
//		cout << it << " ";
//	system("pause");
//	return 0;
//}

/*55. Jump Game */
//bool canJump(vector<int>& nums)
//{
//	if (nums.size() == 0)
//		return false;
//	if (nums.size() == 1)
//		return true;
//	int nMax = 0;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		nMax = max(nMax, i + nums[i]);
//		if (nMax < i + 1)
//			return false;
//		if (nMax >= nums.size() - 1)
//			return true;
//	}
//	return false;
//}
//
//int main()
//{
//	vector<int> vec{ 2,3,1,1,4 };
//	cout << boolalpha << canJump(vec) << endl;
//	system("pause");
//	return 0;
//}

/*56. Merge Intervals */
//struct Interval
//{
//	int start;
//	int end;
//	Interval() : start(0), end(0) {}
//	Interval(int s, int e) : start(s), end(e) {}
//};
//
//static bool cmp(const Interval &A, const Interval &B)
//{
//	return A.start < B.start;
//}
//
//vector<Interval> merge(vector<Interval>& intervals)
//{
//	vector<Interval> res;
//	if ((int)intervals.size() == 0)
//		return res;
//	sort(intervals.begin(), intervals.end(), cmp);
//	res.push_back(intervals.at(0));
//	for (int i = 1; i < (int)intervals.size(); ++i)
//	{
//		if (intervals.at(i).start <= res.back().end)
//		{
//			res.back().end = max(res.back().end, intervals.at(i).end);
//		}
//		else
//		{
//			res.push_back(intervals.at(i));
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	vector<Interval> vec{ Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18) };
//	vector<Interval> res = merge(vec);
//	for (auto &it : res)
//	{
//		cout << it.start << " " << it.end << endl;
//	}
//	system("pause");
//	return 0;
//}
//

/*57. Insert Interval */
//struct Interval {
//	int start;
//	int end;
//	Interval() : start(0), end(0) {}
//	Interval(int s, int e) : start(s), end(e) {}
//};
//
//vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
//{
//	vector<Interval> res;
//	if ((int)intervals.size() == 0)
//		return vector<Interval>{newInterval};
//	for (int i = 0; i < (int)intervals.size(); ++i)
//	{
//		if (newInterval.start > intervals[i].end)
//		{
//			res.push_back(Interval(intervals[i].start, intervals[i].end));
//		}
//		else if (newInterval.end < intervals[i].start)
//		{
//			res.push_back(Interval(newInterval.start, newInterval.end));
//			for (int j = i; j < (int)intervals.size(); ++j)
//			{
//				res.push_back(Interval(intervals[j].start, intervals[j].end));
//			}
//			return res;
//		}
//		else
//		{
//			newInterval.start = min(newInterval.start, intervals[i].start);
//			newInterval.end = max(newInterval.end, intervals[i].end);
//		}
//	}
//	res.push_back(Interval(newInterval.start, newInterval.end));
//	return res;
//}
//
//int main()
//{
//	vector<Interval> vec{ Interval(1,5) };
//	Interval newIn(2, 3);
//	vector<Interval> res = insert(vec, newIn);
//	for (auto &it : res)
//	{
//		cout << it.start << " " << it.end << endl;
//	}
//	system("pause");
//	return 0;
//}

/*62. Unique Paths */
//int uniquePaths(int m, int n)
//{
//	vector<vector<int> > vec(m, vector<int>(n, 1));
//	for (int i = 1; i < m; i++)
//	{
//		for (int j = 1; j < n; j++)
//		{
//			vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
//		}
//	}
//	return vec[m - 1][n - 1];
//}
//
//int main()
//{
//	cout << uniquePaths(3, 2) << endl;
//	system("pause");
//	return 0;
//}

/*66. Plus One */
//vector<int> plusOne(vector<int>& digits)
//{
//	int carry = 1;
//	for (int i = digits.size() - 1; i >= 0; --i)
//	{
//		int sum = digits[i] + carry;
//		carry = 0;
//		if (sum > 9)
//		{
//			digits[i] = sum - 10;
//			carry = 1;
//		}
//		else
//		{
//			digits[i] = sum;
//			break;
//		}
//	}
//	if (carry == 1)
//		digits.insert(digits.begin(), 1);
//	return digits;
//}
//
//int main()
//{
//	vector<int> vec{ 9,9,9 };
//	vector<int> res = plusOne(vec);
//	for (auto &it : res)
//		cout << it << " ";
//	system("pause");
//	return 0;
//}

/*67. Add Binary */
//string addBinary(string a, string b)
//{
//	string res;
//	int i = a.length() - 1;
//	int j = b.length() - 1;
//	int flag = 0;
//	while (i >= 0 || j >= 0 || flag > 0)
//	{
//		int tmp = 0;
//		if (i >= 0)
//			tmp += a[i--] - '0';
//		if (j >= 0)
//			tmp += b[j--] - '0';
//		tmp += flag;
//		if (tmp > 1)
//		{
//			flag = 1;
//			tmp -= 2;
//		}
//		else
//			flag = 0;
//		char ch = tmp + '0';
//		res = ch + res;
//	}
//	return res;
//}
//
//int main()
//{
//	string a = "1010", b = "1011";
//	cout << addBinary(a, b) << endl;
//	system("pause");
//	return 0;
//}

/*69. Sqrt(x) */
//int mySqrt(int x)
//{
//	if (x < 0)
//		return 0;
//	int left = 1, right = x;
//	int mid = left + (right - left) / 2;
//	while (left <= right)
//	{
//		if (mid == x / mid)
//			return mid;
//		if (mid > x / mid)
//			right = mid - 1;
//		else
//			left = mid + 1;
//		mid = left + (right - left) / 2;
//	}
//	return right;
//}
//
//int main()
//{
//	cout << mySqrt(8) << endl;
//	system("pause");
//	return 0;
//}

/*70. Climbing Stairs */
//int climbStairs(int n)
//{
//	if (n == 0) return 0;
//	if (n == 1) return 1;
//	if (n == 2) return 2;
//
//	int first = 1;
//	int second = 2;
//	int all = 0;
//	for (int i = 3; i <= n; ++i)
//	{
//		all = first + second;
//		first = second;
//		second = all;
//	}
//	return all;
//}

/*73. Set Matrix Zeroes */
//void setZeroes(vector<vector<int>>& matrix)
//{
//	int row = (int)matrix.size();
//	if (0 == row)
//		return;
//	int col = (int)matrix[0].size();
//	if (0 == col)
//		return;
//	bool *flag = new bool[row + col];
//	memset(flag, false, sizeof(bool)*(row + col));
//	for (int i = 0; i < row; ++i)
//	{
//		for (int j = 0; j < col; ++j)
//		{
//			if (0 == matrix[i][j])
//			{
//				flag[i] = flag[row + j] = true;
//			}
//		}
//	}
//	for (int i = 0; i < row; ++i)
//	{
//		if (flag[i])
//		{
//			for (int j = 0; j < col; ++j)
//			{
//				matrix[i][j] = 0;
//			}
//		}
//	}
//	for (int j = 0; j < col; ++j)
//	{
//		if (flag[row + j])
//		{
//			for (int i = 0; i < row; ++i)
//			{
//				matrix[i][j] = 0;
//			}
//		}
//	}
//}
//
//int main()
//{
//	vector < vector<int> > vec{ {1,1,1}, {1,0,1}, {1,1,1} };
//	setZeroes(vec);
//	for (int i = 0; i < (int)vec.size(); ++i)
//	{
//		for (int j = 0; j < (int)vec[i].size(); ++j)
//		{
//			cout << vec[i][j] << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*75. Sort Colors */
// void sortColors(vector<int> &nums)
// {
//     int left = 0, right = nums.size()-1;
//     for (int i=0; i<=right; i++)
//     {
//         if (nums[i] == 0)
//         {
//             swap(nums[i], nums[left]);
//             ++left;
//         }
//         else if (nums[i] == 2)
//         {
//             swap(nums[i], nums[right]);
//             --right;
//             --i;
//         }
//     }
// }
//
// int main()
// {
//     vector<int> vec{1,2,0};
//     sortColors(vec);
//     for (auto & it : vec)
//         cout<<it<<endl;
//     system("pause");
//     return 0;
// }

/*76. Minimum Window Substring */
//string minWindow(string s, string t)
//{
//    int begin = 0, end = 0;
//    int nMin = INT_MAX;
//    int resBegin = 0;
//    vector<int> needVec(128, 0);
//    vector<int> findVec(128, 0);
//    int ncount = t.length();
//    for (auto &it : t)
//        needVec[it]++;
//    while (1)
//    {
//        if (ncount == 0)
//        {
//            while (findVec[s[begin]] > needVec[s[begin]])
//            {
//                findVec[s[begin]]--;
//                begin++;
//            }
//            int nsize = end - begin;
//            if (nsize < nMin)
//            {
//                resBegin = begin;
//                nMin = nsize;
//            }
//        }
//        if (end < s.size())
//        {
//            findVec[s[end]]++;
//            if (needVec[s[end]] >= findVec[s[end]])
//            {
//                ncount--;
//            }
//            end++;
//        }
//        else
//            break;
//    }
//    if (nMin == INT_MAX)
//        return "";
//    else
//    {
//        return s.substr(resBegin, nMin);
//    }
//}
//
//int main()
//{
//    cout<<minWindow("ADOBECODEBANC", "ABC")<<endl;
//    system("pause");
//    return 0;
//}

/*77. Combinations */
//void auxCombine(int n, int k, vector<vector<int> >& res, vector<int>& tmp, int index)
//{
//	if (tmp.size() == k)
//	{
//		res.push_back(tmp);
//		return ;
//	}
//	for (int i = index + 1; i <= n; ++i)
//	{
//		tmp.push_back(i);
//		auxCombine(n, k, res, tmp, i);
//		tmp.pop_back();
//	}
//}
//
//vector<vector<int>> combine(int n, int k)
//{
//	vector<vector<int> > res;
//	vector<int> tmp;
//	auxCombine(n, k, res, tmp, 0);
//	return res;
//}
//
//int main()
//{
//	vector<vector<int> > res = combine(4, 2);
//	for (auto &it : res)
//	{
//		for (auto &iter : it)
//		{
//			cout << iter << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*78. Subsets */
//void auxsubsets(vector<vector<int> >& res, vector<int>& tmp, vector<int>&nums, int index)
//{
//	if (tmp.size() <= nums.size())
//	{
//		res.push_back(tmp);
//	}
//	if (tmp.size() == nums.size())
//	{
//		return;
//	}
//	else
//	{
//		for (int i = index; i < nums.size(); ++i)
//		{
//			tmp.push_back(nums[i]);
//			auxsubsets(res, tmp, nums, i+1);
//			tmp.pop_back();
//		}
//	}
//}
//
//vector<vector<int> > subsets(vector<int>& nums)
//{
//	vector<vector<int> > res;
//	vector<int> tmp;
//	auxsubsets(res, tmp, nums, 0);
//	return res;
//}
//
//int main()
//{
//	vector<int> vec{ 1, 2, 3 };
//	vector<vector<int> > res = subsets(vec);
//	for (auto &it : res)
//	{
//		for (auto &iter : it)
//			cout << iter << " ";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*79. Word Search */
//int steps[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
//int rows, cols;
//
//bool isValid(int x_, int y_)
//{
//	if (x_ >= 0 && x_ < rows && y_ >= 0 && y_ < cols)
//		return true;
//	return false;
//}
//
//bool auxExist(vector<vector<char> >&board, string &word, vector<vector<bool> > &visited, int len, int i, int j)
//{
//	if (len == word.length() - 1)
//		return board[i][j] == word[len];
//	if (board[i][j] == word[len])
//	{
//		visited[i][j] = true;
//		for (int index = 0; index < 4; ++index)
//		{
//			int nX = i + steps[index][0];
//			int nY = j + steps[index][1];
//			if (isValid(nX, nY) && !visited[nX][nY] &&auxExist(board, word, visited, len + 1, nX, nY))
//				return true;
//		}
//		visited[i][j] = false;
//	}
//	return false;
//}
//
//bool exist(vector<vector<char>>& board, string word)
//{
//	rows = board.size();
//	cols = board.at(0).size();
//	vector<vector<bool> > visited(rows, vector<bool>(cols, false));
//	for (int i = 0; i < rows; ++i)
//	{
//		for (int j = 0; j < cols; ++j)
//		{
//			if (auxExist(board, word, visited, 0, i, j))
//				return true;
//		}
//	}
//	return false;
//}
//
//int main()
//{
//	vector<vector<char> > board{ {'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'} };
//	string word[3] = { "ABCCED", "SEE", "ABCB" };
//	for (auto &it : word)
//	{
//		cout << exist(board, it) << endl;
//	}
//	system("pause");
//	return 0;
//}

/*84. Largest Rectangle in Histogram */
// int largestRectangleArea(vector<int>& heights)
// {
//    stack<int> sta;
//    int nMax = 0;
//    for (auto &it : heights)
//    {
//        if (sta.empty() || sta.top() <= it)
//        {
//            sta.push(it);
//        }
//        else
//        {
//            int i = 0;
//            while (!sta.empty() && sta.top() > it)
//            {
//                ++i;
//                nMax = max(nMax, sta.top()*i);
//                sta.pop();
//            }
//            while (i--)
//            {
//                sta.push(it);
//            }
//            sta.push(it);
//        }
//    }
//    int cnt = 0;
//    while (!sta.empty())
//    {
//        ++cnt;
//        nMax = max(nMax, sta.top()*cnt);
//        sta.pop();
//    }
//    return nMax;
// }
//
// int main()
// {
//     vector<int> vec{2,1,5,6,2,3};
//     cout<<largestRectangleArea(vec)<<endl;
//     return 0;
// }

/*88. Merge Sorted Array */
//void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
//{
//	int index = m + n - 1;
//	--m;
//	--n;
//	while (m >= 0 && n >= 0)
//	{
//		if (nums1[m] > nums2[n])
//		{
//			nums1[index--] = nums1[m--];
//		}
//		else
//		{
//			nums1[index--] = nums2[n--];
//		}
//	}
//	while (n >= 0)
//	{
//		nums1[index--] = nums2[n--];
//	}
//}
//
//int main()
//{
//	vector<int> vec1{ 1,2,3,0,0,0 };
//	vector<int> vec2{ 2,5,6 };
//	merge(vec1, 3, vec2, 3);
//	for (auto &it : vec1)
//	{
//		cout << it << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

/*91. Decode Ways */
//bool isValid(char ch)
//{
//	if (ch >= '1' && ch <= '26')
//		return true;
//	return false;
//}
//
//bool isValid(char ch1, char ch2)
//{
//	if (ch2 == '0')
//		return false;
//	string str;
//	str += ch2;
//	str += ch1;
//	int integer = stoi(str);
//	if (integer >= 1 && integer <= 26)
//		return true;
//	return false;
//}
//
//int numDecodings(string s)
//{
//	if (s.length() == 0 || s[0] == '0')
//		return 0;
//	if (s.length() == 1)
//		return 1;
//	int dp1 = 1, dp2 = 1;
//	for (int i = 1; i < s.length(); ++i)
//	{
//		int cur = 0;
//		if (isValid(s[i]))
//			cur += dp2;
//		if (isValid(s[i], s[i - 1]))
//			cur += dp1;
//		dp1 = dp2;
//		dp2 = cur;
//	}
//	return dp2;
//}
//
//int main()
//{
//	string strs[2] = { "12", "226" };
//	for (auto &it : strs)
//	{
//		cout << numDecodings(it) << endl;
//	}
//	system("pause");
//	return 0;
//}

/*94. Binary Tree Inorder Traversal*/
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//
// vector<int> inorderTraversal(TreeNode* root)
// {
//     vector<int> res;
//     if (root == nullptr)
//         return res;
//     stack<TreeNode*> sta;
//     TreeNode *p = root;
//     while (p != nullptr || !sta.empty())
//     {
//         while (p != nullptr)
//         {
//             sta.push(p);
//             p = p->left;
//         }
//         p = sta.top();
//         sta.pop();
//         res.push_back(p->val);
//         p = p->right;
//     }
//     return res;
// }
//
// int main()
// {
//     TreeNode* root = new TreeNode(1);
//     root->right = new TreeNode(2);
//     root->right->left = new TreeNode(3);
//     vector<int> res = inorderTraversal(root);
//     for (auto &it : res)
//         cout<<it<<endl;
//     return 0;
// }

/*98. Validate Binary Search Tree */
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//TreeNode *pre = NULL;
//bool isValidBST(TreeNode* root)
//{
//	if (root != NULL)
//	{
//		if (!isValidBST(root->left))
//		{
//			return false;
//		}
//		if (pre != NULL && root->val <= pre->val)
//		{
//			return false;
//		}
//		pre = root;
//		return isValidBST(root->right);
//	}
//	return true;
//}
//
//int main()
//{
//	TreeNode *tree = new TreeNode(5);
//	tree->left = new TreeNode(1);
//	tree->right = new TreeNode(4);
//	tree->right->left = new TreeNode(3);
//	tree->right->right = new TreeNode(6);
//	cout << isValidBST(tree) << endl;
//	system("pause");
//	return 0;
//}

/*101. Symmetric Tree*/
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//
// bool auxSymmetric(TreeNode* left, TreeNode* right)
// {
//     if (left == nullptr && right == nullptr)
//         return true;
//     if (left == nullptr || right == nullptr)
//         return false;
//     if (left->val != right->val)
//         return false;
//     return auxSymmetric(left->left, right->right) && auxSymmetric(left->right, right->left);
// }
//
// bool isSymmetric(TreeNode* root)
// {
//     if (root == nullptr)
//         return true;
//     return auxSymmetric(root->left, root->right);
// }
//
// int main()
// {
//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(2);
//     root->left->left = new TreeNode(3);
//     root->left->right = new TreeNode(4);
//     root->right->left = new TreeNode(4);
//     root->right->right = new TreeNode(3);
//     cout<<boolalpha<<isSymmetric(root)<<endl;
//     return 0;
// }

/*102. Binary Tree Level Order Traversal */
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//vector<vector<int>> levelOrder(TreeNode* root)
//{
//	vector<vector<int> > res;
//	if (root == nullptr)
//		return res;
//	queue<TreeNode*> que;
//	TreeNode* tmp = root;
//	que.push(tmp);
//	while (!que.empty())
//	{
//		int nSize = que.size();
//		vector<int> vec;
//		for (int i = 0; i < nSize; ++i)
//		{
//			TreeNode* val = que.front();
//			que.pop();
//			vec.push_back(val->val);
//			if (val->left != nullptr)
//				que.push(val->left);
//			if (val->right != nullptr)
//				que.push(val->right);
//		}
//		res.push_back(vec);
//	}
//	return res;
//}
//
//int main()
//{
//	TreeNode *root = new TreeNode(3);
//	root->left = new TreeNode(9);
//	root->right = new TreeNode(20);
//	root->right->left = new TreeNode(15);
//	root->right->right = new TreeNode(7);
//	vector<vector<int>> res = levelOrder(root);
//	for (auto &it : res)
//	{
//		for (auto &iter : it)
//			cout << iter << " ";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*103. Binary Tree Zigzag Level Order Traversal*/
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//
// vector<vector<int>> zigzagLevelOrder(TreeNode* root)
// {
//     vector<vector<int> > res;
//     if (root == nullptr)
//         return res;
//     stack<TreeNode*> s1;
//     stack<TreeNode*> s2;
//     vector<int> vec;
//     TreeNode *tmp = root;
//     s1.push(tmp);
//     while (!s1.empty() || !s2.empty())
//     {
//         while (!s1.empty())
//         {
//             TreeNode *nd = s1.top();
//             s1.pop();
//             vec.push_back(nd->val);
//             if (nd->left != nullptr)
//                 s2.push(nd->left);
//             if (nd->right != nullptr)
//                 s2.push(nd->right);
//         }
//         if (!vec.empty())
//             res.push_back(vec);
//         vec.clear();
//         while (!s2.empty())
//         {
//             TreeNode *nd = s2.top();
//             s2.pop();
//             vec.push_back(nd->val);
//             if (nd->right != nullptr)
//                 s1.push(nd->right);
//             if (nd->left != nullptr)
//                 s1.push(nd->left);
//         }
//         if (!vec.empty())
//             res.push_back(vec);
//         vec.clear();
//     }
//     return res;
// }
//
// int main()
// {
//     TreeNode *root = new TreeNode(3);
//     root->left = new TreeNode(9);
//     root->right = new TreeNode(20);
//     root->right->left = new TreeNode(15);
//     root->right->right = new TreeNode(17);
//     vector<vector<int> > res = zigzagLevelOrder(root);
//     for (auto &it : res)
//     {
//         for (auto &iter : it)
//             cout<<iter<<" ";
//         cout<<endl;
//     }
//     return 0;
// }

/*104. Maximum Depth of Binary Tree*/
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//
// int maxDepth(TreeNode* root)
// {
//    return root == nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right))+1;
// }
//
// int main()
// {
//     TreeNode *root = new TreeNode(3);
//     root->left = new TreeNode(9);
//     root->right = new TreeNode(20);
//     root->right->left = new TreeNode(15);
//     root->right->right = new TreeNode(17);
//     cout<<maxDepth(root)<<endl;
//     return 0;
// }

/*105. Construct Binary Tree from Preorder and Inorder Traversal*/
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//
// TreeNode* makeTree(vector<int> &preVec, int preStart, vector<int> &inVec, int inStart, int len)
// {
//     if (len <= 0)
//         return nullptr;
//     int pos = 0;
//     TreeNode *r = new TreeNode(preVec[preStart]);
//     while (pos < len)
//     {
//         if (preVec[preStart] == inVec[inStart+pos])
//             break;
//         ++pos;
//     }
//     r->left = makeTree(preVec, preStart+1, inVec, inStart, pos);
//     r->right = makeTree(preVec, preStart+pos+1, inVec, inStart+pos+1, len-pos-1);
//     return  r;
// }
//
// TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
// {
//    TreeNode *root;
//    int nLen = preorder.size();
//     root = makeTree(preorder, 0, inorder, 0, nLen);
//    return root;
// }
//
// int main()
// {
//     vector<int> preorder{3,9,20,15,7};
//     vector<int> inorder{9,3,15,20,7};
//    TreeNode* res = buildTree(preorder, inorder);
//    cout<<res->val;
//    return 0;
// }

/*108. Convert Sorted Array to Binary Search Tree*/
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//
// TreeNode* auxArray2BST(vector<int> &vec, int start, int end)
// {
//     if (start > end)
//         return nullptr;
//     int mid = start + (end - start) / 2;
//     TreeNode *r = new TreeNode(vec[mid]);
//     r->left = auxArray2BST(vec, start, mid-1);
//     r->right = auxArray2BST(vec, mid+1, end);
//     return r;
// }
//
// TreeNode* sortedArrayToBST(vector<int>& nums)
// {
//     if (nums.empty())
//         return nullptr;
//    TreeNode *root = auxArray2BST(nums, 0, nums.size()-1);
//    return root;
// }
//
// int main()
// {
//     vector<int> vec{-10,-3,0,5,9};
//     TreeNode *root = sortedArrayToBST(vec);
//     cout<<root->val<<endl;
//     return 0;
// }

/*116. Populating Next Right Pointers in Each Node*/
// struct TreeLinkNode {
//     int val;
//     TreeLinkNode *left, *right, *next;
//     TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
// };
//
// void connect(TreeLinkNode *root)
// {
//     if (root == nullptr)
//         return ;
//     if (root->left != nullptr)
//         root->left->next = root->right;
//     if (root->right != nullptr)
//         root->right->next = (root->next!=nullptr) ? root->next->left : nullptr;
//     connect(root->left);
//     connect(root->right);
// }
//
// int main()
// {
//     TreeLinkNode *root = new TreeLinkNode(1);
//     root->left = new TreeLinkNode(2);
//     root->right = new TreeLinkNode(3);
//     root->left->left = new TreeLinkNode(4);
//     root->left->right = new TreeLinkNode(5);
//     root->right->left = new TreeLinkNode(6);
//     root->right->right = new TreeLinkNode(7);
//     connect(root);
//     cout<<root->val<<endl;
//     return 0;
// }

/*118. Pascal's Triangle */
// vector<vector<int>> generate(int numRows)
// {
//     vector<vector<int> > res(numRows, vector<int>{1});
//     for (int i=1; i<numRows; ++i)
//     {
//         for (int j=1; j<i; ++j)
//         {
//             res[i].push_back(res[i-1][j-1] + res[i-1][j]);
//         }
//         res[i].push_back(1);
//     }
//     return res;
// }
//
// int main()
// {
//     vector<vector<int> > res = generate(5);
//     for (auto &it : res)
//     {
//         for (auto &iter : it)
//             cout<<iter<<" ";
//         cout<<endl;
//     }
//     return 0;
// }

/*121. Best Time to Buy and Sell Stock */
// int maxProfit(vector<int>& prices)
// {
//     if (prices.empty())
//         return 0;
//     int minPrice = prices[0];
//     int *array = new int [prices.size()]();
//     int nLen = prices.size();
//     for (int i=1; i<nLen; ++i)
//     {
//         minPrice = min(minPrice, prices[i]);
//         array[i] = max(array[i-1], prices[i]-minPrice);
//     }
//     return array[nLen-1];
// }
//
// int main()
// {
//     vector<int> vec{7,1,5,3,6,4};
//     cout<<maxProfit(vec);
//     return 0;
// }

/*122. Best Time to Buy and Sell Stock II */
// int maxProfit(vector<int>& prices)
// {
//     int res = 0, nLen = prices.size()-1;
//     for (int i=0; i<nLen; ++i)
//     {
//         if (prices[i+1] > prices[i])
//             res += prices[i+1] - prices[i];
//     }
//     return res;
// }
//
// int main()
// {
//     vector<int> vec{7,1,5,3,6,4};
//     cout<<maxProfit(vec)<<endl;
//     return 0;
// }

/*124. Binary Tree Maximum Path Sum */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//
// int nRes = INT_MIN;
//
// int auxMax(TreeNode *r)
// {
//     if (r == nullptr)
//         return 0;
//     int nMax = r->val;
//     int lMax = auxMax(r->left), rMax = auxMax(r->right);
//     if (lMax > 0)
//         nMax += lMax;
//     if (rMax > 0)
//         nMax += rMax;
//     if (nMax > nRes)
//         nRes = nMax;
//     return max(r->val, max(r->val+lMax, r->val+rMax));
// }
//
// int maxPathSum(TreeNode* root)
// {
//    auxMax(root);
//    return nRes;
// }
//
// int main()
// {
//    TreeNode *root = new TreeNode(-10);
//     root->left = new TreeNode(9);
//     root->right = new TreeNode(20);
//     root->right->left = new TreeNode(15);
//     root->right->right = new TreeNode(7);
//     cout<<maxPathSum(root)<<endl;
//     return 0;
// }

/*125. Valid Palindrome */
//void toLower(string &s)
//{
//	for (int i = 0; i < (int)s.length(); ++i)
//	{
//		if (s[i] >= 'A' && s[i] <= 'Z')
//			s[i] += 'a' - 'A';
//	}
//}
//
//bool isPalindrome(string s)
//{
//	toLower(s);
//	int nFront = 0, nTail = (int)s.length() - 1;
//	while (nFront < nTail)
//	{
//		while (!isalnum(s[nFront]))
//			++nFront;
//		while (!isalnum(s[nTail]))
//			--nTail;
//		if (nFront >= nTail)
//			return true;
//		if (s[nFront] != s[nTail])
//			return false;
//		++nFront;
//		--nTail;
//	}
//	return true;
//}
//
//int main()
//{
//	string strs[2] = { "0P" , "race a car" };
//	for (int i = 0; i < 2; i++)
//	{
//		cout << isPalindrome(strs[i]) << endl;
//	}
//	system("pause");
//	return 0;
//}

/*127. Word Ladder */
//bool isAdjacent(string &strF, string &strT)
//{
//	int index = 0;
//	for (int i = 0; i < (int)strF.length(); ++i)
//	{
//		if (strF[i] != strT[i])
//			++index;
//		if (index > 1)
//			return false;
//	}
//	return index == 1;
//}
//
//int ladderLength(string beginWord, string endWord, vector<string>& wordList)
//{
//	queue<string> que;
//	que.push(beginWord);
//	int res = 0;
//	while (!que.empty())
//	{
//		int nSize = (int)que.size();
//		for (int i = 0; i < nSize; ++i)
//		{
//			string tmp = que.front();
//			que.pop();
//			if (tmp == endWord)
//				return res + 1;
//			for (vector<string>::iterator it = wordList.begin(); it!= wordList.end(); )
//			{
//				if (isAdjacent(*it, tmp))
//				{
//					que.push(*it);
//					it = wordList.erase(it);
//				}
//				else
//					++it;
//			}
//		}
//		++res;
//	}
//	return 0;
//}
//
//int main()
//{
//	string sbegin = "hit";
//	string send = "cog";
//	vector<string> wordList{ "hot","dot","dog","lot","log","cog" };
//	cout << ladderLength(sbegin, send, wordList) << endl;
//	system("pause");
//	return 0;
//}

/*128. Longest Consecutive Sequence */
// int longestConsecutive(vector<int>& nums)
// {
//     map<int, bool> hash;
//     for (auto &it : nums)
//         hash[it] = true;
//     int nRes = 0;
//     for (auto &it : nums)
//     {
//         int nLen = 1;
//         hash[it] = false;
//         int item = it+1;
//         while (hash[item])
//         {
//             ++nLen;
//             hash[item] = false;
//             ++item;
//         }
//         item = it-1;
//         while (hash[item])
//         {
//             ++nLen;
//             hash[item] = false;
//             --item;
//         }
//         nRes = max(nLen, nRes);
//     }
//     return nRes;
// }
//
// int main()
// {
//     vector<int> vec{100, 4, 200, 1, 3, 2};
//     cout<<longestConsecutive(vec)<<endl;
//     return 0;
// }

/*129. Sum Root to Leaf Numbers */
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//void auxSumNumbers(TreeNode* root, int sum, int &res)
//{
//	if (root == nullptr)
//		return;
//	sum = sum * 10 + root->val;
//	if (root->left == nullptr && root->right == nullptr)
//	{
//		res += sum;
//		return;
//	}
//	else
//	{
//		if (root->left != nullptr)
//		{
//			auxSumNumbers(root->left, sum, res);
//		}
//		if (root->right != nullptr)
//		{
//			auxSumNumbers(root->right, sum, res);
//		}
//	}
//}
//
//int sumNumbers(TreeNode* root)
//{
//	if (root == nullptr)
//		return 0;
//	int res = 0;
//	auxSumNumbers(root, 0, res);
//	return res;
//}
//
//int main()
//{
//	TreeNode *root = new TreeNode(4);
//	root->left = new TreeNode(9);
//	root->right = new TreeNode(0);
//	root->left->left = new TreeNode(5);
//	root->left->right = new TreeNode(1);
//	cout << sumNumbers(root) << endl;
//	system("pause");
//	return 0;
//}

/*130. Surrounded Regions */
//struct POS
//{
//    int x, y;
//    POS(int _x, int _y):x(_x), y(_y){};
//};
//
//vector<vector<int> > steps{vector<int>{0,1}, vector<int>{0,-1}, vector<int>{1, 0}, vector<int>{-1, 0}};
//
// void bfs(vector<vector<char>> &board, int i, int j, int m, int n)
// {
//     queue<POS*> q;
//     board[i][j] = '*';
//     POS* pos = new POS(i, j);
//     q.push(pos);
//     while(!q.empty())
//     {
//         POS* front = q.front();
//         q.pop();
//         if(front->x > 0 && board[front->x-1][front->y] == 'O')
//         {
//             POS* up = new POS(front->x-1, front->y);
//             q.push(up);
//             board[up->x][up->y] = '*';
//         }
//         if(front->x < m-1 && board[front->x+1][front->y] == 'O')
//         {
//             POS* down = new POS(front->x+1, front->y);
//             q.push(down);
//             board[down->x][down->y] = '*';
//         }
//         if(front->y > 0 && board[front->x][front->y-1] == 'O')
//         {
//             POS* left = new POS(front->x, front->y-1);
//             q.push(left);
//             board[left->x][left->y] = '*';
//         }
//         if(front->y < n-1 && board[front->x][front->y+1] == 'O')
//         {
//             POS* right = new POS(front->x, front->y+1);
//             q.push(right);
//             board[right->x][right->y] = '*';
//         }
//     }
// }
//
// void solve(vector<vector<char>>& board)
// {
//    if (board.empty() || board[0].empty())
//        return ;
//    int rows = board.size(), cols = board[0].size();
//    for (int i=0; i<rows; ++i)
//    {
//        for (int j=0; j<cols; ++j)
//        {
//            if (board[i][j] == 'O' && (i==0 || i==rows-1 || j==0 || j==cols-1))
//            {
//                bfs(board, i, j, rows, cols);
//            }
//        }
//    }
//    for (int i=0; i<rows; ++i)
//    {
//        for (int j = 0; j < cols; ++j)
//        {
//            if (board[i][j] == 'O')
//                board[i][j] = 'X';
//            else if (board[i][j] == '*')
//                board[i][j] = 'O';
//        }
//    }
// }
//
// int main()
// {
//     vector<vector<char> > vec{vector<char>{'X', 'X', 'X', 'X'},
//                               vector<char>{'X', 'O', 'O', 'X'},
//                               vector<char>{'X', 'X', 'O', 'X'},
//                               vector<char>{'X', 'O', 'X', 'X'}};
//     solve(vec);
//     for (auto &it : vec)
//     {
//         for (auto &iter : it)
//             cout<<iter<<" ";
//         cout<<endl;
//     }
//     return 0;
// }

/*131. Palindrome Partitioning */
//bool isPalindrome(string str)
//{
//	int nf = 0, nt=str.length()-1;
//	while (nf < nt)
//	{
//		if (str[nf++] != str[nt--])
//			return false;
//	}
//	return true;
//}
//
//void auxpartition(vector<vector<string> > &res, vector<string> &tmp, string &s, int pos)
//{
//	if (pos == s.length())
//	{
//		res.push_back(tmp);
//	}
//	for (int i = pos; i < s.length(); ++i)
//	{
//		string substr = s.substr(pos, i - pos + 1);
//		if (isPalindrome(substr))
//		{
//			tmp.push_back(substr);
//			auxpartition(res, tmp, s, i+1);
//			tmp.pop_back();
//		}
//	}
//}
//
//vector<vector<string>> partition(string s)
//{
//	vector<vector<string> > res;
//	vector<string> tmp;
//	auxpartition(res, tmp, s, 0);
//	return res;
//}
//
//int main()
//{
//	string str = "aab";
//	vector<vector<string> > res = partition(str);
//	for (auto &it : res)
//	{
//		for (auto &iter : it)
//			cout << iter << " ";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*134. Gas Station */
// int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
// {
//     int nRes = 0, nTotal = 0, nSum = 0;
//     for (int i=0; i<gas.size(); ++i)
//     {
//         nTotal += gas[i] - cost[i];
//         nSum += gas[i] - cost[i];
//         if (nTotal < 0)
//         {
//             nRes = i+1;
//             nTotal = 0;
//         }
//     }
//     return nSum>=0 ? nRes : -1;
// }
//
// int main()
// {
//     vector<int> gas{3,3,4};
//     vector<int> cost{3,4,4};
//     cout<<canCompleteCircuit(gas, cost)<<endl;
//     return 0;
// }

/*136. Single Number */
// int singleNumber(vector<int>& nums)
// {
//    int nRes = 0;
//    for (auto &it : nums)
//        nRes ^= it;
//    return nRes;
// }
//
// int main()
// {
//     vector<int> vec{4,1,2,1,2};
//     cout<<singleNumber(vec)<<endl;
//     return 0;
// }

/*138. Copy List with Random Pointer */
// struct RandomListNode {
//     int label;
//     RandomListNode *next, *random;
//     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
// };
//
// RandomListNode *copyRandomList(RandomListNode *head)
// {
//     if (head == nullptr)
//         return nullptr;
//     RandomListNode *res = new RandomListNode(head->label);
//     RandomListNode *nd1 = head, *nd2 = res;
//     map<RandomListNode*, RandomListNode*> ma;
//     while (nd1->next != nullptr)
//     {
//         ma[nd1] = nd2;
//         nd1 = nd1->next;
//         nd2->next = new RandomListNode(nd1->label);
//         nd2 = nd2->next;
//     }
//     ma[nd1] = nd2;
//     nd1 = head;
//     nd2 = res;
//     while (nd1->next != nullptr)
//     {
//         nd2->random = ma[nd1->random];
//         nd1 = nd1->next;
//         nd2 = nd2->next;
//     }
//     nd2->random = ma[nd1->random];
//     return res;
// }

/*139. Word Break */
// bool wordBreak(string s, vector<string>& wordDict)
// {
//    if (s == "" || wordDict.empty())
//        return false;
//    vector<bool> vec(s.length(), false);
//    set<string> se;
//    for (auto &it : wordDict)
//        se.insert(it);
//    for (int i=0; i<s.length(); ++i)
//    {
//        if (se.count(s.substr(0, i+1)))
//        {
//            vec[i] = true;
//            continue;
//        }
//        for (int j=0; j<i; ++j)
//        {
//            if (vec[j] && se.count(s.substr(j+1, i-j)))
//            {
//                vec[i] = true;
//                break;
//            }
//        }
//    }
//    return vec[s.length()-1];
// }
//
// int main()
// {
//     vector<string> vec{"apple", "pen"};
//     cout<<boolalpha<<wordBreak("applepenapple", vec)<<endl;
//     return 0;
// }

/*140. Word Break II */
// vector<string> resVec;
//
// void dfs(string str, vector<set<string> > &dict, int nLen)
// {
//     if (nLen == 0)
//     {
//         resVec.push_back(str);
//         return;
//     }
//     for (auto &it : dict[nLen])
//     {
//         string newstr = (str == "") ? it : it+" "+str;
//         dfs(newstr, dict, nLen-it.length());
//     }
// }
//
// vector<string> wordBreak(string s, vector<string>& wordDict)
// {
//     set<string> se;
//     for (auto &it : wordDict)
//         se.insert(it);
//     vector<set<string> > vec(s.length()+1);
//     for (int i=0; i<s.length(); ++i)
//     {
//         for (int j=1; j+i<=s.length(); ++j)
//         {
//             if (se.count(s.substr(i, j)))
//             {
//                 vec[i+j].insert(s.substr(i, j));
//             }
//         }
//     }
//     dfs(string(), vec, s.length());
//     return resVec;
// }
//
// int main()
// {
//     string s = "pineapplepenapple";
//     vector<string> wordDict{"apple", "pen", "applepen", "pine", "pineapple"};
//     vector<string> res = wordBreak(s, wordDict);
//     for (auto &it : res)
//         cout<<it<<endl;
//     return 0;
// }

/*141. Linked List Cycle */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
//
// bool hasCycle(ListNode *head)
// {
//     if (head == nullptr || head->next == nullptr)
//         return false;
//     ListNode *fast = head->next;
//     ListNode *late = head;
//     while (fast!= nullptr && fast->next!=nullptr)
//     {
//         if (fast == late)
//             return true;
//         fast = fast->next->next;
//         late = late->next;
//     }
//     return false;
// }
//
// int main()
// {
//     ListNode *root = new ListNode(1);
//     root->next = new ListNode(2);
//     root->next->next = root;
//     cout<<boolalpha<<hasCycle(root);
//     return 0;
// }

/*146. LRU Cache */
//class LRUCache {
//public:
//	LRUCache(int capacity)
//	{
//		nCapacity = capacity;
//	}
//
//	int get(int key)
//	{
//		unordered_map<int, list<pair<int, int> >::iterator >::iterator it = hashMap.find(key);
//		if (it == hashMap.end())
//			return -1;
//		else
//		{
//			int nRes = it->second->second;
//			list< pair<int, int> >::iterator tmp = it->second;
//			pair<int, int> tmpPair = *tmp;
//			cacheList.erase(tmp);
//			cacheList.push_front(tmpPair);
//			hashMap[key] = cacheList.begin();
//			return nRes;
//		}
//	}
//
//	void put(int key, int value)
//	{
//		unordered_map<int, list<pair<int, int> >::iterator >::iterator it = hashMap.find(key);
//		if (it == hashMap.end())
//		{
//			pair<int, int> newPair = make_pair(key, value);
//			if (cacheList.size() >= nCapacity)
//			{
//				int delKey = cacheList.back().first;
//				unordered_map<int, list<pair<int, int> >::iterator >::iterator iter = hashMap.find(delKey);
//				hashMap.erase(iter);
//				cacheList.pop_back();
//			}
//			cacheList.push_front(newPair);
//			hashMap[key] = cacheList.begin();
//		}
//		else
//		{
//			list< pair<int, int> >::iterator tmp = it->second;
//			tmp->second = value;
//			pair<int, int> tmpPair = *tmp;
//			cacheList.erase(tmp);
//			cacheList.push_front(tmpPair);
//			hashMap[key] = cacheList.begin();
//		}
//	}
//
//private:
//	int nCapacity;
//	unordered_map<int, list<pair<int, int> >::iterator > hashMap;
//	list<pair<int, int> > cacheList;
//};
//
//int main()
//{
//	LRUCache *cache = new LRUCache(2);
//
//	cache->put(2, 1);
//	cache->put(2, 2);
//	cout << cache->get(2) << endl;       // returns 1
//	cache->put(1, 1);    // evicts key 2
//	cache->put(4, 1);    // evicts key 1
//	cout << cache->get(2) << endl;       // returns -1 (not found)
//	system("pause");
//	return 0;
//}

/*148. Sort List */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
//
// ListNode* MergeList(ListNode *nd1, ListNode *nd2)
// {
//     ListNode *Dummy = new ListNode(-1);
//     ListNode *res = Dummy;
//     while (nd1 != nullptr || nd2 != nullptr)
//     {
//         int num1 = (nd1 == nullptr) ? INT_MAX : nd1->val;
//         int num2 = (nd2 == nullptr) ? INT_MAX : nd2->val;
//         if (num1 < num2)
//         {
//             res->next = new ListNode(num1);
//             res = res->next;
//             nd1 = nd1->next;
//         }
//         else
//         {
//             res->next = new ListNode(num2);
//             res = res->next;
//             nd2 = nd2->next;
//         }
//     }
//     return Dummy->next;
// }
//
// ListNode* sortList(ListNode* head)
// {
//     if (head == nullptr || head->next == nullptr)
//         return head;
//     ListNode *fast = head;
//     ListNode *slow = head;
//     while (fast->next != nullptr && fast->next->next != nullptr)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     fast = slow;
//     slow = slow->next;
//     fast->next = nullptr;
//     ListNode *nd1 = sortList(head);
//     ListNode *nd2 = sortList(slow);
//     return MergeList(nd1, nd2);
// }
//
// int main()
// {
//     ListNode *ln = new ListNode(-1);
//     ln->next = new ListNode(5);
//     ln->next->next = new ListNode(3);
//     ln->next->next->next = new ListNode(4);
//     ln->next->next->next->next = new ListNode(0);
//     ListNode *res = sortList(ln);
//     while (res != nullptr)
//     {
//         cout<<res->val<<endl;
//         res = res->next;
//     }
//     return 0;
// }

/*149. Max Points on a Line */
// struct Point {
//     int x;
//     int y;
//     Point() : x(0), y(0) {}
//     Point(int a, int b) : x(a), y(b) {}
// };
//
// int maxPoints(vector<Point>& points)
// {
//     int nRes = 0;
//     if (points.empty())
//         return nRes;
//     for (int i=0; i<points.size(); ++i)
//     {
//         unordered_map<double, int> hashMap;
//         int tmpRes = 0;
//         int nDuplicaiton = 0;
//         for (int j=0; j<points.size(); ++j)
//         {
//             if (i == j)
//                 continue;
//             if (points[i].x == points[j].x && points[i].y == points[j].y)
//                 nDuplicaiton++;
//             else if (points[i].x == points[j].x)
//                 hashMap[INT_MAX]++;
//             else
//                 hashMap[(double)(points[i].y - points[j].y) / (points[i].x - points[j].x)]++;
//         }
//         for (auto &it : hashMap)
//             tmpRes = max(it.second, tmpRes);
//         nRes = max(nRes, tmpRes + nDuplicaiton);
//     }
//     return nRes + 1;
// }
//
// int main()
// {
////     vector<Point> points{Point(1,1), Point(3,2), Point(5,3), Point(4,1), Point(2,3), Point(1,4)};
//     vector<Point> points{Point(0,0), Point(94911151,94911150), Point(94911152,94911151)};
//     cout<<maxPoints(points)<<endl;
//     return 0;
// }

/*150. Evaluate Reverse Polish Notation */
// int evalRPN(vector<string>& tokens)
// {
//     if (tokens.size() == 1)
//         return stoi(tokens[0]);
//     stack<int> sta;
//     for (auto &it : tokens)
//     {
//         if (it == "+" || it == "-" || it == "*" || it == "/")
//         {
//             int num1 = sta.top();
//             sta.pop();
//             int num2 = sta.top();
//             sta.pop();
//             if (it == "+")
//                 sta.push(num1 + num2);
//             if (it == "-")
//                 sta.push(num2 - num1);
//             if (it == "*")
//                 sta.push(num1 * num2);
//             if (it == "/")
//                 sta.push(num2 / num1);
//         }
//         else
//         {
//             sta.push(stoi(it));
//         }
//     }
//     return sta.top();
// }
//
// int main()
// {
//     vector<string> vec{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
//     cout<<evalRPN(vec)<<endl;
//     return 0;
// }

/*155. Min Stack */
// class MinStack {
// public:
//     /** initialize your data structure here. */
//     MinStack()
//     {
//     }
//
//     void push(int x)
//     {
//         sta.push(x);
//         if (minStack.empty() || (!minStack.empty() && x <= minStack.top()))
//         {
//             minStack.push(x);
//         }
//     }
//
//     void pop()
//     {
//         if (!sta.empty())
//         {
//             if (sta.top() == minStack.top())
//                 minStack.pop();
//             sta.pop();
//         }
//     }
//
//     int top()
//     {
//         if (!sta.empty())
//             return sta.top();
//         return 0;
//     }
//
//     int getMin()
//     {
//         if (!minStack.empty())
//             return minStack.top();
//         return 0;
//     }
//
// private:
//     stack<int> sta;
//     stack<int> minStack;
// };
//
// int main()
// {
//     MinStack minStack;
//     minStack.push(-2);
//     minStack.push(0);
//     minStack.push(-3);
//     cout<<minStack.getMin()<<endl;   //--> Returns -3.
//     minStack.pop();
//     cout<<minStack.top()<<endl;      //--> Returns 0.
//     cout<<minStack.getMin()<<endl;   //--> Returns -2.
//
//     return 0;
// }

/*160. Intersection of Two Linked Lists */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
//
// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
// {
//     if (headA == nullptr || headB == nullptr)
//         return nullptr;
//
//     auto getLen = [](ListNode *head){
//         int nLen = 0;
//         ListNode *ln = head;
//         while (ln != nullptr)
//         {
//             ++nLen;
//             ln = ln->next;
//         }
//         return nLen;
//     };
//
//     int nLA = getLen(headA);
//     int nLB = getLen(headB);
//     int delta = abs(nLA - nLB);
//     ListNode *tmpA = headA, *tmpB = headB;
//     if (nLA > nLB)
//     {
//         while (delta--)
//             tmpA = tmpA->next;
//     }
//     else
//     {
//         while (delta--)
//             tmpB = tmpB->next;
//     }
//     ListNode *res = nullptr;
//     while (tmpA != nullptr)
//     {
//         if (tmpA == tmpB)
//         {
//             res = tmpA;
//             break;
//         }
//         tmpA = tmpA->next;
//         tmpB = tmpB->next;
//     }
//     return res;
// }
//
// int main()
// {
//     ListNode *headA = new ListNode(4);
//     headA->next = new ListNode(1);
//     headA->next->next = new ListNode(8);
//     headA->next->next->next = new ListNode(4);
//     headA->next->next->next->next = new ListNode(5);
//     ListNode *headB = new ListNode(5);
//     headB->next = new ListNode(0);
//     headB->next->next = new ListNode(1);
//     headB->next->next->next = new ListNode(8);
//     headB->next->next->next->next = new ListNode(4);
//     headB->next->next->next->next->next = new ListNode(5);
//     ListNode *res = getIntersectionNode(headA, headB);
//     cout<<res->val<<endl;
//     return 0;
// }

/*162. Find Peak Element */
// int findPeakElement(vector<int>& nums)
// {
//     int nLeft = 0, nRight = nums.size()-1;
//     while (nLeft < nRight)
//     {
//         int nMid = nLeft + (nRight - nLeft) / 2;
//         if (nums[nMid] < nums[nMid+1])
//         {
//             nLeft = nMid + 1;
//         }
//         else
//         {
//             nRight = nMid;
//         }
//     }
//     return nLeft;
// }
//
// int main()
// {
//     vector<int> vec{1,2,1,3,5,6,4};
//     cout<<findPeakElement(vec)<<endl;
//     return 0;
// }

/*166. Fraction to Recurring Decimal */
// string fractionToDecimal(int numerator, int denominator)
// {
//     if (numerator == 0)
//         return "0";
//     string res;
//     unordered_map<int, int> hashMap;
//     bool decimal = false;
//     long long n = numerator;
//     long long d = denominator;
//     bool minus = (n<0) ^ (d<0);
//     n = abs(n);
//     d = abs(d);
//     while (true)
//     {
//         if (n < d)
//         {
//             if (!decimal)
//             {
//                 if (res == "")
//                     res = "0.";
//                 else
//                     res += ".";
//                 decimal = true;
//             }
//             n *= 10;
//         }
//         int r = n - n/d*d;
//         if (r == 0)
//         {
//             res += to_string(n/d);
//             if (minus)
//                 res = '-' + res;
//             return res;
//         }
//         else
//         {
//             if (decimal)
//             {
//                 if (hashMap.find(n) == hashMap.end())
//                 {
//                     res += to_string(n/d);
//                     hashMap[n] = res.size() - 1;
//                 }
//                 else
//                 {
//                     res = res.substr(0, hashMap[n]) + "(" + res.substr(hashMap[n]) + ")";
//                     if (minus)
//                         res = '-' + res;
//                     return res;
//                 }
//             }
//             else
//             {
//                 res += to_string(n/d);
//             }
//             n = r;
//         }
//     }
// }
//
// int main()
// {
//     cout<<fractionToDecimal(2, 3)<<endl;
//     cout<<fractionToDecimal(2, 1)<<endl;
//     cout<<fractionToDecimal(1, 2)<<endl;
//     return 0;
// }

/*169. Majority Element */
// int majorityElement(vector<int>& nums)
// {
//     if (nums.size() == 1)
//         return nums[0];
//     int nHalf = (nums.size()+1) / 2;
//     unordered_map<int, int> hashMap;
//     for (auto &it : nums)
//     {
//         if (hashMap.find(it) == hashMap.end())
//         {
//             hashMap[it] = 1;
//         }
//         else
//         {
//             hashMap[it]++;
//             if (hashMap[it] == nHalf)
//                 return it;
//         }
//     }
//     return nums[0];
// }
//
// int main()
// {
//     vector<int> vec{2,2,1,1,1,2,2};
//     cout<<majorityElement(vec)<<endl;
//     return 0;
// }

/*171. Excel Sheet Column Number */
// int titleToNumber(string s)
// {
//     int sum = 0;
//     for (int i=0; i<s.length(); ++i)
//     {
//         int tmp = s[i] - 'A' + 1;
//         sum = sum*26 + tmp;
//     }
//     return sum;
// }
//
// int main()
// {
//     cout<<titleToNumber("ZY")<<endl;
//     return 0;
// }

/*172. Factorial Trailing Zeroes */
// int trailingZeroes(int n)
// {
//     int nRes = 0;
//     while (n)
//     {
//         nRes += n / 5;
//         n /= 5;
//     }
//     return nRes;
// }
//
// int main()
// {
//     cout<<trailingZeroes(5)<<endl;
//     return 0;
// }

/*179. Largest Number */
// string largestNumber(vector<int>& nums)
// {
//     vector<string> vec;
//     for (auto &it : nums)
//         vec.push_back(to_string(it));
//     sort(vec.begin(), vec.end(), [](const string &sA, const string &sB){
//         return sA+sB > sB+sA;
//     });
//     if (vec[0] == "0")
//         return "0";
//     else
//     {
//         string res;
//         for (auto &it : vec)
//             res += it;
//         return res;
//     }
// }
//
// int main()
// {
//     vector<int> vec{3,30,34,5,9};
//     cout<<largestNumber(vec)<<endl;
//     return 0;
// }

/*189. Rotate Array */
// void rotate(vector<int>& nums, int k)
// {
//     k %= nums.size();
//     reverse(nums.begin(), nums.end());
//     auto it = nums.begin();
//     while (k--)
//         ++it;
//     reverse(nums.begin(), it);
//     reverse(it, nums.end());
// }
//
// int main()
// {
//     for (int i=1; i<3; ++i)
//     {
//         vector<int> vec{-1,-100,3,99};
//         rotate(vec, i);
//         for (auto &it : vec)
//             cout<<it<<" ";
//         cout<<endl;
//     }
//     return 0;
// }

/*234. Palindrome Linked List*/
//struct ListNode
//{
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//
//};
//
//bool isPalindrome(ListNode* head)
//{
//	ListNode* slow = head;
//	ListNode* fast = head;
//	if (slow == NULL || fast->next == NULL)
//		return true;
//	while (slow->next != NULL && fast->next != NULL && fast->next->next != NULL)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	ListNode* middle = new ListNode(slow->next->val);
//	fast = slow->next->next;
//	while (fast != NULL)
//	{
//		ListNode* tmp = fast->next;
//		fast->next = middle;
//		middle = fast;
//		fast = tmp;
//	}
//	slow = head;
//	while (slow != NULL && middle != NULL)
//	{
//		if (slow->val != middle->val)
//			return false;
//		slow = slow->next;
//		middle = middle->next;
//	}
//	return true;
//}
//
//int main()
//{
//	ListNode *link = new ListNode(1);
//	link->next = new ListNode(2);
//	link->next->next = new ListNode(2);
//	link->next->next->next = new ListNode(1);
//	cout << isPalindrome(link) << endl;
//	system("pause");
//	return 0;
//}

/*532. K-diff Pairs in an Array */
//int findPairs(vector<int>& nums, int k)
//{
//	int res = 0;
//	sort(nums.begin(), nums.end(), [&](const int &A, const int &B) {return A < B; });
//	int left = 0, right = 1;
//	while (right < nums.size())
//	{
//		if (nums[right] - nums[left] < k)
//			++right;
//		else if (nums[right] - nums[left] > k)
//			++left;
//		else
//		{
//			++res;
//			while (++left < nums.size() && nums[left] == nums[left - 1]) {}
//			while (++right < nums.size() && nums[right] == nums[right - 1]) {}
//		}
//		if (left == right)
//			++right;
//	}
//	return res;
//}
//
//int main()
//{
//	vector<int> vec{ 1,3,1,5,4 };
//	cout << findPairs(vec, 0) << endl;
//	system("pause");
//	return 0;
//}