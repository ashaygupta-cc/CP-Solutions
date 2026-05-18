class Solution {
public:
    using ll=long long ;
    unordered_map<ll,int>dp;

    ll solve(ll i,ll mask,ll change,int k,string &s){
    
     ll n = s.size();
     if(i == n) return 1;
      
      ll state = (i << 27) | (mask << 1) | (change);

      if(dp.find(state) != dp.end()) return dp[state];

      int val = (s[i]-'a');
      ll newMask = mask | (1 << val);
      ll ans = 0;
      ll maxi = 0;

      ll count = __builtin_popcount(newMask);
      
      if(count > k){
       ans = 1+solve(i+1,1 << val,change,k,s);
       maxi = max(maxi,ans);
      }
      else{
        ans = solve(i+1,newMask,change,k,s);
        maxi = max(maxi,ans);
      }
      
      if(change){
       return dp[state] = maxi;    
      }

      for(int j = 0; j < 26; j++){
        ll newMask = mask | (1 << j);
        ll count = __builtin_popcount(newMask);

       if(count > k){
         maxi = max(maxi,1+solve(i+1,1<<j,1,k,s));
        }
       else{
        maxi = max(maxi,solve(i+1,newMask,1,k,s));
        }
      }
      return dp[state] = maxi;
    }


    int maxPartitionsAfterOperations(string s, int k) {
    return solve(0,0,0,k,s);
    }
};
