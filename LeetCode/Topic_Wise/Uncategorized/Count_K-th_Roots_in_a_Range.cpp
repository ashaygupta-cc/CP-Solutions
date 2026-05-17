class Solution {
public:
    #define ll long long 
    
    int countKthRoots(int l, int r, int k) {

    if(k == 1){
        return r-l+1;
    }

    ll count = 0;
    __int128 kk = k,a = -1;
        
    for(ll i = 0; i <= r; i++){
        __int128 res=1;
        kk = k;
        a = i;
        bool bl = true;
        while(kk > 0){
            if(kk & 1){
                res = (res*a);
                if(res > r){
                    bl = false;
                    break;
                }
            }
            kk >>= 1;
            if(kk){
                a = a*a;
                if(a > r) a = r+1;
            }
        }
        if(bl){
           if(res >= l) count++;  
        } 
        else break;
    }
        return count;
    }
};