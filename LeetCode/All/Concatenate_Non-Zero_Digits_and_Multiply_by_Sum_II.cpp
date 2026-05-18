class Solution {
public:
    const long long MOD = 1e9+7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();
        vector<long long>prefdig(n+1,0),prefsum(n+1,0),nz(n+1,0),pow10(n+1,1);

        for(int i = 1; i <= n; i++){
            pow10[i] = (pow10[i-1]*10) % MOD;
        }

        for(int i = 1; i <= n; i++){
            if(s[i-1] == '0'){
                prefdig[i] = prefdig[i-1];
                prefsum[i] = prefsum[i-1];
                nz[i] = nz[i-1];
            } 
            else{
                int d = s[i-1]-'0';
                prefdig[i] = (prefdig[i-1]*10 +d) % MOD;
                prefsum[i] = prefsum[i-1]+d;
                nz[i] = nz[i-1]+1;
            }
        }

        vector<int>result;

        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];

            int cnt = nz[r+1]-nz[l];

            if(cnt == 0){
                result.push_back(0);
                continue;
            }

            long long left = prefdig[l];
            long long right = prefdig[r+1];

            long long x = (right-(left*pow10[cnt])%MOD +MOD)%MOD;
            long long sum = prefsum[r+1]-prefsum[l];

            result.push_back((x*sum)%MOD);
        }

        return result;
    }
};
