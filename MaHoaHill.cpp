#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <string>
#include <map>
#include <cstdlib>
#include <conio.h>
typedef long long ll;
using namespace std;
char arrchar[97] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
    'o','p','q','r','s','t','u','v','w','x','y','z','A','B',
    'C','D','E','F','G','H','I','J','K','L','M','N','O','P',
    'Q','R','S','T','U','V','W','X','Y','Z',' ','~','`','!',
    '@','#','$','%','^','&','*','(',')','-','_','+','=','|',
    '\\','\"','\n','\t','{','[',']','}',':',';','\'','<',',',
    '.','>','?','/','0','1','2','3','4','5','6','7','8','9'};

struct matrix
{
	int row, col;
	vector< vector<ll> > data;
	matrix(int row1, int col1){
		row = row1;
		col = col1;
		data.resize(row);
		for(int i = 0; i < row; i++){
			data[i].resize(col);
		}
	}
};
bool ktra1(string s){
	if(s[0] == 48) return true;
	for(int i = 0; i < s.length(); i++){
		if(s[i] < 48 || s[i] > 57) return false;
	}
	return true;
}
bool ktra(string s){
	if(s[0] == 48) return false;
	for(int i = 0; i < s.length(); i++){
		if(s[i] < 48 || s[i] > 57) return false;
	}
	return true;
}
bool ktraXauHopLe(string s){
	for(int i = 0; i < s.length(); i++){
		if(s[i] < 0 || s[i] > 126 || s[i] == 63) return false;
	}
	return true;
}

ll toInteger(string s){
	long long sum = 0;
	for(int i = 0; i < s.length(); i++){
		sum = sum*10 + (s[i] - 48);
	}
	return sum;
}
int UCLN(int a, int b){
	 while ((a % b) != 0){
	     int c = a % b;
	     a = b;
	     b = c;
	 }
 	 return b;
}
matrix SinhMaTran(const matrix &M, int hang, int cot){
	matrix newMT(M.row - 1, M.col - 1);
	int newhang = 0;
	for(int i = 0; i < M.row; i++){
		if(i == hang) continue;
		int newcot = 0;
		for(int j = 0; j < M.col; j++){
			if(j == cot) continue;
			newMT.data[newhang][newcot] = M.data[i][j];
			newcot++;
		}
		newhang++;
	}
	return newMT;
}
ll determinant(const matrix &M){
	ll det = 0;
	if(M.row == 2){
		det = M.data[0][0]*M.data[1][1] - M.data[0][1]*M.data[1][0];
	}
	else{
		for(int j = 0; j < M.col; j++){
			matrix tmp = SinhMaTran(M, 0, j);
			det = det + M.data[0][j]*(int)pow(-1,j)*determinant(tmp);
		}
	}
	det = det % 97;
	if (det < 0) det = det + 97;
	return det;
}

ll Ideterminant(int det){
	int a1 = 1;
	int a2 = 0;
	int a3 = 97;
	int b1 = 0;
	int b2 = 1;
	int b3 = det;
	while ((b3 != 0) && (b3 != 1)){
	    int q = a3 / b3;
	    int t1 = a1 - q * b1;
	    int t2 = a2 - q * b2;
	    int t3 = a3 - q * b3;
	    a1 = b1;
	    a2 = b2;
	    a3 = b3;
	    b1 = t1;
	    b2 = t2;
	    b3 = t3;
	}
	if(b3 == 1)
	{
	    return b2;
	}
	return 0;
}

