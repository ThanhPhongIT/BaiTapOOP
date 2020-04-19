#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

class PTB1{
private:
	float a;
	float b;
public:
	PTB1 operator+(PTB1 A);
	PTB1 operator-(PTB1 A);
	friend istream& operator>>(istream& x, PTB1 &y);
    friend ostream& operator<<(ostream& x, PTB1 y);
};
PTB1 PTB1::operator+(PTB1 A){
	PTB1 sum;
	sum.a = a + A.a;
	sum.b = b + A.b;
	return sum;
}
PTB1 PTB1::operator-(PTB1 A){
	PTB1 hieu;
	hieu.a = a - A.a;
	hieu.b = b - A.b;
	return hieu;
}
istream&operator>>(istream& x, PTB1& y)
{
    cout<<"\n Nhap vao a:  ";      x>>y.a;
    cout<<"\n Nhap vao b: ";      x>>y.b;
    return x;
}
ostream&operator<<(ostream& x, PTB1 y)
{
    x<<y.a<<"x + "<<y.b<<" = 0"<<endl;
    return x;
}

int main(){
	PTB1 A, B, tong, hieu;
	cout<<"Phuong trinh nhap vao co dang ax + b = 0"<<endl;
	cout<<"Nhap vao phuong trinh thu nhat: "<<endl;
	cin>>A;
	cout<<"Nhap vao phuong trinh thu hai: "<<endl;
	cin>>B;
	tong = A + B;
	hieu = A - B;
	cout<<"Tong hai phuong trinh vua nhap: ";		cout<<tong;
	cout<<"Hieu hai phuong trinh vua nhap: ";		cout<<hieu;
	return 0;
}
