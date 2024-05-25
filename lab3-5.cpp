#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int,int> pii;


bool cmp(const pii &a, const pii &b) {
    return a.second>b.second;
}

int prim(vector<vector<int>> &graph, int V) {
    priority_queue<pii,vector<pii>,decltype(&cmp)>pq(cmp);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1); 
    vector<bool> inMST(V, false);

    
    key[0]=0;
    pq.push(make_pair(0,0));

    while (!pq.empty()) {
        int u=pq.top().second;
        pq.pop();

        if (!inMST[u]) {
            inMST[u]=true;

            for (int v=0; v<V;++v) {
                if (graph[u][v]&&!inMST[v]&&graph[u][v]<key[v]) {
                    pq.push(make_pair(graph[u][v],v));
                    key[v]=graph[u][v];
                    parent[v]=u;
                }
            }
        }
    }
    int mst_weight=0;
    for (int i=1; i<V;++i) {
        if (parent[i]!=-1) {
            mst_weight+=graph[parent[i]][i];
        }
    }

    return mst_weight;
}

int main() {
    int n,m;cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int r,c;cin>>r>>c;
        cin>>graph[r-1][c-1];
        graph[c-1][r-1]=graph[r-1][c-1];
    }

    cout <<prim(graph, n);

    return 0;
}