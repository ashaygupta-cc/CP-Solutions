class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        if (m == 0 || n == 0) return "0";
        
        vector<int> result(m + n, 0);
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        string res = "";
        for (int i = 0; i < result.size(); i++) {
            if (!(res.empty() && result[i] == 0)) {
                res += to_string(result[i]);
            }
        }
        
        return res.empty() ? "0" : res;
    }
};
