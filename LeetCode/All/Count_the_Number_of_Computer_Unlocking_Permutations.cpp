class Solution {
public:
    const long long MOD = 1e9+7;

    int countPermutations(vector<int>& c) {
        int n = c.size();

        vector<int> a = c;
        sort(a.begin(), a.end());

        if (a[0] != c[0]) return 0; 
        if(n > 1&& a[0] == a[1]) return 0;
        long long ways = 1;
        long long unlocked = 1;  

        int i = 1;
        while(i < n){
            int j = i;
            while(j < n && a[i] == a[j]) j++;

            int m = j-i; 

            for(int k = 0; k < m; k++){
                ways = (ways*unlocked) % MOD;
                unlocked++;
            }
            i = j;
        }
        return ways;
    }
};
