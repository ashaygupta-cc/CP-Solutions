class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        int count = 1;
        string str;

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && s[i] == s[i + 1]) {
                count++;
            } else {
                if (count >= 3) {
                    str.insert(str.size(), 2, s[i]); 
                } else {
                    str.insert(str.size(), count, s[i]);
                }
                count = 1; 
            }
        }

        return str;
    }
};
