class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long n=p.size(),sum=0,cnt=1;
        for(int i=0;i<n;i++){
            while(i<n-1&&p[i+1]==p[i]-1){
                i++;
                cnt++;
            }
            cout<<cnt<<" ";
            sum+=(cnt*(cnt+1))/2;
            cnt=1;
        }
        return sum;
    }
};