#include<iostream>
using namespace std;
class PS1{
	protected:
		int tu;
		int mau;
	public: 
	void nhap(){
		cout <<"Nhap tu so: ";
		cin >> tu;
		do {
			cout << "Nhap mau so (khac 0): ";
			cin >> mau;
		}while (mau == 0);
	}
	void xuat(){
		cout << tu << "/" << mau;
	}
	void toiGian(){
		int a = tu, b = mau;
		if(a < 0) a = -a;
		if (b < 0) b = -b;
		while (b != 0){
			int r = a % b;
			a = b;
			b = r;
		}
		int UCLN = a; 
		if(UCLN != 0){
			tu /= UCLN;
			mau /= UCLN;
		}
		if (mau < 0){
			mau = -mau;
			tu = -tu;
		}
	}
};
class PS2 : public PS1 {
	public: 
	void operator=(const PS2 &ps){
		tu = ps.tu;
		mau = ps.mau;
	}
	bool operator>(const PS2 &ps){
		return(tu * ps.mau) > (ps.tu * mau);
	}
};
int main(){
	int n; 
	do {
		cout << "Nhap so phan tu: ";
		cin >> n; 
	}while (n <= 0 || n > 10);
	PS2 ds[10];
	for(int i = 0; i < n; i++){
		cout << "Nhap phan so thu " << i + 1 << ":\n";
		ds[i].nhap();
		ds[i].toiGian();	
	}
	for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (ds[j + 1] > ds[j]) {
                PS2 tam;
                tam = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = tam;
            }
        }
    }
    cout << "\nDanh sach sau khi sap xep giam dan:\n";
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
        cout << "  ";
    }
    cout << endl;
    return 0;
}
