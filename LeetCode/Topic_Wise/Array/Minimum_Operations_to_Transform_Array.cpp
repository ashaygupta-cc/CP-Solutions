class Solution {
public:
    typedef long long ll;
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();   
        ll x = nums2[n];

        ll totalOper = 0;
        ll dist = LLONG_MAX;
        
       for(int i = 0; i < n; i++){
           ll a = nums1[i];  
           ll b = nums2[i];

        totalOper += abs(a-b);
           
        dist = min(dist,min(1+abs(x-a),1+abs(x-b)));
        if(min(a,b) <= x && x <= max(a,b)) dist = 1;
       }
        return totalOper + dist;
    }
};