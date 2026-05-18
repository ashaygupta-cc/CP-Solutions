class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int>result;
        for(int i = 0 ; i < n ; i++){
            if (count(words[i].begin(),words[i].end(),x)) result.push_back(i);
        }
        return result;
    }
};