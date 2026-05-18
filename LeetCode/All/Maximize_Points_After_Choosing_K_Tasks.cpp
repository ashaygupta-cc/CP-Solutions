class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {

        int n = technique1.size();

        vector<tuple<int,int,int>>compute;

        for(int i = 0; i < n; i++){
            compute.push_back({abs(technique1[i]-technique2[i]),technique1[i], technique2[i]});
        }

        sort(compute.begin(),compute.end(),
            [](const tuple<int,int,int> &a,const tuple<int,int,int> &b){
                return get<0>(a) > get<0>(b);
            }
        );

        int rem = k;
        long long maxi = 0;
        int idx = -1;
        
        for(int i = 0; i < n; i++){
            
            int a = get<1>(compute[i]);   
            int b = get<2>(compute[i]);  

            if(n-i == rem){      
                idx = i;
                break; 
            }
            
            if(a >= b){
                maxi += a;
                rem--;
            }

            if(a < b){
                maxi += b;
            }
        }

        if(rem > 0){
            for(int i = idx; i < n; i++){
                int a = get<1>(compute[i]);   
                int b = get<2>(compute[i]);   
                maxi += a;
            }
        }
        return maxi;
    }
};
