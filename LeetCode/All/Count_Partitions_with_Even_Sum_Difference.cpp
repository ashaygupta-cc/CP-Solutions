class Solution {
public:
    int countPartitions(vector<int>& nums) {
       int n = nums.size();
       vector<int>prefsum(n,0);
        prefsum[0] = nums[0];
        
        for(int i = 1; i < n; i++){
          prefsum[i] = prefsum[i-1] + nums[i];
        }

        if(prefsum[n-1]%2 == 1) return 0;

        int count = n-1;
        return count;
    }
};