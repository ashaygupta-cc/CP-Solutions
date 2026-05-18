class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {     
        long long n = grid[0].size();   
        vector<vector<long long>>PrefixSum(2,vector<long long>(n+1,0));
 
        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= n; j++){
               PrefixSum[i][j] = PrefixSum[i][j - 1] + grid[i][j - 1];
            }
        }

        long long mini = LLONG_MAX;
        for(int i = 1; i <= n; i++){
            long long a = PrefixSum[0][n]-PrefixSum[0][i];
            long long b = PrefixSum[1][i-1];
            mini = min(mini,max(a,b));
        }
        return mini;
    }
};
