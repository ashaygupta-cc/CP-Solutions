class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) {
            return result;
        }

        int wordLength = words[0].size();
        int numWords = words.size();
        int totalLength = wordLength * numWords;

        if (s.size() < totalLength) {
            return result;
        }

        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        for (int i = 0; i < wordLength; i++) {
            unordered_map<string, int> seen;
            int left = i, right = i, count = 0;

            while (right + wordLength <= s.size()) {
                string word = s.substr(right, wordLength);
                right += wordLength;

                if (wordCount.find(word) != wordCount.end()) {
                    seen[word]++;
                    count++;

                    while (seen[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLength);
                        seen[leftWord]--;
                        left += wordLength;
                        count--;
                    }

                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
