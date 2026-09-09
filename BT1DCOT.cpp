#include<iostream>
using namespace std; 
class PhanSo{
	private: 
	int tu;
	int mau;
	public: 
	PhanSo() : tu(0), mau(1) {
	}
	PhanSo(int tu, int mau){
		if (mau == 0){
			cout << "Mau so khong the bang 0, gan mau = 1\n";
			mau = 1;
		}
		this->tu = tu;
		this->mau = mau;
		rutGon();
	} 
	~PhanSo() {}
	
	void nhap(){
		cout << " Nhap tu so: ";
        cin >> tu;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mau;
            if (mau == 0) cout << "Mau so khong duoc bang 0. Nhap lai!\n";
        } while (mau == 0);
        rutGon();
    }
    void xuat() const {
        cout << tu << "/" << mau;
    }
 
    void rutGon() {
        if (tu == 0) {
            mau = 1;
            return;
        }

        int a = (tu < 0) ? -tu : tu;
        int b = (mau < 0) ? -mau : mau;
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        tu /= a;
        mau /= a;
 
        if (mau < 0) {
            mau = -mau;
            tu = -tu;
        }
    }
     PhanSo operator+(const PhanSo& b) const {
        return PhanSo(tu * b.mau + b.tu * mau, mau * b.mau);
    }
 
    PhanSo operator-(const PhanSo& b) const {
        return PhanSo(tu * b.mau - b.tu * mau, mau * b.mau);
    }
 
    PhanSo operator*(const PhanSo& b) const {
        return PhanSo(tu * b.tu, mau * b.mau);
    }
 
    PhanSo operator/(const PhanSo& b) const {
        if (b.tu == 0) {
            cout << "Khong the chia cho phan so co tu bang 0!\n";
            return PhanSo(0, 1);
        }
        return PhanSo(tu * b.mau, mau * b.tu);
    }

    friend istream& operator>>(istream& in, PhanSo& p) {
        cout << "Nhap tu so: ";
        in >> p.tu;
        do {
            cout << "Nhap mau so (khac 0): ";
            in >> p.mau;
            if (p.mau == 0) cout << "Mau so khong duoc bang 0. Nhap lai!\n";
        } while (p.mau == 0);
        p.rutGon();
        return in;
    }
 
    friend ostream& operator<<(ostream& out, const PhanSo& p) {
        out << p.tu << "/" << p.mau;
        return out;
    }
};

int main(){
	PhanSo ps1, ps2;
 
    cout << "Nhap phan so thu nhat:\n";
    cin >> ps1;
    cout << "Nhap phan so thu hai:\n";
    cin >> ps2;
 
    cout << "\nPhan so thu nhat: " << ps1 << endl;
    cout << "Phan so thu hai: " << ps2 << "\n\n";
 
    PhanSo tong    = ps1 + ps2;
    PhanSo hieu    = ps1 - ps2;
    PhanSo tich    = ps1 * ps2;
    PhanSo thuong  = ps1 / ps2;
 
    cout << "Tong: "    << ps1 << " + " << ps2 << " = " << tong   << endl;
    cout << "Hieu: "    << ps1 << " - " << ps2 << " = " << hieu   << endl;
    cout << "Tich: "    << ps1 << " * " << ps2 << " = " << tich   << endl;
    cout << "Thuong: "  << ps1 << " / " << ps2 << " = " << thuong << endl;
 
    return 0;
}
