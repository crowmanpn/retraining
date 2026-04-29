#include <unordered_map>
#include <vector>
#include <iostream>
#include <limits>
struct myPair {
	int m_cnt;  //
	int m_index;//i

	myPair(int cnt,int index) {
		m_cnt = cnt;
		m_index = index;
	}
};


class Solution {
public:
	bool containsDuplicate(std::vector<int>& nums) {
		std::unordered_map<int, int> myMap;

		for (size_t i = 0; i < nums.size(); i++)
		{
			/*auto result = myMap.insert({ nums[i],5 });
			if (result.second)
			{
				std::cout << "Success!\n";
			}

			else  return true;*/
			
		}
		return false;
	}
};

class Solution219 {
public:
	bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
		std::unordered_map<int,myPair> myMap;

		for (int i = 0; i < nums.size(); i++) {
			auto tmp=myMap.find(nums[i]);
			if (tmp==myMap.end())
			{
				myMap.insert({ nums[i],{1,i}});
			}
			else
			{
				tmp->second.m_cnt++;
				if (i-tmp->second.m_index<=k)
				{
					return true;
				}
				tmp->second.m_cnt = 1;
				tmp->second.m_index = i;
			}
		}
		return false;
	}
};

int main() {
	
	std::vector<int> myVec{ 1,2,3,1 };


	/*Solution mySol;
	auto test=mySol.containsDuplicate(myVec);*/

	Solution219 mySol;
	auto test=mySol.containsNearbyDuplicate(myVec,3);

	int x=120;
	long long res = 0;
	
	if (x<INT_MIN || x>INT_MAX) {
		return 0;
	}
	else{
	while (x != 0) {
		int tmp;
		tmp = x % 10;
		x /= 10;
		res = res * 10 + tmp;
		
	}
	}
	//посмотреть переполнение 1534236469.

	return 0;
}