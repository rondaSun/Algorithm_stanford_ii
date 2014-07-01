#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsack(vector<int> v, vector<int> w, int W, int n){
	vector<int> A(W + 1, 0);

	for (int i = 1; i <= n; i++){
		for (int x = W; x >= 0; x--){
			int temp = x > w[i] ? A[x - w[i]] + v[i] : INT_MIN;
			A[x] = max(A[x], temp);
		}
	}
	return A[W];

}

int main(){
	int W, n;
	cin >> W >> n;
	vector<int> v(n + 1, 0);
	vector<int> w(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

	cout << knapsack(v, w, W, n) << endl;
	return 0;
}