class Solution{
public:
    int minFallingPathSum(vector<vector<int>>& matrix){

    // The below code has SpaceComplexity O(N*N);  
         int n = matrix.size();
    vector<vector<int>>dp(n,vector<int>(n,0));

      for(int i = 0; i < n; i++){
       dp[n-1][i] = matrix[n-1][i];
      }

    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j < n; j++){
     int up = dp[i+1][j] + matrix[i][j];
     int diagpost = matrix[i][j];
            if(j-1 >= 0) diagpost +=  dp[i+1][j-1];
            else diagpost += 1e8;
     int diagpre = matrix[i][j];
            if(j+1 <= n-1) diagpre += dp[i+1][j+1];
            else diagpre += 1e8;

        dp[i][j] = min(up,min(diagpost,diagpre));
        }
      }
        int mini = dp[0][0];
    for(int i = 1; i < n; i++){
      mini = min(dp[0][i],mini);
    }
    return mini;
    }
};

/*
   // The below code has SpaceComplexity O(N);    
          int n = matrix.size();
            vector<int>temp(n,0);
    
        for(int i = 0; i < n; i++){
            temp[i] = matrix[n-1][i];
        }
    
      for(int i = n-2; i >= 0; i--){
        vector<int>cur(n,0);
        for(int j = 0; j < n; j++){
    int up = temp[j] + matrix[i][j];
    int diagpost = matrix[i][j];
            if(j-1 >= 0) diagpost +=  temp[j-1];
            else diagpost += 1e8;
    int diagpre = matrix[i][j];
            if(j+1 <= n-1) diagpre += temp[j+1];
            else diagpre += 1e8;

        cur[j] = min(up,min(diagpost,diagpre));
        }
     temp = cur;
    }

            int mini = temp[0];
            for(int i = 1; i < n; i++){
            mini = min(mini,temp[i]);
                }
  return mini; 
*/
 

/* 
    // The below code is a recursive TLE solution

int f(int i,int j, vector<vector<int>> &matrix,vector<vector<int>> &dp){

   if(j < 0 || j >= matrix.size()) return 1e8;
   if(i == 0) return matrix[0][j];
       if(dp[i][j] != -1) return dp[i][j];

   int up = matrix[i][j] + f(i-1,j,matrix,dp);
   int diagonalpre = matrix[i][j] + f(i-1,j-1,matrix,dp);
   int diagonalpost = matrix[i][j] + f(i-1,j+1,matrix,dp);

   return min(up,min(diagonalpre,diagonalpost));
}
    int minFallingPathSum(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
  vector<vector<int>> dp(n,vector<int>(m,-1));
    int mini = 1e8;

    for(int j = 0; j < n; j++){
      mini = min(mini,f(n-1,j,matrix,dp));
    }

return mini; 
*/   