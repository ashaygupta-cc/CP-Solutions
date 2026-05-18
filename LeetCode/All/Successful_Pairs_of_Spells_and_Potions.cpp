class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int>result(n,0);

        sort(potions.begin(),potions.end());

        for(int i = 0; i < n; i++){
            long long x = (success/spells[i]);
            if(success%spells[i] != 0) x++;
            auto it = lower_bound(potions.begin(),potions.end(),x)-potions.begin();
            result[i] = potions.size()-it;
        }
    return result;
    }
};