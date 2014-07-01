#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int W, n;
	cin >> W >> n;
	vector<int> v(n + 1, 0);
	vector<int> w(n + 1, 0);
	vector<vector<int>> A(n + 1, vector<int>(W + 1, 0));

	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	for (int x = 0; x <= W; x++) A[0][x] = 0;

	for (int i = 1; i <= n; i++){
		for (int x = 0; x <= W; x++){
			int temp = x > w[i] ? A[i - 1][x - w[i]] + v[i] : INT_MIN;
			A[i][x] = max(A[i - 1][x], temp);
		}
	}
	cout << A[n][W] << endl;


}