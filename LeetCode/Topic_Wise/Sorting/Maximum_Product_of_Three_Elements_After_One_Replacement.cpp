class Solution {
public:
    typedef long long ll;
    long long maxProduct(vector<int>& nums) {

    int n = nums.size();
        
    for(int i = 0; i < n; i++){
        nums[i] = abs(nums[i]);
    }

    sort(nums.begin(),nums.end());

    return (ll)((ll)nums[n-1] * (ll)nums[n-2] * (ll)1e5);
        
    }
};