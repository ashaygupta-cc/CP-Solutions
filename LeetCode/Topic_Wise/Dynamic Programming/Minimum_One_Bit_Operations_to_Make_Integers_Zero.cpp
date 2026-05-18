class Solution {
public:
    int minimumOneBitOperations(int n) {
    if (n == 0) return 0;
      int numOp = 0,k;
      int sign = 1;
        
      while(n > 0){
       k = 31 - __builtin_clz(n);
       numOp += sign*((1 << (k+1))-1);
       n ^= (1 << k);
       sign *= -1;
      }
        
    return numOp;
    }
};