class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        
        for(int i = 0; i < n; i++) {
            unordered_map<int, int> frequency;
            for(int j = 0; j < n; j++) {
                frequency[matrix[i][j]]++;
            }
              if(frequency.size() != n) {
                    return false;
                }
            }       

        
        for(int i = 0; i < n; i++) {
            unordered_map<int, int> frequency;
            for(int j = 0; j < n; j++) {
                frequency[matrix[j][i]]++;
            }
             if(frequency.size() != n) {
                    return false;
                }         
            }

        return true; 
    }
};
