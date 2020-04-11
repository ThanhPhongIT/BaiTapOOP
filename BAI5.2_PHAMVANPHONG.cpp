#include<iostream>
#include<math.h>
#include<iomanip>
#include<string.h>
using namespace std;

class VEHICLE{
	protected:
		char NhanHieu[20];
		int NamSX;
		char Hang[20];
		void Nhap();
		void Xuat();
};
class OTO : public VEHICLE{
	private:
		int SoChoNgoi;
		int DungTich;
	public:
		void Nhap();
		void Xuat();
};
class MOTO : public VEHICLE{
	private:
		int PhanKhoi;
	public:
		void Nhap();
		void Xuat();
};
void VEHICLE::Nhap(){
	cout<<"Nhap nhan hieu: ";				fflush(stdin);		gets(NhanHieu);
	cout<<"Nhap nam san xuat: ";			cin>>NamSX;
	cout<<"Nhap hang: ";					fflush(stdin);		gets(Hang);
}
void VEHICLE::Xuat(){
	cout<<setw(15)<<NhanHieu;
	cout<<setw(7)<<NamSX;
	cout<<setw(15)<<Hang;
}
void MOTO::Nhap(){
	VEHICLE::Nhap();
	cout<<"Nhap phan khoi: ";				cin>>PhanKhoi;
}
void MOTO::Xuat(){
	VEHICLE::Xuat();
	cout<<setw(7)<<PhanKhoi<<endl;
}
void OTO::Nhap(){
	VEHICLE::Nhap();
	cout<<"\n nhap so cho ngoi: ";cin>>SoChoNgoi;
	cout<<"\n nhap dung tich: ";cin>>DungTich;
}
void OTO::Xuat(){
	VEHICLE::Xuat();
	cout<<setw(10)<<SoChoNgoi;
	cout<<setw(10)<<DungTich<<endl;
}
void menu(){
	cout<<setw(15)<<"NhanHieu";
	cout<<setw(7)<<"NamSx";
	cout<<setw(10)<<"Hang";
}
int main(){
	OTO A;
	cout<<"\n Nhap thong tin oto: \n";
	A.Nhap();
	MOTO B;
	cout<<"\n Nhap thong tin moto: \n";
	B.Nhap();
	cout<<"\n\t======Thong tin o to vua nhap========\n";
	menu();
	cout<<setw(10)<<"SoChoNgoi";
	cout<<setw(10)<<"DungTich"<<endl;
	A.Xuat();
	cout<<"\n\t======Thong tin mo to vua nhap========\n";
	menu();
	cout<<setw(10)<<"PhanKhoi"<<endl;
	B.Xuat();
	return 0;
}
