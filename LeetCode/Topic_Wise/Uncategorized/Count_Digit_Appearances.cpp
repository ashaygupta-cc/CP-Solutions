class Solution {
public:
    #define ll long long
    
    int countDigitOccurrences(vector<int>& nums, int digit) {
        
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            ll x = nums[i];
            ll y;
            while(x != 0){
                 y = x%10;
                 if(y == digit) count++;
                 x = x/10;
            }
        }
        return count;
    }
};