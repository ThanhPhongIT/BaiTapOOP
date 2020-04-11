#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

class VECTO{
	private:
		float x;
		float y;
	public:
		void Nhap();
		void Xuat();
		VECTO operator+(VECTO B);
		VECTO operator-(VECTO B);	
};

void VECTO::Nhap(){
	cout<<"Nhap vao toa do x: ";			cin>>x;
	cout<<"Nhap vao toa do y: ";			cin>>y;
}
void VECTO::Xuat(){
	cout<<"("<<x<<","<<y<<")"<<endl;
}
VECTO VECTO::operator+(VECTO B){
	VECTO tong;
	tong.x = x + B.x;
	tong.y = y + B.y;
	return tong;
}
VECTO VECTO::operator-(VECTO B){
	VECTO hieu;
	hieu.x = x - B.x;
	hieu.y = y - B.y;
	return hieu;
}
int main(){
	VECTO A,B,T,H;
	A.Nhap();
	cout<<"Toa do vto A la : ";			A.Xuat();
	B.Nhap();
	cout<<"Toa do vto B la : ";			B.Xuat();
	T = A + B;
	H = A - B;
	cout<<"Tong hai vto A va B la: ";	T.Xuat();
	cout<<"\nHieu hai vto A va B la: ";	H.Xuat();
	return 0;
}
