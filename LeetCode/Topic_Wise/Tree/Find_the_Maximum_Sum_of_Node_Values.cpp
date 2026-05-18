// class Solution {
// public:
//     long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
//         vector<long long>dp = {0,LLONG_MIN};

//         for(int n : nums){
//             vector<long long>maxcount = {n+dp[0],n+dp[1]};
//             maxcount[1] = max(maxcount[1],dp[0] + (n^k));  //even -> odd parity
//             maxcount[0] = max(maxcount[0],dp[1] + (n^k));  //odd -> even parity
//             dp = maxcount;
//         }
//     return dp[0];
//     }
// };

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        vector<long long>result;

        for(int x : nums){
            sum += x;
            int y = x^k;
            result.push_back(y-x);
        }
        sort(result.begin(),result.end());
        reverse(result.begin(),result.end());
        
        for(int i = 0; i < result.size() - 1; i += 2){ 
            if(result[i] + result[i+1] <= 0) break;
            sum += result[i] + result[i+1];
        }
        return sum;
    }
};