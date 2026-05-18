class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        set<long long> store;
        
        for (int i = 0; i < nums.size(); i++) {
            long long num = (long long)nums[i];
            
            auto it = store.lower_bound(num - (long long)valueDiff);
            if (it != store.end() && *it <= num + (long long)valueDiff) {
                return true;
            }
            
            store.insert(num);
            
            if (store.size() > indexDiff) {
                store.erase((long long)nums[i - indexDiff]);
            }
        }
        
        return false;
    }
};
