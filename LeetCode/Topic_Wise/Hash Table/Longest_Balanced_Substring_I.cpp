class Solution {
public:
    int longestBalanced(string s) {
        
        int maxi = 0;
        int n = s.size();

        for(int i  = 0; i < n; i++){
            unordered_map<char,int>freq;
            
            for(int j = i; j < n; j++){
                freq[s[j]]++;

            bool bal = true;
            int exiFreq = freq.begin()->second;

            for(auto &a: freq){
                if(a.second != exiFreq){
                    bal = !bal;
                    break;
                }
            }

            if(bal) maxi = max(maxi,j-i+1);                
            }
        }
        return maxi;
    }
};