class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        vector<int> result;
        stack<int> calc;

        for(int i = 0; i < asteroids.size(); i++){
    
            if(asteroids[i] > 0 || calc.empty() || calc.top() < 0) {
                calc.push(asteroids[i]);
            } 
            else{           
        while(!calc.empty() && calc.top() > 0 && calc.top() < abs(asteroids[i])) {
                    calc.pop();
                }
                if(!calc.empty() && calc.top() == abs(asteroids[i])) {
                    calc.pop();
                } 
                else if(calc.empty() || calc.top() < 0){
                    calc.push(asteroids[i]);
                }
            }
        }
        
        while(!calc.empty()){
            result.push_back(calc.top());
            calc.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
