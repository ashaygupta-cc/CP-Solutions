class Solution {
private:
void solve(int col,vector<vector<string>>& result,vector<string>& board,int n){
    if(col == n){
        result.push_back(board);
        return;
    }

for(int row = 0; row < n; row++){
    if(Valid(row,col,board,n)){
       board[row][col] = 'Q';
       solve(col+1,result,board,n);
       board[row][col] = '.';
    }
  }
}

bool Valid(int row,int col,vector<string>board,int n){

    int a = row,b = col;
    while(row >= 0 && col >= 0){  // UPPER-LEFT
        if(board[row--][col--] == 'Q') return false;
    }

    row = a, col = b;
    while(col >= 0){        // STRAIGHT UP
        if(board[row][col--] == 'Q') return false;
    }

    col = b;
    while(row < n && col >= 0){ // UPPER-RIGHT
        if(board[row++][col--] == 'Q') return false;
    }
    return true;
}


public:
    vector<vector<string>>solveNQueens(int n){
        vector<vector<string>>result;
        vector<string>board(n);

        string s(n,'.');  // Assume whole grid empty first

        for(int i = 0; i < n; i++){
            board[i] = s;
        }

    solve(0,result,board,n);
    return result;


    }
};