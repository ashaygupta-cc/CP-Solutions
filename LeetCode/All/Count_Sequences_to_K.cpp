class Solution {
public: 
    #define ll long long
    int n;

    ll rec(ll idx,ll num,ll deno,vector<int>&nums,ll k,map<tuple<ll,ll,ll>,ll>&dp){
          
        if(idx == n){
            ll x = gcd(num,deno);
            deno = deno/x;
            num = num/x;

            if(deno == 1 && num == k) return 1;
            return 0;
        }
        
        if(dp.count({idx,num,deno})) return dp[{idx,num,deno}];
        
        ll count = 0;

        count += rec(idx+1,num,deno,nums,k,dp);
        ll newN = nums[idx]*num;
        ll gcdN = gcd(newN,deno);
        
        count += rec(idx+1,newN/gcdN,deno/gcdN,nums,k,dp);

        if(nums[idx] != 0){
            ll newD = nums[idx]*deno;
            ll gcdC = gcd(num,newD);
            count += rec(idx+1,num/gcdC,newD/gcdC,nums,k,dp);
        }
        return dp[{idx,num,deno}] = count;
    }

    int countSequences(vector<int>& nums, long long k) {
    
     n = nums.size();

     map<tuple<ll,ll,ll>,ll>dp;

     return rec(0,1,1,nums,k,dp);
        
    }
};