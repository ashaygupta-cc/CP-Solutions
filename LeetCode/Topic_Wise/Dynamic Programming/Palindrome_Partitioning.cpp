class Solution {
public:
    int n;
    bool ispalindrome(string &s,int l,int r){
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(vector<vector<string>>& result,vector<string>& curr,string& s,int idx){
        if(idx == n){
            result.push_back(curr);
            return;
        }
        for(int i=idx;i<n;i++){
            if(ispalindrome(s,idx,i)){
                curr.push_back(s.substr(idx, i-idx+1));
                backtrack(result, curr, s, i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>> result;
        vector<string> curr;
        backtrack(result,curr,s,0);
        return result;
    }
};