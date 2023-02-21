#include <fstream>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 7;
const ll mod = 1e9 + 7;
pair<ll , ll> p[maxn];
ll a[maxn] ;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("connect.inp" , " r " , stdin);
	//freopen("connect.out" , " w " , stdout);
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		p[i].first = a[i];
		p[i].second = 0;
	}
	for(int i = n + 1 ; i <= 2*n ; i++){
		cin >> a[i];
		p[i].first = a[i];
		p[i].second = 1;
	}
	sort(p + 1 , p + 2*n + 1);
	ll cnt = 0 , ans = 1 ;
	for(int i = 1 ; i <= 2*n ; i++){
		if(p[i].second == 0){
			if(cnt < 0) ans = (1LL*ans*(-cnt))%mod;
			++cnt;
		}
		else{
			if(cnt > 0) ans = (1LL*ans*cnt)%mod;
			--cnt;
		}
		
	}
	cout << ans << endl;
	return 0 ;
}