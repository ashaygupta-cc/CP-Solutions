class Solution {
public:
    #define ll long long

    ll dp[17][8][10][2];
    vector<ll>pathIdx;
    string dir;

    ll rec(ll idx,ll pathPos,ll lastTaken,bool tight,string &s){

        if(idx == 16){
            return (pathPos == pathIdx.size()) ? 1 : 0;
        }

        if(dp[idx][pathPos][lastTaken][tight] != -1)
            return dp[idx][pathPos][lastTaken][tight];

        ll limit = (tight) ? s[idx]-'0' : 9;
        
        ll count = 0;

        for(int i = 0; i <= limit; i++){

            bool newTight = tight && (i == limit);

            ll newPathPos = pathPos;
            ll newLastTaken = lastTaken;

            if(pathPos < pathIdx.size() && idx == pathIdx[pathPos]){

                if(pathPos > 0){
                    if(i < lastTaken) continue;
                }

                newLastTaken = i;
                newPathPos++;
            }

            count += rec(idx+1,newPathPos,newLastTaken,newTight,s);
        }

        return dp[idx][pathPos][lastTaken][tight] = count;
    }

    long long countGoodIntegersOnPath(long long l,long long r,string directions){

        dir = directions;

        ll idx = 0;
        pathIdx.clear();
        pathIdx.push_back(idx);

        for(char d : directions){
            if(d == 'D') idx += 4;
            else idx += 1;
            pathIdx.push_back(idx);
        }

        string L = to_string(l-1);
        ll rem = 16 - L.size();
        L = string(rem,'0') + L;

        memset(dp,-1,sizeof(dp));
        ll LL = rec(0,0,0,1,L);

        string R = to_string(r);
        rem = 16 - R.size();
        R = string(rem,'0') + R;

        memset(dp,-1,sizeof(dp));
        ll RR = rec(0,0,0,1,R);

        return RR - LL;
    }
};