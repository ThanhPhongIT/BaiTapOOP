#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;

class XeHoi{
private:
    char nhanHieu[10];
    char hangSanXuat[10];
    char kieuDang[10];
    char mauSon[5];
    int  namSanXuat;
    char xuatXu[10];
    long long giaBan;
public:
    void nhap();
    void xuat();
    friend void toyota(XeHoi a[], int &n);
    friend void sort(XeHoi a[], int &n);
};
void XeHoi::nhap(){
    cout<<"Nhap vao nhan hieu xe: ";        fflush(stdin);      gets(nhanHieu);
    cout<<"Nhap vao hang san xuat: ";       fflush(stdin);      gets(hangSanXuat);
    cout<<"Nhap vao kieu dang: ";           fflush(stdin);      gets(kieuDang);
    cout<<"Nhap vao mau son: ";             fflush(stdin);      gets(mauSon);
    cout<<"Nhap vao nam san xuat: ";        cin>>namSanXuat;
    cout<<"Nhap vao xuat xu: ";             fflush(stdin);      gets(xuatXu);
    cout<<"Nhap vao gia ban: ";             cin>>giaBan;

}
void XeHoi::xuat(){
    cout<<setw(12)<<nhanHieu;
    cout<<setw(12)<<hangSanXuat;
    cout<<setw(12)<<kieuDang;
    cout<<setw(12)<<mauSon;
    cout<<setw(10)<<namSanXuat;
    cout<<setw(12)<<xuatXu;
    cout<<setw(15)<<giaBan<<endl;
}
void title(){
	cout<<setw(12)<<"Nhan Hieu";
    cout<<setw(13)<<"Hang san xuat";
    cout<<setw(12)<<"Kieu dang";
    cout<<setw(12)<<"Mau son";
    cout<<setw(10)<<"Nam sx";
    cout<<setw(12)<<"Xuat xu";
    cout<<setw(15)<<"Gia ban"<<endl;
}
void toyota(XeHoi a[], int &n){
	for(int i = 0; i < n; i++){
		if(strcmp(a[i].hangSanXuat, "toyota") == 0){
			a[i].xuat();
		}
	}
}
void sort(XeHoi a[], int &n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){	
			if(a[j].giaBan >= a[j+1].giaBan){
				long long tmp = a[j].giaBan;
				a[j].giaBan = a[j+1].giaBan;
				a[j+1].giaBan = tmp;
			}
		}
	}
}
int main(){
    int n;
    XeHoi *a = new XeHoi[n];
    cout<<"Nhap vao so xe: "; cin>>n;
    for(int i = 0; i < n; i++){
         cout<<"**** Xe thu "<<i + 1<<"****"<<endl;
        a[i].nhap();
    }
    cout<<"\t\t=======================DANH SACH XE HOI VUA NHAP=====================\n";
    title();
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }
    cout<<"\t\t=======================DANH SACH XE HOI HANG TOYOTA=====================\n";
    title();
    toyota(a, n);
    sort(a, n);
    cout<<"\t\t=======================DANH SACH XE HOI GIA TANG DAN=====================\n";
    title();
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }
    
    return 0;
}
