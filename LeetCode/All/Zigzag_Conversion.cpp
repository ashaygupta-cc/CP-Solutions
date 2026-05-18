class Solution {
public:

    string convert(const string& s, int numRows) {

    if (numRows == 1 || numRows >= s.length()) {
        return s;
    }
    
  vector<vector<char>> matrix(numRows, vector<char>(s.length(), '0'));

    int row = 0, col = 0;
    bool directionDown = true; 

    for(char c : s) {
        matrix[row][col] = c;

        if (directionDown) {
            if (row == numRows - 1) {
                directionDown = false;
                row--;
                col++;
            }
            else {
                row++;
            }
        } 
        else {
            if (row == 0) {
                directionDown = true;
                row++;
            }
            else {
                row--;
                col++;
            }
        }
    }

    string result;
    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < s.length(); c++) {
            if (matrix[r][c] != '0') {
                result += matrix[r][c];
            }
        }
    }

    return result;
}

};