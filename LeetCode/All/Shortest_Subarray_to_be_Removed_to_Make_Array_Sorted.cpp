class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int left = 0;
        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            left++;
        }
        
        if (left == n - 1) return 0;

        int right = n - 1;
        while (right - 1 >= 0 && arr[right] >= arr[right - 1]) {
            right--;
        }
        
        int minLength = min(n - left - 1, right),i = 0, j = right;
        
            while (j < n && i <= left) {
                if(arr[i] <= arr[j]){
            minLength = min(minLength, j - i - 1);
                    i++;
                }
                else{
                    j++;
                }
            }     
        return minLength;
    }
};
