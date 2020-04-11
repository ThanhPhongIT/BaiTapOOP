#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<math.h>
using namespace std;
class SINHVIEN{
protected:
	char HoTen[30];
	char SBD[15];
};
class DIEMTHI:public SINHVIEN{
protected:
	float DiemThi1;
	float DiemThi2;
};
class KETQUA:public SINHVIEN DIEMTHI{
private: 
	float TongDiem = DIemDiemThi1 + DiemThi2;
};
