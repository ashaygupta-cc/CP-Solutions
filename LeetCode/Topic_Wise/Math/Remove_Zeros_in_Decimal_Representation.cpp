class Solution {
public:
    typedef long long ll;
    long long removeZeros(long long n) {
        long long result = 0;

        while(n > 0){
            ll x = n%10;
            if(x) result = (result*10)+x;
            n /= 10;
        }
        string s = to_string(result);
        reverse(s.begin(),s.end());
        result = stoll(s); 
        return result;
    }
};