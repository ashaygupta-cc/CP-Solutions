class Solution {
public:
    
    int solve(int x, vector<int>& dp){
        if(x == 0) return 0;
        
        if(dp[x] != -1) return dp[x];
        
        int mini = INT_MAX;
        
        for(int i = 1; i*i <= x; i++){
            mini = min(mini, 1 + solve(x - i*i, dp));
        }
        
        return dp[x] = mini;
    }
    
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};