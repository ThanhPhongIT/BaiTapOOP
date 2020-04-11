#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;
//*****************class San Pham
class sanPham{
	protected:
		char tenSp[20];
		int namSx;
		long long giaThanh;
	public:
		void nhap();
		void xuat();
};
//**************class Hoa Don
class hoaDon:public sanPham{
	private:
		int soLuong;
		long long giaBan;
	public:
		void nhap();
		void xuat();
		long long thanhTien();
		long long tinhThue();
		long long tinhLai();
		friend void sort(hoaDon list[], int &n);
		friend long long max(hoaDon list[], int &n);
};
void sanPham::nhap(){
	cout<<"Nhap vao ten SP: ";		fflush(stdin);			gets(tenSp);
	cout<<"Nhap vao nam SX: ";		cin>>namSx;
	cout<<"Nhap vao gia thanh: ";	cin>>giaThanh;
}

void hoaDon::nhap(){
	sanPham::nhap();
	cout<<"Nhap vao so luong: ";	cin>>soLuong;
	cout<<"Nhap vao gia ban: ";		cin>>giaBan;
}
long long hoaDon::thanhTien(){
	return soLuong*giaBan;
}
long long hoaDon::tinhThue(){
	return hoaDon::thanhTien()*0.1;
}
long long hoaDon::tinhLai(){
	return (giaBan-giaThanh)*soLuong;
}
void sanPham::xuat(){
	cout<<setw(25)<<tenSp;
	cout<<setw(20)<<giaThanh;
}
void hoaDon::xuat(){
	sanPham::xuat();
	cout<<setw(15)<<soLuong;
	cout<<setw(15)<<giaBan;
	cout<<setw(15)<<thanhTien();
	cout<<setw(15)<<tinhThue();
	cout<<setw(15)<<tinhLai()<<endl;
}
//***************Sap xep theo tien thue giam dan
void sort(hoaDon list[], int &n){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if (list[j].tinhThue() < list[j+1].tinhThue()) {
                hoaDon temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
		}
	}
}
//******************tong thanh tien cua danh sach hoa don
long long tong(hoaDon list[], int &n){
	long long tongTien = 0;
	for(int i = 0; i<n; i++){
		tongTien += list[i].thanhTien();
	}
	return tongTien;
}
//******************thue lon nhat
long long max(hoaDon list[], int &n){
	long long max=list[0].tinhThue();
	for(int i=0; i<n; i++){
		if(list[i].tinhThue() >= max){
			max = list[i].tinhThue();
		}
	}
	return max;
}
//********************tieu de
void title(){
	cout<<setw(5)<<"STT";
	cout<<setw(25)<<"Ten Sp";
	cout<<setw(20)<<"Gia Thanh";
	cout<<setw(15)<<"So Luong";
	cout<<setw(15)<<"Gia Ban";
	cout<<setw(15)<<"Thanh Tien";
	cout<<setw(15)<<"TinhThue";
	cout<<setw(15)<<"Tinh Lai"<<endl;
}
int main(){
	int n;
	//***********Nhap vao danh sach****************
	cout<<"Nhap so luong hoa don: ";		cin>>n;
	hoaDon *list = new hoaDon[n];
	for(int i = 0; i < n; i++){
		cout<<"\t**Hoa don thu "<<i+1<<"**"<<endl;
		list[i].nhap();
	}
	//************sap xep va hien thi****************
	sort(list, n);
	cout<<"\t\t=============Danh sach hoa don da sap xep la=============\n";
	title();
	for(int i = 0; i<n; i++){
		cout<<setw(5)<<i+1;
		list[i].xuat();
	}
	//************tong tien hoa don******************
	cout<<"Tong tien cac hoa don vua nhap la: "<<tong(list,n)<<endl;
	//************thue max***************
	cout<<"\t\t=============Danh sach hoa don co thue max=============\n";
	title();
	for(int i = 0; i<n; i++){
		if(list[i].tinhThue() == max(list, n)){
			cout<<setw(5)<<i+1;
			list[i].xuat();
		}
	}
	return 0;
}
