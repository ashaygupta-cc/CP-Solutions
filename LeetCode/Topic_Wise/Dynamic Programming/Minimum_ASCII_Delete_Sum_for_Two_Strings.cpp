class Solution {
public:
    int minimumDeleteSum(string s1, string s2){

        int N = s1.size();
        int M = s2.size();

        vector<vector<int>>dp(N+1,vector<int>(M+1,0));

        for(int j = M-1;j >= 0; j--){
            dp[N][j] = dp[N][j+1]+s2[j];
        }

        for(int i = N-1; i >= 0; i--){
            dp[i][M] = dp[i+1][M]+s1[i];
        }

        for(int i = N-1; i >= 0; i--){
            for(int j = M-1; j >= 0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else dp[i][j] = min(s1[i]+dp[i+1][j],s2[j]+dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
