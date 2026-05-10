class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

      int n = nums.size();
      vector<int>prefMax(n,LLONG_MIN),SuffMin(n,LLONG_MAX);

     prefMax[0] = nums[0];
     SuffMin[n-1] = nums[n-1];
        
     for(int i = 1; i < n; i++){
         prefMax[i] = max(nums[i],prefMax[i-1]);
     }

     for(int i = n-2; i >= 0; i--){
         SuffMin[i] = min(nums[i],SuffMin[i+1]);
    }

    for(int i = 0; i < n; i++){
        if(prefMax[i]-SuffMin[i] <= k) return i;
    }
    return -1;   
    }
};