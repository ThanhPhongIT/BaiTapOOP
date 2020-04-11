#include<iostream>
#include<math.h>
#include<iomanip>
#include<string.h>
using namespace std;

class PERSON{
	protected:
		char HOTEN[20];
		char NGAYSINH[20];
		char QUEQUAN[20];
};

class KYSU : private PERSON{
	private:
		char NGANHHOC[20];
		int NAMTOTNGHIEP;
	public:
		void Nhap();
		void Xuat();
		friend void NamTN(KYSU a[], int n);
}; 

void KYSU::Nhap()
{
	cout<<"Nhap vao ho ten: ";				fflush(stdin);		gets(HOTEN);
	cout<<"Nhap vao ngay sinh: ";			gets(NGAYSINH);
	cout<<"Nhap vao que quan: ";			gets(QUEQUAN);
	cout<<"Nhap vao nganh hoc: ";			gets(NGANHHOC);
	cout<<"Nhap vao nam tot nghiep: ";		cin>>NAMTOTNGHIEP;
}
void KYSU::Xuat(){
	cout<<setw(15)<<HOTEN;
	cout<<setw(15)<<NGAYSINH;
	cout<<setw(15)<<QUEQUAN;
	cout<<setw(15)<<NGANHHOC;
	cout<<setw(15)<<NAMTOTNGHIEP;
}
void menu(){
	cout<<setw(15)<<"HOTEN";
	cout<<setw(15)<<"NGAYSINH";
	cout<<setw(15)<<"QUEQUAN";
	cout<<setw(15)<<"NGANHHOC";
	cout<<setw(15)<<"NAMTOTNGHIEP\n";
}
void NamTN(KYSU a[], int n){
	int max = a[0].NAMTOTNGHIEP;
	for(int i=0; i<n; i++){
		if(a[i].NAMTOTNGHIEP>=max)	max = a[i].NAMTOTNGHIEP;
	}
	cout<<"================================DANH SACH KY SU TOT NGHIEP GAN DAY================================\n";
	menu();
	for(int i=0;i<n;i++){
		if (a[i].NAMTOTNGHIEP == max)
			a[i].Xuat();
	}
}
int main(){
	KYSU A[100];
	int n;
	cout<<"Nhap vao so ky su: "; 		cin>>n;
	for(int i=0; i<n; i++){
		A[i].Nhap();
	}
	cout<<"================================DANH SACH KY SU================================\n";
	menu();
	for(int i=0; i<n; i++){
		A[i].Xuat();
		cout<<"\n";
	}
	NamTN(A, n);
	return 0;
}

