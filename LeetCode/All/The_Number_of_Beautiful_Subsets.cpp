class Solution {
public:
    vector<vector<int>> result;
    int z;
    bool isvalid(vector<int>& temp){
        for(int i=0;i<temp.size();i++){
            for(int j=i+1;j<temp.size();j++){
                if(abs(temp[j] - temp[i]) == z) return false;
            }
        }
        return true;
    }
    void solve(int i,vector<int>& nums,vector<int>& temp){
        if(i >= nums.size()){
            if(isvalid(temp)){
                result.push_back(temp);
                
            }
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,temp);
        temp.pop_back();
        solve(i+1,nums,temp);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        z = k;
        vector<int>temp;
        solve(0,nums,temp);
        return result.size()-1;
    }
};