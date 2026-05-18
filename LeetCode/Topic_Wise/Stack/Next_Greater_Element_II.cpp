class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<pair<int, int>> st;

        for (int i = 0; i < 2 * n; i++) {
            int check = nums[i % n];

            while(!st.empty() && st.top().first < check){
                result[st.top().second] = check;
                st.pop();  
            }
            if(st.empty() || (check <= st.top().first && i < n)){
                st.push({check, i});
            }
        }
        return result;
    }
};
