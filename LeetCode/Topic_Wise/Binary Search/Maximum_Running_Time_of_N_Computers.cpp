class Solution {
public:
    typedef long long ll;
    long long maxRunTime(int n, vector<int>& batteries) {
        
        ll tot = 0;
        
         for(auto b : batteries){
            tot += b;
         }

        tot /= n;
        sort(batteries.begin(),batteries.end());
        ll l = batteries[0],r = tot,ans = 0;
        
        while(l <= r){
           ll mid = l+(r-l)/2;
           ll calc = 0;

           for(auto b : batteries){
              if(b <= mid) calc += b;
              else calc += mid;
           }

           if(calc >= n*mid){
              ans = mid;
              l = mid+1;
           }
           else r = mid-1;
        }
        return ans;
    }
};