class Solution {
    public:
        long long maximumSubarraySum(vector<int>& nums, int k) {
                int n = nums.size();
                        unordered_set<int> uniqueElements;
                                long long max_sum = 0, current_sum = 0;
                                        int left = 0;

                                                for (int right = 0; right < n; right++) {
                                                            while (uniqueElements.count(nums[right])) {
                                                                            uniqueElements.erase(nums[left]);
                                                                                            current_sum -= nums[left];
                                                                                                            left++;
                                                                                                                        }
                                                                                                                                    uniqueElements.insert(nums[right]);
                                                                                                                                                current_sum += nums[right];

                                                                                                                                                            if (right - left + 1 == k) {
                                                                                                                                                                            max_sum = max(max_sum, current_sum);
                                                                                                                                                                                            uniqueElements.erase(nums[left]);
                                                                                                                                                                                                            current_sum -= nums[left];
                                                                                                                                                                                                                            left++;
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                        return max_sum;
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                            };

        

