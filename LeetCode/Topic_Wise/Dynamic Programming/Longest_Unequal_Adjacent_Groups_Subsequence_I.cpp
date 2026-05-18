class Solution {
public:
    vector<string> TakeSkip(int index,int lastGroup,vector<string>& words, vector<int>& groups,vector<vector<vector<string>>>& dp){
       
        if(index == words.size()) return {};

        if(!dp[index][lastGroup + 1].empty()) return dp[index][lastGroup + 1];

        // Option 1: Skip current word
        vector<string>skip = TakeSkip(index + 1,lastGroup,words,groups,dp);

        // Option 2: Take current word if group alternates
        vector<string>take;
        
        if(lastGroup == -1 || groups[index] != lastGroup){
            take = TakeSkip(index + 1,groups[index],words,groups,dp);
            take.insert(take.begin(),words[index]);
        }

        // Store and return longer sequence
        return dp[index][lastGroup + 1] = (take.size() > skip.size()) ? take : skip;
    }

 vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups){
        int n = words.size();
        vector<vector<vector<string>>>dp(n,vector<vector<string>>(3));
        return TakeSkip(0,-1,words,groups,dp);
    }
};
