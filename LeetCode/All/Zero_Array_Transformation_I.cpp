class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>count(n,0);

        for(auto& query : queries){
            int l = query[0];
            int r = query[1];
            count[l]++;
            if(r < n-1) count[r+1]--;
        }

        for(int i = 1; i < n; i++){
            count[i] += count[i-1];
        }

    for(int i = 0; i < n; i++){
        if(count[i] < nums[i]) return false;
    }
    return true;     
    }
};
