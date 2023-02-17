#include <fstream>
#include <iostream>
using namespace std;
#define ll long long
const ll maxn = 1e6 + 7;
ll n , x , a[maxn],t;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("ways.inp" , "r" , stdin);
	//freopen("ways.out" , "w" , stdout);
	cin >> t;
	while(t != 0){
		ll right = 1 , left = 1 , cnt = 0 , sum = 0;
		cin >> n >> x;
		for(int i = 1 ; i <= n ; i++) cin >> a[i];
		while(right <= n){
			sum = sum + a[right];
			while(sum >= x){
				if(sum == x) cnt++;
				sum = sum - a[left];
				left++;
			}
			right++;
		}
		if(cnt == 0 ) cout << "HUHU" << endl;
		else cout << cnt << endl;
		t--;
	}
	return 0;
}