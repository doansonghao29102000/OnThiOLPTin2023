#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
	string str1 , str2;
	cin >> str1 >> str2;
	reverse(str1.begin() , str1.end());
	reverse(str2.begin() , str2.end());
	if(str1.length() > str2.length()){
		swap(str1,str2) ;
	}
	string str = "";
	int n1 = str1.length();
	int n2 = str2.length();
	int carry = 0;
	for(int i = 0 ; i < n1 ; i++){
		int sum = ((str1[i] - 48) + (str2[i] - 48)) + carry ;
		str.push_back(sum%10 + '0');
		carry = sum / 10 ;
	}
	for(int i = n1 ; i < n2 ; i++){
		int sum = (str2[i] - 48) + carry;
		str.push_back(sum%10 + '0');
		carry = sum / 10;
	}
	if(carry == 1){
		str.push_back(carry + '0');
	}
	reverse(str.begin(),str.end());
	cout << str << endl;
	return 0;
}