#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;
class NhanVien;
class Date{
	private:
		int day, month, year;
	public:
		friend class NhanVien;
		friend void ganNv(NhanVien a, NhanVien b);
		friend void chen(NhanVien list[], int &n, int &k);
		friend void xoa(NhanVien list[], int &n);
};
class PhongBan{
	private:
		int maPb, soNv;;
		char tenPb[50], truongPhong[10];	
	public:
		friend class NhanVien;
		friend void ganNv(NhanVien a, NhanVien b);
		friend void taiChinh(NhanVien ds[], int &n);
		friend void chen(NhanVien list[], int &n, int &k);
		friend void xoa(NhanVien list[], int &n);
};
class NhanVien{
	private:
		int maNv;
		char hoDem[25], ten[10];
		Date NgaySinh;
		PhongBan phong;
	public:
		void nhap();
		void xuat();
		friend void ganNv(NhanVien a, NhanVien b);
		friend void taiChinh(NhanVien ds[], int &n);
		friend void sort(NhanVien ds[], int &n);
		friend void chen(NhanVien list[], int &n, int &k);
		friend void xoa(NhanVien list[], int &n);
		
	
};
void NhanVien::nhap(){
	cout<<"Nhap vao ma NV: ";		cin>>maNv;
	cout<<"Nhap vao ho dem: ";		fflush(stdin);		gets(hoDem);
	cout<<"Nhap vao ten: ";			fflush(stdin);		gets(ten);
	cout<<"Nhap ngay sinh: ";		cin>>NgaySinh.day;
	cout<<"Nhap thang sinh: ";		cin>>NgaySinh.month;
	cout<<"Nhap nam sinh: ";		cin>>NgaySinh.year;
	cout<<"Nhap vao ma pb: ";		cin>>phong.maPb;
	cout<<"Nhap vao ten pb: ";						fflush(stdin);		gets(phong.tenPb);
	cout<<"Nhap vao ten truong phong: ";			fflush(stdin);		gets(phong.truongPhong);
	cout<<"Nhap so nv: ";			cin>>phong.soNv;
}
void NhanVien::xuat(){
	cout<<setw(7)<<maNv;
	cout<<setw(27)<<hoDem;
	cout<<setw(12)<<ten;
	cout<<setw(7)<<NgaySinh.day;
	cout<<setw(7)<<NgaySinh.month;
	cout<<setw(7)<<NgaySinh.year;
	cout<<setw(7)<<phong.maPb;
	cout<<setw(30)<<phong.tenPb;
	cout<<setw(30)<<phong.truongPhong;
	cout<<setw(7)<<phong.soNv<<endl;
	
}
void taiChinh(NhanVien ds[], int &n){
	int count = 0;
	for(int i = 0; i<n; i++){
		if(strcmp(ds[i].phong.tenPb, "taichinh")==0){
			count++;
			ds[i].xuat();
		}
	}
	if(count == 0) {
		cout<<"Khong co nv thuoc phong tai chinh!\n";
	}
}
void sort(NhanVien ds[], int &n){
	for(int i = 0; i< n; i++){
		for(int j = 0; j < n-1; j++){	
			if(strcmp(ds[j].ten,ds[j+1].ten)>0){
				NhanVien a = ds[j];
				ds[j] = ds[j+1];
				ds[j+1] = a;
			}
		}
	}
	for(int i=0; i<n; i++){
		cout<<setw(3)<<i+1;
		ds[i].xuat();	
	}
	
}
void chen(NhanVien list[], int &n, int &k){
	
	for(int i = n; i>k-1; i--){
		list[i] = list[i-1];
	}
	list[k-1].nhap();
	n++;
}
void xoa(NhanVien list[], int &n){
	for(int i = 0; i<n; i++){
		if(list[i].maNv == 123){
			for(int j=i; j<n; j++){
				list[j] = list[j-1];
			}
			n--;
		}
	}
}
void title(){
	cout<<setw(3)<<"STT";
	cout<<setw(7)<<"Ma NV";
	cout<<setw(27)<<"Ho Dem";
	cout<<setw(12)<<"Ten";
	cout<<setw(7)<<"NS";
	cout<<setw(7)<<"TS";
	cout<<setw(7)<<"NS";
	cout<<setw(7)<<"Ma Pb";
	cout<<setw(30)<<"Ten Pb";
	cout<<setw(30)<<"Truong Phong";
	cout<<setw(7)<<"So Nv"<<endl;
}

int main(){
	int n;
	cout<<"Nhap vao so nhan vien: ";		cin>>n;
	NhanVien *list = new NhanVien[n];
	for(int i=0; i<n; i++){
		cout<<"\t**Nhan vien thu "<<i+1<<"**"<<endl;
		list[i].nhap();
	}
	cout<<"\t\t\t\t===========Danh sach nhan vien thuoc phong tai chinh=============\n";
	title();
	taiChinh(list, n);
	cout<<"\t\t\t\t===========Danh sach nhan vien da sap xep=============\n";
	title();
	sort(list , n);
	int k;
	cout<<"Nhap thu tu nhan vien: ";	cin>>k;
	chen(list, n, k);
	cout<<"\t\t\t\t===========Danh sach nhan vien sau chen=============\n";
	title();
	for(int i=0; i<n; i++){
		cout<<setw(3)<<i+1;
		list[i].xuat();	
	}
	xoa(list, n);
	cout<<"\t\t\t\t===========Danh sach nhan vien sau xoa=============\n";
	title();
	for(int i=0; i<n; i++){
		cout<<setw(3)<<i+1;
		list[i].xuat();	
	}
	return 0;
}
