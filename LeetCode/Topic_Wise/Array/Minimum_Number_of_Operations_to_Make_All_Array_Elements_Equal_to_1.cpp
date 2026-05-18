class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();

        int GCD = nums[0];
        for(int i = 1; i < n; i++){
            GCD = gcd(GCD,nums[i]);
        }
        if(GCD != 1) return -1;

        int ans = INT_MAX;
        int ones = 0;
        for(int i = 0 ; i < n; i++){
            if(nums[i] == 1) ones++;
        }

        if(ones) return n-ones;

        for(int i = 0; i < n; i++){
            int tempGCD = nums[i];
            for(int j = i+1; j < n; j++){
                tempGCD = gcd(tempGCD,nums[j]);
                if(tempGCD == 1){
                    ans = min(ans,j-i-1+n);
                    break;
                }
            }
        }
        return ans;
    }
};