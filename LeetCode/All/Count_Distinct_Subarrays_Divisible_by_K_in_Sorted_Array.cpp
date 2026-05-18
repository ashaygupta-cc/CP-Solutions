class Solution {
public:
    typedef long long ll;
    long long numGoodSubarrays(vector<int>& nums,int k){
    
    int n = nums.size();
    map<int,ll>count;
    count[0] = 1;
    
    ll sum = 0,ans = 0;

    for(int i = 0; i < n;){
       int j = i;
       ll sum2 = sum;

       while(j < n && nums[i] == nums[j]){
          sum2 += nums[j];
          sum2 %= k;
          ans += count[sum2];
          j++;
       }
       j = i;

       while(i < n && nums[i] == nums[j]){
          sum += nums[j];
          sum %= k;
          count[sum]++;
          i++;
       }
    }
    return ans;
    }
};