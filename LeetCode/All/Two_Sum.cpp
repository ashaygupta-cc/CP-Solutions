class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
          unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int k = target - nums.at(i);
            if (mp.find(k) != mp.end()) 
                return {mp[k], i};
            else
            mp[nums[i]] = i;
        }
        return {};
    }
};