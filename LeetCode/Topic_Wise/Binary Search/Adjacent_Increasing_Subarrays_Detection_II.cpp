#define ll long long
class Solution {
 public:
    int maxIncreasingSubarrays(vector<int>& nums){
        int n = nums.size();
        int up = 1,preUp = 0,res = 0;
        
        for(int i = 1; i < n; i++){
        if(nums[i] > nums[i-1]){
                up++;
            } 
        else{
                preUp = up;
                up = 1;
            }           
        int half = up/2;
        int mini = min(preUp,up);
            
    if(max(mini,half) > res) res = max(mini,half);
          }
        return res;
    }
};