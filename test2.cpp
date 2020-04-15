#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<windows.h>
using namespace std;
class HangHoa;
class MOTO;
class NhaSanXuat
{
    private:
        char Ten_NSX[30];
        char DiaChi[30];
    public:
        void nhap();
        void xuat();
    friend class HangHoa;
    friend void y_d( MOTO a[], int &n);
};
class HangHoa
{
    protected:
        char NhanHieu[30];
        NhaSanXuat x;
    public:
        void nhap();
        void xuat();
    friend void y_d(MOTO a[], int &n);
};
class MOTO: private HangHoa
{
    private:
        int PhanKhoi;
        float GiaThanh;
    public:
        void nhap();
        void xuat();
    friend class NhaSanXuat;
    friend void y_b( MOTO a[], int n);
    friend void y_c( MOTO a[], int n);
    friend void y_d(MOTO a[], int &n);
};
void NhaSanXuat::nhap()
{
     cout<<"Ten NSX : ";fflush(stdin);gets(Ten_NSX);
     cout<<"Dia Chi: "; fflush(stdin);gets(DiaChi);
}
void NhaSanXuat::xuat()
{
    cout<<setw(15)<<Ten_NSX;
    cout<<setw(15)<<DiaChi;
}
void HangHoa::nhap()
{
     cout<<"\nNhan hieu : ";fflush(stdin);gets(NhanHieu);
     x.nhap();
}
void HangHoa::xuat()
{
    cout<<setw(15)<<NhanHieu;
    x.xuat();
}
void MOTO::nhap()
{
     HangHoa::nhap();
     cout<<"Phan Khoi : ";cin>>PhanKhoi;
     cout<<"Gia Thanh :";cin>>GiaThanh;
}
void MOTO::xuat()
{
    HangHoa::xuat();
    cout<<setw(15)<<PhanKhoi;
    cout<<setw(15)<<GiaThanh<<endl;
}
void cot_mau()
{
    cout<<setw(15)<<"NhanHieu";
    cout<<setw(15)<<"Ten_NSX";
    cout<<setw(15)<<"DiaChi";
    cout<<setw(15)<<"PhanKhoi";
    cout<<setw(15)<<"GiaThanh"<<endl;
}
void nhapds( MOTO a[], int &n)
{
    do{
        cout<<"\n nhap vao so moto: ";cin>>n;
        if(n<=0)cout<<"\n vui long nhap lai, ";
    }while(n<=0);
    for( int i=0;i<n;i++)
    {
        cout<<"\n ===MOTO thu: "<<i+1;
        a[i].nhap();
    }
}
void hienthids(MOTO a[], int n)
{
    cot_mau();
    for( int i=0;i<n;i++)
        a[i].xuat();
}
void y_b( MOTO a[], int n)
{
    float minn=a[0].GiaThanh;
    for( int i=1;i<n;i++)
        if(a[i].GiaThanh<minn)minn=a[i].GiaThanh;
    cout<<"\n\n\n\t\t\t========NHUNG MOTO CO GIA THANH MIN ======"<<endl;
    cot_mau();
    for( int i=0;i<n;i++)
        if(a[i].GiaThanh==minn)a[i].xuat();
}
void y_c( MOTO a[], int n)
{
    cout<<"\n\n\t\t======== Danh sach moto da sap xep =========== "<<endl;
    for( int i=0;i<n;i++)
    {
        int k=0;
        for( int j=n-1;j>i;j--)
        {
            if(a[j].GiaThanh<a[j-1].GiaThanh)
            {
                MOTO tam=a[j];
                a[j]=a[j-1];
                a[j-1]=tam;
                k=1;
            }
        }
        if(k==1)break;
    }
    hienthids(a,n);
}
void xoa1( MOTO a[], int &n, int k)
{
    for( int i=k;i<n-1;i++)
        a[i]=a[i+1];
    n--;
}
void y_d(MOTO a[], int &n)
{
    int k=0;
    for( int i=0 ;i<n;i++)
        if(strcmp(a[i].x.Ten_NSX,"HonDa")==0)
        {
            k=1;break;
        }
    if (k==0)cout<<"\n Khong co oto co ten NSX la HonDa !"<<endl;
    else{
        for( int i=0;i<n;i++)
            if(strcmp(a[i].x.Ten_NSX,"HonDa")==0)
            {
                xoa1(a,n,i);
                i--;
            }
        cout<<"\n\n\t\t ========Danh sach moto da xoa nsx HonDa ========== "<<endl;
        hienthids(a,n);
        cout<<endl;
    }
}
int main()
{
    int n;
    MOTO a[20];
    nhapds(a,n);
    system("cls");
    cout<<"\n \t\t\t============ Danh sach moto vua nhap la============= "<<endl<<endl;
    hienthids(a,n);
    y_b(a,n);
    y_c(a,n);
    y_d(a,n);
    return 0;
}
