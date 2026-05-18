class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        
       sort(nums.begin(),nums.end());

       int n = nums.size();
       int last = INT_MIN; 
       int count = 0;

    for(int i = 0; i < n; i++){
        int a = nums[i]-k;
        int b = nums[i]+k;

        int x = max(last+1,a);

        if(x <= b){
            count++;
            last = x;
        }
     }
    return count;
    }
};