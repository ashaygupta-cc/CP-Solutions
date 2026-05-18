class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return 0;
        }

      sort(nums.begin(),nums.end());
        int left = 0,right = 1;
          int maxi = 0;

      while(right < n){

       int checker = abs(nums[right]-nums[left]);

    if(checker > maxi){
        maxi = checker;
    }
        right++;
        left++;
      }
      return maxi;      
        }
};