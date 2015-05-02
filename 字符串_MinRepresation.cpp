int minRepresation(char *s, int len) {
	int i = 0, j = 1, k;
	while (i < len && j < len) {
		k = 0;
		while (s[(i+k)%len] == s[(j+k)%len] && k < len) k++;
		if (k == len) return i;
		if (s[(i+k)%len] > s[(j+k)%len]) {
			if (i+k+1 > j) i = i+k+1;
			else i = j+1;
		}
		else {
			if (j+k+1 > i) j = j+k+1;
			else j = i+1;
		}
	}
	return (i < j ? i : j);
}