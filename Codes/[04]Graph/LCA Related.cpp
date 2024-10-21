using vec = vector <int>;
using mat = vector <vector <int>>;
namespace ta {
  int time;
  void dfs(int u, int p, vec &par, vec &lvl, Tree &T) {
    for(int e: T[u]) {
      int v = T(e).to(u);
      if(v == p) continue;
      par[v] = u, lvl[v] = lvl[u] + 1;
      dfs(v, u, par, lvl, T);
    }
  }
  mat ancestorTable(vec &par) {
    int n = par.size(), sz = __lg(n) + 1;
    mat anc(sz, par);
    for(int k = 1; k < sz; k++) {
      for(int i = 0; i < n; i++) {
          anc[k][i] = anc[k - 1][anc[k - 1][i]];
      }
    }
    return anc;
  }
  int getAncestor(int u, int ht, mat &anc) {
    int sz = anc.size();
    for (int k = 0; k < sz; k++) {
        if (ht >> k & 1) u = anc[u][k];
    }
    return u;
  }
  bool isAncestor(int u, int par, vec &st, vec &en) {
      return st[par] <= st[u] and en[par] >= en[u];
  }
  int subtreeSize(int u, vec &st, vec &en) {
      return en[u] - st[u] + 1 >> 1;
  }
  int lca(int u, int v, vec &lvl, mat &anc) {
    if (lvl[u] > lvl[v]) swap(u, v);
    for (int k = anc.size() - 1; ~k; k--) {
        if (lvl[u] + (1 << k) <= lvl[v]) v = anc[k][v];
    }
    if (u == v) return u;
    for (int k = anc.size() - 1; ~k; k--) {
        if (anc[k][u] != anc[k][v]) u = anc[k][u], v = anc[k][v];
    }
    return anc[0][u];
  }
  int dis(int u, int v, vec &lvl, mat &anc) {
    int g = lca(u, v, lvl, anc);
    return lvl[u] + lvl[v] - 2 * lvl[g];
  }
}
