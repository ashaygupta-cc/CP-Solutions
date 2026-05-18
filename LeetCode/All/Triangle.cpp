class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
    // The below code has SpaceComplexity O(N*N)
                int n = triangle.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
            for(int j = 0; j < n;j++){
        dp[n-1][j] = triangle[n-1][j];
            }
        
        for(int i = n-2; i >=0; i--){
            for(int j = i; j >= 0; j--){

        int down = triangle[i][j] + dp[i+1][j];
        int diagonal = triangle[i][j] + dp[i+1][j+1];

        dp[i][j] = min(diagonal,down);
            }
        }
    return dp[0][0];
    }
};

/*
  // The below code has SpaceComplexity O(N);
         int n = triangle.size();
    vector<int>temp(n,0);
            for(int j = 0; j < n;j++){
          temp[j] = triangle[n-1][j];
            }      
        for(int i = n-2; i >=0; i--){
              vector<int>cur(n,0);
            for(int j = i; j >= 0; j--){

        int down = triangle[i][j] + temp[j];
        int diagonal = triangle[i][j] + temp[j+1];

        cur[j] = min(diagonal,down);
            }
        temp = cur;
        }
    return temp[0];   
*/
   