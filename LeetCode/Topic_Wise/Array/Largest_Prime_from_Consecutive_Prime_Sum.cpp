   #define ll long long

    vector<bool>primes = vector<bool>(500006,true);
    bool bl = false;

    void sieve(){
        if(bl) return;
        bl = true;

        primes[0] = primes[1] = false;

        for(int i = 2; i < 500006; i++){
            if(primes[i]){
                for(long long j = 1LL*i*i; j < 500006; j += i){
                    primes[j] = false;
                }
            }
        }
    }

class Solution {
public:
 
    int largestPrime(int n) {
        
        sieve();
       
       ll sum = 0;
       ll maxi = 0;

       for(int i = 2; i <= n; i++){
          if(primes[i]) sum += i;
          if(sum > n) return maxi;
          if(primes[sum]) maxi = sum;
       }
    return maxi;
    }
};