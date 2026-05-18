class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int ans = numBottles;
       int fullBottles = 0;
       int emptyBottles = numBottles;

       while(emptyBottles >= numExchange || fullBottles != 0){
          if(fullBottles){
            ans += fullBottles;
            emptyBottles += fullBottles;
            fullBottles = 0;
          }

          if(emptyBottles >= numExchange){
             fullBottles += (emptyBottles/numExchange);
             emptyBottles = (emptyBottles % numExchange);
          }
       } 
       return ans;
    }
};