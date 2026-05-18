class Solution {
public:
    typedef long long ll;

    ll solve(ll l,ll r,vector<ll>&pref,ll flatCost,ll encCost){

            ll len = r-l+1;
            ll ones = pref[r+1]-pref[l];

            ll cost = 0;

            if(!ones) cost = flatCost;
            else cost = len*ones*encCost;

            if(len % 2 == 0){
                ll mid = l+(r-l)/2;
                cost = min(cost,solve(l,mid,pref,flatCost,encCost)+solve(mid+1,r,pref,flatCost,encCost));
            }
            return cost;
        };
    

    long long minCost(string s, int encCost, int flatCost) {

        ll n = s.size();

        vector<ll>pref(n+1,0);

        for(int i = 0; i < n; i++){
            pref[i+1] = pref[i]+(s[i] == '1');
        }
     
        return solve(0,n-1,pref,flatCost,encCost);
    }
};