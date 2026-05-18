class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k){
        
        int M = grid.size();
        int N = grid[0].size();

        vector<vector<vector<int>>>dp(
            M,vector<vector<int>>(N, vector<int>(k+1,-1)));
        
        int startPenalty = grid[0][0] > 0 ? 1 : 0;
        
        if(startPenalty <= k)
            dp[0][0][startPenalty] = grid[0][0];

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
                
            for(int used = 0; used <= k; used++){

                if(dp[i][j][used] == -1) continue; 

                int add = grid[i][j];

          if(j+1 < N){
                int nextPenalty = used + (grid[i][j+1] > 0 ? 1 : 0);
                                                if(nextPenalty <= k){
            dp[i][j+1][nextPenalty] =
  max(dp[i][j+1][nextPenalty],dp[i][j][used]+grid[i][j+1]);
          }
                 }

          if(i+1 < M){
 int nextPenalty = used+(grid[i+1][j] > 0 ? 1 : 0);
                                           if(nextPenalty <= k){
         dp[i+1][j][nextPenalty] =
    max(dp[i+1][j][nextPenalty],dp[i][j][used]+grid[i+1][j]);
                        }
                    }
                }
            }
        }

        int ans = -1;
        for(int used = 0; used <= k; used++){
            ans = max(ans,dp[M-1][N-1][used]);
        }
        return ans;
    }
};