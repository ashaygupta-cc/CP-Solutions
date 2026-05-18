class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int max_val = INT_MIN;
        deque<pair<int, int>> dq;

        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && points[i][0] - dq.front().first > k) {
                dq.pop_front();
            }

            if (!dq.empty()) {
                max_val = max(max_val, points[i][1] + points[dq.front().second][1] + points[i][0] - points[dq.front().second][0]);
            }

            while (!dq.empty() && points[dq.back().second][1] - points[dq.back().second][0] <= points[i][1] - points[i][0]) {
                dq.pop_back();
            }

            dq.push_back({points[i][0], i});
        }

        return max_val;
    }
};
