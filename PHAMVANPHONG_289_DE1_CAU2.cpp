#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string>
using namespace std;
class NhanVien{
private:
	char nhanVienKiemKe[20];
	char chucVu[15];
	friend class Phieu;
};



class Phong{
private:
	char tenPhong[20];
	char maPhong[5];
	char truongPhong[20];
	friend class Phieu;
};
class TaiSan{
private:
	char tenTaiSan[20];
	int  soLuong;
	char tinhTrang[25];
public:
	void nhap();
	void xuat();
	friend void xuatDS(TaiSan *list, int &n);
	friend class Phieu;
};
void TaiSan::nhap(){
	cout<<"Nhap vao ten Tai San: ";			fflush(stdin);		gets(tenTaiSan);
	cout<<"Nhap vao so luong: ";			cin>>soLuong;
	cout<<"Nhap vao tinh trang: ";			fflush(stdin);		gets(tinhTrang);
}
void TaiSan::xuat(){
	cout<<setw(20)<<tenTaiSan;
	cout<<setw(7)<<soLuong;
	cout<<setw(25)<<tinhTrang<<endl;
}

class Phieu{
private:
	char maPhieu[6];
	char ngayKiemKe[12];
	NhanVien a;
	Phong b;
	TaiSan list[100];
	int n;
public:
	void nhap();
	void xuat();
};
void Phieu::nhap(){
	cout<<"Nhap vao ma phieu: ";						fflush(stdin);		gets(maPhieu);
	cout<<"Nhap vao ngay kiem ke: ";					fflush(stdin);		gets(ngayKiemKe);
	cout<<"Nhap vao ten nhan vien kiem ke: ";			fflush(stdin);		gets(a.nhanVienKiemKe);
	cout<<"Nhap vao chuc vu nhan vien:";				fflush(stdin);		gets(a.chucVu);
	cout<<"Nhap vao ten phong: ";						fflush(stdin);		gets(b.tenPhong);
	cout<<"Nhap vao ma phong: ";						fflush(stdin);		gets(b.maPhong);
	cout<<"Nhap vao ten truong phong: ";				fflush(stdin);		gets(b.truongPhong);
	cout<<"Nhap vao so luong tai san: "; cin>>n;
	for(int i=0; i<n; i++){
		cout<<"***Nhap vao thong tin tai san thu "<<i+1<<endl;
		list[i].nhap();
	}
}
void Phieu::xuat(){
	cout<<"\n===================================\n\n\t\t\tPHIEU KIEM KE TAI SAN\n";
	cout<<"Ma phieu: "<<maPhieu<<"\t\t\t\t\t\t";
	cout<<"Ngay kiem ke: "<<ngayKiemKe<<endl;
	cout<<"Nhân vien kiem ke: "<<a.nhanVienKiemKe<<"\t\t\t\t";
	cout<<"Chuc vu: "<<a.chucVu<<endl;
	cout<<"Kiem ke tai phong: "<<b.tenPhong<<"\t\t\t";
	cout<<"Ma phong: "<<b.maPhong<<endl;
	cout<<"Truong phong: "<<b.truongPhong<<endl;
	cout<<setw(20)<<"Ten tai san";
	cout<<setw(10)<<"So luong";
	cout<<setw(25)<<"Tinh trang"<<endl;
	for(int i=0; i<n; i++){
		list[i].xuat();
	}
	int sum=0;
	for(int i=0; i<n; i++){
		sum += list[i].soLuong;
	}
	cout<<"\nSo tai san da kiem ke: "<<n<<"\tTong so luong: "<<sum;
}
int main(){
	int n;
	TaiSan *list = new TaiSan[n];
	Phieu A;
	A.nhap();
	A.xuat();
	return 0;
}
