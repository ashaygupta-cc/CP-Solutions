class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
       
        sort(nums.begin(),nums.end());        
        int x = original;
        
        for(auto i:nums){
            if(i > x) break;
            if(i == x) x*=2;
        }
        return x;
    }
};