#include<stdio.h>
#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;

class CanBo{
private:
    char MaCanBo[5];
    char HoVaTen[50];
    char NgaySinh[10];
    int  SoNgayLV;
public:
    void nhap();
    int  tinhLuong();
    void xuat();
};
void CanBo::nhap(){
    cout<<"Nhập vào mã cán bộ: ";
    cout<<"Nhập vào họ tên cán bộ: ";
    cout<<"Nhập vào ngày sinh: ";
    cout<<"Nhập số ngày làm việc: ";
}
int tinhLuong(){
    long luong;
}
void xuat(){

}
int main(){
    CanBo a;
    cout<<"Phong";
    return 0;
}


