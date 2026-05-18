class Solution {
public:
    const long long MOD = 1000000007;

    long long modPow(long long b, long long exp){
        long long res = 1;
        while(exp > 0){
            if(exp & 1) res = (res*b) % MOD;
            b = (b * b)%MOD;
            exp >>= 1;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;  
        long long odd = n/2;        
        long long part1 = modPow(5,even);
        long long part2 = modPow(4,odd);
        return (part1 * part2)%MOD;
    }
};