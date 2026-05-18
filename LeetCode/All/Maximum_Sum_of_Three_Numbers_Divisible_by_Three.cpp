class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> rem;

        for(int i = 0; i < n; i++){
            rem[nums[i] % 3].push_back(nums[i]);
        }

        int maxi = INT_MIN;

        vector<int> sumcheck;
        for(auto &it : rem){
            auto &b = it.second;
            sort(b.rbegin(), b.rend());
            int x = b.size();
            if(x >= 3){
                maxi = max(b[0] + b[1] + b[2],maxi);
            }
            if(x) sumcheck.push_back(b[0]);
        }

        if(sumcheck.size() == 3){
            maxi = max(maxi, sumcheck[0] + sumcheck[1] + sumcheck[2]);
        }

    return (maxi != INT_MIN)? maxi : 0;
    }
};