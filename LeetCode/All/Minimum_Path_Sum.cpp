class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
         // The below solution has Space Complexity M*N;     
      int m = grid.size();
      int n = grid[0].size(); 
      vector<vector<int>>dp(m,vector<int>(n,0));
         
     for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
          
         if(i == m-1 && j == n-1) dp[i][j] = grid[i][j];          
     else{
            int left = 1e8,up = 1e8;
         if(j+1 < n) left = dp[i][j+1]+grid[i][j];
         if(i+1 < m) up = dp[i+1][j]+grid[i][j];
            dp[i][j] = min(left,up);
     }
        }
    }
   return dp[0][0];
    }
};

/*
   // The below solution has Space Complexity N;
       int m = grid.size();
      int n = grid[0].size();     
         vector<int>temp(n,0);
    
     for(int i = m-1; i >= 0; i--){
          vector<int>cur(n,0);
        for(int k = n-1; k >= 0; k--){
            cur[k] = grid[i][k];
        }
     
      for(int j = n-1; j >= 0; j--){      
     if(i == m-1 && j == n-1) cur[j] = grid[i][j];  
     else{
            int left = 1e8,up = 1e8;
         if(j+1 < n) left = cur[j+1]+grid[i][j];
         if(i+1 < m) up = temp[j]+grid[i][j];
            cur[j] = min(left,up);
        }
      }
        temp = cur;
    }
   return temp[0];     
*/
 