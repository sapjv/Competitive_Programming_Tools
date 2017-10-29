/*nandishwar001*/
#include <bits/stdc++.h>
#define ll long long int
#define minn(x,y) (x<y?x:y)
using namespace std;

ll mod_inverse(ll a,ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
       x1 += m0;
    return x1;
}

ll power(ll base,ll exp,ll mod)
{
    ll res=1;
    while(exp)
    {
        if(exp&1)
            res=(res*base)%mod;
        base=(base*base)%mod;
        exp>>=1;
    }
    return res;
}

int main()
{
    int t;
    ll a,b,x,ans;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>x;
        if(b<0)
            {
                ans=mod_inverse(a,x);
                ans=power(ans,abs(b),x);
                cout<<ans<<endl;
            }
        else
        {
            ans=power(a,b,x);
            cout<<ans<<endl;
        }
    }
    return 0;
}

