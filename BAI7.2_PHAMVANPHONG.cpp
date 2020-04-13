#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string>

using namespace std;
class SCHOOL{
private:
	char name[30];
	char date[12];
	friend class FACULTY;
};
class FACULTY{
private:
	char name[30];
	char date[12];
	SCHOOL x;
public:
	void input();
	void output();
	friend class Student;
};
void FACULTY::input(){
	cout<<"Nhap vao ten truong: ";					fflush(stdin);		gets(x.name);
	cout<<"Nhap vao nam thanh lap truong: ";		fflush(stdin);		gets(x.date);
	cout<<"Nhap vao ten nganh: ";					fflush(stdin);		gets(name);
	cout<<"Nhap vao nam thanh lap khoa: ";			fflush(stdin);		gets(date);
}
void FACULTY::output(){
	cout<<"Ten truong: "<<x.name<<endl;
	cout<<"Ngay TL truong: "<<x.date<<endl;
	cout<<"Ten nganh: "<<name<<endl;
	cout<<"Ngay TL khoa"<<date<<endl;
}
class Person{
protected:
	char name[30];
	char date[12];
	char address[30];
public:
	void input();
	void output();
	
};
void Person::input(){
	cout<<"Nhap vao ten sinh vien: ";		fflush(stdin);		gets(name);
	cout<<"Nhap vao ngay sinh: ";		fflush(stdin);		gets(date);
	cout<<"Nhap vao dia chi: ";		fflush(stdin);		gets(address);
}
void Person::output(){
	cout<<"Ten SV: "<<name<<endl;
	cout<<"Ngay Sinh: "<<date<<endl;
	cout<<"Dia chi: "<<address<<endl;
}
class Student:public Person{
private:
	FACULTY y;
	char Class[10];
	float score;
public:
	void input();
	void output();
	
};
void Student::input(){
	Person::input();
	y.input();
	cout<<"Nhap vao lop: ";		fflush(stdin);		gets(Class);
	cout<<"Nhap vao diem: ";		cin>>score;
}
void Student::output(){
	Person::output();
	y.output();
	cout<<"Lop: "<<Class<<endl;
	cout<<"Diem: "<<score<<endl;
}

int main(){
	Student a;
	cout<<"Nhap vao thong tin cua 1 sinh vien:\n";
	a.input();
	cout<<"******Thong tin sinh vien vua nhap la*******\n";
	a.output();
	return 0;
}
