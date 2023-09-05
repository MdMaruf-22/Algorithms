#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	vector<vector<int> > K(n + 1, vector<int>(W + 1));
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1]
								+ K[i - 1][w - wt[i - 1]],
							K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	for(i=0;i<=n;i++){
		for(w=0;w<=W;w++){
			cout<<K[i][w]<<" ";
		}
		cout<<endl;
	}
	return K[n][W];
}
int main()
{
    int s,n;
    cin>>s>>n;
    int profit[n],weight[n];
    for(int i=0;i<n;i++) cin>>weight[i]>>profit[i];
	cout << knapSack(s, weight, profit, n);

	return 0;
}

// This code is contributed by Debojyoti Mandal
