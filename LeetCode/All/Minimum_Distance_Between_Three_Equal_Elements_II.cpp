class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
     unordered_map<int,vector<int>>store;
     int n = nums.size();

    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
       store[nums[i]].push_back(i);
    }

    for(auto &[z,a] : store){
        if(a.size() < 3) continue;
        for(int j = 0; j < a.size()-2; j++){
            ans = min(ans,abs(a[j]-a[j+1])+abs(a[j+1]-a[j+2])+abs(a[j+2]-a[j]));
        }
    }
    if(ans == INT_MAX) return -1;
    return ans;
    }
};
