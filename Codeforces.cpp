#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DEC(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,1,n)
#define REPN(i,n) FOR(i,0,n-1)
#define VEC(i,a) for(auto i:a)
#define pb push_back
#define is insert
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define fi first
#define se second
#define si set<int>
#define ll long long int
#define oo 1e18+7
#define micro 1e-9
#define mod 1000000007
#define mxn 1000005
#define mp make_pair
#define upbo(a,k) upper_bound(a.begin(),a.end(),k)-a.begin()
#define lobo(a,k) lower_bound(a.begin(),a.end(),k)-a.begin()
#define YES() {cout<<"YES"<<"\n";}
#define NO() {cout<<"NO"<<"\n";}
#define all(a) a.begin(),a.end()
#define endl "\n"
#define _max(a,b) a=max(a,b);
#define _min(a,b) a=min(a,b);
#define _add(a,b,mod) a=(a+b)%mod;
#define _multi(a,b,mod) a=(a*b)%mod;
#define sz(a) (int)a.size()
//#define int long long int
int n;
ll a[mxn];
int num[mxn];
ll calc(int l,int r)
{
    if(l==r) return 1ll;
    int m=(l+r)/2;
    ll ans=0;
    int lmin,lmax,rmin,rmax;
    rmin=m+1;
    rmax=m+1;
    lmin=m;
    lmax=m;
    vi cas(64,0);
    for(int i=m;i>=l;i--)
    {
        if(a[i]>=a[lmax]) lmax=i;
        if(a[i]<=a[lmin]) lmin=i;
        while(rmax<=r&&a[rmax]<=a[lmax])
        {
            cas[num[rmax]]++;
            rmax++;
        }
        while(rmin<=r&&a[rmin]>a[lmin])
        {
            cas[num[rmin]]--;
            rmin++;
        }
        //if(cas[num[i]]>0) ans+=cas[num[i]];
        int dem=0;
        for(int i=rmin;i<rmax;i++)
        {
            if(a[i]<=a[lmin]&&)
        }
    }
    return ans+calc(l,m)+calc(m+1,r);
}
ll calc1(int l,int r)
{
    if(l==r) return 1ll;
    int m=(l+r)/2;
    ll ans=0;
    int lmin,lmax,rmin,rmax;
    rmin=m+1;
    rmax=m+1;
    lmin=m;
    lmax=m;
    vi cas(64,0);
    for(int i=m;i>=l;i--)
    {
        if(a[i]>=a[lmax]) lmax=i;
        if(a[i]<=a[lmin]) lmin=i;
        while(rmin<=r&&a[rmin]>=a[lmin])
        {
            cas[num[rmin]]++;
            rmin++;
        }
        while(rmax<=r&&a[rmax]<a[lmax])
        {
            cas[num[rmax]]--;
            rmax++;
        }
        if(cas[num[i]]>0) ans+=cas[num[i]];
    }
    return ans+calc1(l,m)+calc1(m+1,r);
}
void Solve()
{
    cin>>n;
    REP(i,n) cin>>a[i];
    REP(i,n)
    {
        ll tmp=a[i];
        int dem=0;
        while(tmp)
        {
            if(tmp%2) dem++;
            tmp/=2;
        }
        num[i]=dem;
    }
    cout<<calc(1,n)+calc1(1,n)-n;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //create();
    //pretest();
    freopen("Codeforces.inp","r",stdin);
    freopen("Codeforces.out","w",stdout);
    Solve();
    return 0;
}
