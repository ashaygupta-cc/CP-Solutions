class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        int n = s.length();
        
        unordered_map<char, pair<int, int>> freq;
        
        for (int i = 0; i < n; i++) {
            if (freq.find(s[i]) == freq.end()) {
                freq[s[i]].first = i;
            }
            freq[s[i]].second = i;
        }
        
        for (auto& [ch, pos] : freq) {
            int l = pos.first;
            int r = pos.second;
            
            if(r - l <= 1){
              continue; 
            }
            
            unordered_set<char> uniqueChars;
            for (int i = l + 1; i < r; i++) {
                uniqueChars.insert(s[i]);
            }
            
            ans += uniqueChars.size();  
        }
        
        return ans;
    }
};