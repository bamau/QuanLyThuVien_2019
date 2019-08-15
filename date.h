#pragma once
#include <iostream>
#include <math.h>
#include <time.h>
#include <string.h>

using namespace std;
//------------------------------------------------------
//Khai bao
struct date
{
	int day;
	int month;
	int year;
};
//------------------------------------
void NhapNgayThangNam (date &d);
void ShowNgayThangNam (date d);
bool RangBuocNgayThangNam (date d);
int SoSanhNam (int Nam1, int Nam2);
int SoSanhThang (int Thang1, int Thang2);
int SoSanhNgay (int Ngay1, int Ngay2);
int SoSanhNgayThangNam (date d1, date d2);

//-------------------------------------
void NhapNgayThangNam(date &d)
{
	do
	{
		cout<<"Nhap ngay: "<<endl;
		cin>>d.day;
	}while(d.day<0);
	
	do
	{
		cout<<"Nhap thang: "<<endl;
		cin>>d.month;
	}while(d.month<0);
	
	do
	{
		cout<<"Nhap nam: "<<endl;
		cin>>d.year;
	}while(d.year<0);
	
}

void ShowNgayThangNam(date d)
{
	cout<<d.day<<"-"<<d.month<<"-"<<d.year<<endl;
}
//------------------------------------------------------------------
bool RangBuocNgayThangNam(date d)
{
	if (d.month >= 1 && d.month <= 12)		//xét tháng s? d?ng switch case
	{
		switch (d.month)
		{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			{	
				if(d.day>31)
				{
					cout<<"So ngay cua thang khong qua 31. "<<endl;
					return false;
				}
				break;
			}
			case 4: case 6: case 9: case 11:
			{
				if(d.day>30)
				{
					cout<<"So ngay cua thang khong qua 30. "<<endl;
					return false;
				}
				break;
			}
			case 2:
			{
				if (d.year % 4 == 0 && d.day>29)		//ki?m tra nam nhu?n du?c l?ng vào case tháng 2
				{
					cout<<"Nam nhuan, so ngay cua thang 2 khong qua 29. "<<endl;
					return false;
				}
				if (d.year % 4 != 0 && d.day>28)
				{
					cout<<"Nam khong nhuan, so ngay cua thang 2 khong qua 28. "<<endl;
					return false;
				}
				break;
			}
		}
		return true;
	}
}
//-----------------------------------------------------
int SoSanhNam (int Nam1, int Nam2)
{
	if(Nam1<Nam2)
		return -1;
	else
	{
		if(Nam1==Nam2)
			return 0;
		else
			return 1;
	}
}

int SoSanhThang (int Thang1, int Thang2)
{
	if(Thang1<Thang2)
		return -1;
	else
	{
		if(Thang1==Thang2)
			return 0;
		else
			return 1;
	}
}
int SoSanhNgay(int Ngay1, int Ngay2)
{
	if (Ngay1<Ngay2)	return -1;
	else
	{
		if(Ngay1==Ngay2)	return 0;
		else	return 1;
	}
}
//------------------------------------------------------------
int SoSanhNgayThangNam(date d1,date d2)
{
	int result;	//tao result de nhan ket qua tra ve
	result=SoSanhNam(d1.year,d2.year);	//cho result nhan ket qua tra ve cua SoSanhNam truoc
	if (result >0)			return 1;
	if (result<0) 		 	return -1;
	//result=0 xet tiep Thang

			result=SoSanhThang(d1.month,d2.month);	//dua result vao SoSanhThang
			if (result<0)		return-1;
			if (result>0)		return 1;
			
			//result =0 xét tiep Ngay
					result=SoSanhNgay(d1.day,d2.day);		//tuong tu cho SoSanhNgay
						if(result<0)	return -1;
						if(result>0)	return 1;
						else	//result =0 
						return 0;
}


date TinhNgayTra(date d1)
{
	date d2;
	int n;
	
	n = d1.day + 7;
	switch(d1.month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10:
			{
				if(n>31)
				{
					d2.month = d1.month+1;
					d2.day = n-31;
					d2.year=d1.year;
					break;
				}
				else
				{
					d2.day = n;
					d2.month=d1.month;
					d2.year=d1.year;
					break;
				}	
			}
		case 4: case 6: case 9: case 11:
			{
				if(n>30)
				{
					d2.month=d1.month+1;
					d2.day=n-30;
					d2.year=d1.year;
					break;
				}
				else
				{
					d2.day=n;
					d2.month=d1.month;
					d2.year=d1.year;
					break;
				}
			}
		case 2:
			{
				if(d1.year % 4 == 0 && d1.year % 100 != 0 || d1.year % 400 == 0)		//nhuan
				{
					if(n>29)
					{
						d2.month=d1.month+1;
						d2.day=n-29;
						d2.year=d1.year;
						break;
					}
					else
					{
						d2.month=d1.month;
						d2.day=n;
						d2.year=d1.year;
						break;
					}
				}
				else		//khong nhuan
				{
					if(n>28)
					{
						d2.month=d1.month+1;
						d2.day=n-28;
						d2.year=d1.year;
						break;
					}
					else
					{
						d2.month=d1.month;
						d2.day=n;
						d2.year=d1.year;
						break;
					}
				}
			}
		case 12:
			{
				if(n>31)
				{
					d2.month=1;
					d2.day=n-31;
					d2.year=d1.year+1;
					break;
				}
				else
				{
					d2.month=d1.month;
					d2.day=n;
					d2.year=d1.year;
					break;
				}	
			}
	}
	return d2;
}

void NhapNgayNhap(date &d)
{
	bool kiemtrangaythangnam=false;
	do
	{
		NhapNgayThangNam(d);
		kiemtrangaythangnam=RangBuocNgayThangNam(d);
	}while(kiemtrangaythangnam == false);
}

