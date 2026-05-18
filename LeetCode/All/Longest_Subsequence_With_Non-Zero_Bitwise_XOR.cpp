class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
     int n = nums.size();
     int ultimateXor = 0;
        
    for(int i = 0; i < n; i++){
       ultimateXor ^= nums[i];
    }

    if(ultimateXor) return n;

    int count = 0;
        
    for(int i = 0; i < n; i++){
        if(nums[i]) count++;
        if(count == 1) return n-1;
    }
     return 0;   
    }
};