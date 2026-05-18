class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        
        int n = nums.size();
        const int MOD = 1e9 + 7;
        
        vector<int>dp(n+1,0),prefix(n+1,0);
        
        dp[0] = 1;
        prefix[0] = 1;

        int j = 0;
        multiset<int>m;

        for(int i = 0; i < n; i++){
            m.insert(nums[i]);  

            while(j <= i && !m.empty() && (*(m.rbegin())-*(m.begin())) > k){
                m.erase(m.find(nums[j]));  
                j++;
            }

            int left = (j > 0 ? prefix[j-1] : 0);
            
            dp[i+1] = (((prefix[i]-left) % MOD)+MOD) % MOD;
            prefix[i+1] = (prefix[i]+dp[i+1]) % MOD;
        }

        return dp[n];
    }
};
