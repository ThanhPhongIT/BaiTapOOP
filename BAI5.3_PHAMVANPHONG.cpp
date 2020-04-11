#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
class SanPham{
	protected:
		int MaSanPham;
		char TenSanPham[10];
		char NgaySx[10];
		int TrongLuong;
		char MauSac[10];
		void Nhap();
		void Xuat();
};
class HangDienTu: private SanPham{
	private:
		int CongSuat;
		char DongDienSuDung[7];
	public:
		void Nhap();
		void Xuat();
	friend void TrongLuongMin(HangDienTu b[], int n);
};
void SanPham::Nhap(){
	cout<<"\n Nhap ma san pham: "; 			cin>>MaSanPham;
	cout<<"\n Nhap ten san pham: ";			fflush(stdin);			gets(TenSanPham);
	cout<<"\n Nhap ngay san xuat: ";		fflush(stdin);			gets(NgaySx);
	cout<<"\n Nhap trong luong: "; 			cin>>TrongLuong;
	cout<<"\n Nhap mau sac: ";				fflush(stdin);			gets(MauSac);
}
void SanPham::Xuat(){
	cout<<setw(10)<<MaSanPham;
	cout<<setw(12)<<TenSanPham;
	cout<<setw(10)<<NgaySx;
	cout<<setw(12)<<TrongLuong;
	cout<<setw(10)<<MauSac;
}
void HangDienTu::Nhap(){
	SanPham::Nhap();
	cout<<"\n Nhap cong suat: "; 				cin>>CongSuat;
	cout<<"\n Nhap dong dien su dung: ";		fflush(stdin);			gets(DongDienSuDung);
}
void HangDienTu::Xuat(){
	SanPham::Xuat();
	cout<<setw(10)<<CongSuat;
	cout<<setw(10)<<DongDienSuDung<<endl;
}
void menu(){
	cout<<setw(10)<<"MaSanPham";
	cout<<setw(12)<<"TenSanPham";
	cout<<setw(10)<<"NgaySx";
	cout<<setw(12)<<"TrongLuong";
	cout<<setw(10)<<"MauSac";
	cout<<setw(10)<<"CongSuat";
	cout<<setw(10)<<"DongDien"<<endl;
}
void TrongLuongMin(HangDienTu b[], int n){
	//tim namTN lon nhat
	int min = b[0].TrongLuong;
	for(int i = 1;i<n;i++)
		if (b[i].TrongLuong < min)
			min = b[i].TrongLuong;
	//end
	cout<<"\n\n\t ============Danh sach HangDienTu co trong luong thap nhat============\n"<<endl;
	menu();
	for(int i=0;i<n;i++){
		if (b[i].TrongLuong == min)
			b[i].Xuat();
	}
}
int main(){
	int n;
	cout<<"\nNhap so luong Hang Dien Tu: ";cin>>n;
	HangDienTu B[n];
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin HangDienTu thu "<<i+1<<": "<<endl;
		B[i].Nhap();
	}
	cout<<"\n\n\t =================Danh sach HangDienTu vua nhap=================\n"<<endl;
	menu();
	for(int i=0;i<n;i++){
		B[i].Xuat();
	}
	TrongLuongMin(B,n);
	return 0;
}

