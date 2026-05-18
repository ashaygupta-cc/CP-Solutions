class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int maxPoints = 1;
        
        for (int i = 0; i < n; ++i) {
            unordered_map<double, int> freq;
            int curMax = 0;

            for (int j = i + 1; j < n; ++j) {
                double slope;
                if (points[j][0] - points[i][0] == 0) {
                    slope = INT_MAX; 
                } 
                else {
                    slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                }

                freq[slope]++;
                curMax = max(curMax, freq[slope]);
            }

            maxPoints = max(maxPoints, curMax + 1);
        }

        return maxPoints;
    }
};
