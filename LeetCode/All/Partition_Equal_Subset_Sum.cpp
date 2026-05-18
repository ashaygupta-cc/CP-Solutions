class Solution {
public:
    bool canPartition(vector<int>& nums){
   
   // The below code has SpaceComplexity O(N*target);
         int n = nums.size();
int sum = accumulate(nums.begin(),nums.end(),0);
      
     if(sum % 2) return false;
     else{
          int target = sum/2;
  vector<vector<bool>>dp(n,vector<bool>(target+1,0));

    for(int i = 0; i < n; i++) dp[i][0] = true; //At any index target is 0
       if(nums[0] <= target) dp[0][nums[0]] = true; //Index 0 this can be achieved.
      
       for(int i = 1; i < n; i++){
      for(int j = 1; j <= target; j++){
            bool nontake = dp[i-1][j]; //Not taken then index i-1 same target
            bool take = false;   
        if(nums[i] <= j) take = dp[i-1][j-nums[i]]; //Taken index i-1 with target (target-nums[i]);
            dp[i][j] = take|nontake;
          }
        }
         return dp[n-1][target];
      }
    }
};


/*
  // The below code has SpaceComplexity O(N);     
        int n = nums.size();
 int sum = accumulate(nums.begin(),nums.end(),0);
      
    if(sum % 2) return false;
    else{
        int target = sum/2;
           
        vector<bool>temp(target+1,0);
            temp[0] = true;
    if(target >= nums[0]) temp[nums[0]] = true;

        for(int i = 1; i < n; i++){
          vector<bool>cur(target+1,0);
            cur[0] = true;
        for(int j =1; j <= target ; j++){
           bool nontake = temp[j];
           bool take = false;
    if(nums[i] <= j) take = temp[j-nums[i]];
         cur[j] = take|nontake;
        }
        temp = cur;
     }
    return temp[target];
    }
*/
  