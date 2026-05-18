class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }

        int ans = 0;
        long long prev = 0;
        for(int i=0; i<nums.size()-1; i++){
            prev += nums[i];
            sum -= nums[i];
            if(prev >= sum){
                ans++;
            }
        }

        return ans;
    }
};