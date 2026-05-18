class Solution {
public:
    int nthUglyNumber(int n){
        vector<int>t(n+1);
        t[1] = 1; 
        int i2,i3,i5; 
        i2 = i3 = i5 = 1;

        for(int i = 2; i <= n; i++){
            int uglyi2 = t[i2]*2;
            int uglyi3 = t[i3]*3 ;
            int uglyi5 = t[i5]*5;
            t[i] = min({uglyi2,uglyi3,uglyi5});
            if(t[i] == uglyi2) i2++;
            if(t[i] == uglyi3) i3++;
            if(t[i] == uglyi5) i5++;
        }  
        return t[n];
    }
};