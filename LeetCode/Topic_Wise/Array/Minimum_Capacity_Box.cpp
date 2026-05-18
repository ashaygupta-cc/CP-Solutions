class Solution {
public:
    typedef long long ll;
    int minimumIndex(vector<int>& capacity, int itemSize) {

    ll mini = LLONG_MAX;
    ll idx = -1;
        
      for(int i = 0; i < capacity.size(); i++){
          if(capacity[i] >= itemSize){
            if(capacity[i] < mini){
                mini = capacity[i];
                idx = i;
            }   
          }
      }
        
      return (idx != -1) ? idx : -1;
    }
};