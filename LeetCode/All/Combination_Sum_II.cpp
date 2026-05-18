class Solution {
public:
    void check(vector<vector<int>>& res,vector<int>&combi,vector<int>& candidates,int target,int start){
        if(target == 0){
            res.push_back(combi);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            combi.push_back(candidates[i]);
            check(res,combi,candidates,target-candidates[i],i+1);
            combi.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,int target){
        vector<vector<int>>res;
        vector<int>combi;
        sort(candidates.begin(), candidates.end());
        check(res,combi,candidates,target,0);
        return res;
    }
};