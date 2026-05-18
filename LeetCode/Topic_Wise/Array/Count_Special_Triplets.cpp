class Solution {
public:
    const int MOD = 1e9+7;
    typedef long long ll;

    int specialTriplets(vector<int>& nums){
        
        unordered_map<long long,int> PrefFreq,SuffFreq;
        int n = nums.size();

        PrefFreq[nums[0]]++;
        for(int i = 1; i < n; i++){
            SuffFreq[nums[i]]++;
        }

        ll ans = 0;

        for(int i = 1; i < n-1; i++){
            
            SuffFreq[nums[i]]--;
            if(SuffFreq[nums[i]] == 0) 
                SuffFreq.erase(nums[i]);

            ll twice = (ll)nums[i]*2; 

            if(PrefFreq[twice] == 0 || SuffFreq[twice] == 0){
                PrefFreq[nums[i]]++;
                continue;
            }

            ll ways = ((ll)PrefFreq[twice]*SuffFreq[twice]) % MOD;
            ans = (ans+ways) % MOD;

            PrefFreq[nums[i]]++;
        }

        return ans;
    }
};
