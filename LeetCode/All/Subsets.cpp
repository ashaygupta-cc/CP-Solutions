class Solution {
public:
    void generate(vector<int>&nums, int idx,vector<int>&cur, vector<vector<int>>&subs){
        if(idx == nums.size()){
            subs.push_back(cur);
            return;
        }
        // Include nums[idx]
    cur.push_back(nums[idx]);
        generate(nums,idx+1,cur,subs);
        
     cur.pop_back(); // Exclude nums[idx]
        generate(nums,idx+1,cur,subs);
    }

    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>>subs;
        vector<int>cur;
        generate(nums,0,cur,subs);
        return subs;
    }
};