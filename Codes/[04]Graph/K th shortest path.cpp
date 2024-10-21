void K_shortest(int n,int m){
	int st,des,k,u,v;
	LL w;
	scanf("%d%d%d", &st,&des,&k);
	st--,des--;
	vector <vector<pii > > edges(n);
	for(int i=0;i<m;i++){
		scanf("%d%d%lld", &u,&v,&w);
		u--,v--;
		edges[u].push_back({w,v});
	}
	vector < vector <LL> > dis(n,vector <LL> (k+1,1e8));
	vector <int> vis(n);
	priority_queue <pii ,vector <pii >, greater< pii > > q;

	q.emplace(0LL,st);
	while(!q.empty()){
		v = q.top().second, w = q.top().first;
		q.pop();
		if(vis[v]>=k) continue;
		// for the varient, check if this path is greater than previous, if not, continue
		//if(vis[v]>0 && w == dis[v][vis[v]-1]) continue;
		dis[v][vis[v]] = w;
		vis[v]++;
		for(auto nd:edges[v]){
			q.emplace(w+nd.first,nd.second);
		}
	}
	LL ans = dis[des][k-1];
	if(ans==1e8) ans = -1;
	printf("%lld\n", ans);
}
