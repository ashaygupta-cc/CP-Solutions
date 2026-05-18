class Solution {
public:
    int maxOperations(string s) {
        
        int n = s.size();
        int Oper = 0,Ones = 0;

        for(int i = 0; i < n-1; i++){
            if(s[i] == '1') Ones++;
            if(s[i] == '0' && s[i+1] == '1') Oper += Ones;
            else continue;
        }
        if(s[n-1] == '0') Oper += Ones;        
        return Oper;
    }
};