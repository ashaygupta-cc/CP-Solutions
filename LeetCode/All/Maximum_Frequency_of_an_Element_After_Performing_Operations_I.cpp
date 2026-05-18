class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
       
       vector<int>pref(1e5+1,0);

       for(auto a : nums){
        pref[a]++;
       }

       for(int i = 1 ; i < 1e5+1; i++){
          pref[i] += pref[i-1];
       }
           int maxi= 0;
       for(int i = 1; i < 1e5+1; i++){
          int x = pref[min(100000,i+k)];
          if(i > k) x -= pref[i-k-1];
          int y = pref[i]-pref[i-1]; // Already there!

          maxi = max(maxi,y+min(x-y,numOperations));
       }
    return maxi;
    }
};