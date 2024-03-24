//路径压缩版本（下方为启发式合并）
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
int pre[N],sz[N],top,d[N];
std::pair<int,int>stk[N];
int mo(int x){return (x%2+2)%2;};
int find(int x){
    if(pre[x]==x)return x;
    int fa=pre[x];
    pre[x]=find(pre[x]);
    d[x]+=d[fa];
    return pre[x];
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    pre[fx]=fy;
    d[fx]=mo(d[x]-d[y]+1);
}
void dd(){
    int n,q;
    std::cin>>n>>q;
    for(int i=1;i<=n;i++)pre[i]=i,sz[i]=1,d[i]=0;
    while(q--){
        int op,x,y;
        std::cin>>op>>x>>y;
        if(op==1)merge(x,y);
        else{
            int rx=find(x),ry=find(y);
            if(rx!=ry)std::cout<<"Unknown\n";
            else if(mo(d[x]-d[y])){
                std::cout<<"NO\n";
            }else{
                std::cout<<"YES\n";
            }
        }
    }

}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
//    std::cin>>_;
    while(_--)dd();
    return 0;
}
//启发式合并
/*#include<bits/stdc++.h>
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
int pre[N],sz[N],top,d[N];
std::pair<int,int>stk[N];
int mo(int x){return (x%2+2)%2;};
int find(int x){
    return pre[x]==x?x:find(pre[x]);
}
//求x到根的距离
int getd(int x){
    int res=0;
    while(pre[x]!=x){
        res+=d[x];
        x=pre[x];
    }
    return res;
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    if(sz[fx]>sz[fy])std::swap(fx,fy);
    pre[fx]=fy;
    sz[fy]+=sz[fx];
    d[fx]=mo(getd(x)-getd(y)+1);
}
void dd(){
    int n,q;
    std::cin>>n>>q;
    for(int i=1;i<=n;i++)pre[i]=i,sz[i]=1,d[i]=0;
    while(q--){
        int op,x,y;
        std::cin>>op>>x>>y;
        if(op==1)merge(x,y);
        else{
            int rx=find(x),ry=find(y);
            if(rx!=ry)std::cout<<"Unknown\n";
            else if(mo(getd(x)-getd(y))){
                std::cout<<"NO\n";
            }else{
                std::cout<<"YES\n";
            }
        }
    }

}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
//    std::cin>>_;
    while(_--)dd();
    return 0;
}*/