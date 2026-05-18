class Solution {
private:
    vector<int> NextsmallestElement(vector<int> heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> next(n);

        for (int i = n - 1; i >= 0; i--) {
            int num = heights[i];

            while (st.top() != -1 && heights[st.top()] >= num) {
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
        return next;
    }

    vector<int> PrevsmallestElement(vector<int> heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            int num = heights[i];

            while (st.top() != -1 && heights[st.top()] >= num) {
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }
        return prev;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        vector<int> prev(n);

        next = NextsmallestElement(heights, n);
        prev = PrevsmallestElement(heights, n);
        int maxArea = INT_MIN;

        for (int i = 0; i < n; i++) {
            int l = heights[i];

            if (next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            maxArea = max(maxArea, newArea);
        }
        return maxArea;
    }
};
