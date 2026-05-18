class Solution {
public:

int expandAroundCenter(const string &s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        int maxi = -1,start = -1,end = -1;

         for (int i = 0; i < n; i++) {
        int len1 = expandAroundCenter(s, i, i);  
        int len2 = expandAroundCenter(s, i, i + 1);  
        

        int length = max(len1, len2);
        if (length > maxi) {
            maxi = length;
            start = i - (length - 1) / 2;
            end = i + length / 2;
        }
    }
    return s.substr(start, end - start + 1);
}

};