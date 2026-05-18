class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
           long long s = nums1.size();
           long long k = nums2.size();
                  long long XOR = 0;
        if(s%2 == 0 && k%2 == 0) return 0;
        if(s%2 == 0){
            for(int i =0; i < s; i++){
                XOR ^= nums1[i];
            }
        }
        else if(k%2 ==0){
            for(int i =0; i < k; i++){
                XOR ^= nums2[i];
            }
        }
        else{
            for(int i =0; i < k; i++){
                XOR ^= nums2[i];
            }
             for(int i =0; i < s; i++){
                XOR ^= nums1[i];
            }
        }
        return XOR;
    }
};