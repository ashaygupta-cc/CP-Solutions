class Solution {
public:
    int hammingDistance(int x, int y) {
        if(x==0 && y == 0) return 0;
        int k = pow(2,(int)((double)((x<y)?log(y):log(x)) / log(2)));

        int count = 0;
        while(k >= 1){
            if((x & k) != (y & k)) count +=1;
            k/=2;
        }

        return count;
    }
};