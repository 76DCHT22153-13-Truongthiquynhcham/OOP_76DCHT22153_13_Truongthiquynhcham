#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[5];

public:
    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cout << "Nhap diem 5 mon: ";
        for (int i = 0; i < 5; i++) cin >> diem[i];
        cin.ignore();
    }

    void xuat() {
        cout << "Ho ten: " << hoTen << ", Nam sinh: " << namSinh << endl;
        cout << "Diem cac mon: ";
        for (int i = 0; i < 5; i++) cout << diem[i] << " ";
        cout << endl;
    }

    float diemTB() {
        float sum = 0;
        for (int i = 0; i < 5; i++) sum += diem[i];
        return sum / 5;
    }

    void kiemTraThiLai() {
        bool thiLai = false;
        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5) {
                thiLai = true;
                cout << hoTen << " phai thi lai mon " << i+1 << " (diem: " << diem[i] << ")" << endl;
            }
        }
        if (!thiLai) cout << hoTen << " khong phai thi lai." << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    SinhVien sv[100];
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i+1 << endl;
        sv[i].nhap();
    }

    cout << "\nDanh sach sinh vien phai thi lai:\n";
    for (int i = 0; i < n; i++) {
        sv[i].kiemTraThiLai();
    }

    return 0;
}

