class Solution {
public:
    bool canConstruct(string s, int k) {
         if(s.size() < k){
            return false;
          }

        vector<int>freq(27,0);

    for(int i = 0; i < s.size(); i++){
         freq[s[i]-'a'+1]++;
    }
       int count = 0;
     for(int i = 1; i < 27; i++){
         if(freq[i]%2 != 0){
           count++;
         }
     }

     if(count > k){
        return false;
     }
     return true;
    }
};