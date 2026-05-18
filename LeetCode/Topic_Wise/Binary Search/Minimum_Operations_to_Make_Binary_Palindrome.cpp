class Solution {
public:
    bool isPalindrome(int n){

        string s = bitset<32>(n).to_string();  
        int msb;

        if(n == 0){
            s = "0";
            msb = 0;
        }
        else{
            msb = 31 - __builtin_clz(n);
            s = s.substr(31-msb);
        }

        int fBits = 0;
        int i = 0,j = s.size()-1;
        
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int toMakePalindrome(int n){

        int x = n;
        int dist = 0;

        while(true){
            int a = x-dist;
            int b = x+dist;

            if(a >= 0 && isPalindrome(a))
                return dist;

            if(isPalindrome(b))
                return dist;

            dist++;
        }
        return 0;
    }
    
    vector<int> minOperations(vector<int>& nums) {

        int n = nums.size();
        vector<int>result(n,0);
        
        for(int i = 0; i < n; i++){
            result[i] = toMakePalindrome(nums[i]);
        }
        
        return result;    
    }
};
