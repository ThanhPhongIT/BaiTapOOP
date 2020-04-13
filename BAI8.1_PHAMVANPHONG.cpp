#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string>

using namespace std;
class Hang{
private:
	char tenHang[20];
	float donGia;
	int soLuong;
public:
	void nhap();
	void xuat();
	float thanhTien();
	friend void nhapDS(Hang list[], int &n);
	friend void xuatDS(Hang list[], int &n);
	friend float tongTien(Hang list[], int &n);
};
void Hang::nhap(){
	cout<<"Nhap vao ten hang: ";	fflush(stdin);		gets(tenHang);
	cout<<"Nhap vao don gia: ";		cin>>donGia;
	cout<<"Nhap vao so luong: ";	cin>>soLuong;
}
void Hang::xuat(){
	cout<<setw(20)<<tenHang;
	cout<<setw(10)<<donGia;
	cout<<setw(10)<<soLuong;
	cout<<setw(12)<<thanhTien()<<endl;	
}
float Hang::thanhTien(){
	return soLuong*donGia;
}
void nhapDS(Hang list[], int &n){
	for(int i=0; i<n; i++){
		cout<<"*****Nhap thong tin hang thu "<<i+1<<endl;
		list[i].nhap();
	}
}
void xuatDS(Hang list[], int &n){
	for(int i=0; i<n; i++){
		cout<<setw(5)<<i+1;
		list[i].xuat();
	}
}
float tongTien(Hang list[], int &n){
	float tong = 0;
	for(int i=0; i<n; i++){
		tong += list[i].thanhTien();
	}
	return tong;
}
class PhieuNhapHang{
private:
	char maPhieu[10];
	char ngayLap[15];
	char maNCC[10];
	char TenNCC[20];
	char diaChi[20];
public:
	void nhap();
	void xuat();
};
void PhieuNhapHang::nhap(){
	cout<<"Nhap vao ma phieu: ";	fflush(stdin);		gets(maPhieu);
	cout<<"Nhap vao ngay lap: ";	fflush(stdin);		gets(ngayLap);
	cout<<"Nhap vao ma NCC: ";		fflush(stdin);		gets(maNCC);
	cout<<"Nhap vao ten NCC: ";		fflush(stdin);		gets(TenNCC);
	cout<<"Nhap vao dia chi: ";		fflush(stdin);		gets(diaChi);
}
void PhieuNhapHang::xuat(){
	cout<<"Ma Phieu: "<<maPhieu<<"\t\t\t\t";
	cout<<"Ngay TL: "<<ngayLap<<endl;
	cout<<"Ma NCC: "<<maNCC<<"\t\t\t\t";
	cout<<"ten NCC: "<<TenNCC<<endl;
	cout<<"Dia Chi: "<<diaChi<<endl;
}
void title(){
	cout<<setw(5)<<"STT";
	cout<<setw(20)<<"Ten hang";
	cout<<setw(10)<<"Don gia";
	cout<<setw(10)<<"So Luong";
	cout<<setw(12)<<"Thanh Tien"<<endl;
}
int main(){
	int n;
	Hang *list = new Hang[n];
	PhieuNhapHang y;
	y.nhap();
	cout<<"Nhap vao so luong mat hang: ";		cin>>n;
	nhapDS(list, n);
	cout<<"\n\n\t\t\t==========Thong tin phieu hang vua nhap=========\n";
	y.xuat();
	title();
	xuatDS(list, n);
	cout<<setw(45)<<"Cong thanh tien: ";
	cout<<setw(12)<<tongTien(list, n);
	return 0;
}
