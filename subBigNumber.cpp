#include <fstream>
#include <iostream>
using namespace std;
bool isSmaller(string str1 , string str2)
{
	int n1 = str1.length();
	int n2 = str2.length();
	if(n1 < n2) return true;
	if(n1 > n2) return false;
	for(int i = 0 ; i < n1 ; i++){
		if(str1[i] < str2[i]) return true;
		else if(str1[i] > str2[i]) return false;
	}
	return false;
	
}
string subDiff(string str1 , string str2){
	
	if(isSmaller(str1 , str2) == true){
		swap(str1 , str2);
	}
	string str = "" ;
	int n1 = str1.length();
	int n2 = str2.length();
	reverse(str1.begin() , str1.end());
	reverse(str2.begin() , str2.end());
	int carry = 0;
	for(int i = 0 ; i < n2 ; i++){
		int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
		if(sub < 0){
			sub = sub + 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		str.push_back(sub + '0');
	}
	for(int i = n2 ; i < n1 ; i++){
		int sub = (str1[i] - '0') - carry;
		if(sub < 0){
			sub = sub + 10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		str.push_back(sub + '0');
	}
	reverse(str.begin() ,str.end());
	return str;
}
int main(){
	string s1 = "123457886";
	string s2 = "765543";
	cout << subDiff(s1,s2) << endl;
	return 0;
}