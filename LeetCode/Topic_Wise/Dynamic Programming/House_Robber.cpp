class Solution{
     // Code has space complexity O(1)
 /*   
       int n = nums.size();
         int prev = nums[0];
         int prev2 = 0;

    for(int i = 1; i < n; i++){
        int take = nums[i];
        if(i>1) take += prev2;
        int nontake = prev;

       int cur = max(take,nontake);
            prev2 = prev;
            prev = cur;
    } 
  return prev;
*/  
public:
    // The code has space complexity of O(N)
    int rob(vector<int>& nums){
        int n = nums.size();
         vector<int>dp(n+1,0);
             dp[0] = nums[0];
    for(int i = 1; i < n; i++){
        int take = nums[i];
         if(i>1) take += dp[i-2];
        int nontake = 0+ dp[i-1];

        dp[i] = max(take,nontake);
    }
    return dp[n-1];
    }
};