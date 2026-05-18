class Solution {
public:
    #define ll long long

    ll dp[16][2][2][12][12][137];
    
    bool isGood(int n){
        if(n < 10) return true;
        string s = to_string(n);
        bool inc = true,dec = true;
        for(int i = 1; i < s.size(); i++){
            if(s[i] <= s[i-1]) inc = false;
            if(s[i] >= s[i-1]) dec = false;
        }
        return inc || dec;
    }

    ll solve(int idx,int tight,int valid,int prevI,int prevD,int sum,string &s){

        if(idx == s.size()){
            if(!valid) return 0;

            if(prevI != 11 || prevD != 11 || isGood(sum)) return 1;
            return 0;
        }

        if(dp[idx][tight][valid][prevI][prevD][sum] != -1)
            return dp[idx][tight][valid][prevI][prevD][sum];

        int limit = tight ? s[idx]-'0' : 9;
        ll ans = 0;

        for(int d = 0; d <= limit; d++){

            int newtight = tight && (d == limit);

            if(!valid && d == 0){

                ans += solve(idx+1,newtight,0,11,11,0,s);
            }
            else{

            int newI = 11,newD = 11;

                if(!valid){
                    newI = d;
                    newD = d;
                }
                else{
                    if(prevI != 11 && d > prevI) newI = d;
                    if(prevD != 11 && d < prevD) newD = d;
                }

                ans += solve(idx+1,newtight,1,newI,newD,sum+d,s);
            }
        }

        return dp[idx][tight][valid][prevI][prevD][sum] = ans;
    }

    long long countFancy(long long l, long long r){

        string R = to_string(r);

        memset(dp,-1,sizeof(dp));
        ll right = solve(0,1,0,11,11,0,R);

        string L = to_string(l-1);

        memset(dp,-1,sizeof(dp));
        ll left = solve(0,1,0,11,11,0,L);

        return right-left;
    }
};