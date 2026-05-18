class Solution {
public:
    typedef long long ll;
    int numberOfBeams(vector<string>& bank) {
     int m = bank.size();
     int n = bank[0].size();
     ll prev = 0,tot = 0;
        
    for(int i = 0; i < m; i++){
      ll one = count(bank[i].begin(),bank[i].end(),'1');
     if(one){
        tot += prev*one;
        prev = one;  
     }
   }
    return tot;
  }
};