﻿#include <iostream>
#include <stack>
#include<vector>
#include<algorithm>

//1. O(n)
bool IsValidParentheses(std::string s)
{
	std::stack<char> stk;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c == '(' || c == '{' || c == '[')
			stk.push(c);
		else {
			if (stk.size() == 0)
				return false;
			char pre = stk.top();
			switch (c)
			{
			case ')':
				if (pre == '(')
					stk.pop();
				else
					return false;
				break;

			case ']':
				if (pre == '[')
					stk.pop();
				else
					return false;
				break;
			case '}':
				if (pre == '{')
					stk.pop();
				else
					return false;
				break;
			}
		}
	}
	if (stk.empty())
		return true;
	else
		return false;
}

————————————————

版权声明：本文为博主原创文章，遵循 CC 4.0 BY - SA 版权协议，转载请附上原文出处链接和本声明。

原文链接：https ://blog.csdn.net/zhaoyuxiang126/article/details/46606453
}

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr){}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//2.O(n)
ListNode* ResverseList(ListNode* head)
{
	auto p = head->next;
	ListNode* temp = head;
	ListNode* later = head->next->next;

	head->next = nullptr;

	if (p->next)
	{
		p->next = temp;
		temp = p;
		p = later;
		later =later->next;
	}
	return p;
}

//3.O(n)
int MissingNumber(std::vector<int>& nums)
{
	int count = nums.size();
	int total{};
	for (int i = 1; i <= count; i++)
	{
		total += i;
	}
	int numsSum{};
	for (auto num : nums)
	{
		numsSum += num;
	}

	return total - numsSum;
}

//4.O(n * lng n)
std::vector<int> MostFrequentElements(std::vector<int>& nums,const int k)
{
	if (nums.size() == 1)
	{
		return nums;
	}
	std::vector<int> result;
	int count{1};
	std::vector<std::pair<int, int>> numsCount;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i + 1 < nums.size())
		{
			if (nums[i] == nums[i + 1])
			{
				count++;
			}
			else
			{
				numsCount.push_back({ count, nums[i] });
				count = 1;
			}
		}
	}
	numsCount.push_back({ count, nums[nums.size() - 1 ] });

	std::sort(numsCount.begin(), numsCount.end(),
		[](std::pair<int, int> a, std::pair<int, int> b) {return a.first > b.first; });

	for (int i = 0; i < k; i++)
	{
		result.push_back(numsCount[i].second);
	}

	return result;
}

//5.O( min(m*m*n, m*n*n) )
void SetZeroesRowCol(std::vector<std::vector<int>>& matrix)
{
	int row{}, column{};
	std::vector<std::pair<int, int>> zeroRC;

	for (auto r : matrix)
	{
		for (auto c : r)
		{
			if (c == 0)
			{
				zeroRC.push_back({ row, column });
			}
			column++;
		}
		column = 0;
		row++;
	}
	column = 0; 
	row = 0;

	for (auto p : zeroRC)
	{
		for (auto& r : matrix)
		{
			for (auto& c : r)
			{
				if (p.first == row || p.second == column)
				{
					c = 0;
				}
				column++;
			}
			column = 0;
			row++;
		}
	}

}

int main()
{
	//std::string s{ "()}[]" };
	//std::cout << IsValidParentheses(s);
	//std::vector<int> nums{ 1,2,2,3,3,3 };
	//for (auto e : MostFrequentElements(nums, 2))
	//{
	//	std::cout << e << " ";
	//}

	//std::vector<std::vector<int>> matrix{
	//	{1,1,1},
	//	{1,0,1},
	//{1,1,1}
	//};
	//SetZeroesRowCol(matrix);

	//	for (auto e : matrix)
	//	{
	//		for (auto i : e)
	//		{
	//			std::cout << i << ", ";
	//		}
	//		std::cout << std::endl;
	//	}
}
