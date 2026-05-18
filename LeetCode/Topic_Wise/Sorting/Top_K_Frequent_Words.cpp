class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> strCount;
        vector<string> result;

        for (const string& word : words) {
            strCount[word]++;
        }

        vector<pair<string, int>> wordFreq(strCount.begin(), strCount.end());
        sort(wordFreq.begin(), wordFreq.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            
            if (a.second == b.second) {
                return a.first < b.first; 
            }
            return a.second > b.second; 
        });

        for (int i = 0; i < k; i++) {
            result.push_back(wordFreq[i].first);
        }

        return result;
    }
};
