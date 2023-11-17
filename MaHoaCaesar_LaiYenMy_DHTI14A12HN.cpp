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
		if(s[i] < 32 || s[i] > 126) return false;
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
int main(){
	map<char, int> mp;
	for(int i = 0; i < 97; i++){
		mp[arrchar[i]] = i;
	}
	string br;
	string bm;
	int kt = 0;
	int sel, k;
	string lc;
	while(true){
        cout << "======MENU=====" << endl;
        cout << "1. Nhap khoa K" << endl;
        cout << "2. Sinh khoa K" << endl;
        cout << "3. Ma Hoa" << endl;
        cout << "4. Giai Ma" << endl;
        cout << "5. Thoat" << endl;
        cout << "=======END=====" << endl;
        
  		while(true){
		  	cout << "Nhap vao lua chon: ";;
		    getline(cin, lc);
		    if (lc == "") {
		      cout << "Lua phai la 1 so nguyen duong tu 1 den 5. Hay nhap lai!" << endl;
	    	}
		    else if(ktra(lc) == false){
		    	cout << "Lua phai la 1 so nguyen duong tu 1 den 5. Hay nhap lai!" << endl;
	    	}
		    else if(lc[0] == 45){
		    	cout << "Lua phai la 1 so nguyen duong tu 1 den 5. Hay nhap lai!" << endl;
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
			string ele;
			while(true){
				cout << "Nhap Vao Khoa K: ";
			    getline(cin, ele);
			    if (ele == "") {
			      cout << "Nhap sai dinh dang. Hay nhap lai!" << endl;
			    }
			    else if(ktra1(ele) == false){
	    			cout << "K phai la 1 so nguyen. Hay nhap lai!" << endl;
				}
	    		else if(ele[0] == 45){
	    			cout << "K phai la 1 so nguyen. Hay nhap lai!" << endl;
				}
				else{
					k = toInteger(ele);
					cout<<"Khoa K sinh thu cong da duoc luu!"<<endl;
					break;
				}
			 }
 		 }
 		 else if(sel == 2){
		     srand(time(0));
		 	 kt = 1;
			 int x = rand()%100 + 1;
		     int y = rand();	
		 	 k = x*y;;		
		 	 cout << "Khoa K Sinh Tu Dong La: " << k << endl;
		 	 cout << "Khoa K tu dong da duoc luu !"<<endl;
 		 }
 		 else if(sel == 3){
 		 	bm = "";
 		 	 if(kt == 0){
 	 		 	cout << "Hay Nhap Thong Tin Cho Khoa K" << endl;
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
 				for(int i = 0; i < br.size(); i++){
 					char kt = br[i];
 					int chiso = mp[br[i]] + k;
 					chiso = chiso%97;
				 	bm.push_back(arrchar[chiso]);
				 	cout << "Ki tu " << kt << " tai vi tri thu " << mp[br[i]] << 
				  	" duoc thay bang ki tu " << arrchar[chiso] << " tai vi tri thu " << chiso << endl;
			 	}
                cout << "=> Ban Ma: " << bm <<endl;
 				
 	 		 }
 		 }
 		 else if(sel == 4){
 		 	 if(kt == 0){
 	 		 	cout << "Hay Nhap Thong Tin Cho Khoa K" << endl;
 	 		 }
 	 		 else{
 	 		 	br = "";
 		 	 	while(true){
	  				cout << "Nhap Vao Ban Ma: ";;
	    			getline(cin, bm);
	    			if (bm == "") {
	      					cout << "Nhap sai dinh dang. Hay nhap lai!" << endl;
	    			}
	    			else if(ktraXauHopLe(bm) == false){
	    					cout << "Nhap sai dinh dang. Hay nhap lai!" << endl;
	    			}
	    			else{
    					break;
					}
 				}
 				for(int i = 0; i < bm.size(); i++){
 					char kt = bm[i];
 					int chiso = mp[bm[i]] - k;
 					chiso = chiso%97;
 					if(chiso < 0) chiso = chiso + 97;
				 	br.push_back(arrchar[chiso]);

				 	cout << "Ki tu " << kt << " tai vi tri thu " << mp[bm[i]] << 
				 	" duoc thay bang ki tu " << arrchar[chiso] << " tai vi tri thu " << chiso<< endl;
			 	}
                cout << "=> Ban RO: " << br <<endl;
 				
 		 	 }
 		 }
	  	 if(sel == 5){
	  	 	cout<<"Thoat thanh cong !"<<endl;
  		 	break;
	  	 }
  	}
  	return 0;
}