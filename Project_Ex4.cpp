#include <iostream>
#include <stack>
#include<vector>
#include<algorithm>

//1. O(n)
bool IsValidParentheses(std::string s)
{
	std::stack<char> st;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c == '(' || c == '{' || c == '[')
			st.push(c);
		else {
			if (st.size() == 0)
				return false;
			char pre = st.top();
			switch (c)
			{
			case ')':
				if (pre == '(')
					st.pop();
				else
					return false;
				break;

			case ']':
				if (pre == '[')
					st.pop();
				else
					return false;
				break;
			case '}':
				if (pre == '{')
					st.pop();
				else
					return false;
				break;
			}
		}
	}
	if (s.empty())
		return true;
	else
		return false;
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

	while (p->next)
	{
		p->next = temp;
		temp = p;
		p = later;
		later =later->next;
	}
	return p;
}

ListNode* ResverseList2(ListNode* head)
{
	if (node == nullptr || node->next == nullptr)
	{
		return 0;
	}

	ListNode* new_head = ResverseList2(node->next);

	node->next->next = node;
	node->next = nullptr;

	return new_head;
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
int MissingNumber2(std::vector<int>& nums)
{
	int n = nums.size();
	for (i = 0~size)
	{
		n ^= i;
		n ^= nums[i];
	}
	return n;
}

//4.O(n * lng n)
//min heap, max heap로 만들어서 top을 팝,
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
//패인트 재귀
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

	if (zeroRC.size() >= matrix.size() || zeroRC.size() >= matrix[0].size())
	{
		for (auto& r : matrix)
			{
				for (auto& c : r)
				{
					c = 0;				
				}
			}
	}

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
	// 
}
