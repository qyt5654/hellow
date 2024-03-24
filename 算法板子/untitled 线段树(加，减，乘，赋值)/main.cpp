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
int a[N],n,t[4*N],ad[4*N],mul[4*N];
int mo(int x){
    return (x%mod+mod)%mod;
}
void pushup(int p){
    t[p]=mo(t[pl]+t[pr]);
}
void update(int s,int e,int p,int k,int x){
    t[p]=mo(mo(t[p]*k)+mo((e-s+1)*x));
    mul[p]=mo(mul[p]*k);
    ad[p]=mo(mo(ad[p]*k)+x);
}
void pushdown(int s,int e,int p){
    int mid=(s+e)>>1;
    update(s,mid,pl,mul[p],ad[p]);
    update(mid+1,e,pr,mul[p],ad[p]);
    mul[p]=1;//下放完毕
    ad[p]=0;
}
void buildtree(int s,int e,int p){
    mul[p]=1;
    if(s==e){
        t[p]=a[s];
        return;
    }
    int mid=(s+e)>>1;
    buildtree(s,mid,pl);
    buildtree(mid+1,e,pr);
    pushup(p);
}
void add(int l,int r,int k,int x,int s,int e,int p){
    if(l<=s&&r>=e){
        update(s,e,p,k,x);
        return;
    }
    pushdown(s,e,p);
    int mid=(s+e)>>1;
    if(mid>=l)add(l,r,k,x,s,mid,pl);
    if(mid+1<=r)add(l,r,k,x,mid+1,e,pr);
    pushup(p);
}
int query(int l,int r,int s,int e,int p){
    if(l<=s&&r>=e){
        return t[p];
    }
    int res=0,mid=(s+e)>>1;
    pushdown(s,e,p);
    if(mid>=l)res=mo(res+query(l,r,s,mid,pl));
    if(mid+1<=r)res=mo(res+query(l,r,mid+1,e,pr));
    return res;
}
void dd(){//f(val,k,x)=val*k+x
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
            add(l,r,1,d,1,n,1);
        }
        if(x==2){
            int l,r,d;
            std::cin>>l>>r>>d;
            add(l,r,d,0,1,n,1);
        }
        if(x==3){
            int l,r,d;
            std::cin>>l>>r>>d;
            add(l,r,0,d,1,n,1);
        }
        if(x==4){
            int l,r;
            std::cin>>l>>r;
            std::cout<<mo(query(l,r,1,n,1))<<'\n';
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