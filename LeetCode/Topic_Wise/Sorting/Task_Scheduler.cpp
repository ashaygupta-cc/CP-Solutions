class Solution {
public:
    int leastInterval(vector<char>& tasks, int n){
       
        vector<int>freq(26,0);
        int maxFreq = 0;

        for(auto task: tasks){
            freq[task-'A']++;
            maxFreq = max(maxFreq, freq[task-'A']);
        }

        int ans = (maxFreq-1)*(n+1);
        
        for(auto f: freq){
             if(f == maxFreq) ans++;
        }

        ans = ans > tasks.size() ? ans : tasks.size();
        return ans;

    }
};