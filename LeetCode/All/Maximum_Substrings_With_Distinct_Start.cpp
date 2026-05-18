class Solution {
public:
    int maxDistinct(string s) {
        
        int n = s.size();
        unordered_map<char,int>freq;
        int count = 0;

        for(int i = 0; i < n; i++){
         if(freq[s[i]] == 0) count++;
         freq[s[i]]++;
        }
     return count;
    }
};