#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<math.h>
using namespace std;
class SINHVIEN{
protected:
	char HoTen[30];
	char SBD[15];
public:
	void nhap();
	void xuat();
};
void SINHVIEN::nhap(){
	cout<<"Nhap vao ho ten SV: ";		fflush(stdin);		gets(HoTen);
	cout<<"Nhap vao SBD: ";				fflush(stdin);		gets(SBD);
}
void SINHVIEN::xuat(){
	cout<<setw(30)<<HoTen;
	cout<<setw(15)<<SBD;
}
class DIEMTHI:public SINHVIEN{
protected:
	float DiemThi1;
	float DiemThi2;
public:
	void nhap();
	void xuat();
};
void DIEMTHI::nhap(){
	SINHVIEN::nhap();
	cout<<"Nhap vao diem thi 1: "; 		cin>>DiemThi1;
	cout<<"Nhap vao diem thi 2: ";		cin>>DiemThi2;
}
void DIEMTHI::xuat(){
	SINHVIEN::xuat();
	cout<<setw(12)<<DiemThi1;
	cout<<setw(12)<<DiemThi2;
}
class KETQUA:public SINHVIEN, DIEMTHI{
public: 
	float TongDiem();
	void nhap();
	void xuat();
};
void KETQUA::nhap(){
	DIEMTHI::nhap();
}
float KETQUA::TongDiem(){
	return DiemThi1 + DiemThi2;
}
void KETQUA::xuat(){
	DIEMTHI::xuat();
	cout<<setw(10)<<TongDiem()<<endl;
}
void title(){
	cout<<setw(5)<<"STT";
	cout<<setw(30)<<"Ho Ten";
	cout<<setw(15)<<"SBD";
	cout<<setw(12)<<"DiemThi1";
	cout<<setw(12)<<"DiemThi2";
	cout<<setw(10)<<"TongDiem"<<endl;
}
int main(){
	int n;
	KETQUA SV[100];
	cout<<"Nhap so sinh vien(<100): ";	cin>>n;
	for(int i=0; i<n; i++){
		cout<<"*****Nhap vao sinh vien thu "<<i+1<<endl;
		SV[i].nhap();
	}
	cout<<"\t\t================Danh Sach Sinh Vien================\n";
	title();
	for(int i=0; i<n; i++){
		cout<<setw(5)<<i+1;
		SV[i].xuat();
	}
	return 0;
}
