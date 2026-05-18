class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int MOD = 1e9+7;

        vector<int>dp(151,0); 

        for(int j = 0; j < n; j++){
            dp[mat[0][j]]++;
        }

        for(int i = 1; i < m; i++){
            vector<int>next(151,0);
            for(int g = 1; g <= 150; g++){
                if(dp[g] == 0) continue;
                for(int j = 0; j < n; j++){
                    int newG = gcd(g,mat[i][j]);
                    next[newG] = (next[newG] + dp[g]) % MOD;
                }
            }
            dp = next;
        }
        return dp[1]; 
    }
};
