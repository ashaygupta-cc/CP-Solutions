class Solution {
public:
    typedef long long ll;
    const int MOD = 1000000007;

    int countTrapezoids(vector<vector<int>>& points) {

        int n = points.size();

        unordered_map<int,int>freqY;

        for(int i = 0; i < n; i++){
            freqY[points[i][1]]++;
        }

        ll tot = 0,prefPairs = 0;

        for(auto &f : freqY){
           
           ll y = f.first;
           ll ff = f.second;

           if(ff == 1) continue;
           ll totComb = (ff*(ff-1)/2LL);
           
           tot = (tot+(totComb*prefPairs)%MOD)%MOD;
           prefPairs += totComb;

        }
    return tot%MOD;
    }
};
