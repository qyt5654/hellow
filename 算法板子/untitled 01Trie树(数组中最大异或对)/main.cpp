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
int a[N];

struct node{
    int val;
    int son[2];
}t[N*32];
int idx;
void insert(int x){
    int o=0;
    t[o].val++;
    for(int i=30;i>=0;i--){
        //取出x的第i位
        int y=x>>i&1;
        int &u=t[o].son[y];
        if(!u)u=++idx;
        o=u;
        t[o].val++;
    }
}
int getmax(int x){
    int o=0,res=0;
    for(int i=30;i>=0;i--){
        //取出x的i位
        int y=x>>i&1;
        int u=t[o].son[y],v=t[o].son[!y];
        if(v){
            o=v,res|=(1<<i);
        }else{
            o=u;
        }
    }
    return res;
}
void dd(){
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)std::cin>>a[i];
    insert(a[1]);
    int ans=a[1]^a[2];
    for(int i=2;i<=n;i++){
        ans=std::max(ans,getmax(a[i]));
        insert(a[i]);
    }
    std::cout<<ans<<'\n';
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
//    std::cin>>_;
    while(_--)dd();
    return 0;
}