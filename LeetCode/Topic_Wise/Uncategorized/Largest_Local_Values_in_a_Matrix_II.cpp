class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int count = 0;

        vector<int>Maxi(n,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                Maxi[i] = max(Maxi[i],matrix[i][j]);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                int num = matrix[i][j];
                if(num == 0) continue;

                bool bl = true;
                int rightBound = min(n-1,i+num);
                int leftBound = max(0,i-num);
                int upBound = max(0,j-num);
                int downBound = min(m-1,j+num);

                for(int k = leftBound; k <= rightBound; k++){
                    if(Maxi[k] <= num) continue;
                    for(int l = upBound; l <= downBound; l++){
                        if(abs(k-i) == num && abs(l-j) == num) continue;
                        if(matrix[k][l] > num){
                            bl = false;
                            break;
                        }
                    }
                    if(!bl) break;
                }
                if(bl) count++;
            }
        }
        return count;
    }
};