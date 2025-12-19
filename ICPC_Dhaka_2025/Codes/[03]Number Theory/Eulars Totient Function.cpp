void phi_in_range() {
  int N = 1e6, phi[N + 1];
  for (int i = 0; i <= N; i++) phi[i] = i;
  for (int i = 2; i <= N; i++) {
    if (phi[i] != i) continue;
    for (int j = i; j <= N; j += i) {
      phi[j] -= phi[j] / i;
    }
  }
}
/* some important properties of phi 
phi(a * b) = phi(a) * phi(b) * (gcd(a, b) / phi(gcd(a, b))) 
phi(p ^ k) = p ^ k - p ^ (k - 1), where p is a prime number 
SUM{phi(d)} = n, d | n */