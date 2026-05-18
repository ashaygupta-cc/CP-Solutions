class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> requiredFreq;
        for (char c : t) {
            requiredFreq[c]++;
        }

        int left = 0, minLen = INT_MAX, minStart = 0;
        int matchedCount = 0;
        unordered_map<char, int> windowFreq;

        for (int right = 0; right < s.size(); right++) {
            char rightChar = s[right];
            windowFreq[rightChar]++;

            if (requiredFreq.count(rightChar) && windowFreq[rightChar] == requiredFreq[rightChar]) {
                matchedCount++;
            }

            while (matchedCount == requiredFreq.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                if (requiredFreq.count(leftChar) && windowFreq[leftChar] == requiredFreq[leftChar]) {
                    matchedCount--;
                }
                windowFreq[leftChar]--;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};