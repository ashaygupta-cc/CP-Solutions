class Solution {
public:
    typedef long long ll;
    long long countStableSubarrays(vector<int>& capacity) {
       int n = capacity.size();
        vector<ll>pref(n+1,0);
        unordered_map<ll,unordered_map<ll,int>>seen;
        ll ans = 0;

        for(int i = 0; i < n; i++){
            pref[i+1] += pref[i]+capacity[i];
        }

        for(int i = 0; i < n; i++){
            
            if(i >= 2){
                int l = i-2;
                int valL = capacity[l];
                ll keyL = pref[l]+(ll)valL;
                seen[valL][keyL]++;
            }
            
            int r = i;
            int valR = capacity[r];
            ll target = pref[r]-(ll)valR;
            
            if(seen.count(valR)){
                if(seen[valR].count(target)){
                    ans += seen[valR][target];
                }
            }
        }
        return ans;
    }
};