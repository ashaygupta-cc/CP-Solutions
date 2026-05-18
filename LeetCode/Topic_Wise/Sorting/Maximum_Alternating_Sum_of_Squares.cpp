class Solution {
public:
    typedef long long ll;
    long long maxAlternatingSum(vector<int>& nums){

        int n = nums.size();
        int count = (n+1)/2; 
        vector<int>store;

        for (int i = 0; i < n; i++) {
            store.push_back(abs(nums[i]));
        }

        sort(store.begin(),store.end()); 

        ll result = 0;
        for(int i = n - 1; i >= 0; i--){
            if(count > 0){
                result += 1LL * store[i] * store[i];
                count--;
            } 
            else{
                result -= 1LL * store[i] * store[i];
            }
        }
        return result;
    }
};
