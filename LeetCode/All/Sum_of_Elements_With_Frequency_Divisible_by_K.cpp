class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {

        int n = nums.size();
        int sum = 0;
        unordered_map<int,int>freq;

        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }

        for(auto &a : freq){
            if(a.second % k == 0) sum += (a.first * a.second);
        }
        
    return sum;
    }
};