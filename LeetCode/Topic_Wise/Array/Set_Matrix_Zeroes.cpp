class Solution{
public:
    int row,col;
    vector<vector<int>>solve(int i,int j,vector<vector<int>>& matrix){
        for(int idx = 0; idx < row; idx++){
            matrix[idx][j] = 0;
        }
        for(int idx = 0; idx < col; idx++){
            matrix[i][idx] = 0;
        }
        return matrix;
    }
    void setZeroes(vector<vector<int>>& matrix){
        row = matrix.size();
        col = matrix[0].size();
       
        vector<pair<int,int>>zeros;
       
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!matrix[i][j]){
                    zeros.push_back({i,j});
                }
            }
        }
        for(auto& p : zeros){
            solve(p.first,p.second,matrix);
        }
    }
};
