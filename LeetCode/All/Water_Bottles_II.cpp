class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptyBottles = numBottles;
        int fullBottles = 0;
        while(emptyBottles >= numExchange || fullBottles != 0){
            if(fullBottles){
                emptyBottles += fullBottles;
                ans += fullBottles;
                fullBottles = 0;
            }

            if(emptyBottles >= numExchange){
                emptyBottles -= numExchange;
                fullBottles++;
                numExchange++;
            }
        }
        return ans;
    }
};