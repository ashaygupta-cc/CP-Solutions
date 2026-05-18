class Solution {
public:
    const long long MOD = 1000000007LL;
    int numSub(string s) {

       int n = s.size();
       long long count = 0,ans = 0;

    for(int i = 0; i < n; i++){
       if(s[i] == '1'){
        count++;
        ans = (ans+count) % MOD;
       }
       else count = 0;
    }
    return ans;
    }
};