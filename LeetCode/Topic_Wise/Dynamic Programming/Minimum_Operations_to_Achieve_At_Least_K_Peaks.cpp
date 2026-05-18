class Solution {
public:
    #define ll long long  
    vector<vector<ll>>dp;

    ll cost(int i,vector<int>& nums){
    
    ll n = nums.size();

    if(i == 0){     
        ll maxi = max(nums[1], nums[n-1]);
    
    if(nums[0] > maxi) return 0;
    return (maxi-nums[0]+1);
    }

    if(i == n-1){
        ll maxi = max(nums[n-2], nums[0]);
    
    if(nums[n-1] > maxi) return 0;
    return (maxi-nums[n-1]+1);
    }

    ll maxi = max(nums[i-1], nums[i+1]);
    
    if(nums[i] > maxi) return 0;
    return (maxi-nums[i]+1);
}

    ll rec(ll idx,ll count,vector<int>&nums,int k,int n, int limit){

        if(count >= k) return 0;
        if(idx >= limit) return LLONG_MAX;
        if((limit-idx+1)/2 < (k-count)) return LLONG_MAX;
        
        if(dp[idx][count] != -1)
            return dp[idx][count];

        ll ans = LLONG_MAX;

        ans = min(ans, rec(idx+1,count,nums,k,n,limit));

        ll c = cost(idx,nums);
        ll next = rec(idx+2,count+1,nums,k,n,limit);
        
        if(next != LLONG_MAX)
            ans = min(ans,c+next);

        return dp[idx][count] = ans;
    }
    
    int minOperations(vector<int>& nums, int k){

        ll n = nums.size();
        if(k > n/2) return -1;
        
        dp.assign(n+2,vector<ll>(k+2,-1));
        ll res1 = rec(1,0,nums,k,n,n);

        dp.assign(n+2,vector<ll>(k+2,-1));
        ll res2 = rec(2,1,nums,k,n,n-1);
        if(res2 != LLONG_MAX) res2 += cost(0,nums);

        ll res = min(res1,res2);
        if(res == LLONG_MAX) return -1;
        return res;
    }
};
