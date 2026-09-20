#include<iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std;
class monHoc{
protected:
	string tenMon;
	float diemCC;
	float diemKT;
	float diemDT;
public: 
	monHoc() : tenMon (""), diemCC(0), diemKT(0), diemDT(0) {}
	monHoc(string tenMon, float diemCC, float diemKT, float diemDT) 
	: tenMon(tenMon), diemCC(diemCC), diemKT(diemKT), diemDT(diemDT){}
void nhap(){
	cout <<"Ten mon hoc: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, tenMon);
	cout << " Diem chuyen can: ";
	cin >> diemCC;
	cout << " Diem kiem tra: ";
	cin >> diemKT;
	cout << " Diem thi: ";
	cin >> diemDT;
}
void xuat(){
	cout << "Mon hoc: " << tenMon;
	cout << "CC: " << diemCC;
	cout << "KT: " << diemKT;
	cout << "DT: " << diemDT;
}
float tinhDiemHocPhan(){
	return diemCC * 0.1f + diemKT * 0.3f + diemDT * 0.6f;
}
float getDiemCC(){return diemCC;}
float getDiemKT(){return diemKT;}
};
class SinhVien : public monHoc{
private: 
string hoTen;
string lop;
string maSV;
public: 
SinhVien() : monHoc(), hoTen(""), lop(""), maSV(""){}
SinhVien(string tenMon, float CC, float KT, float DT,
		string hoTen, string lop, string maSV)
		: monHoc(tenMon, CC, KT, DT), hoTen(hoTen), lop(lop), maSV(maSV){
		}
void nhap(){
	cout << "Ho ten: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin,hoTen);
	cout << "Lop: ";
	getline(cin,lop);
	cout << "Ma Sinh vien: ";
	cin >> maSV;
	monHoc::nhap();
}
void xuat(){
	cout <<"MSSV: " << maSV;
	cout <<"Ho ten: " << hoTen;
	cout <<"Lop: " << lop;
	monHoc::xuat();
	cout << "Diem hoc phan: " << tinhDiemHocPhan() << endl;
}
bool bicamThi(){
	return (getDiemCC() < 5 || getDiemKT() == 0);
}
};
int main(){
	int n;
	cout << "Nhap so luong sinh vien n: "; 
	cin >> n;
	vector<SinhVien> ds(n);
	for(int i = 0; i < n; i++){
		cout <<"\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
		ds[i].nhap();
	}
	cout << "\nDANH SACH SINH VIEN BI CAM THI\n";
	bool coCamThi = false;
	for(int i = 0; i < n; i++){
		if(ds[i].bicamThi()){
			ds[i].xuat();
			coCamThi = true;
		}
	}
	if(!coCamThi){
		cout << "Khong co sinh vien nao bi cam thi.\n";
	}
	return 0;
}

