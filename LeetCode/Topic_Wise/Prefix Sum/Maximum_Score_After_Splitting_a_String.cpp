class Solution {
public:
    int maxScore(string s) {
        int left_zeros = 0, right_ones = 0;
        int max_score = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                right_ones++;
            }
        }

        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == '0') {
                left_zeros++;
            }
             else {
                right_ones--;
            }

            max_score = max(max_score, left_zeros + right_ones);
        }
        
        return max_score;
    }
};
