struct info {
  int u, v, w;
};
int parent[N], sz[N];
void initialize(int n) {
  for(int i=0;i<=n;i++) {
    parent[i] = i;
    sz[i] = 1;
  }
}
int root(int x) {
  if(parent[x] == x) return x;
  return parent[x] = root(parent[x]);
}
void merge(int x, int y) {
  int p = root(x);
  int q = root(y);
  if(sz[p] > sz[q]) {
    parent[p] = parent[q];
    sz[p] += sz[q];
    sz[q] = 0;
  }
  else {
    parent[q] = parent[p];
    sz[q] += sz[p];
    sz[p] = 0;
  }
}
// v should be already sorted according to weight
LL kruskal(int n, vector<info> &v) {
  initialize(n);
  LL cost = 0;
  for(auto cur : v) {
    if(root(cur.u) != root(cur.v)) {
      cost += cur.w;
      merge(cur.u, cur.v);
    }
  }
  return cost;
}
// PRIM'S SPANNING TREE (MST)
bool marked[N];
vector<PII> adj[N]; // adj[from] -> {weight, to}

int prim(int n, int src) {
  for(int i=1;i<=n;i++) marked[i] = false;
  priority_queue<PII, vector<PII>, greater<PII> > pq;
  int cost = 0;
  pq.push({0, src});
  while(!pq.empty()) {
    PII cur = pq.top(); pq.pop();
    if(marked[cur.second]) continue;
    cost += cur.first;
    marked[cur.second] = true;
    cc++;
    for(auto next : adj[cur.second]) {
      if(!marked[next.second]) pq.push(next);
    }
  }
  return cost;
}
