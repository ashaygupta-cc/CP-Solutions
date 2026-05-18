class Solution {
public:
    int minSubarray(vector<int>& nums, int p){
                    
      int n = nums.size();
      int preftot = 0;

    for(int i = 0; i < n ; i++){
        preftot = (preftot+nums[i])%p;
    }

    preftot %= p;
    if(!preftot) return 0;
        
    unordered_map<int,int>idxL;
    int prefcur = 0,ans = n;
    idxL[0] = -1;
        
    for(int i = 0; i < n ; i++){
      
      prefcur = (prefcur+nums[i])%p;
      int searchRem = (prefcur-preftot+p)%p;

      if(idxL.count(searchRem)){
          ans = min(ans,i-idxL[searchRem]);
      }

      idxL[prefcur] = i;  
    }

    return (ans >= n) ? -1 : ans;
        
    }
};