class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,vector<int>& nums2){
        unordered_map<int,int> next_GreaterMap;
        stack<int>st;

        for(int num : nums2){
            while(!st.empty() && st.top() < num){
                next_GreaterMap[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while(!st.empty()){
            next_GreaterMap[st.top()] = -1;
            st.pop();
        }

        vector<int>result;
        for(int num : nums1){
            result.push_back(next_GreaterMap[num]);
        }

        return result;
    }
};