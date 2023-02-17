#include <fstream>
#include <iostream>
using namespace std;
const int maxn = 1001;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int a[maxn][maxn];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("coast.inp" , "r" ,stdin);
	//freopen("coast.out" , "w" , stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i<= n; i++){
		for(int j = 1; j<= m; j++){
			cin >> a[i][j];
		}
	}
	int c = 2;
	int res = 0;
	for(int i = 1; i<= n; i++){
		for(int j = 1; j<= m; j++){
			if(a[i][j] == 1){
				res++;
				for(int k = 0; k< 8; k++){
					if(a[i + dx[k]][j + dy[k]] == 0 && i + dx[k] >0 && i + dx[k] <= n && j + dy[k] > 0 && dy[k] + j <= m){
						res++;
						a[i + dx[k]][j + dy[k]] = c;
					}
				}
				c++;
			}
		}
	}
	cout << res;
}	