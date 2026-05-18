class Solution {
public:
    #define ll long long
    const ll mod = 1e9+7;
    
    vector<vector<ll>>store;

    void precompute(){

        store.assign(51,{});
        
      for(int i = 0; i <= 5000; i++){
          ll x = i;
          ll tot = 0;
          while(x){
              tot += (x%10);
              x /= 10;
          }
          store[tot].push_back(i);
      }

      for(int i = 0; i < 51; i++){
          if(store[i].empty()) continue;
                    sort(store[i].begin(),store[i].end());
      }
    }

    int countArrays(vector<int>& digitSum) {

       precompute();
       ll n = digitSum.size();
       vector<vector<ll>>dp(n+1);
        
       if(store[digitSum[0]].empty()) return 0;

       dp[0].assign(store[digitSum[0]].size(),1);

        for(int i = 1; i < n; i++){

            auto &prev = store[digitSum[i-1]];
            auto &cur = store[digitSum[i]];

            if(cur.empty()) return 0;

        vector<ll>pref(prev.size());
          pref[0] = dp[i-1][0];

          for(int j = 1; j < pref.size(); j++){
              pref[j] = (pref[j-1]+dp[i-1][j])%mod;
          }

        dp[i].assign(cur.size(),0);
         for(int j = 0; j < cur.size(); j++){
            auto it = upper_bound(prev.begin(),prev.end(),cur[j])-prev.begin();
             
             if(it) dp[i][j] = pref[it-1];          
         }          
        }

        ll ans = 0;

        for(int i = 0; i < dp[n-1].size(); i++){
            ans = (ans+dp[n-1][i])%mod;
        }
        return ans;
    }
};