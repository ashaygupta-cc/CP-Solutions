class Solution {
    vector<int> vec;
    int n;
public:
    Solution(vector<int>& nums) {
        vec = nums;
        n = (int)nums.size();
    }
    
    int pick(int target) {
        int i;
        do{
            i = rand()%n;
        }
        while(vec[i] != target);
        return i;
    }
};