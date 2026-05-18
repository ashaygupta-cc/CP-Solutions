class Solution {
public:
    int minOperations(vector<int>& nums) {
     int n = nums.size();
     int idx = -1;
        
    unordered_map<int,int>freq;

    for(int i = n-1; i >= 0; i--){
       freq[nums[i]]++;
       if(freq[nums[i]] == 2){
         idx = i;
         break;
       }
    }
     return (idx+3)/3;
    }
};