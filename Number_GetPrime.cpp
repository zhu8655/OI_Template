void getPrime(int n, int &tot, int *p){
	int vis[MAXN]; tot = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i <= n; i++){
		if (!vis[i]) *(p+(++tot)) = i;
		for (int j = 1; j <= tot; j++){
			if (i * (*(p+j)) > n) break;
			vis[i * (*(p+j))] = 1;
			if (i % (*(p+j)) == 0) break;
		}
	}
}