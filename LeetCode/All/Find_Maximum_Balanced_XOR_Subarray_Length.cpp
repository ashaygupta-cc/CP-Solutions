class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>prefixXOR(n+1,0);
        vector<pair<int,int>>EveOddi(n+1,{0,0});
        int maxi = 0;

        unordered_map<long long,int> visited;

        for(int i = 0; i < n; i++){
            prefixXOR[i+1] = prefixXOR[i] ^ nums[i];

            if(nums[i] & 1){
                EveOddi[i+1].second = EveOddi[i].second + 1;
                EveOddi[i+1].first = EveOddi[i].first;
            }
            else{
                EveOddi[i+1].second = EveOddi[i].second;
                EveOddi[i+1].first = EveOddi[i].first + 1;
            }
        }

        for(int i = 0; i <= n; i++){
            
            int diff = EveOddi[i].second-EveOddi[i].first;
            long long key = ((long long)prefixXOR[i] << 32) ^ (diff+200000);

            if(visited.find(key) != visited.end()){
                maxi = max(maxi,i-visited[key]);
            }
            else{
                visited[key] = i; 
            }
        }

        return maxi;
    }
};
