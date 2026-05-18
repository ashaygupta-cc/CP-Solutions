class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
       long long elesum = 0;
       long long dsum = 0;
for (int i = 0; i < nums.size(); i++) {
    elesum += nums[i];
    while(nums[i] != 0){
         dsum += ((nums[i]) % 10);
          nums[i] /= 10;
    }
}
       return abs(elesum - dsum); 
    }
};