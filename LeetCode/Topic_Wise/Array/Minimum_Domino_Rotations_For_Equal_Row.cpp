class Solution{
public:
    int check(vector<int>& tops,vector<int>& bottoms,int key){
       int n = tops.size();
       int TopSwap = 0, BottomSwap = 0;

       for(int i = 0; i < n; i++){
        if(tops[i] != key && bottoms[i] != key) return INT_MAX;
        else if(tops[i] != key) TopSwap++;
        else if(bottoms[i] != key) BottomSwap++;
       }
       return min(TopSwap,BottomSwap);
    }

    int minDominoRotations(vector<int>& tops,vector<int>& bottoms){
        int result = INT_MAX;

        for(int i = 1; i <= 6; i++){
            int swaps = check(tops,bottoms,i);
            result = min(result,swaps);
        }      
       return (result == INT_MAX) ? -1 : result;       
    }
};