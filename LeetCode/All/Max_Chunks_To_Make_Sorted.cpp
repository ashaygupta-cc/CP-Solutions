class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
      int maxi = -1,count = 0;

    for(int i = 0; i < n; i++){      
       maxi = max(maxi,arr[i]);
       if(maxi <= i){
         continue;
       }
       else{
         count++;
       }
    }   
    return n-count;
    }
};