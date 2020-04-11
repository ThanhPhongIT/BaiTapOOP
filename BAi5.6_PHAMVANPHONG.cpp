#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<math.h>
using namespace std;
class SanPham{
protected:
	int MaSp;
	char TenSp[20];
	char NgaySx[10];
	float TrongLuong;
	char MauSac[10];
public:
	void nhap();
	void xuat();	
};
class HangDienTu:public SanPham{
private:
	float CongSuat;
	int dongDien;
public:
	void nhap();
	void xuat();
	friend void trongLuongMin(HangDienTu *list, int n);
};
void SanPham::nhap(){
	cout<<"Nhap vao ma sp: ";		cin>>MaSp;
	cout<<"Nhap vao ten sp: ";		fflush(stdin);		gets(TenSp);
	cout<<"Nhap vao trong luong: ";	cin>>TrongLuong;
	cout<<"Nhap vao mau sac: ";		fflush(stdin);		gets(MauSac);
}
void SanPham::xuat(){
	cout<<setw(5)<<MaSp;
	cout<<setw(20)<<TenSp;
	cout<<setw(12)<<TrongLuong;
	cout<<setw(10)<<MauSac;
}
void HangDienTu::nhap(){
	SanPham::nhap();
	cout<<"Nhap vao cong suat: ";	cin>>CongSuat;
	cout<<"Nhap vao dong dien su dung(1/2?): ";		cin>>dongDien;
}
void HangDienTu::xuat(){
	SanPham::xuat();
	cout<<setw(12)<<CongSuat;
	cout<<setw(12)<<dongDien<<" chieu"<<endl;
}
void trongLuongMin(HangDienTu *list, int n){
	float min = list[0].TrongLuong;
	for(int i=0; i<n; i++){
		if(list[i].TrongLuong <= min){
			min = list[i].TrongLuong;
		}
	}
	for(int i=0; i<n; i++){
		if(list[i].TrongLuong == min){
			cout<<setw(5)<<i+1;
			list[i].xuat();
		}
	}
}
void title(){
	cout<<setw(5)<<"STT";
	cout<<setw(7)<<"Ma SP";
	cout<<setw(20)<<"Ten SP";
	cout<<setw(15)<<"Trong Luong";
	cout<<setw(10)<<"Mau Sac";
	cout<<setw(12)<<"Cong Suat";
	cout<<setw(15)<<"Dong dien\n";
}
int main(){
	int n;
	cout<<"Nhap vao so luong hang dien tu: ";		cin>>n;
	HangDienTu *list = new HangDienTu[n];
	for(int i=0; i<n; i++){
		cout<<"*****Nhap vao hang dien tu thu "<<i+1<<endl;
		list[i].nhap();
	}
	cout<<"\t\t================Hang dien tu vau nhap================\n";
	title();
	for(int i=0; i<n; i++){
		cout<<setw(5)<<i+1;
		list[i].xuat();
	}
	cout<<"\t\t================Hang dien tu trong luong min================\n";
	title();
	trongLuongMin(list, n);
	return 0;
}