matrix SinhMaTranDao(const matrix &M, int det){
	matrix MT(M.row, M.col);
	matrix MTD(M.row, M.col);
	int Idet = Ideterminant(det);
 	Idet = Idet % 97;
	if(Idet < 0) Idet = Idet + 97;
	if(M.row == 2){
		ll a00 = Idet*M.data[1][1];
		a00 = a00 % 97;
		if(a00 < 0) a00 = a00 + 97;
		
		ll a01 = (-1)*Idet*M.data[1][0];
		a01 = a01 % 97;
		if(a01 < 0) a01 = a01 + 97;
		
		ll a10 = (-1)*Idet*M.data[0][1];
		a10 = a10 % 97;
		if(a10 < 0) a10 = a10 + 97;
		
		ll a11 = Idet*M.data[0][0];
		a11 = a11 % 97;
		if(a11 < 0) a11 = a11 + 97;
		
		MTD.data[0][0] = a00;
		MTD.data[0][1] = a10;
		MTD.data[1][0] = a01;
		MTD.data[1][1] = a11;
	}
	else{
		for(int i = 0; i < M.row; i++){
			for(int j = 0; j < M.col; j++){
				matrix tmpMT(M.row - 1, M.col - 1);
				tmpMT = SinhMaTran(M, i, j);
				MT.data[i][j] = (int)pow(-1,(i+j))*determinant(tmpMT);
				MT.data[i][j] = (MT.data[i][j]*Idet) % 97;
				if(MT.data[i][j] < 0) MT.data[i][j] = MT.data[i][j] + 97;
				MTD.data[j][i] = MT.data[i][j];
			}
		}
	}
	return MTD;
}
int main(){
	map<char, int> mp;
	for(int i = 0; i < 97; i++){
		mp[arrchar[i]] = i;
	}
	while(true){
		string siz;
		int k;
		while(true){
		  	cout << "Nhap vao do lon cua ma tran vuong K: ";;
		    getline(cin, siz);
		    if (siz == "") {
		      cout << "Nhap sai dinh dang. Hay nhap lai!" << endl;
		    }
		    else if(ktra(siz) == false){
		    	cout << "Nhap sai dinh dang. Hay nhap lai!" << endl;
		    }
		    else if(siz[0] == 45){
		    	cout << "Do lon ma tran vuong phai la mo so nguyen duong lon hon 2. Hay nhap lai!" << endl;
		    }
		    else if(toInteger(siz) < 2){
	    		cout << "Do lon ma tran vuong phai la mo so nguyen duong lon hon 2. Hay nhap lai!" << endl;
	    	}
	    	else{
	    		k = toInteger(siz);
	    		break;
	    	}
	    	
		}
		matrix MT(k,k);
		string br;
		bool check = true;
		int kt = 0;
		int sel;
		string lc;
		while(check){
			cout << "===========MENU=========" << endl;
			cout << "1. Sinh Ma Tran Vuong" << endl;
			cout << "2. Nhap Ma Tran Vuong" << endl;
			cout << "3. Ma Hoa" << endl;
			cout << "4. Giai Ma" << endl;
			cout << "5. Thoat" << endl;
			cout << "===========END=========" << endl;
	  		while(true){
			  	cout << "Nhap vao lua chon: ";;
			    getline(cin, lc);
			    if (lc == "") {
			      cout << "Nhap sai dinh dang. Hay nhap lai!" << endl;
			    }
			    else if(ktra(lc) == false){
			    	cout << "Nhap sai dinh dang. Hay nhap lai!" << endl;
			    }
			    else if(lc[0] == 45){
			    	cout << "Lua chon phai la 1 so nguyen duong. Hay nhap lai!" << endl;
			    }
			    else if(toInteger(lc) < 1 || toInteger(lc) > 6){
		    		cout << "Lua phai la 1 so nguyen duong tu 1 den 5. Hay nhap lai!" << endl;
		    	}
		    	else{
		    		sel = toInteger(lc);
		    		break;
		    	}
		  	}
		    if(sel == 1){
				kt = 1;
				int x;
				srand(time(0));
				for(int i = 0; i < k; i++){
					for(int j = 0; j < k; j++){
						x = rand()%96 + 1;
						MT.data[i][j] = x;
					}
				}
				cout << "Ma Tran Vuong K" << endl;
				for(int i = 0; i < k; i++){
					for(int j = 0; j < k; j++){
						cout << MT.data[i][j] << " ";
					}
					cout << endl;
				}
				int det = determinant(MT);
				if(UCLN(det, 97) > 1){
					cout << "Ma tran vuong K khong co ma tran kha dao" << endl;
				}
				else{
					cout << "Ma tran vuong K co ma tran kha dao" << endl;
				}	
			}
			else if(sel == 2){
				kt = 1;
				int res;
				string ele;
				cout << "Nhap thong tin ma tran vuong K" << endl;
				for(int i = 0; i < k; i++){
					for(int j = 0; j < k; j++){
						while(true){
								cout << "A[" << i << "][" << j << "] = ";
							    getline(cin, ele);
							    if (ele == "") {
							      cout << "Nhap sai dinh dang. Hay nhap lai!" << endl;
							    }
							    else if(ktra1(ele) == false){
							    	cout << "Nhap sai dinh dang. Hay nhap lai!" << endl;
							    }
							    else if(ele[0] == 45){
							    	cout << "Lua chon phai la 1 so nguyen duong. Hay nhap lai!" << endl;
							    }
						    	else{
						    		res = toInteger(ele);
						    		break;
						    	}
						  	}		
						MT.data[i][j] = res%97;
					}
				}
				cout << "Ma Tran Vuong K" << endl;
				for(int i = 0; i < k; i++){
					for(int j = 0; j < k; j++){
						cout << MT.data[i][j] << " ";
					}
					cout << endl;
				}
				int det = determinant(MT);
				if(UCLN(det, 97) > 1){
					cout << "Ma tran vuong K khong co ma tran kha dao" << endl;
				}
				else{
					cout << "Ma tran vuong K co ma tran kha dao" << endl;
				}
			}
			else if(sel == 3){
				if(kt == 0) cout << "Hay nhap thong tin cho ma tran vuong K" << endl;
				else{
					int det = determinant(MT);
					if(UCLN(det, 97) > 1){
						cout << "Ma tran vuong K khong co ma tran kha dao" << endl;
					}
					else{
						while(true){
			  				cout << "Nhap Vao Ban Ro: ";;
			    			getline(cin, br);
			    			if (br == "") {
			      					cout << "Nhap sai dinh dang. Hay nhap lai!" << endl;
			    			}
			    			else if(ktraXauHopLe(br) == false){
			    					cout << "Nhap sai dinh dang. Hay nhap lai!" << endl;
			    			}
			    			else{
		    					break;
	    					}
		  				}
						int du = br.size()/k;
						string s1 = br.substr(0, du*k);
						string s2 = br.substr(du*k);
						string ss = "";
						for(int i = 0; i < s1.size(); i = i + k){
							vector<int> v;
							for(int j = i; j < i + k; j++){
								v.push_back(mp[s1[j]]);
							}
							for(int j = 0; j < k; j++){
								ll sum = 0;
								for(int x = 0; x < k; x++){
									sum = sum + MT.data[x][j]*v[x];
								}
								sum = sum % 97;
								if(sum < 0) sum = sum + 97;
								ss = ss + arrchar[sum];
							}
						}
						cout << "Ban Ma: " << ss + s2 << endl;
					}
				}	
			}
			else if(sel == 4){
				if(kt == 0) cout << "Hay nhap thong tin cho ma tran vuong K" << endl;
				else{
					int det = determinant(MT);
					if(UCLN(det, 97) > 1){
						cout << "Ma tran vuong K khong co ma tran kha dao" << endl;
					}
					else{
						cout << "Sinh Ma Tran Dao Cua Ma Tran Vuong K" << endl;
						int det = determinant(MT);
						matrix MTD = SinhMaTranDao(MT, det);
						for(int i = 0; i < MTD.row; i++){
							for(int j = 0; j < MTD.col; j++){
								cout << MTD.data[i][j] << " ";
							}
							cout << endl;
						}
						while(true){
			  				cout << "Nhap Vao Ban Ma: ";;
			    			getline(cin, br);
			    			if (br == "") {
			      					cout << "Nhap sai dinh dang. Hay nhap lai!" << endl;
			    			}
			    			else if(ktraXauHopLe(br) == false){
			    					cout << "Nhap sai dinh dang. Hay nhap lai!" << endl;
			    			}
			    			else{
		    					break;
	    					}
		  				}
						int du = br.size()/k;
						string s1 = br.substr(0, du*k);
						string s2 = br.substr(du*k);
						string ss = "";
						for(int i = 0; i < s1.size(); i = i + k){
							vector<int> v;
							for(int j = i; j < i + k; j++){
								v.push_back(mp[s1[j]]);
							}
							for(int j = 0; j < k; j++){
								ll sum = 0;
								for(int x = 0; x < k; x++){
									sum = sum + MTD.data[x][j]*v[x];
								}
								sum = sum % 97;
								if(sum < 0) sum = sum + 97;
								ss = ss + arrchar[sum];
							}
						}
						cout << "Ban Ro: " << ss + s2 << endl;
					}
				}
			}
			else if(sel == 5){
				check = false;
				cout << endl;
				cout << endl;
			}
		}
	}
	return 0;	
}
/*
map<char, int> mp;
	for(int i = 0; i < 97; i++){
		mp[arrchar[i]] = i;
	}
	cout << char(10) << " " << endl;
	cout << mp[char(10)] << " ";
	return 0;*/