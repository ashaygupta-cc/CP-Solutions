class Solution {
public:
    // Function to print a vector (just for debugging)
    void print(const vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Sort the array to enable two-pointer approach
        sort(nums.begin(), nums.end());

        // Loop through the array
        for (int start = 0; start < nums.size() - 2; start++) {
            // Skip duplicate elements for 'start'
            if (start > 0 && nums[start] == nums[start - 1]) {
                 continue;
            }

            int low = start + 1;
            int end = nums.size() - 1;

            // Two-pointer approach to find pairs that sum up to -nums[start]
            while (low < end) {
                int total = nums[start] + nums[low] + nums[end];
                
                if (total == 0) {
                    // Found a valid triplet
                    result.push_back({nums[start], nums[low], nums[end]});
                    print({nums[start], nums[low], nums[end]});

                    // Skip duplicates for 'low'
                    while (low < end && nums[low] == nums[low + 1]) {
                        low++;
                    }
                    // Skip duplicates for 'end'
                    while (low < end && nums[end] == nums[end - 1]) {
                        end--;
                    }

                    // Move the pointers after finding a valid triplet
                    low++;
                    end--;
                } else if (total < 0) {
                    low++; // We need a larger sum, move 'low' pointer to the right
                } else {
                    end--; // We need a smaller sum, move 'end' pointer to the left
                }
            }
        }
        
        return result;
    }
};
