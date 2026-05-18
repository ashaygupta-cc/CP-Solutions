class Solution {
    public:
        string addSpaces(string s, vector<int>& spaces) {
                string k = "";
                        k += string(s.begin(), s.begin() + spaces[0]);
                                for (int i = 0; i < spaces.size() - 1; i++) {
                                            k += " ";
                                                        k += string(s.begin() + spaces[i], s.begin() + spaces[i + 1]);
                                                                }
                                                                        k += " ";
                                                                                k += string(s.begin() + spaces[spaces.size() - 1], s.end());
                                                                                        return k;
                                                                                            }
                                                                                            };



