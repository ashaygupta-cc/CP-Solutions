class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(char character : s){
            if(character == '{' || character == '(' || character == '['){
                stk.push(character);
            }
            else{
                if(stk.empty()) return false;
                if(!stk.empty()){
                    if(character == '}' && stk.top() == '{') stk.pop();
                    else if(character == ')' && stk.top() == '(') stk.pop();
                    else if(character == ']' && stk.top() == '[') stk.pop();
                    else return false;
                }   
            } 
        }
        if(stk.empty()) return true;
        else return false;
    }
};