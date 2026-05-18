class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
           stack<int>check;
          int j = 0;
      for(int i = 0; i < pushed.size(); i++){
          if(check.empty() || check.top() != popped[j]){
             check.push(pushed[i]);
          }
          else if(!check.empty() && check.top() == popped[j]){
                 check.pop();
                 j++;
                 i--;
          }
      }
      while(!check.empty()){
        if(check.top() == popped[j]){
            check.pop();
            j++;
        }
        else return false;
      }
      return true;
    }
};