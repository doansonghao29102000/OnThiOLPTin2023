#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[15] ;
bool kTraChuoi(string s){
	if(s.size() == 0) return false;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == 'X') return false;
	}
	if(s.size() == 1) return true;
	else{
		for(int i = 0 ; i < s.size()/2 ; i++){
			if(s[i] != s[s.size() - 1 - i]){
				return false ;
			}
		}
		return true ;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("cutstr.inp" , "r" , stdin);
	//freopen("cutstr.out" , "w" , stdout);
	string s1;
	cin >> s1;
	int T;
	cin >> T;
	while(T--){
		int k;
		cin >> k;
		int z = 0;
		for(int i = 1 ; i <= k ; i++){
			cin >> a[i];
		}
		string s = s1 ;
		sort(a + 1 , a + 1 + k , greater<int>());
		for(int i = 1 ; i <= k ; i++){
			for(int j = 0 ; j <= s.size() - a[i] ; j++){
				if(kTraChuoi(s.substr(j,a[i])) == true){
					z++;
					if(j == 0) s = s.substr(a[i]);
					else s = s.substr(0, j) + "X" + s.substr(j + a[i] , s.size() - j - a[i]);
					break;
				}
			}
		}
		if(z == k) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}