class Solution {
public:
    int longestBalanced(vector<int>& nums) {
       int n = nums.size();
        int maxi = 0;
        
    for(int i = 0; i < n; i++){
      unordered_map<int,int>even,odd;
     for(int j = i; j < n; j++){
     if(nums[j] & 1)odd[nums[j]]++;
    else even[nums[j]]++;
      
        if(!even.empty() && (even.size() == odd.size())){
        maxi = max(maxi,j-i+1);
      }
      }
    }
   return maxi;   
    }
};