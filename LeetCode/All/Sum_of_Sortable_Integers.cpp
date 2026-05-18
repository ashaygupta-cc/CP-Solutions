class Solution {
public:
    #define ll long long

   bool check(int k,int n,vector<int>&nums){

       int mini = LLONG_MIN;
       
    for(int i = 0; i < n; i += k){

        if(nums[i] < mini) return 0;

        int maxi = nums[i];
        bool rev = false; // As 1 time rev, 2 times one must be swapped and swap is not allowed!

       for(int j = i+1; j < i+k; j++){

          if(nums[j] < mini) return 0;

          if(nums[j-1] > nums[j]){
              if(rev) return 0;
              rev = true;
          }
          maxi = max(maxi,nums[j]);
       }

      if(rev){
          if(nums[i] < nums[i+k-1]) return false;
      }
        mini = maxi;
    }  
     return true;  
   }

    
    int sortableIntegers(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;
        
        for(int i = 1; i <= n; i++){
           if(n%i) continue;
           if(check(i,n,nums)) ans += i;
        }    
    return ans;    
    }
};