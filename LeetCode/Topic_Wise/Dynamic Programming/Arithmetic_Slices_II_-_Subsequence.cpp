class Solution{
public:
    int numberOfArithmeticSlices(vector<int>& nums){
      
        int n = nums.size();
        int result = 0;
        unordered_map<long long,int>difcheck[n];

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                
                auto diff = (long long)nums[i]-nums[j];
                auto it = difcheck[j].find(diff);
                int difcountJ = (it == difcheck[j].end()) ? 0 : it->second;
                difcheck[i][diff] += (difcountJ + 1);
                result += difcountJ;
            }
        }
        return result;
    }
};
