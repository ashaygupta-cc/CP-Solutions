class Solution {
public:
    string ans;

    bool check(vector<char> &path,map<char,int> &freq, string &target, bool bl){
       int n = target.size();
       if(!ans.empty()) return true;

       if(path.size() == n){
        if(bl) ans = string(path.begin(),path.end());
        return false;
       }

       int i = path.size();

       for(auto &f : freq){
          if(!f.second) continue;
          if(!bl && f.first < target[i]) continue;
          path.push_back(f.first);
          f.second--;
          bool newbl = bl || (f.first > target[i]);

          if(check(path,freq,target,newbl)) return true;

          freq[f.first]++;
          path.pop_back();
          }
          return false;
       }
    

    string lexGreaterPermutation(string s, string target) {
        map<char,int>freq;
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            freq[s[i]]++;
        }

        ans = "";
        vector<char>path;
        check(path,freq,target,false);
        return ans;

    }
};