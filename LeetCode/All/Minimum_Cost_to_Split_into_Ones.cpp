class Solution {
public:
    int minCost(int n) {
        
        vector<long long> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 0;
        
        for(int x = 2; x <= n; x++){
            long long mini = LLONG_MAX;
            
            for(int i = 1; i < x; i++){
                mini = min(mini,dp[x - i]+dp[i]+ 1LL*i*(x-i));
            }
            
            dp[x] = mini;
        }
        
        return dp[n];
    }
};