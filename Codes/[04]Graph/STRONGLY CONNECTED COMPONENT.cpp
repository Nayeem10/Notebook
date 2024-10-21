vii adj[MAXN], rev_adj[MAXN], components[MAXN];
vii visited(MAXN), toposorted;
ll cnt = 0;
void dfs(ll now)
{
  visited[now] = 1;
  for(auto next : adj[now]) {
      if(!visited[next]) dfs(next);
  }
  toposorted.pb(now);
}
void dfs2(ll now){
  visited[now] = 1;
  components[cnt].pb(now);
  for(auto next : rev_adj[now]) {
      if(!visited[next]) dfs(next);
  }
}
void strongly_connected_component(ll n, ll m){
  visited.assign(n + 1, 0);
  for(ll i=0;i<m;i++) {
    ll a, b; cin >> a >> b;
    adj[a].pb(b);
    rev_adj[b].pb(a);
  }
  for(ll i=1;i<=n;i++) {
      if(!visited[i]) dfs(i);
  }
  reverse(all(toposorted));
  visited.assign(n + 1, 0);
  for(auto now : toposorted) {
      if(!visited[now]) {
          dfs2(now); cnt++;
      }
  }
}
