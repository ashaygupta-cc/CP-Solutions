class Solution {
    typedef long long ll;

public:
    int nextBeautifulNumber(int n) {
       
       while(n++){
        vector<int>count(10,0);
          int y = n;
        while(y != 0){
            count[y%10]++;
            y /= 10;
        }
        if(count[0]) continue;
        bool bl = true;
        for(int i = 1; i < 10; i++){
             if(count[i] != 0 && count[i] != i){
             bl = false;
             break;
             }
        }
        if(bl) return n;
        }
        return 1;
    }
};