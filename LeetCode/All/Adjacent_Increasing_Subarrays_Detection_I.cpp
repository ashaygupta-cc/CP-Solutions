class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>pref(n,1);
        for(int i  = 1; i < n; i++){
            pref[i] = pref[i-1];
            if(nums[i] > nums[i-1]) pref[i]++;
        }

        for(int i  = 0; i <= n-2*k; i++){
            if((pref[i+k-1]-pref[i] == k-1) && (pref[i+2*k-1]-pref[i+k] == k-1)) return true;
        }
        return false;
    }
};