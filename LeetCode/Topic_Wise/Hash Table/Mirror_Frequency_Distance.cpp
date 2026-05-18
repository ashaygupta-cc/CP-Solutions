class Solution {
public:
    #define ll long long
    
    int mirrorFrequency(string s) {

        vector<ll>num(10,0);
        vector<ll>ch(26,0);

        ll n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] >= '0' && s[i] <= '9') num[s[i]-'0']++;
            else ch[s[i]-'a']++;
        }
        ll count = 0;
        
        for(int i = 0; i <= 4; i++){

            ll mini = min(num[i],num[9-i]);
            num[i] -= mini;
            num[9-i] -= mini;

            count += num[i]+num[9-i];
        }

        for(int i = 0; i <= 12; i++){

            ll mini = min(ch[i],ch[25-i]);
            ch[i] -= mini;
            ch[25-i] -= mini;

            count += ch[i]+ch[25-i];
        }
      return count;  
    }
};