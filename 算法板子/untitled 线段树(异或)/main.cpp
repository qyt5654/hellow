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
int a[N],n,t[4*N],lz[4*N];
void pushup(int p){
    t[p]=t[pl]^t[pr];
}
void pushdown(int s,int e,int p){
    if(!lz[p])return;
    int mid=(s+e)>>1;
    t[pl]^=((mid-s+1)&1)?lz[p]:0;//更新权值
    t[pr]^=((e-mid)&1)?lz[p]:0;
    lz[pl]^=lz[p];//更新懒标记
    lz[pr]^=lz[p];
    lz[p]=0;//下放完毕
}
void buildtree(int s,int e,int p){
    if(s==e){
        t[p]=a[s];
        return;
    }
    int mid=(s+e)>>1;
    buildtree(s,mid,pl);
    buildtree(mid+1,e,pr);
    pushup(p);
}
void add(int l,int r,int x,int s,int e,int p){
    if(l<=s&&r>=e){
        t[p]^=((e-s+1)&1)?x:0;
        lz[p]^=x;
        return;
    }
    pushdown(s,e,p);
    int mid=(s+e)>>1;
    if(mid>=l)add(l,r,x,s,mid,pl);
    if(mid+1<=r)add(l,r,x,mid+1,e,pr);
    pushup(p);
}
int query(int l,int r,int s,int e,int p){
    if(l<=s&&r>=e){
        return t[p];
    }
    int res=0,mid=(s+e)>>1;
    pushdown(s,e,p);
    if(mid>=l)res^=query(l,r,s,mid,pl);
    if(mid+1<=r)res^=query(l,r,mid+1,e,pr);
    return res;
}
void dd(){
    int m;
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)std::cin>>a[i];
    buildtree(1,n,1);
    while(m--){
        int x;
        std::cin>>x;
        if(x==1){
            int l,r,d;
            std::cin>>l>>r>>d;
            add(l,r,d,1,n,1);
        }else{
            int l,r;
            std::cin>>l>>r;
            std::cout<<query(l,r,1,n,1)<<'\n';
        }
    }
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
/*    std::cin>>_;*/
    while(_--)dd();
    return 0;
}