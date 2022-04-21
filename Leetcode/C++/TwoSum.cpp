#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
- Approach 1: Brute Force
    - Two for loops, first for loop, using i, loops through all the integers in the array. 
    - While the second, using j, takes the other integers after i, one by one, adds it with current nums[I] to see if they sum to the target.
    - Break whenever we find the sum to be equal to the target.
    - O(n^2)
*/
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i != nums.size(); ++i)
    {
        for (int j = i+1; j != nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    
    return res;
}

/*
- Approach 2: Use Hash Map
    - Use a hash map to store the integers (key) and its corresponding index (value)
    - In a for loop, first, try to find the key in the hash map that equals to the target - nums[j]
    - If we cannot find it, store the nums[j] as a new key in the hash map
    - O(n)
*/
vector<int> twoSumHash(vector<int>& nums, int target) {
        
    unordered_map<int, int> imap;
    vector<int> res;
    
    for (int i = 0; i != nums.size(); ++i)
    {
        auto found = imap.find(target - nums[i]);
        
        if (found != imap.end())
        {
            res.push_back(found->second);
            res.push_back(i);
            return res;
        }
        
        imap[nums[i]] = i;
    }
    
    return res;
}

int main()
{
    vector<int> res;
    res.push_back(3);
    res.push_back(2);
    res.push_back(3);

    auto r = twoSum(res, 6);
    for (size_t i = 0; i < r.size(); i++)
    {
        cout << r[i] << endl;
    }
}