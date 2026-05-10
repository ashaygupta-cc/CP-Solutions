#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define read(i, a, b) for (ll i = a; i < b; i++)
#define chalna return
#define shi true
#define galat false

using namespace std;

const ll mod = 1e9 + 7;

class Solution {
public:
    ll binpow(ll a,ll b,ll m = mod){
        ll res = 1;
        a %= m;
        while(b > 0){
            if(b & 1) res = (res*a)%m;
            a = (a*a)%m;
            b >>= 1;
        }
        chalna res;
    }

    int maxValue(vector<int>& nums1, vector<int>& nums0){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        ll n = nums1.size();
        ll totBits = 0;
        ll pureOnes = 0;

        vector<pair<ll,ll>>p;

        read(i,0,n){
            totBits += (nums1[i]+nums0[i]);
            
            if(nums0[i] == 0){
                pureOnes += nums1[i];
            } 
            else{                                p.push_back({(ll)nums1[i], (ll)nums0[i]});
            }
        }

        sort(p.begin(),p.end(),[](const pair<ll,ll>& a,const pair<ll, ll>& b){
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        ll ans = 0;
        ll cur = totBits;

        if(pureOnes > 0){
            ll x = (binpow(2,pureOnes)-1+mod)%mod;
            ll numer = (x*binpow(2,cur-pureOnes))%mod;
            ans = (ans+numer)%mod;
            cur -= pureOnes;
        }

        for (auto& [o,z] : p){
            ll ones = o;
            ll zeros = z;

            if(ones > 0){
                ll x = (binpow(2,ones)-1+mod)%mod;
                ll numer = (x*binpow(2,cur-ones))%mod;
                ans = (ans+numer)%mod;
            }
            
            cur -= (ones+zeros);
        }
        return (int)ans;
    }
};