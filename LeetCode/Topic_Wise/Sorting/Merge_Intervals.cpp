class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
       
        int first= intervals[0][0];
        int second = intervals[0][1];
        vector<vector<int>>result;
        int i = 1;
        while(i < intervals.size()){
            if(second < intervals[i][0]){
            result.push_back({first,second});
                first = intervals[i][0];
                second = intervals[i][1];
            }
            else{
                if(second<intervals[i][1]){
                    second = intervals[i][1];
                }
                if(first>intervals[i][0]){
                    first = intervals[i][0];
                }
            }
            i++;
        }
        result.push_back({first,second});
        return result;
    }
};