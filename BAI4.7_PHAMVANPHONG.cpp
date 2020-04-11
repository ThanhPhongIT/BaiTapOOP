#include<iostream>
#include<iomanip>
#include<math.h>
#include<string.h>
using namespace std;
//dinh nghia lop diachi
class DiaChi{
	public:
		char dienThoai[12];
		char phuong[30];
		char quan[30];
		char thanhPho[30];
		friend class DoanhNgiep;
};	
//dinh nghia lop ngaytl
class Date{
	private:
		int day;
		int month;
	public:
		int year;
		friend class DoanhNgiep;
		void Nhap();
		void Xuat();
};
void Date::Nhap()
{
	cout<<"Nhap ngay: ";			cin>>day;
	cout<<"Nhap thang: ";			cin>>month;
	cout<<"Nhap nam: ";				cin>>year;
}
void Date::Xuat()
{
	cout<<setw(15)<<day<<"/"<<month<<"/"<<year;
}
//dinh nghia lop Doanh Nghiep
class DoanhNghiep{
	private:
		int maDn;
		char TenDn[60];
		char giamDoc[30];
	public:
		//public vi ham main dùng
		long DoanhThu;
		Date ngayTl;
		DiaChi diaChi;
		void Nhap();
		void Xuat();
};
void DoanhNghiep::Nhap()
{
	cout<<"Moi nhap thong tin doanh nghiep: "<<endl;
	cout<<"MaDN: ";					cin>>maDn;
	cout<<"TenDN: ";				fflush(stdin);		gets(TenDn);
	cout<<"Chair man: ";			gets(giamDoc);
	cout<<"Dien Thoai: ";			gets(diaChi.dienThoai);
	cout<<"Phuong: ";				gets(diaChi.phuong);
	cout<<"Quan: ";					gets(diaChi.quan);
	cout<<"Thanh pho: ";			gets(diaChi.thanhPho);
	ngayTl.Nhap();	
	cout<<"Doanh Thu: ";			cin>>DoanhThu;
}
void DoanhNghiep::Xuat()
{
	cout<<setw(15)<<maDn;					
	cout<<setw(15)<<TenDn;			
	cout<<setw(15)<<giamDoc;
	ngayTl.Xuat();			
	cout<<setw(15)<<diaChi.dienThoai;		
	cout<<setw(15)<<diaChi.phuong;				
	cout<<setw(15)<<diaChi.quan;				
	cout<<setw(15)<<diaChi.thanhPho;
	cout<<setw(15)<<DoanhThu<<endl;	
}

void Sua()
{
	
}
void menu()
{
	cout<<"\t\t\t====================================Danh sach Doanh Nghiep===================================="<<endl;
	cout<<setw(15)<<"MaDN";					
	cout<<setw(15)<<"TenDN";			
	cout<<setw(15)<<"GiamDoc";
	cout<<setw(20)<<"Ngay TL";		
	cout<<setw(18)<<"Dien Thoai";		
	cout<<setw(15)<<"Phuong";				
	cout<<setw(15)<<"Quan";				
	cout<<setw(15)<<"Thanh pho";
	cout<<setw(15)<<"Doanh Thu"<<endl;
}
int main(){
	int n;
	float doanhthu = 0;
	//nhap vao 
	cout<<"Nhap so doanh nghiep: ";		cin>>n;
	DoanhNghiep DN[n];
	for(int i=1; i<=n; i++){
		DN[i].Nhap();
	}
	//xuat ra
	menu();
	for(int i=1; i<=n; i++){
		DN[i].Xuat();
	}
	//ha noi
	cout<<"Nhung doanh nghiep o ha noi: "<<endl;
	menu();
	for(int i=1; i<=n; i++){
		if(strcmp(DN[i].diaChi.thanhPho, "ha noi")==0)
			DN[i].Xuat();
	}
	//tong doanh thu
	cout<<"Tong doanh thu nhung doanh nghiep thanh lap nam 2015: ";
	for(int i=1; i<=n; i++){
		if(DN[i].ngayTl.year==2015)
			doanhthu = doanhthu + DN[i].DoanhThu;
	}
	cout<<doanhthu<<endl;
	return 0;
}

