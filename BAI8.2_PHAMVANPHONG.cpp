#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class MonHoc{
private:
    char tenMon[30];
    int soTrinh;
    float diem;
public:
    void nhap();
    void xuat();
    friend class Phieu;
};
void MonHoc::nhap(){
    cout << "Nhap ten mon hoc: ";   fflush(stdin); gets(tenMon);
    cout << "Nhap so trinh: ";  cin >> soTrinh;
    cout << "Nhap diem: ";  cin >> diem;
}
void MonHoc::xuat(){
    cout << setw(15) << tenMon;
    cout << setw(15) << soTrinh;
    cout << setw(15) << diem << endl;
}
class SinhVien{
private:
    char maSV[10];
    char tenSV[30];
    char lop[10];
    char khoa[5];
public:
    void nhap();
    void xuat();
};
void SinhVien::nhap(){
    cout << "Nhap ma sinh vien: ";  		fflush(stdin);  	gets(maSV);
    cout << "Nhap ten sinh vien: "; 		fflush(stdin);  	gets(tenSV);
    cout << "Nhap lop: ";   				fflush(stdin);  	gets(lop);
    cout << "Nhap khoa: ";  				fflush(stdin);  	gets(khoa);
}
void SinhVien::xuat(){
    cout << "Ma sinh vien: " << maSV << "\tTen sinh vien: " << tenSV << endl;
    cout << "Lop: " << lop << "\t\tKhoa: " << khoa << endl;
}

class Phieu{
private:
    SinhVien A;
    MonHoc *dsMonHoc;
    int n;
public:
    void nhap();
    void xuat();
    float TBC();
};

void Phieu::nhap(){
    A.nhap();
    cout << "Nhap so mon hoc: ";   cin >> n;
    dsMonHoc = new MonHoc[n];
    for(int i = 0; i < n; i++){
        cout << "\tNhap thong tin mon hoc thu " << i + 1 << endl;
        dsMonHoc[i].nhap();
    }
}
float Phieu::TBC(){
    float tongDiem = 0;
    int tongMon = 0;
    for(int i = 0; i < n; i++){
        tongDiem += dsMonHoc[i].diem * dsMonHoc[i].soTrinh;
        tongMon += dsMonHoc[i].soTrinh;
    }
    return tongDiem/tongMon;
}
void Phieu::xuat(){
  	cout<<"\n*********************************\n\t\t\tPHIEU BAO DIEM\n";
    A.xuat();
    cout << "Bang diem: " << endl;
    cout << setw(15) << "TenMon" << setw(15) << "SoTrinh" << setw(15) << "Diem" << endl;
    for(int i = 0; i < n; i++){
        dsMonHoc[i].xuat();
    }
    cout <<setw(30)<< "Diem trung binh: " <<setw(15)<< TBC();
}
int main()
{
    Phieu B;
    cout << "Nhap thong tin phieu: " << endl;
    B.nhap();
    B.xuat();
    return 0;
}
