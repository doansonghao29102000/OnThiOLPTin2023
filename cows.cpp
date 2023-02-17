#include <fstream>
#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("cows.inp" , "r" , stdin);
	//freopen("cows.out" , "w" , stdout);
	long long n , s;
	cin >> n;
	cin >> s;
	cout<<((n+1)*n)/2 - s<<endl;
	return 0;
}