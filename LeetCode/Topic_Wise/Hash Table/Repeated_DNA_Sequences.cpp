class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string>result;  
        unordered_set<string>seen; 
        unordered_set<string>repeated;
        
        for(int i = 0; i <= n - 10; ++i) {
            string substring = s.substr(i, 10);
            if(seen.find(substring) != seen.end()){
               repeated.insert(substring);
            }
            seen.insert(substring); 
        }
          result.assign(repeated.begin(), repeated.end());
          return result;
    }
};
