class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>expectednums;
        expectednums.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) continue;
            else  expectednums.push_back(nums[i]);
        }
        nums = expectednums;
    return expectednums.size();
    }
};