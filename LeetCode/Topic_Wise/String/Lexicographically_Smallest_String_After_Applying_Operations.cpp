#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b){
        unordered_set<string>visited;
        queue<string> q;
        string ans = s;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            ans = min(ans,cur);

            string t = cur;
            for (int i = 1; i < t.size(); i += 2){
                t[i] = ((t[i]-'0')+a)%10 +'0';
            }

            if (!visited.count(t)){
                visited.insert(t);
                q.push(t);
            }

            string r = cur.substr(cur.size()-b) + cur.substr(0,cur.size()-b);

            if (!visited.count(r)){
                visited.insert(r);
                q.push(r);
            }
        }

        return ans;
    }
};
