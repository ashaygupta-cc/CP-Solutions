class Solution {
public:
#define ll long long
#define read(i,a,b) for(ll i = a; i < b; i++)
#define read2(i,a,b) for(ll i = a; i >= b; i--)
#define chalna return

static const ll mod = 1e9+7;
static const ll MAXN = 1e5+5;

ll fact[MAXN],invfact[MAXN];

ll binpow(ll a,ll b,ll m=mod){
    ll res=1;
    while(b>0){
        if(b&1) res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    chalna res;
}

ll modinv(ll a,ll m=mod){
    chalna binpow(a,m-2,m);
}

void pre(ll n=MAXN-1,ll m=mod){
    fact[0]=1;
    read(i,1,n+1) fact[i]=(fact[i-1]*i)%m;
    invfact[n]=binpow(fact[n],m-2,m);
    read2(i,n-1,0) invfact[i]=(invfact[i+1]*(i+1))%m;
}

ll nCr(ll n,ll r,ll m=mod){
    if(r<0 || r>n) chalna 0;
    chalna (((fact[n]*invfact[r])%m)*invfact[n-r])%m;
}
   
    int countVisiblePeople(int n, int pos, int k) {
        pre();
        
        int l = pos;
        int r = n - pos - 1;
        
        ll tot = 0;

        for(int i = 0; i <= k; i++){
            ll left = nCr(l, i);
            ll right = nCr(r, k - i);
            
            tot = (tot + (left*right) % mod) % mod;
        }
         tot = (tot*2)%mod;
        return tot;
    }
};