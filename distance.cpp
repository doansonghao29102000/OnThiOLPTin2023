#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 7 ;
const ll mod = 1e9 + 7 ;
ll a[maxn] , b[maxn] , segtree[maxn] , treemin[4*maxn];
void buildMin(int id , int l , int r){
	if(l == r){
		treemin[id] = segtree[l];
		return ;
	}
	int mid = (l + r)/2;
	buildMin(id*2 , l , mid);
	buildMin(id*2 + 1 , mid + 1 , r);
	treemin[id] = min(treemin[id*2] , treemin[id*2 + 1]);
}
ll getValMin(int id , int l , int r , int u , int v){
	if(l > v || r < u){
		return mod ;
	}
	if(u <= l &&  r <= v){
		return treemin[id];
	}
	int mid = (l + r)/2;
	return min(getValMin(id*2 , l , mid , u , v) , getValMin(id*2 + 1 , mid + 1 , r , u , v));
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("distance.inp" ,"r" , stdin);
	//freopen("distance.out" , "w" , stdout);
	int m , n , k;
	cin >> m >> n >> k;
	for(int i = 1 ; i <= m ; i++) cin>>a[i];
	for(int i = 1 ; i <= n ; i++) cin>>b[i];
	sort(b + 1 , b + n + 1);
	for(int i = 1 ; i <= m ; i++){
		if(a[i] <= b[1]){
			segtree[i] = abs(a[i] - b[1]);
		}
		else if(a[i] >= b[n]){
			segtree[i] = abs(a[i] - b[n]);
		}
		else{
			int left = 1;
			int right = n;
			int cnt = 0;
			while(left <= right){
				int mid = (left + right)/2;
				if(a[i] == b[mid]){
					cnt++;
					break;
				}
				else if(a[i] > b[mid]){
					left = mid + 1;
				}
				else if(a[i] < b[mid]){
					right = mid - 1;
				}
			}
			if(cnt == 1){
				segtree[i] = 0;
			}
			else{
				segtree[i] = min(abs(a[i] - b[right]),abs(a[i] - b[left]));
			}
		}
	}
	buildMin(1 , 1 , m);
	while(k--){
		int L , R ;
		cin >> L >> R ;
		cout << getValMin(1 , 1 , m , L , R) << endl;
	}
	
	return 0;
}