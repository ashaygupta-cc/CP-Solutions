class Solution {
public:
    const long long MOD = 1e9+7;
    
    int numberOfWays(string corridor) {

      int n = corridor.size();
      vector<int>idx;
     for(int i = 0; i < n; i++){
         if(corridor[i] == 'S'){
             idx.push_back(i+1);
         }
     }

     int N = idx.size();
     if(N%2 || N < 2) return 0;
     
     long long ways = 1;

     for(int i = 0; i < N-1; i++){
         if(i%2){
             ways = (ways*(idx[i+1]-idx[i])%MOD)%MOD;
         }
     }
        
    return (int)ways;
    }
};