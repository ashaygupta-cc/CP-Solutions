class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int cycles = sum/9;
        int rem = sum%9;
        int zeros;

        if(rem) zeros = num-(cycles+1);
        else zeros = num-cycles;

        if(zeros < 0) return "";
        
        string s = "";
        for(int i = 0; i < cycles; i++){
           s += '9';
        }

        if(rem > 0){
           s += to_string(rem);
        }

    if(zeros){
        for(int i = 0; i < zeros; i++){
           s += '0';
        }
    }
     return s;   
    }
};