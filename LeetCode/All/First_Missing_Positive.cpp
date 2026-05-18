class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         int n=nums.size();
         for(int i=0;i<n;i++) {
            if(nums[i]<0) {
                nums[i]=0;
            }
         }
         for(int i=0;i<n;i++) {
            if(nums[i]!=0 && nums[i]!=i+1 && nums[i]<=n) {
                while(nums[i]!=i+1 && nums[i]!=0 && nums[i]<=n) {
                if(nums[i]!=nums[nums[i]-1]){
                     swap(nums[i],nums[nums[i]-1]); 
                     }
                else{
                    break;
                }
              }
            }
         }
         int i=0;
         
         while( i<n && nums[i]==i+1) {
            i++;
         }
        return i+1;
    }
};
