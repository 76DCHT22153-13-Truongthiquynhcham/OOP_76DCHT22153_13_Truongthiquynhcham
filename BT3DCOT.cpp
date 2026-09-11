#include <iostream>
using namespace std;
class SoPhuc {
private:
    float phanThuc;
    float phanAo;
public:
    //Ham tao khong doi
    SoPhuc() {
        phanThuc = 0;
        phanAo = 0;
    }
    //Ham tao co doi
    SoPhuc(float thuc, float ao) {
        phanThuc = thuc;
        phanAo = ao;
    }
    SoPhuc operator+(SoPhuc sp) {
        return SoPhuc(phanThuc + sp.phanThuc,
                      phanAo + sp.phanAo);
    }
    SoPhuc operator-(SoPhuc sp) {
        return SoPhuc(phanThuc - sp.phanThuc,
                      phanAo - sp.phanAo);
    }
    SoPhuc operator*(SoPhuc sp) {
        return SoPhuc(
            phanThuc * sp.phanThuc - phanAo * sp.phanAo,
            phanThuc * sp.phanAo + phanAo * sp.phanThuc
        );
    }
    SoPhuc operator/(SoPhuc sp) {
        float mau = sp.phanThuc * sp.phanThuc
                  + sp.phanAo * sp.phanAo;
        return SoPhuc(
            (phanThuc * sp.phanThuc + phanAo * sp.phanAo) / mau,
            (phanAo * sp.phanThuc - phanThuc * sp.phanAo) / mau
        );
    }
    void xuat() {
        cout << phanThuc;
        if (phanAo >= 0)
            cout << " + " << phanAo << "i";
        else
            cout << " - " << -phanAo << "i";
        cout << endl;
    }
};
int main() {
    SoPhuc sp1(3, 2);
    SoPhuc sp2(1, 4);
    
    SoPhuc tong = sp1 + sp2;
    SoPhuc hieu = sp1 - sp2;
    SoPhuc tich = sp1 * sp2;
    SoPhuc thuong = sp1 / sp2;

    cout << "So phuc 1: ";
    sp1.xuat();
    cout << "So phuc 2: ";
    sp2.xuat();
    cout << "Tong: ";
    tong.xuat();
    cout << "Hieu: ";
    hieu.xuat();
    cout << "Tich: ";
    tich.xuat();
    cout << "Thuong: ";
    thuong.xuat();
    return 0;
}
