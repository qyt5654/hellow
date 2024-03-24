#include<bits/stdc++.h>
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define sst(n) setprecision(n)
#define INF 4e18
#define lowBit(n) ((n)&(-n))
#define pl (p*2)
#define pr (p*2+1)
#define mod 998244353
int ABS(int x) {return (x<0?-x:x);}
const int N=2e5+10;
int n,q,a[N],rt[N],idx,lst[N];
std::vector<int>x;
int bin(int p){
    return std::lower_bound(x.begin(),x.end(),p)-x.begin()+1;
}
struct node{
    int ls,rs,val;
}t[N<<5];
void insert(int &o,int pre,int val,int s=0,int e=n){
    o=++idx;
    t[o]=t[pre];
    t[o].val++;
    if(s==e)return;
    int mid=(s+e)>>1;
    if(val<=mid){
        insert(t[o].ls,t[pre].ls,val,s,mid);
    }else{
        insert(t[o].rs,t[o].rs,val,mid+1,e);
    }
}

int query(int lo,int ro,int l,int r,int s=0,int e=n){
    if(l<=s&&e<=r)return t[ro].val-t[lo].val;
    int mid=(s+e)>>1,res=0;
    if(mid>=l)res+=query(t[lo].ls,t[ro].ls,l,r,s,mid);
    if(mid+1<=r)res+=query(t[lo].rs,t[ro].rs,l,r,mid+1,e);
    return res;
}
void dd(){
    std::cin>>n>>q;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        x.emplace_back(a[i]);
    }
    //离散化，去重
    std::sort(x.begin(),x.end());
    x.erase(std::unique(x.begin(),x.end()),x.end());

    for(int i=1;i<=n;i++){
        insert(rt[i],rt[i-1],lst[bin(a[i])]);
        lst[bin(a[i])]=i;
    }

    while(q--){
        int l,r,k;
        std::cin>>l>>r;
        std::cout<<query(rt[l-1],rt[r],0,l-1)<<'\n';
    }
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
/*    std::cin>>_;*/
    while(_--)dd();
    return 0;
}