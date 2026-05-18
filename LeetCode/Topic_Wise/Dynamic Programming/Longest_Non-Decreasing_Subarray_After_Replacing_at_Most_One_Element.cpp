class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;

        vector<vector<int>>segments;
        vector<int>current;
        current.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            if(nums[i] >= nums[i-1])          current.push_back(nums[i]);
            
            else{                             segments.push_back(current);
                current.clear();
        current.push_back(nums[i]);
            }
        }
        segments.push_back(current);

        int ans = 1;
       
        for(auto &seg : segments)
       ans = max(ans,(int)seg.size());

        for(int i = 1; i < (int)segments.size(); i++){
        
        auto &prev = segments[i-1];
        auto &next = segments[i];
        
        int prevLast = prev.back();
        int nextFirst = next.front();
        
        bool bl = false;
        
        if(prev.size() >= 2 && prev[prev.size()-2] <= nextFirst)
            bl = true;
        
        if(next.size() >= 2 && prevLast <= next[1])
            bl = true;
        
        if(bl)ans = max(ans,(int)prev.size()+(int)next.size());
        else ans = max(ans,(int)prev.size()+1);
        }
    if(segments.size() >= 2)
    ans = max(ans,(int)segments.back().size()+1);
        
        return ans;
    }
};