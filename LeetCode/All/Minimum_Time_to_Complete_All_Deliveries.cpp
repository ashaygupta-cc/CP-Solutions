class Solution {
public:
    typedef long long ll;
    ll minimumTime(vector<int>& d, vector<int>& r) {
        ll low = 0, high = 1e12;
        
        auto lcm = [&](ll a,ll b){
            return a / gcd(a,b)*b;
        };
        
        ll L = lcm(r[0],r[1]);
        ll need = (ll)d[0]+d[1];

        auto can = [&](ll t){
            ll d1 = t - t/r[0];
            ll d2 = t - t/r[1];

            if (d1 < d[0] || d2 < d[1]) return false;

            ll available = t-t/L;
            return available >= need;
        };

        while (low < high){
            ll mid = low + (high-low)/2;
            if (can(mid)) high = mid;
            else low = mid+1;
        }
        return low;
    }
};
