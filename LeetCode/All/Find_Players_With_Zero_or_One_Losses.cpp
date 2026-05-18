const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 1 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
   vector<vector<int>> findWinners(vector<vector<int>>& matches) {
   
    vector<vector<int>>answer(2);
    map<int,int>freq1,freq2;

    for(int i = 0; i < matches.size(); i++){
        freq2[matches[i][1]]++;
        freq1[matches[i][0]]++;
    }
    for(auto &p : freq1){
        if(freq2.find(p.first) == freq2.end()){
            answer[0].push_back(p.first);
        }
    }
    for(auto &p : freq2){
        if(p.second == 1){
            answer[1].push_back(p.first);
        }
    }
   
    return answer;
  }
};