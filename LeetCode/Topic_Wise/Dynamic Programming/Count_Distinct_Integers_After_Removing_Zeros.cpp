class Solution {
public:
    typedef long long ll;

    ll pow9(ll k){
        ll r = 1;
        for(ll i = 0; i < k; i++) r *= 9;
        return r;
    }

    long long countDistinct(long long n){

        ll x = n;
        vector<ll>idxC;
        while(x != 0){
            idxC.push_back(x % 10);
            x /= 10;
        }
        reverse(idxC.begin(), idxC.end());
        ll L = idxC.size();

        for(int i = 0; i < L; i++){
            if(idxC[i] == 0){
                int j = i-1;
                while(j >= 0 && idxC[j] == 1) j--; 
                if(j < 0) return (pow9(L)-9)/8; 
                idxC[j]--;
                for(int k = j+1; k < L; k++) idxC[k] = 9;
                break;
            }
        }

        ll partA = (pow9(L)-9)/8;
        ll partB = 0;

        for(int i = 0; i < L; i++){
            if(idxC[i] == 0) return partA;
    
            else partB += ((idxC[i]-1)*(pow9(L-1-i)));
        }
        partB++;
        return partA+partB;
    }
};