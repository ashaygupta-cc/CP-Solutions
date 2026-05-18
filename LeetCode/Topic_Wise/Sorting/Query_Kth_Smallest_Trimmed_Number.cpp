class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
      
        int n = queries.size();
        vector<int> result;
        
        for(int x = 0; x < n; x++) {
            int k = queries[x][0], trim = queries[x][1];
            vector<pair<string, int>> trimmed_nums;
            
            for(int i = 0; i < nums.size(); i++) {
                trimmed_nums.push_back({nums[i].substr(nums[i].size() - trim), i});
            }
            
            sort(trimmed_nums.begin(), trimmed_nums.end());
            
            result.push_back(trimmed_nums[k - 1].second);
        }
        
        return result;
    }
};
