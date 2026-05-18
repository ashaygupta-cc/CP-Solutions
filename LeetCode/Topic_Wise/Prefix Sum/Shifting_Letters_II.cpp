class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        long long n = s.size();
        vector<long long> diff(n + 1, 0);

        for (const auto& shift : shifts) {
            long long i = shift[0], j = shift[1];
            bool bl = shift[2];
            int delta = bl ? 1 : -1;

            diff[i] += delta;
            if (j + 1 < n) {
                diff[j + 1] -= delta;
            }
        }

        long long currentShift = 0;
        for (long long i = 0; i < n; i++) {
            currentShift += diff[i];
            currentShift %= 26;
            s[i] = (s[i] - 'a' + currentShift + 26) % 26 + 'a';
        }

        return s;
    }
};
