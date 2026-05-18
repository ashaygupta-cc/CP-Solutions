class Solution {
public:
    #define ll long long
    
    ll dp[16][16][2][2][300];

    ll rec(ll idx,ll pos,ll diff,bool validNum,bool tight,string &s){
        
        if(idx == s.size()){
            return (validNum && pos >= 2 && diff == 0);
        }

        if(dp[idx][pos][validNum][tight][diff+150] != -1) 
            return dp[idx][pos][validNum][tight][diff+150];

        ll count = 0;
        ll limit = (tight) ? (s[idx]-'0') : 9;

        for(int i = 0; i <= limit; i++){
            
            bool newValid = validNum || (i != 0);
            bool newTight = tight && (i == limit);

            ll newPos = pos;
            ll newDiff = diff;

            if(newValid){
                if(pos % 2 == 0) newDiff += i;   
                else newDiff -= i;  
                newPos++;
            }

            count += rec(idx+1, newPos,newDiff,newValid,newTight,s);
        }

        return dp[idx][pos][validNum][tight][diff+150] = count;
    }

    long long countBalanced(long long low, long long high){

        memset(dp,-1,sizeof(dp));
        string h = to_string(high);
        ll right = rec(0,0,0,false,true,h);

        memset(dp,-1,sizeof(dp));
        string l = to_string(low-1);
        ll left = rec(0,0,0,false,true,l);

        return right-left;
    }
};