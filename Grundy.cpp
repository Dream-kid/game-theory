//http://lightoj.com/volume_showproblem.php?problem=1199
////=====================================////
///-----SOURAV CHAKRABORTY-----///
///-----KUET CSE 2K16-----///
////=====================================////
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define inf 10000000000000000
#define mod1 1000000007
#define check(n,i)n&1<<i
#define set(n,i)n|1<<i
ll dp[10010];
ll Grundy(ll n)
{
    if(n<=2)
        return 0;
    ll &res=dp[n];
    if(res!=-1)
        return res;
    set<ll>st;
    for(ll i=1; 2*i<n; i++)
        st.insert((Grundy(i)^Grundy(n-i)));
    ll ans=0;
    while(st.find(ans)!=st.end())
        ans++;
    return res=ans;
}
int main()
{
    memset(dp,-1,sizeof dp);
    ll ts;
    cin>>ts;
    for(ll t=1; t<=ts; t++)
    {
        ll total;
        cin>>total;
        ll ans=0;
        for(ll i=1; i<=total; i++)
        {
            ll val;
            cin>>val;
            ans^=Grundy(val);
        }
        cout<<"Case "<<t<<": ";
        if(!ans)
            cout<<"Bob"<<endl;
        else
            cout<<"Alice"<<endl;
    }
}
 
