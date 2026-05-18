class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
              long long XOR = 0;
           for(int i = 0; i < derived.size(); i++){
                 XOR ^= derived[i];
           }
        return XOR == 0;
    }
};