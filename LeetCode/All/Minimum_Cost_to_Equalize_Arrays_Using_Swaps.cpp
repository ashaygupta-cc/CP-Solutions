class Solution {
public:
    #define ll long long 

    int minCost(vector<int>& nums1, vector<int>& nums2) {

      ll n = nums1.size();
      ll m = nums2.size();

      if(n != m) return -1;

    unordered_map<ll,ll>f,f1,f2;

     for(ll i = 0; i < n; i++){
         f[nums1[i]]++;
         f[nums2[i]]++; 
         f1[nums1[i]]++;
         f2[nums2[i]]++;
     }

    ll ans = 0;
        
     for(auto [i,ff] : f){
         if(ff &1) return -1;

         ll mini = min(f1[i],f2[i]);

         ff -= (mini*2);
         ans += ff;
     }
      return ans/4;  
    }
};