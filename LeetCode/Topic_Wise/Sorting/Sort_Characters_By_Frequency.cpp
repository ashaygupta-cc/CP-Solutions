class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> charCount;

        for (const char& ch : s) {
            charCount[ch]++;
        }

        vector<pair<char, int>> charFreq(charCount.begin(), charCount.end());

        sort(charFreq.begin(), charFreq.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first; 
            }
            return a.second > b.second;  
        });

            string result;
        for (const auto& p : charFreq) {
            result.append(p.second, p.first); 
        }

        return result;
    }
};
