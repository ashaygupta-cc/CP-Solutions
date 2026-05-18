class Solution {
public:
    #define ll long long
    
    vector<int> findGoodIntegers(int n) {

    ll r = cbrt(n);
    
        while ((r+1)*(r+1)*(r+1) <= n) r++;
        while (r*r*r > n) r--;
        
        set<ll>s;
        set<int>res;
        
        for(int i = 1; i <= r; i++){
            for(int j = i+1; j <= r; j++){
            ll x = i*i*i*1LL;
            ll y = j*j*j*1LL;

                if((x+y) > n) break;
            if(s.count(x+y)) res.insert(x+y);
            else s.insert(x+y);
            }
        }
       vector<int>ans(res.begin(),res.end());
        
      // sort(ans.begin(),ans.end());
    return ans;       
    }
};