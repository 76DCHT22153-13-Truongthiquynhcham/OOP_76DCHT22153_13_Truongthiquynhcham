#include<iostream>
#include<string>
#include<vector>
using namespace std;
class nhanvien {
	private:
		string manv;
		string hovaten;
		string diachi;
		double luong ;
		double  heso;
	public:
	void nhap(){
		
		getline(cin,hovaten);
		
    cin.ignore();
	}	
	void inra(){
	
		cout<<"hovaten:"<<hovaten<<"\n";
		
	}
  typedef nhanvien nv;
		
};
int main(){
	nhanvien nv;
 vector<int>a(n);
 cout<<"nhap so luong nhan vien:";
 cin>>n;
 cin.ignore();
 //vector

 vector<nv>ds(n);
 for(int i=0;i<n;i++){
   ds[i].nhap();
 }
 //mảng động
 nhanvien *dsnv2 = new nhanvien[n];
    cin.ignore();
    for (int i = 0; i < n; i++) {
        dsnv2[i].nhap();
    }
    for (int i = 0; i < n; i++) {
        dsnv2[i].inra();
    }
    delete[] dsnv2;
 //mảng tĩnh
 nhanvien dsnv3[n];
    for (int i = 0; i < n; i++) {
        dsnv3[i].nhap();
    }
    for (int i = 0; i < n; i++) {
        dsnv3[i].inra();
    }
}
