#include<iostream>
#include<cmath>
using namespace std;
class SP1{
	protected:
		double thuc;
		double ao;
	public:
		//ham tao
		SP1(double t = 0, double a = 0) : thuc(t), ao(a){}
		//phuong thuc nhap so phuc
		void nhap(){
			cout << " Nhap phan thuc: ";
			cin >> thuc;
			cout << " Nhap phan ao: ";
			cin >> ao;
		}
		void xuat(){
			if(ao >= 0)
			cout << thuc << "+" << ao << "i";
			else 
			cout << thuc << "-" << -ao << "i";
		}
		//phuong thuc tinh module so phuc
		double module(){
			return sqrt(thuc * thuc + ao * ao);
		}
};
class SP2 : public SP1{
	public: 
	//ham tao ke thua
	SP2(double t = 0, double a = 0) : SP1(t,a){}
	//nap chong toan tu gan (=)
	SP2& operator=(SP2& sp){
		if(this != &sp);{
			thuc = sp.thuc;
			ao = sp.ao;
		}
		return *this;
	}
	//nap chong toan tu so sanh lon hon
	bool operator>(SP2& sp){
		return this->module()>sp.module();
	}
};
int main(){
	int n;
	SP2 ds[10]; //ds cac doi tuong toi da 10 phan tu
	do{
		cout << "Nhap so luong so phuc: ";
		cin >> n; 
	}while(n<1||n>10);
	cout <<"\nDANH SACH SO PHUC\n";
	for(int i = 0; i < n; i++){
		cout << "Nhap so phuc thu " << i + 1 << ":\n";
		ds[i].nhap();
	}
	//sap xep danh sach giam dan
	 for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!(ds[i] > ds[j])) { 
                SP2 temp = ds[i];
                ds[i] = ds[j];   
                ds[j] = temp;  
            }
        }
    }
    cout << "\nDANH SACH SAU KHI SAP XEP GIAM DAN THEO MODULE\n";
    for (int i = 0; i < n; i++) {
        cout << "SP " << i + 1 << ": ";
        ds[i].xuat();
        cout << " | Module = " << ds[i].module() << endl;
    }

    return 0;
}

