class Solution{
public:
    vector<string>removeAnagrams(vector<string>& words){
        
        vector<string>result;
        string prev_sorted = "";

    for(const string &w : words){
            string s = w;
            sort(s.begin(),s.end());
            if(s != prev_sorted){
                result.push_back(w);
                prev_sorted = s;
            }
        }
        return result;
    }
};