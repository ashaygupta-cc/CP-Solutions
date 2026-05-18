class Solution {
public:
    vector<string>pre;
    string lexSmallest(string s) {
        int n = s.size();

        for(int i = 0; i < n; i++){
            string a = s;
            reverse(a.begin(),a.begin()+i+1);
            pre.push_back(a);
        }
        for(int i = n-1; i >= 0; i--){
            string a = s;
            reverse(a.end()-i,a.end());
            pre.push_back(a);
        }

    sort(pre.begin(),pre.end());
    return pre[0];
    }
};