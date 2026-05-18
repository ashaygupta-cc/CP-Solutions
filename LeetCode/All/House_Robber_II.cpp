class Solution{
private:
 int val(vector<int>&temp){
   
  int n = temp.size();
  int prev = temp[0];
  int prev2 = 0;

for(int i = 0; i < n; i++){
    int take = temp[i];
    if(i>1) take += prev2;
    int nontake = prev;

 int cur = max(take,nontake);
        prev2 = prev;
         prev = cur;
}
  return prev;
 }

public:
    int rob(vector<int>& nums){
      // The below code has Space Complexity O(1);
            int n = nums.size();
                if(n == 0)return 0;
                if(n == 1)return nums[0];
            vector<int>temp1,temp2;

            for(int i = 0; i < n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]); 
            }
            return max(val(temp1),val(temp2));
    }
};

/*
  // The code has Space Complexity O(N);
     
        int n = nums.size();
        if(n == 0)return 0;
        if(n == 1)return nums[0];
       vector<int>temp1,temp2;

    for(int i = 0; i < n; i++){
       if(i != 0) temp1.push_back(nums[i]);
       if(i != n-1) temp2.push_back(nums[i]); 
    }
    return max(val(temp1),val(temp2));
 int val(vector<int>&temp){
     int n = temp.size();
      vector<int>dp(n,-1);
         dp[0]= temp[0];
    for(int i = 1; i < n; i++){
      
        int take = temp[i];
      if(i > 1) take += dp[i-2];    
        int nontake = dp[i-1];  

       dp[i] = max(take,nontake);    
    }
        return dp[n-1];
 }
 */