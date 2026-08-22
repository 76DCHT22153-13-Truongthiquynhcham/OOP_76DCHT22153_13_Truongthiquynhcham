#include <iostream>
#include <string>
using namespace std;
class NhanVien
{
private:
    string manv;
    string hoten;
    string ngaysinh;
    string diachi;
public:
    void nhap(){
    
        cout << "Nhap ma nhan vien: ";
        getline(cin, manv);
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap ngay sinh: ";
        getline(cin, ngaysinh);
        cout << "Nhap dia chi: ";
        getline(cin, diachi);
    }
    void xuat()
    {
        cout << "\n--- Thong tin nhan vien ---\n";
        cout << "Ma nhan vien: " << manv << endl;
        cout << "Ho ten: " << hoten << endl;
        cout << "Ngay sinh: " << ngaysinh << endl;
        cout << "Dia chi: " << diachi << endl;
    }
};

int main()
{
    NhanVien Minh;

    Minh.nhap();
    Minh.xuat();

    return 0;
}