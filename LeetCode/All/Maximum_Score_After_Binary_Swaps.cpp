class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {

      long long n = nums.size();
      int count = 0;

      priority_queue<long long>pq;
      long long score = 0;

      for(int i = 0; i < n; i++){
          pq.push(nums[i]);
          
          if(s[i] == '1'){
             score += pq.top();
              pq.pop();
          }
      }

      return score;
    }
};