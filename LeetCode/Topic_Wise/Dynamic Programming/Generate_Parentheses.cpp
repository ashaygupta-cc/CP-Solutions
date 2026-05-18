class Solution{
public:
  vector<string>generateParenthesis(int n){
        vector<string>res;
        dfs(res,"",0,0,n);
        return res;
    }

    void dfs(vector<string>&res, string cur,int open,int close,int n){
        if(cur.size() == 2*n){
            res.push_back(cur);
            return;
        }
        if(open < n) dfs(res,cur+"(",open+1,close,n);
        if(close < open) dfs(res,cur +")",open,close+1,n);
    }
};