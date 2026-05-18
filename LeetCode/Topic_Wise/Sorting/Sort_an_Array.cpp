class Solution {
public:
    int medianOfThree(vector<int>& nums, int left, int right) {
        int mid = left + (right - left) / 2;
        if (nums[left] > nums[mid]) {
            swap(nums[left], nums[mid]);
        }
        if (nums[left] > nums[right]) {
            swap(nums[left], nums[right]);
        }
        if (nums[mid] > nums[right]) {
            swap(nums[mid], nums[right]);
        }
        return nums[mid];
    }

    void quicksort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int pivot = medianOfThree(nums, left, right);
        int i = left, j = right;

        while (i <= j) {
            while (nums[i] < pivot) {
                i++;
            }
            while (nums[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        if (left < j) {
            quicksort(nums, left, j);
        }
        if (i < right) {
            quicksort(nums, i, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};