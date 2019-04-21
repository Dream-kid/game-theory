//http://lightoj.com/volume_showproblem.php?problem=1315
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
ll fx[]= {-2,-2,1,-1,-3,-1};
ll fy[]= {1,-1,-2,-2,-1,-3};
ll arr[510][510];
ll movel(ll x,ll y)
{
    if(arr[x][y]!=-1)
        return arr[x][y];
    set<ll>st;
    for(ll i=0; i<=5; i++)
    {
        ll ux=x+fx[i];
        ll uy=y+fy[i];
        if(ux<=0||uy<=0)
            continue;
        st.insert(movel(ux,uy));
    }
    ll ans=0;
    while(st.find(ans)!=st.end())
        ans++;
    arr[x][y]=ans;
    return ans;
}
int main()
{
    memset(arr,-1,sizeof arr);
    ll ts;
    cin>>ts;
    for(ll t=1; t<=ts; t++)
    {
        ll total;
        cin>>total;
        ll ans=0;
        for(ll i=1; i<=total; i++)
        {
            ll x,y;
            cin>>y>>x;
            ans^=movel(x+1,y+1);
        }
        cout<<"Case "<<t<<": ";
        if(!ans)
            cout<<"Bob"<<endl;
        else
            cout<<"Alice"<<endl;
    }
}
