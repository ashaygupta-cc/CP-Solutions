#define ll long long
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();    
        ll add = 0,sub = 0;

        for(int i = 0; i < n; i++){
          if((operations[i][0] == '+') || (operations[i].back() == '+')) add++;
          else sub++;
        }

        return add-sub;
    }
};