class Solution {
    typedef long long ll;
    vector<string>nums;

private:
    void calc(){
        for(int i = 1; i <= 1e9; i *= 2){
             string s = to_string(i);
             sort(s.begin(),s.end());
             nums.push_back(s);
        }
    }

public:
    bool reorderedPowerOf2(int n) {
       
       calc();
       string k = to_string(n);
       sort(k.begin(),k.end());

       return (find(nums.begin(),nums.end(),k) != nums.end());       
    }
};