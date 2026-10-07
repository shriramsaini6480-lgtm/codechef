#include <bits/stdc++.h>
using namespace std;

struct Blossom {
    int n;
    vector<vector<int>> g;
    vector<int> match, p, base;
    vector<bool> used, flower;

    Blossom(int n):n(n),g(n),match(n,-1),p(n),base(n),used(n),flower(n){}
    void add(int a,int b){g[a].push_back(b);g[b].push_back(a);}

    int lca(int a,int b){
        vector<bool> seen(n);
        while(true){
            a=base[a];
            seen[a]=true;
            if(match[a]==-1) break;
            a=p[match[a]];
        }
        while(true){
            b=base[b];
            if(seen[b]) return b;
            b=p[match[b]];
        }
    }

    void mark(int v,int b,int child){
        while(base[v]!=b){
            flower[base[v]]=flower[base[match[v]]]=true;
            p[v]=child;
            child=match[v];
            v=p[match[v]];
        }
    }

    int find(int root){
        fill(used.begin(),used.end(),false);
        fill(p.begin(),p.end(),-1);
        iota(base.begin(),base.end(),0);
        queue<int> q;
        q.push(root);
        used[root]=true;

        while(!q.empty()){
            int v=q.front();q.pop();
            for(int u:g[v]){
                if(base[v]==base[u]||match[v]==u) continue;
                if(u==root||(match[u]!=-1&&p[match[u]]!=-1)){
                    int b=lca(v,u);
                    fill(flower.begin(),flower.end(),false);
                    mark(v,b,u);
                    mark(u,b,v);
                    for(int i=0;i<n;i++) if(flower[base[i]]){
                        base[i]=b;
                        if(!used[i]) used[i]=true,q.push(i);
                    }
                }else if(p[u]==-1){
                    p[u]=v;
                    if(match[u]==-1) return u;
                    u=match[u];
                    used[u]=true;
                    q.push(u);
                }
            }
        }
        return -1;
    }

    void solve(){
        for(int i=0;i<n;i++) if(match[i]==-1){
            int v=find(i);
            if(v==-1) continue;
            while(v!=-1){
                int pv=p[v],next=(pv==-1?-1:match[pv]);
                match[v]=pv;
                if(pv!=-1) match[pv]=v;
                v=next;
            }
        }
    }
};

bool good(int a,int b,int k){
    long long x=1LL*a*b;
    for(long long i=1;i*i<=x+k;i++)
        if(llabs(x-i*i)<=k) return true;
    return false;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int m=n+n%2;
        Blossom b(m);

        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(good(i,j,k)) b.add(i-1,j-1);

        if(n%2) for(int i=0;i<n;i++) b.add(i,n);
        b.solve();

        vector<pair<int,int>> pairs;
        int last=-1;
        for(int i=0;i<n;i++){
            int j=b.match[i];
            if(j==n) last=i+1;
            else if(j!=-1&&i<j) pairs.push_back({i+1,j+1});
        }

        if(pairs.size()*2+(last!=-1)!=n){cout<<-1<<'\n';continue;}
        for(auto [a,c]:pairs) cout<<a<<' '<<c<<' ';
        if(last!=-1) cout<<last;
        cout<<'\n';
    }
}