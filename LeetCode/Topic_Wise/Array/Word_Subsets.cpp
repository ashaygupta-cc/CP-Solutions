class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
            vector<int> words(27, 0);
            vector<string> result;

        for(int i = 0; i < words2.size(); i++){
            vector<int> words2Freq(27, 0);
           for(int j = 0; j < words2[i].size(); j++){
                words2Freq[words2[i][j] - 'a' + 1]++;
            }
           for(int k = 1; k < 27; k++){
                words[k] = max(words[k], words2Freq[k]);
            }
        }

        for(int i = 0; i < words1.size(); i++){
            vector<int> words3(27, 0);
           for(int j = 0; j < words1[i].size(); j++){
                words3[words1[i][j] - 'a' + 1]++;
            }

            bool bl = true;
           for(int k = 1; k < 27; k++){
                if(words[k] > words3[k]){
                    bl = false;
                    break;
                }
            }
            if(bl){
                result.push_back(words1[i]);
            }
        }

        return result;
    }
};
