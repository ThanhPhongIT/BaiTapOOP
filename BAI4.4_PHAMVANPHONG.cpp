#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

class PtBac2
{
	private:
		float a,b,c;
	public:
		PtBac2(void){
			a = 0;
			b = 0;
			c = 0;
		}
		void Nhap();
		void Xuat();
		void Giai();
};

void PtBac2::Nhap()
{
	do{
		cout<<"Nhap vao a: ";			cin>> a;
	}while(a==0);
	cout<<"Nhap vao b: ";			cin>> b;
	cout<<"Nhap vao c: ";			cin>> c;
}
void PtBac2::Giai()
{
	float denta = b*b - 4*a*c;
	if(denta < 0){
		cout<<"Phuong trinh vo nghiem"<<endl;
	}else if(denta == 0){
		cout<<"Phuong trinh co nghiem kep x1 = x2 = "<<-b/(2*a)<<endl; 
	}else{
		cout<<"x1 = "<<(-b+sqrt(denta))/(2*a)<<endl;
		cout<<"x2 = "<<(-b-sqrt(denta))/(2*a)<<endl;
	}
}
void PtBac2::Xuat()
{
	cout<<"Phuong trinh vua nhap la: "<<endl;
	cout<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0"<<endl;
}

int main(){
	PtBac2 P,Q;
	cout<<"Nhap tham so phuong trinh P: "<<endl;
	P.Nhap();
	P.Xuat();
	P.Giai();
	cout<<"Nhap tham so phuong trinh Q: "<<endl;
	Q.Nhap();
	Q.Xuat();
	Q.Giai();
	
	
	return 0;
}
