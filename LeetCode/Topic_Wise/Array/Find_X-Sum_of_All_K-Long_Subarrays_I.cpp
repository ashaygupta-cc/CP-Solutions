class Solution {
public:
    int getSumX(vector<pair<int,int>>freq,int x){

        sort(freq.begin(),freq.end(),[](auto &a, auto &b){
            if(a.first != b.first) 
                return a.first > b.first; 
            return a.second > b.second;
        });

        int sum = 0;
        for(int i = 0; i < x && i < freq.size(); i++){
            if(freq[i].first > 0)
                sum += freq[i].first*freq[i].second;
        }
        return sum;
    }
    
    vector<int> findXSum(vector<int>& nums, int k, int x){

        int n = nums.size();
        vector<int> result;
        vector<pair<int,int>> freq(51,{0,0});

        for(int i = 0; i < 51; i++) freq[i].second = i;

        for(int i = 0; i < k; i++) freq[nums[i]].first++;

        result.push_back(getSumX(freq,x));

        for(int i = 1; i <= n-k; i++){
            freq[nums[i-1]].first--;
            freq[nums[i+k-1]].first++;
            result.push_back(getSumX(freq,x));
        }

        return result;
    }
};
