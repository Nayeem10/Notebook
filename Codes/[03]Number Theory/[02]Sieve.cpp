mod = {1500000007, 1500000013, 1500000023, 1500000057, 1500000077};

const int N = 1e6;
int divisor[N+1];
void sieve(){
	for(int i=1;i<=N;i++) divsor[i]=i;
	for(int i=2;i<=N;i+=2) divisor[i]=2;
	for(int i=3;i<=N;i+=2){
		if(divisor[i]==i){
			for(int j=i*i;j<=N;j+=i){
				if(divisor[j]==j) divisor[j]=i;
			}
		}
	}
}
