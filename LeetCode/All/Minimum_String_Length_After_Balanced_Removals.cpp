class Solution {
public:
    int minLengthAfterRemovals(string s) {
        
        int a = 0,b = 0;
        stack<int>st;
        int n = s.size();
         
        for(int i = 0; i < n; i++){
           if(st.empty() || (st.top() == s[i])) st.push(s[i]);
           else st.pop();
        }
    return st.size();
    }
};