class Solution {
public:
    typedef long long ll;

    int minOperations(string s) {

        int n = s.size();

        string f = s;
        string sr = s;

        reverse(sr.begin(),sr.end());
        sort(f.begin(),f.end());

        char st = f[0];
        char e  = f[n-1];

        ll fs = 0, fe = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == st) fs++;
            if(s[i] == e)  fe++;
        }

        if(n == 1) return 0;

        if(n == 2){
            if(f != s) return -1;
            return 0;
        }

        if(s == f) return 0;

        if(s[0] == f[0] || s[n-1] == f[n-1]) return 1;
        
        if(s[0] == f[n-1] && s[n-1] == f[0]){
            if(fs > 1 || fe > 1)
                return 2;
            else
                return 3;
          }
        return 2;
    }
};