#include<iostream>
#include<set>
using namespace std;

#define MAXD 100002

int main() {
	int T=0, D=0, M=0, overshoot=0, res=0;
	set<int> free;
	set<int>::iterator it, iter;
	for (int i = 1; i <= MAXD; i++) {
		free.insert(i);
	}

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> D >> M;
		it = free.upper_bound(D);
		iter = it;
		while (it != free.begin() && M > 0) {
			it--;
			M--;
		}
		free.erase(it, iter);
		overshoot += M;
		cout << overshoot << endl;
	}
    
	return 0;
}