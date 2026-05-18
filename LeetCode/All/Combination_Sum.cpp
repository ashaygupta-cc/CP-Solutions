class Solution {
public:
    void check(vector<vector<int>>&res,vector<int>&combi,vector<int>&candidates,int target,int start){
        if(target == 0){
            res.push_back(combi);
            return;
        }
        
    for(int i = start; i < candidates.size(); i++){
    
 if(candidates[i] <= target){

 combi.push_back(candidates[i]);     

check(res,combi,candidates,target-candidates[i],i);
        combi.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,int target){
        vector<vector<int>>res;
        vector<int>combi;
        check(res,combi,candidates,target,0);
        return res;
    }
};