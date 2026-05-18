class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> NewCode(n, 0); 
    
        if (k == 0) {
            return NewCode; 
        }

        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= k; j++) {  
                    sum += code[(i + j) % n];
                }
                NewCode[i] = sum;
            }
        }

        if (k < 0) {
            k = n + k;
            int sum = 0;  
   for(int i = 0; i < n; i++){
    sum += code[i];
   }

            for (int i = 0; i < n; i++) {
                int l = sum;
                for (int j = 1; j <= k; j++) {  
                    l -= code[(j+i-1) % n];
                }
                NewCode[i] = l;
            }
        }

        return NewCode;
    }
};
