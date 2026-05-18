class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        
        sort(power.begin(),power.end());
        int n = power.size();

        unordered_map<long long,int>freq;
        
        for(int i = 0; i < n; i++){
           freq[power[i]]++;
        }
        vector<long long>uniquePowers;
        for(auto &p : freq) uniquePowers.push_back(p.first);
        sort(uniquePowers.begin(),uniquePowers.end());

        int m = uniquePowers.size();
        vector<long long>dp(m,0);

        dp[0] = uniquePowers[0]*freq[uniquePowers[0]];
        
         for (int i = 1; i < m; i++) {
            long long currDamage = uniquePowers[i]*freq[uniquePowers[i]];
            int j = i-1;
            while (j >= 0 && uniquePowers[j] >= uniquePowers[i]-2) j--;
            if (j >= 0)
                dp[i] = max(dp[i-1],dp[j]+currDamage);
            else
                dp[i] = max(dp[i-1],currDamage);
        }
        return dp[m-1];
    }
};