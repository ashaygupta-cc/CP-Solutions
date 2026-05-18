class Solution {
public:
    long long minOperations(vector<vector<int>>& queries){
        long long ans = 0;

        vector<long long>arr;
        arr.push_back(1);
        for(int i = 1; i < 32; i++){
            arr.push_back(arr.back() * 4);
        }

        for(auto &q : queries){
            long long low = q[0], high = q[1];
            long long totalSteps = 0;

            for(int k = 1; k < arr.size(); k++){
                long long caps = arr[k-1];
                long long cape = arr[k]-1;

                long long Low = max(low,caps);
                long long High = min(high,cape);

                if(High >= Low){
                    long long count = High-Low+1;
                    totalSteps += count*k; 
                }

                if(cape >= high) break;
            }

            ans += (totalSteps+1)/2;
        }

        return ans;
    }
};