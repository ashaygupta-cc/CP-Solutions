class Solution {
public:
    long long lastInteger(long long n) {
        long long first = 1,len = n,gap = 1;
        while(len > 1){
            if(len > 1){
                len = (len+1)/2;
                gap *= 2;   
            }
            if(len > 1){
                if(len % 2 == 0) first += gap;
                len = (len+1)/2;
                gap *= 2;   
            }
        }
        return first;
    }
};