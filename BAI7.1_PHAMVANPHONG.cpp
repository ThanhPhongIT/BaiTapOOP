#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string>
using namespace std;

class Date{
private:
	int day, month, year;
public:
	void nhap();
	void xuat();
	friend class TIVI;
};
void Date::nhap(){
	cout<<"Nhap vao ngay: ";		cin>>day;
	cout<<"Nhap vao thang: ";		cin>>month;
	cout<<"Nhap vao nam: ";		cin>>year;
}
void Date::xuat(){
	cout<<setw(7)<<day;
	cout<<setw(7)<<month;
	cout<<setw(7)<<year;
}
class NSX{
private:
	char tenNSX[20];
	char diaChi[20];
public:
	void nhap();
	void xuat();
	friend class Hang;
};
void NSX::nhap(){
	cout<<"Nhap ten NSX Tivi: ";			fflush(stdin);		gets(tenNSX);
	cout<<"Nhap dia chi NSX Tivi: ";		fflush(stdin);		gets(diaChi);
}
void NSX::xuat(){
	cout<<setw(20)<<tenNSX;
	cout<<setw(20)<<diaChi;
}
class Hang{
protected:
	char tenHang[15];
	NSX x;
public:
	void nhap();
	void xuat();
};
void Hang::nhap(){
	cout<<"Nhap vao ten hang: ";		fflush(stdin);		gets(tenHang);
	x.nhap();
}
void Hang::xuat(){
	cout<<setw(15)<<tenHang;
	x.xuat();
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
	NgayNhap.nhap();
	cout<<"Nhap vao kich thuoc TV: ";		fflush(stdin);		gets(kichThuoc);
}
void TIVI::xuat(){
	Hang::xuat();
	NgayNhap.xuat();
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
