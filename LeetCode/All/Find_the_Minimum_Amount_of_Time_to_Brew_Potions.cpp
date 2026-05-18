class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        
        int n = skill.size();
        int m = mana.size();

       vector<long long>calcMax(n+1,0);

       for(auto &a : mana){
         for(int i = 0; i < n; i++){
            calcMax[i+1] = max(calcMax[i+1],calcMax[i])+(long long)(skill[i]*a);
         }
         for(int i = n-1; i > 0; i--){
              calcMax[i] = calcMax[i+1]-(a*skill[i]);
         }
       }
      return calcMax[n];
    }
};