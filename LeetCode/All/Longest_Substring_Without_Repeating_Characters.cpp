class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           int n = s.size();
           if(n == 1){
            return 1;
           }

         int maxi = 0;

          for(int i = 0; i < n; i++ ){
               int count = 1 ;
                set<char>distinct_letters;
                distinct_letters.insert(s[i]);
            for(int j = i+1 ; j < n ; j++){
           distinct_letters.insert(s[j]);
              count++;
            if(count != distinct_letters.size()){
                maxi = max(count-1,maxi);
                count = 1;
                break;
            }
          }
          maxi = max(count,maxi); 
          }
    return maxi;
    }
};