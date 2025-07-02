#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 2005;
int N;
vector<int> adj[MAXN];
int P[MAXN];

// for LCA
int up[12][MAXN], depth[MAXN];

// bitsets holding labels on path from root to u
bitset<MAXN> path_bits[MAXN];

// preprocess distances to leaf and assign P[]
void computeDistanceToLeafAndLabels() {
    vector<int> dist(N+1, -1);
    queue<int> q;
    vector<bool> isLeaf(N+1, true);
    for(int u=1;u<=N;u++){
        if(adj[u].size()>1) isLeaf[u]=false;
        if(isLeaf[u]){
            dist[u]=0;
            q.push(u);
        }
    }
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v:adj[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    vector<pair<int,int>> A;
    A.reserve(N);
    for(int u=1;u<=N;u++){
        A.emplace_back(dist[u],u);
    }
    sort(A.begin(),A.end());
    for(int i=0;i<N;i++){
        P[A[i].second] = i;
    }
}

// dfs to set up[0], depth, and path_bits
void dfs(int u,int p){
    up[0][u]=p;
    depth[u] = (p<0?0:depth[p]+1);
    if(p<0) path_bits[u].reset();
    else       path_bits[u] = path_bits[p];
    path_bits[u].set(P[u]);
    for(int v:adj[u]) if(v!=p){
        dfs(v,u);
    }
}

// binary‐lift LCA
int lca(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);
    int diff = depth[u]-depth[v];
    for(int k=0;k<12;k++){
        if(diff&(1<<k)) u = up[k][u];
    }
    if(u==v) return u;
    for(int k=11;k>=0;k--){
        if(up[k][u]!=up[k][v]){
            u = up[k][u];
            v = up[k][v];
        }
    }
    return up[0][u];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=1;i<=N;i++){
            adj[i].clear();
        }
        for(int i=0,u,v;i<N-1;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 1) label by distance to nearest leaf
        computeDistanceToLeafAndLabels();

        // 2) pick 1 as root (any), build LCA & path_bits
        dfs(1, -1);
        for(int k=1;k<12;k++){
            for(int u=1;u<=N;u++){
                up[k][u] = (up[k-1][u]<0 ? -1 : up[k-1][ up[k-1][u] ]);
            }
        }

        // 3) sum over all pairs u<=v
        long long ans = 0;
        bitset<MAXN> tmp;
        for(int u=1;u<=N;u++){
            for(int v=u;v<=N;v++){
                int w = lca(u,v);
                tmp = path_bits[u] | path_bits[v];
                // remove ancestors above w
                if(up[0][w]>=1){
                    tmp &= ~path_bits[ up[0][w] ];
                }
                // find smallest k s.t. tmp[k]==0
                int mex=0;
                while(tmp.test(mex)) ++mex;
                ans += mex;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

