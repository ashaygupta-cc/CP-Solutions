#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define read(i,a,b) for(ll i = a; i < b; i++)
#define read2(i,a,b) for(ll i = a; i >= b; i--)
#define chalna return
#define shi true
#define galat false
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ll INF = 1e18;
using namespace std;

vector<ll>pr;
vector<ll>prime(500005,1);

void sieve(){
   prime[1] = prime[0] = 0;

   read(i,2,500005){
    if(prime[i]){
        for(int j = 2*i; j < 500005; j += i){
            prime[j] = 0;
        }
    }
   }
   read(i,0,500005){
    if(prime[i]) pr.push_back(i);
   }
}

class Solution {
public:
     
    int minOperations(vector<int>& nums) {
    
      sieve();
      
      int n = nums.size();
      int oper = 0;

      for(int i = 0; i < n; i += 2){
        ll mini  = LLONG_MAX;
         auto idx = lower_bound(pr.begin(),pr.end(),nums[i])-pr.begin();
         mini = min(mini,pr[idx]-nums[i]);
         oper += mini;
      }
      
      for(int i = 1; i < n; i += 2){
        ll mini  = LLONG_MAX;
         auto idx = lower_bound(pr.begin(),pr.end(),nums[i])-pr.begin();
         if(nums[i] == pr[idx]){
            if(pr[idx] == 2) oper += 2;
            else oper++;
         }
      }
    return oper;
    }
};