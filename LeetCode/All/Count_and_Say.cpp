class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        
        for(int i = 2; i <= n; i++) {
            string new_s = "";
            int j = 0, counter = 1;
            char num = s[0];
            
            while(j < s.length() - 1) {
                if(s[j] == s[j + 1]) {
                    counter++;
                } else {
                    new_s += to_string(counter);
                    new_s += num;
                    counter = 1;
                    num = s[j + 1];
                }
                j++;
            }
            new_s += to_string(counter);
            new_s += num;

            s = new_s;
        }
        return s;
    }
};
