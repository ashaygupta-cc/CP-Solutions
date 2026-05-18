class Solution {
public:
    #define ll long long
    int n,m;
    
    int minCost(vector<vector<int>>& grid) {
       n = grid.size();
       m = grid[0].size();
      
        vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(m,vector<bool>(1024,false)));

    dp[0][0][grid[0][0]] = true;

    ll cur = grid[0][0];
        
    for(int i = 1; i < m; i++){
        cur ^= grid[0][i];
        dp[0][i][cur] = true;
    }
    cur = grid[0][0];
        
    for(int j = 1; j < n; j++){
        cur ^= grid[j][0];
       dp[j][0][cur] = true;
    }
        
    for(int i = 1; i < n; i++){
       for(int j = 1; j < m; j++){
            auto &up = dp[i-1][j];
            auto &left = dp[i][j-1];

          for(int k = 0; k <= 1023; k++){
                if(up[k]) dp[i][j][k^grid[i][j]] = true;
                if(left[k]) dp[i][j][k^grid[i][j]] = true;
          }
       }
    }

        for(int i = 0; i <= 1023; i++){
            if(dp[n-1][m-1][i]) return i;
        }
       return -1; 
    }
};