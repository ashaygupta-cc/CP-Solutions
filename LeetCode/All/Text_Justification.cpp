class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        
        while (i < words.size()) {
            int words_count = words[i].size();
            int j = i + 1;
            while (j < words.size() && words_count + words[j].size() + (j - i - 1) < maxWidth) {
                words_count += words[j].size();
                j++;
            }
            
            int spaces = maxWidth - words_count;
            int num_words = j - i;
            
            string line = words[i];
            
            if (j == words.size() || num_words == 1) {
                for (int k = i + 1; k < j; k++) {
                    line += " " + words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            }
            
            else {
                int spaces_per_gap = spaces / (num_words - 1);
                int extra_spaces = spaces % (num_words - 1);
                
                for (int k = i + 1; k < j; k++) {
                    line += string(spaces_per_gap + (k - i <= extra_spaces ? 1 : 0), ' ') + words[k];
                }
            }
            
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};
