#include<iostream>
#include<stdio.h>
#include<string>
#include<iomanip>
using namespace std;
class Hang{
private:
	char tenHang[15];
	float donGia;
	int soLuong; 
public:
	void nhap();
	void xuat();
	float thanhTien();
};
void Hang::nhap(){
	cout<<"Nhap vao ten hang: ";		fflush(stdin);		gets(tenHang);
	cout<<"Nhap vao don gia: ";			cin>>donGia;
	cout<<"Nhap vao so luong: ";			cin>>soLuong;
}
float Hang::thanhTien(){
	return soLuong*donGia;
}
void Hang::xuat(){
	cout<<setw(15)<<tenHang;
	cout<<setw(15)<<donGia;
	cout<<setw(15)<<soLuong;
	cout<<setw(15)<<thanhTien()<<endl;
}
class Phieu{
	char maPhieu[5];
	char ngayThanhLap[15];
	Hang *list;
	int n;
public:
	void nhap();
	void xuat();
	float congTien();
};

void Phieu::nhap(){
	cout<<"Nhap vao ma phieu: ";		fflush(stdin);		gets(maPhieu);
	cout<<"Nhap vao ngay thanh lap ";	fflush(stdin);		gets(ngayThanhLap);
	cout<<"Nhap vao so mat hang: ";		cin>>n; 
	list = new Hang[n];
	for(int i=0; i<n; i++){
		cout<<"Nhap vao mat hang thu "<<i+1<<endl;
		list[i].nhap();
	}
}
float Phieu::congTien(){
	float sum = 0;
	for(int i=0; i<n; i++){
		sum += list[i].thanhTien();
	}
	return sum;
}
void Phieu::xuat(){
	cout<<"\n*********************************\n\t\t\tPHIEU MUA HANG\n";
	cout<<setw(12)<<"Ma phieu: "<<maPhieu<<"\t\t"<<"Ngay thanhLap: "<<ngayThanhLap<<endl;
	cout<<setw(15)<<"Ten Hang";
	cout<<setw(15)<<"Don Gia";
	cout<<setw(15)<<"So Luong";
	cout<<setw(15)<<"Thanh Tien"<<endl;
	for(int i=0; i<n; i++){
		list[i].xuat();
	}
	cout<<setw(45)<<"Cong thanh tien: "<<setw(15)<<congTien();
}
int main(){
	Phieu A;
	cout << "Nhap thong tin phieu: " << endl;
	A.nhap();
	A.xuat();
	return 0;
}
