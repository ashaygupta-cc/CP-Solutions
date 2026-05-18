class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,vector<int>>idx;
        int mini = INT_MAX;

        for(int i = 0; i < n; i++){
            idx[nums[i]].push_back(i);
        }

        for(int i = 0; i < n; i++){
            int x = nums[i];
            int rev = 0;
            int count = 0;

            while(x != 0){
                count++;
                rev = rev*10+(x%10);
                x /= 10;
            }
            if(count == 1) rev = nums[i];

            auto it = upper_bound(idx[rev].begin(),idx[rev].end(),i);     
            if(it != idx[rev].end()) mini = min(mini,(*it)-i);
        }

        return (mini == INT_MAX) ? -1 : mini;
    }
};
