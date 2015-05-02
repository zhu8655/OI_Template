int CRT(int *a, int *m, int n){
	int M = 1;
	for (int i = 1; i <= n; i++) M *= (*(m+i));
	int ret = 0;
	for (int i = 1; i <= n; i++){
		int x, y, tm = M/(*(m+i));
		exGcd(tm, (*(m+i)), x, y);
		ret = (ret+tm*x*(*(a+i))) % M;
	}
	return (ret+M) % M;
}