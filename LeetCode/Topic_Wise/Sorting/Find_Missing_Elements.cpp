class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>result;
        
        for(int i = 0; i < n-1; i++){
            for(int j = nums[i]+1; j <= nums[i+1]-1; j++){
                result.push_back(j); 
            }
        }
        return result;
    }
};