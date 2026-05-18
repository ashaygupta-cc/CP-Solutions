class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int sum = 0, sign = 1, num = 0;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '+') {
                sum += sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-') {
                sum += sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(') {
                stack.push(sum);
                stack.push(sign);
                sum = 0;
                sign = 1;
            }
            else if (c == ')') {
                sum += sign * num;
                num = 0;
                sum *= stack.top();
                stack.pop();
                sum += stack.top();
                stack.pop();
            }
        }

        if (num != 0) {
            sum += sign * num;
        }

        return sum;
    }
};
