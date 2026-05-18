class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);  // Total sum of the array
        int half = n/2;

        // Store all possible subset sums by count of elements taken from both halves
        vector<vector<int>>leftSums(half+1),rightSums(half+1);

        // Generate all subsets using bitmasking
        for(int mask = 0; mask < (1 << half); mask++){
            int count = 0,sumLeft = 0,sumRight = 0;
            
            for(int i = 0; i < half; i++){
                if(mask & (1 << i)){
                    count++;
                    sumLeft += nums[i];
                    sumRight += nums[i+half];
                }
            }
            leftSums[count].push_back(sumLeft);
            rightSums[count].push_back(sumRight);
        }

        // Sort right-side sums for binary search
        for(int count = 0; count <= half; count++){
            sort(rightSums[count].begin(), rightSums[count].end());
        }

        // Initialize result with worst case
    int minDiff = min(abs(totalSum - 2*leftSums[half][0]),abs(totalSum - 2*rightSums[half][0]));

        // Try all combinations of subsets of size 1 to half-1
        for(int count = 1; count < half; count++){
            for(int sumA : leftSums[count]){
                int target = (totalSum - 2*sumA)/2;
                int rightCount = half-count;
                auto& rightVec = rightSums[rightCount];

                // Binary search for best match on the right side
                auto it = lower_bound(rightVec.begin(),rightVec.end(),target);
                if(it != rightVec.end()){
                    minDiff = min(minDiff,abs(totalSum - 2*(sumA+*it)));
                }
            }
        }
        return minDiff;
    }
};
