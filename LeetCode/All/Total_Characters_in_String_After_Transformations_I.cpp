class Solution {
public:
    int lengthAfterTransformations(string s,int t){
        const int MOD = 1e9+7;
        vector<long long>freq(26,0);  // Count of each letter
        
        for(char c : s) freq[c-'a']++;
        long long len = s.length(); 
        
        while(t--){
            
            long long countZ = freq[25];  // count of 'z'
            len = (len + countZ) % MOD;   // 'z' to 'ab' len += 1
            
            // Shift freq of prev of cur char to prev char's freq
            for(int i = 25; i > 0; i--) freq[i] = freq[i-1];
            
            // 'z' to "ab" change
            freq[0] = countZ;         // 'a's from "ab"
            freq[1] = (freq[1] + countZ) % MOD;  // 'b's from "ab"
        }
        return len;
    }
};