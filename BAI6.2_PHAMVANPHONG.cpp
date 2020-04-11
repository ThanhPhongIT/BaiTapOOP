#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class PhanSo{
private:
    int tuSo;
    int mauSo;
public:
    void nhap();
    void xuat();
    PhanSo operator*(PhanSo b);
    PhanSo operator/(PhanSo b);
    PhanSo operator+(PhanSo b);
    PhanSo operator-(PhanSo b);
};
void PhanSo::nhap(){
    cout<<"Nhap vao tu so: ";       cin>>tuSo;
    cout<<"Nhap vao mau so: ";      cin>>mauSo;
}
PhanSo PhanSo:: operator*(PhanSo b){
    PhanSo tich;
    tich.tuSo = (tuSo*b.tuSo);
    tich.mauSo = (mauSo*b.mauSo);
    return tich;
}
PhanSo PhanSo:: operator/(PhanSo b){
    PhanSo thuong;
    thuong.tuSo = (tuSo*b.mauSo);
    thuong.mauSo = (mauSo*b.tuSo);
    return thuong;
}
PhanSo PhanSo:: operator+(PhanSo b){
    PhanSo tong;
    tong.tuSo = ((tuSo*b.mauSo)+(mauSo*b.tuSo));
    tong.mauSo = (mauSo*b.mauSo);
    return tong;
}
PhanSo PhanSo:: operator-( PhanSo b){
    PhanSo hieu;
    hieu.tuSo = ((tuSo*b.mauSo)-(mauSo*b.tuSo));
    hieu.mauSo = (mauSo*mauSo);
    return hieu;
}
void PhanSo::xuat(){
    cout<<tuSo<<"/"<<mauSo<<" = "<<tuSo*1.0/mauSo<<endl;
}

int main(){
    PhanSo a,b,tong,hieu,tich,thuong;
    a.nhap();
    b.nhap();
    tong = a + b;
    hieu = a - b;
    tich = a * b;
    thuong = a / b;
    cout<<"Tong hai phan so = ";		tong.xuat();
    cout<<"Hieu hai phan so = ";		hieu.xuat();
    cout<<"Tich hai phan so = ";		tich.xuat();
    cout<<"Thuong hai phan so = ";		thuong.xuat();


}

