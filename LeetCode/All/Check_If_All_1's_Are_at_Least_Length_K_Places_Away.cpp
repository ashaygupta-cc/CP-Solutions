class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int idx = -1,n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                if(idx == -1) idx = i;
                else{
                    if(i-idx-1 < k) return false;
                    idx = i;
                }
            }
        }
        return true;
    }
};