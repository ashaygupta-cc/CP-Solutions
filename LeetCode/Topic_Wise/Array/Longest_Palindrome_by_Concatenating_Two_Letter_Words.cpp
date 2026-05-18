class Solution {

public:

 int longestPalindrome(vector<string>& words){

        vector<vector<int>>

        mp(26,vector<int>(26,0));

        int mid = 0;

        int count = 0;

        for(auto &s : words){

            int x = s[0] - 'a', y = s[1] - 'a';

            if(mp[y][x] > 0){

                mp[y][x]--;

                count += 4;

                if(x == y) mid--;

            }

            else{

                mp[x][y]++;

                if(x == y) mid++;

            }

        }

        if(mid > 0) count += 2;

        return count;

    }

};

        

