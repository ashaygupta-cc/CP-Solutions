class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points){
        if(points.empty()) return 0;

        sort(points.begin(), points.end(),[](const vector<int>& a, const vector<int>& b) {
            return a[1]<b[1];
        });

        long long count = 1;
        long long check = points[0][1];

        for(int i = 1;i < points.size();i++){
            if (points[i][0] > check){
                check = points[i][1];
                 count++;
            }
        }
        return count;
    }
};
