#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<math.h>
using namespace std;

class MayGiat{
private:
	char Brand[30];
	float CongSuat;
	long giaTien;
	int dungTich;
public:
	void nhap();
	void xuat();
};
void MayGiat::nhap(){
	cout<<"Nhap vao thuong hieu: ";		fflush(stdin);		gets(Brand);
	cout<<"Nhap vao cong suat: ";		cin>>CongSuat;
	cout<<"Nhap vao gia tien: ";		cin>>giaTien;
	cout<<"Nhap vao dung tich: ";		cin>>dungTich;
}
void MayGiat::xuat(){
	cout<<setw(30)<<Brand;
	cout<<setw(12)<<CongSuat;
	cout<<setw(12)<<giaTien;
	cout<<setw(12)<<dungTich<<endl;
}
class TuLanh{
private:
	char Brand[30];
	float CongSuat;
	long giaTien;
	int khoiLuongGiat;
public:
	void nhap();
	void xuat();
};
void TuLanh::nhap(){
	cout<<"Nhap vao thuong hieu: ";		fflush(stdin);		gets(Brand);
	cout<<"Nhap vao cong suat: ";		cin>>CongSuat;
	cout<<"Nhap vao gia tien: ";		cin>>giaTien;
	cout<<"Nhap vao dung tich: ";		cin>>khoiLuongGiat;
}
void TuLanh::xuat(){
	cout<<setw(30)<<Brand;
	cout<<setw(12)<<CongSuat;
	cout<<setw(12)<<giaTien;
	cout<<setw(12)<<khoiLuongGiat<<endl;
}
class ThucPham{
protected:
	char TenThucPham[30];
	long gia;
public:
	void nhap();
	void xuat();
};
void ThucPham::nhap(){
	cout<<"Nhap vao ten TP: ";		fflush(stdin);		gets(TenThucPham);
	cout<<"Nhap vao gia: ";			cin>>gia;
}
void ThucPham::xuat(){
	cout<<setw(30)<<TenThucPham;
	cout<<setw(12)<<gia;
}
class TPHOP:public ThucPham{
private:
	int soHop;
public:
	void nhap();
	void xuat();
};
void TPHOP::nhap(){
	ThucPham::nhap();
	cout<<"Nhap vao so hop: ";			cin>>soHop;
}
void TPHOP::xuat(){
	ThucPham::xuat();
	cout<<setw(12)<<soHop<<endl;
}
class TPKHOP:public ThucPham{
private:
	float khoiLuong;
public:
	void nhap();
	void xuat();
};
void TPKHOP::nhap(){
	ThucPham::nhap();
	cout<<"Nhap vao khoi luong: ";			cin>>khoiLuong;
}
void TPKHOP::xuat(){
	ThucPham::xuat();
	cout<<setw(12)<<khoiLuong<<endl;
}
int main(){
	MayGiat a;
	TuLanh b;
	cout<<"Nhap vao may giat a\n";
	a.nhap();
	cout<<setw(30)<<"Brand";
	cout<<setw(12)<<"CongSuat";
	cout<<setw(12)<<"giaTien";
	cout<<setw(12)<<"dungTich"<<endl;
	a.xuat();
	cout<<"Nhap vao tu lanh b\n";
	b.nhap();
	cout<<setw(30)<<"Brand";
	cout<<setw(12)<<"CongSuat";
	cout<<setw(12)<<"giaTien";
	cout<<setw(12)<<"KhoiLuong"<<endl;
	b.xuat();
	TPHOP x;
	TPKHOP y;
	cout<<"Nhap vao thuc pham hop\n";
	x.nhap();
	cout<<setw(30)<<"TenThucPham";
	cout<<setw(12)<<"gia";
	cout<<setw(12)<<"soHop\n";
	x.xuat();
	cout<<"Nhap vao thuc pham khong hop\n";
	y.nhap();
	cout<<setw(30)<<"TenThucPham";
	cout<<setw(12)<<"gia";
	cout<<setw(12)<<"khoiluong\n";
	y.xuat();
	return 0;
}
