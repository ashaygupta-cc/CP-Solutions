class Solution {
public:
    #define ll long long
    
    long long minOperations(vector<int>& nums) {

     int n = nums.size();
     int mini = nums[0];
     int cur = nums[0];
     ll tot = 0;

    for(int i = 1; i < n; i++){
        if(nums[i] < nums[i-1]){
           mini = min(mini,nums[i]);
        }
        else{
           tot += (cur-mini);
           mini = nums[i];
           cur = nums[i];
        }
    }
        tot += (cur-mini);
        
     return tot;   
    }
};