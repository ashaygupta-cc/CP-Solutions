class Solution {
public:
    int countCollisions(string directions) {
        
        int n = directions.size();
        int count = 0;     
        string s = "";
        
        if(n == 1) return 0;
        
        for(int i = 0; i < n-1; i++){
           if(directions[i] == 'R' && directions[i+1] == 'L'){
              count += 2;
              i++;
              s += 'S';
           }
           else s += directions[i];
        }
        if(directions[n-2] != 'R' || directions[n-1] != 'L'){
            s += directions[n-1];
        }
          
        int i = 0,j = s.size()-1;

        while(i < n && s[i] == 'L') i++;
        while(j >= 0 && s[j] == 'R') j--;

        for(int k = i; i <= j; i++){
            if(s[i] != 'S') count++;
        }
    return count;
    }
};