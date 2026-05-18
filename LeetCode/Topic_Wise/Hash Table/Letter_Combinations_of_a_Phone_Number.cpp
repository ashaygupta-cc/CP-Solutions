class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()){
          return {};
        }
        
        vector<vector<char>> characters = {
            {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'},
            {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
        };

        vector<string> result = {""};  
        for (char digit : digits) {
            vector<string> temp;
            int index = digit - '2';
            for (const string& str : result) {
                for (char c : characters[index]) {
                    temp.push_back(str + c);
                }
            }
            result = temp;
        }

        return result;
    }
};
