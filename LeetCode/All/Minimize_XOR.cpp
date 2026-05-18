class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while(n){
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    
    int minimizeXor(int num1, int num2) {
        int bits = countSetBits(num2);
        int ans = 0;
        // end to start matching 
        for (int i = 31; i >= 0 && bits > 0; i--) {
            if (num1 & (1 << i)) {
                ans |= (1 << i);
                bits--;
            }
        }
        // if num2 has 5 bits and num1 has less bits , that extra where 0s 
        for (int i = 0; i < 32 && bits > 0; i++) {
            if (!(ans & (1 << i))) {
                ans |= (1 << i);
                bits--; 
            }
        }
        return ans;
        // By Ashay
    }
};