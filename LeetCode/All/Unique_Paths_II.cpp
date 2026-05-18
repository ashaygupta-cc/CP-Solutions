#define ll long long
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    
   // The below solution has Space Complexity M*N;
      ll m = obstacleGrid.size();
      ll n = obstacleGrid[0].size();     
    vector<vector<ll>>dp(m,vector<ll>(n,0));
    
     for(ll i = m-1; i >= 0; i--){
        for(ll j = n-1; j >= 0; j--){
          
         if(i == m-1 && j == n-1){
            if(obstacleGrid[i][j] != 1){
                dp[i][j] = 1;
            }
            else return 0;
         }
        else if(obstacleGrid[i][j] == 1) dp[i][j] = 0;    
     else{
            ll left = 0,up = 0;
         if(j+1 < n) left = dp[i][j+1];
         if(i+1 < m) up = dp[i+1][j];
            dp[i][j] = (left+up);
     }
        }
    }
   return dp[0][0]; 
    }
};


/*
   // The below solution has Space Complexity N;
      ll m = obstacleGrid.size();
      ll n = obstacleGrid[0].size();     
         vector<ll>temp(n,0);
    
     for(ll i = m-1; i >= 0; i--){
          vector<ll>cur(n,0);
        for(ll k = n-1; k >= 0; k--){
            cur[k] = obstacleGrid[i][k];
        }
     
      for(ll j = n-1; j >= 0; j--){      
     if(i == m-1 && j == n-1){
    if(obstacleGrid[i][j] != 1){
       cur[j] = 1;
    } 
    else return 0;
     }
    else if(obstacleGrid[i][j] == 1) cur[j] = 0;    
     else{
            ll left = 0,up = 0;
         if(j+1 < n) left = cur[j+1];
         if(i+1 < m) up = temp[j];
            cur[j] = (left+up);
     }
        }
        temp = cur;
    }
   return temp[0];      
*/
