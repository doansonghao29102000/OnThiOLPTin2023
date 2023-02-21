#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e6 + 7 ;
int a[maxn] ;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("house.inp" , "r" ,stdin);
	//freopen("house.out" , "w" , stdout);
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	vector<int> v , s;
	v.push_back(a[n]);
	int z = 0;
	for(int i = n-1 ; i > 1 ; i--){
		if(a[i] < v[z]){
			v.push_back(a[i]);
		}
		else{
			v.push_back(v[z]);
		}	
		z++;
	}
	for(int i = v.size() - 1 ; i >= 0 ; i--){
		s.push_back(v[i]);
	}
	int max = -1;
	for(int i = 1 ; i <= n-1 ; i++){
		if(a[i] < s[i-1]) a[i] = -2;
		else{
			a[i] = a[i] - s[i-1];
		}
		if(max < a[i]) max = a[i];
	}

	if(max != -1) cout << max << endl;
	else cout << "Lo nang roi!"<< endl;
	return 0;
}