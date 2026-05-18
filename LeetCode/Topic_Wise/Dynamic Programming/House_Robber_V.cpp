class Solution {
public:
    #define ll long long
    int n;

    long long rec(ll idx,vector<int>&nums,vector<int>&colors,vector<ll>&dp){

         if(idx >= n) return 0;
        
         if(dp[idx] != -1) return dp[idx];

         ll take = 0;

         if(idx+1 < n && colors[idx] == colors[idx+1]) take += nums[idx]+rec(idx+2,nums,colors,dp);
         else take += nums[idx]+rec(idx+1,nums,colors,dp);

         ll notTake = rec(idx+1,nums,colors,dp);

         return dp[idx] = max(take,notTake);
    }


    long long rob(vector<int>& nums, vector<int>& colors) {
        
        n = nums.size();
        vector<ll>dp(n+1,-1);
        return rec(0,nums,colors,dp);
    }
};