class Solution {
public:
     int minimumLength(string& s) {
        long long freq[26] = {0};
        for(char c: s){
            freq[c-'a']++;
          }
             
        long long l = 0;
        for(int i=0; i<26; i++){
            if (freq[i]==0){
                 continue;
            }
            l += 2-(freq[i]&1);
        }
        return l;
    }
};