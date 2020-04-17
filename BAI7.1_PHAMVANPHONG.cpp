#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string>
using namespace std;

class Date{
private:
	int day, month, year;
	friend class TIVI;
};
class NSX{
private:
	char tenNSX[20];
	char diaChi[20];
	friend class Hang;
};

class Hang{
protected:
	char tenHang[15];
	NSX x;
public:
	void nhap();
	void xuat();
};
void Hang::nhap(){
	cout<<"Nhap vao ten hang: ";			fflush(stdin);		gets(tenHang);
	cout<<"Nhap ten NSX Tivi: ";			fflush(stdin);		gets(x.tenNSX);
	cout<<"Nhap dia chi NSX Tivi: ";		fflush(stdin);		gets(x.diaChi);
}
void Hang::xuat(){
	cout<<setw(15)<<tenHang;
	cout<<setw(20)<<x.tenNSX;
	cout<<setw(20)<<x.diaChi;
}
class TIVI:public Hang{
protected:
	char kichThuoc[10];
	Date NgayNhap;
public:
	void nhap();
	void xuat();
};
void TIVI::nhap(){
	Hang::nhap();
	cout<<"Nhap vao ngay: ";		cin>>NgayNhap.day;
	cout<<"Nhap vao thang: ";		cin>>NgayNhap.month;
	cout<<"Nhap vao nam: ";			cin>>NgayNhap.year;
	cout<<"Nhap vao kich thuoc TV: ";		fflush(stdin);		gets(kichThuoc);
}
void TIVI::xuat(){
	Hang::xuat();
	cout<<setw(7)<<NgayNhap.day;
	cout<<setw(7)<<NgayNhap.month;
	cout<<setw(7)<<NgayNhap.year;
	cout<<setw(14)<<kichThuoc;
}
void title(){
	cout<<setw(15)<<"Ten Hang";
	cout<<setw(20)<<"Ten NSX";
	cout<<setw(20)<<"Dia Chi";
	cout<<setw(7)<<"Ngay";
	cout<<setw(7)<<"Thang";
	cout<<setw(7)<<"Nam";
	cout<<setw(14)<<"Kich thuoc TV"<<endl;
}

int main(){
	TIVI a;
	a.nhap();
	cout<<"\n\n\t\t======================Thong tin tivi vua nhap=================\n\n";
	title();
	a.xuat();
	return 0;
}
