class Solution {
public:
    int smallestNumber(int n){
        vector<int>nums = {1,3,7,15,31,63,127,255,511,1023};

        auto idx = lower_bound(nums.begin(),nums.end(),n)-nums.begin();

       return nums[idx]; 
    }
};