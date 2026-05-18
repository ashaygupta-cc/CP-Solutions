#define ll long long
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
         int n = nums.size();
         vector<int>pref(value,0);
 
    for(int i = 0; i < n; i++){
        ll a = (abs(nums[i]))%value;
        if(nums[i] >= 0 || !a) pref[a]++;
        else pref[value-a]++;
     }
     int mini = INT_MAX;
     int miniIdx = -1;
     int result = -1;

     for(int i = 0; i < value; i++){
        if(pref[i] != 0 && pref[i] < mini){
            mini = pref[i];
            miniIdx = i;
        }
        else if(!pref[i]){
          return result = i; 
        } 
     }
    result = mini*value + miniIdx;
    return result;
    }
};