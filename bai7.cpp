#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int SO_MON = 4;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[SO_MON];

public:
    void Nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, hoTen);

        cout << "Nhap nam sinh: ";
        cin >> namSinh;

        for (int i = 0; i < SO_MON; i++) {
            cout << "Nhap diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    void Xuat() const {
        cout << "Ho ten      : " << hoTen << endl;
        cout << "Nam sinh    : " << namSinh << endl;
        cout << "Diem cac mon: ";
        for (int i = 0; i < SO_MON; i++) {
            cout << diem[i] << " ";
        }
        cout << endl;
        cout << "Diem trung binh: " << TinhDiemTB() << endl;
    }

    float TinhDiemTB() const {
        float tong = 0;
        for (int i = 0; i < SO_MON; i++) {
            tong += diem[i];
        }
        return tong / SO_MON;
    }

    bool PhaiThiTotNghiep() const {
        if (TinhDiemTB() >= 7) return false;
        for (int i = 0; i < SO_MON; i++) {
            if (diem[i] < 5) return false;
        }
        return true;
    }
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    SinhVien *dsSV = new SinhVien[n];

    for (int i = 0; i < n; i++) {
        cout << "\nSinh vien thu " << i + 1 << ":\n";
        dsSV[i].Nhap();
    }

    cout << "\n===== DANH SACH SINH VIEN PHAI THI TOT NGHIEP =====\n";
    bool coSV = false;
    for (int i = 0; i < n; i++) {
        if (dsSV[i].PhaiThiTotNghiep()) {
            coSV = true;
            cout << "\n";
            dsSV[i].Xuat();
        }
    }

    if (!coSV) {
        cout << "\nKhong co sinh vien nao phai thi tot nghiep.\n";
    }

    delete[] dsSV;
    return 0;
}