#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<math.h>
using namespace std;
class BenhAn;
class BenhNhan{
protected:
    char hoTen[30];
    char queQuan[30];
    int namSinh;
public:
    virtual void nhap();
    virtual void xuat();
};
class BenhAn: public BenhNhan{
public:
    char  tenBenhAn[30];
    float tienVienPhi;
    void nhap();
    void xuat();
    int tuoi();
};
void BenhNhan::nhap(){
    cout<<"\n Nhap ho ten: ";			    fflush(stdin);			gets(hoTen);
	cout<<"\n Nhap que quan: ";		        fflush(stdin);			gets(queQuan);
	cout<<"\n Nhap nam sinh: "; 		    cin>>namSinh;
}
void BenhNhan::xuat(){
    cout<<setw(30)<<hoTen;
	cout<<setw(20)<<queQuan;
	cout<<setw(10)<<namSinh;
}
void BenhAn::nhap(){
    cout<<"\n Nhap ten benh an: ";			fflush(stdin);			gets(tenBenhAn);
    cout<<"\n Nhap tien vien phi: ";		cin>>tienVienPhi;
}
void BenhAn::xuat(){
    cout<<setw(20)<<tenBenhAn;
	cout<<setw(10)<<tienVienPhi<<endl;
}
int BenhAn::tuoi(){

    return 2021 - BenhAn::namSinh;
}
void menu(){
    cout<<setw(30)<<"TenBenhNhan";
	cout<<setw(20)<<"QueQuan";
	cout<<setw(10)<<"NamSinh";
	cout<<setw(20)<<"TenBenhAn";
	cout<<setw(15)<<"TienVienPhi"<<endl;
}

int main(){
    BenhNhan a[100], *pt;
    BenhAn b[100];
    int n;
    cout<<"Nhap vao so benh an: ";      cin>>n;
    for(int i = 0; i<n; i++){
        a[i].nhap();
        pt = &b[i];
        pt->nhap();
    }
    cout<<"\n\n\t =================Danh sach Benh An vua nhap=================\n"<<endl;
    menu();
    for(int i = 0; i<n; i++){
        a[i].xuat();
        pt = &b[i];
        pt->xuat();
    }
    cout<<"\n\n\t =================Danh sach Benh Nhan nho hon bang 10 tuoi=================\n"<<endl;
    menu();
    for(int i = 0; i<n; i++){
        if(int(b[i].tuoi()) <= 10){
            a[i].xuat();
            pt = &b[i];
            pt->xuat();
        }
    }
        cout<<"\n\n\t =================Benh Nhan vien phi cao nhat=================\n"<<endl;
    menu();
    float Max = b[0].tienVienPhi;;
    for(int i = 0; i<n; i++){
        if(Max <= b[i].tienVienPhi){
            Max = b[i].tienVienPhi;
        }
    }
    for(int i = 0; i<n; i++){
        if(Max == b[i].tienVienPhi){
            a[i].xuat();
            pt = &b[i];
            pt->xuat();
        }
    }


    return 0;
}
