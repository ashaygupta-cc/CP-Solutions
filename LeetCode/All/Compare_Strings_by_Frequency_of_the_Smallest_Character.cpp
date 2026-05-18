class Solution {
public:
 vector<int> numSmallerByFrequency(vector<string>& queries,vector<string>& words){
        
        vector<int>freq1,freq2(12,0);

    for(int i = 0; i < words.size(); i++){
       string& s = words[i];
       char c = s[0];
       int count = 1;
       for(int j = 1; j < s.size(); j++){
           if(s[j] < c){
               c = s[j];
               count = 1;
           }
           else if(s[j] == c){
               count++;
           }
       }
       freq2[count]++;
    }

    for(int i = 9; i >= 0; i--){
        freq2[i] += freq2[i+1];
    }

    for(int i = 0; i < queries.size(); i++){
       string& s = queries[i];
       char c = s[0];
       int count = 1;
       for(int j = 1; j < s.size(); j++){
           if(s[j] < c){
               c = s[j];
               count = 1;
           }
           else if(s[j] == c){
               count++;
           }
       }
       freq1.push_back(count);
    }
      
    vector<int>result;

    for(int i = 0; i < freq1.size(); i++){
        result.push_back(freq2[freq1[i]+1]);
    }
    return result;
    }
};
