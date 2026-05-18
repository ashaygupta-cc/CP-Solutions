class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {

       int n = bits.size();
       int last = -1 ,sLast = -1;
        
       for(int i = n-1; i >= 0; i--){
           if(bits[i] == 0){
               if(last == -1) last = i;
               else{
                   sLast = i;
                   break;
               }
           }
       }

       if(last == -1) return false;

       if(sLast == -1){
           int cnt = n-1;
           return (cnt & 1) == 0;
       }

       int cnt = last - sLast - 1;
       return (cnt & 1) == 0;
    }
};