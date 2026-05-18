class Solution{
public:
    int climbStairs(int n){
       
  // The below code is having SpaceComplexity O(1)
       vector<int>dp(n+1,0);
    for(int i = 0; i <= n; i++){
        if(i == 1 || i == 0) dp[i] = 1;
         else{
            dp[i] = dp[i-1]+dp[i-2];  
         }       
    }
      return dp[n];
    }
};

/*
  // The below code is having SpaceComplexity O(1)
     int prev = 1;
     int prev2 = 1;
    
    for(int i = 1; i <= n; i++){
        int step1 = prev;
        int step2 = 0;
        if(i > 1) step2 = prev2;
       int cur = step2 + step1;
            prev2 = prev;
            prev = cur;           
    }
      return prev;
*/