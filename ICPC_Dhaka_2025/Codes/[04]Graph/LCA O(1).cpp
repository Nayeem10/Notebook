void dfs(int u, int p, int d, vector<int> g[], vector<pair<int, int>> &order, vector<int> &mp){
    for(auto v: g[u]){
        if(v == p) continue;
        order.push_back({d, u});
        dfs(v, u, d + 1, g, order, mp);
    }
    order.push_back({d, u});
    mp[u] = (int) order.size() - 1;
}

void solve(int tc) {
    vector<int> g[n + 1], mp(n + 1);
    vector<pair<int, int>> order;
    dfs(1, 0, 0, g, order, mp);
    SparsedTable<pair<int, int>> sp(order);
    auto lca = [&](int u, int v){
        if(mp[u] > mp[v]) swap(u, v);

        return sp.query(mp[u], mp[v]).second;
    };
    auto dis = [&](int u, int v){
        int w = lca(u, v);
        u = mp[u], v = mp[v], w = mp[w];
        return order[u].first + order[v].first - 2 * order[w].first;
    };
}