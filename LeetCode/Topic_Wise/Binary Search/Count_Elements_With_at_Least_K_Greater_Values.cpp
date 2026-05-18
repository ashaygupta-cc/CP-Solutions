class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        
        int count = 0;
        int n = nums.size();

        sort(nums.begin(),nums.end());
        if(k == 0) return n;

        for(int i = 0; i < n; i++){
            auto it = upper_bound(nums.begin(),nums.end(),nums[i]);
           if(it != nums.end() && (nums.end()-it) >= k) count++;
        }
        return count;
    }
};