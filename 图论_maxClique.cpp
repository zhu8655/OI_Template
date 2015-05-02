struct maxClique{
	int g[MAXN][MAXN], dp[MAXN], stack[MAXN][MAXN], ans;
	
	bool dfs(int tot, int step) {
		int i, j, u, cnt;
		if (tot == 0) {
			if (step > ans) {
				ans = step;
				return 1;
			}
			else return 0;
		}
		for (i = 1; i <= tot; i++) {
			u = stack[step][i];
			if (step+n-u+1 <= ans) return 0;
			if (step+dp[u] <= ans) return 0;
			cnt = 0;
			for(j = i+1; j <= tot; j++) {
				if (g[u][stack[step][j]])
					stack[step+1][++cnt] = stack[step][j];
			}
			if (dfs(cnt, step+1)) return 1;
		}
		return 0;
	}
	int solve(){
		int i, j, cnt; ans = 1;
		memset(dp, 0, sizeof(dp));
		for (i = n; i >= 1; i--) {
			cnt = 0;
			for(j = i+1; j <= n; j++)
				if (g[i][j]) stack[1][++cnt] = j;
			dfs(cnt, 1);
			dp[i] = ans;
		}
		return ans;
	}
};