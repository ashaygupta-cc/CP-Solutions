class Solution {
public:
    bool isBalanced(string num) {
        int t = num.length();
        int sum_even = 0, sum_odd = 0;

    for(int i = 0; i < t; i++){
      
      if(i%2 == 0){
        sum_even += num[i]-'0';
      }
      
      if(i%2 != 0){
        sum_odd += num[i]-'0';
      }
        }
      
      if(sum_even == sum_odd){
        return true;
      }

      else{
        return false;
      }
    }
};