class Solution {
public:
    typedef long long ll;
    int smallestBalancedIndex(vector<int>& nums) {

      ll n = nums.size();
      vector<double>prefsum(n+1,0),sufmul(n+1,1);
      for(int i = 0; i < n; i++){
          prefsum[i+1] = prefsum[i]+nums[i];
      }
      for(int i = n-1; i >= 0; i--){
          sufmul[i] = (double)sufmul[i+1]*nums[i];
      }

     for(int i = 0; i < n; i++){
         if(prefsum[i] == sufmul[i+1]) return i;
     }
    return -1;
    }
};