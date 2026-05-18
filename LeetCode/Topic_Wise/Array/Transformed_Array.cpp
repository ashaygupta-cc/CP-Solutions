class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            int j = (i+nums[i]) % n;
            if(j < 0) j += n;
            res[i] = nums[j];
        }
        return res;
    }
};