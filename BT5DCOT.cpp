#include<iostream> 
#include<string>
#include<vector>
#include<limits>
using namespace std; 
class nguoi{
protected: 
	string Hoten;
	int Namsinh;
public: 
	nguoi() : Hoten(""), Namsinh(0) {}
    nguoi(string Hoten, int Namsinh) : Hoten(Hoten), Namsinh(Namsinh) {}
void nhap() {
        cout << "  Ho ten: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, Hoten);
        cout << "  Nam sinh: ";
        cin >> Namsinh;
    }
 
    void xuat() const {
        cout << "Ho ten: " << Hoten
             << "Nam sinh: " << Namsinh;
    }
 
    string getHoten() const { return Hoten; }
};
 
class SinhVien : public nguoi {
private:
    string maSV;
    float diemTB;
 
public:
    SinhVien() : nguoi(), maSV(""), diemTB(0) {}
    SinhVien(string Hoten, int Namsinh, string maSV, float diemTB)
        : nguoi(Hoten, Namsinh), maSV(maSV), diemTB(diemTB) {}

    void nhap() {
        nguoi::nhap();
        cout << "  Ma sinh vien: ";
        cin >> maSV;
        cout << "  Diem trung binh: ";
        cin >> diemTB;
    }
 
    void xuat() const {
        nguoi::xuat();
        cout << " MSV: " << maSV
             << " DTB: " << diemTB << endl;
    }
 
    string getMaSV() const { return maSV; }
};
int main() {
    int n;
    cout << "Nhap so luong sinh vien n: ";
    cin >> n;
 
    vector<SinhVien> ds(n);
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        ds[i].nhap();
    }
 
    cout << "\nNhap thong tin tim kiem: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string keyword;
    getline(cin, keyword);
 
    bool found = false;
    cout << "\nKET QUA TIM KIEM\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].getMaSV() == keyword || ds[i].getHoten() == keyword) {
            ds[i].xuat();
            found = true;
        }
    }
 
    if (!found) {
        cout << "Khong tim thay sinh vien nao voi thong tin: " << keyword << endl;
    }
    return 0;
}
