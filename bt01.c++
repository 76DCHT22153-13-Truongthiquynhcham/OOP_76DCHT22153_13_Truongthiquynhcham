#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct NhanVien {
    string maNV;
    string tenNV;
    double luongCoBan;
    double heSo;
};

void nhapNhanVien(NhanVien &nv) {
    cout << "Nhap ma nhan vien: ";
    cin >> nv.maNV;
    cin.ignore(); 
    cout << "Nhap ten nhan vien: ";
    getline(cin, nv.tenNV);
    cout << "Nhap luong co ban: ";
    cin >> nv.luongCoBan;
    cout << "Nhap he so luong: ";
    cin >> nv.heSo;
}

void xuatNhanVien(const NhanVien &nv) {
    cout << "Ma NV: " << nv.maNV 
         << " | Ten NV: " << nv.tenNV 
         << " | Luong CB: " << nv.luongCoBan 
         << " | He so: " << nv.heSo 
         << " | Tong luong: " << (nv.luongCoBan * nv.heSo) << endl;
}
int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    vector<NhanVien> dsNhanVien(n);

    cout << "\n=== NHAP THONG TIN NHAN VIEN ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nNhan vien thu " << i + 1 << ":\n";
        nhapNhanVien(dsNhanVien[i]);
    }
    cout << "\n=== DANH SACH NHAN VIEN ===\n";
    for (int i = 0; i < n; i++) {
        xuatNhanVien(dsNhanVien[i]);
    }

    return 0;
}
