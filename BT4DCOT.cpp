#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;

//CAU 1: Lop Nguoi 
class Nguoi {
protected:
    string hoTen;
    int namSinh;

public:
    // Ham tao khong doi
    Nguoi() : hoTen(""), namSinh(0) {}

    // Ham tao co doi
    Nguoi(string hoTen, int namSinh) : hoTen(hoTen), namSinh(namSinh) {}

    void nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // xoa bo dem truoc khi getline
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
    }

    void xuat() const {
        cout << "Ho ten: " << left << setw(20) << hoTen
             << " Nam sinh: " << namSinh;
    }

    string getHoTen() const { return hoTen; }
};

//CAU 1: Lop SinhVien ke thua Nguoi
class SinhVien : public Nguoi {
private:
    string maSV;
    float diemTB;

public:
    // Ham tao khong doi - phai goi lai ham tao khong doi cua Nguoi
    SinhVien() : Nguoi(), maSV(""), diemTB(0) {}

    // Ham tao co doi - phai goi lai ham tao co doi cua Nguoi
    SinhVien(string hoTen, int namSinh, string maSV, float diemTB)
        : Nguoi(hoTen, namSinh), maSV(maSV), diemTB(diemTB) {}

    void nhap() {
        Nguoi::nhap();
        cout << "Nhap ma sinh vien: ";
        cin >> maSV;
        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
    }

    void xuat() const {
        Nguoi::xuat();
        cout << " MSV: " << left << setw(10) << maSV
             << " DTB: " << fixed << setprecision(2) << diemTB;
    }

    float getDiemTB() const { return diemTB; }
};

bool soSanhGiamDan(const SinhVien &a, const SinhVien &b) {
    return a.getDiemTB() > b.getDiemTB();
}

int main() {
    int n;
    cout << "Nhap so luong sinh vien can nhap: ";
    cin >> n;

    vector<SinhVien> ds(n);
    for (int i = 0; i < n; i++) {
        cout << "\n-- Nhap thong tin sinh vien thu " << i + 1 << " --\n";
        ds[i].nhap();
    }

    // Sap xep giam dan theo diem trung binh
    sort(ds.begin(), ds.end(), soSanhGiamDan);

    cout << "\n===== DANH SACH SINH VIEN (giam dan theo DTB) =====\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ";
        ds[i].xuat();
        cout << endl;
    }

    return 0;
}
