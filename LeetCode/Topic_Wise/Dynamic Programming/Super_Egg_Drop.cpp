class Solution {
public:
    typedef long long ll;
    
    ll get(int k,int n){
      if(n == 0|| n == 1) return n;
      if(k == 1) return n;

      vector<vector<int>>dp(k+1,vector<int>(n+1,0));

      for(int i = 0; i <=k; i++){
        dp[i][0] = 0;
        dp[i][1] = 1;
      }

      for(int i = 0; i <= n; i++){
        dp[0][i] = 0;
        dp[1][i] = i;
      }

      for(int i = 2; i <= k; i++){
        for(int j = 2; j <= n; j++){
            ll l = 1,h = j;
            ll ans = LLONG_MAX,temp = 0;
      
         while(l <= h){
            ll mid = l+(h-l)/2;
            ll left = dp[i-1][mid-1];
            ll right = dp[i][j-mid];
            temp = 1+max(left,right);

            if(left < right) l = mid+1;
            else h = mid-1;
            ans = min(temp,ans);
         }
         dp[i][j] = ans;
        }
      }
        return dp[k][n];
    }

    int superEggDrop(int k,int n){  
    return get(k,n);
    }
};