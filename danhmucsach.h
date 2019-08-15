#pragma once
#include <iostream>
#include <math.h>
#include <time.h>
#include "config.h"
#include <string.h>
#include <stdlib.h>
#include <fstream> //thu vien cua fstream

#define dms_file "ds_dms.txt"
using namespace std;
//--------------------------------------------

//----------------------------------------------------------------------------
void init_DanhMucSach(NODEPTR &ds_dms);
void Newnode_dms(NODEPTR &ds_dms);

void Insert_dms_First(NODEPTR &ds_dms, DanhMucSach info_dms);
void Insert_dms_Last(NODEPTR &ds_dms, DanhMucSach info_dms);

void NhapInfoDanhMucSach(DanhMucSach &danhmucsach);
void DuaDanhMucSachVaoDanhSach(NODEPTR &ds_dms);

void ShowInfoDanhMucSach(DanhMucSach danhmucsach);
void ShowDanhSachDanhMucSachDaNhap(NODEPTR ds_dms);

void WriteList_dms(NODEPTR ds_dms);
void ReadList_dms(NODEPTR &ds_dms);
//--------------------------------------------------------------------------------

void init_DanhMucSach(NODEPTR &ds_dms)	//khoi tao dsach
{
	ds_dms =NULL;
}

void Newnode_dms (NODEPTR &ds_dms)	//cap phat vung nho
{
	ds_dms = new struct node_danhmucsach;		//dms thay = *node
}
//----------------------------------------------------------------------
void Insert_dms_First(NODEPTR &ds_dms, DanhMucSach info_dms)
{
	NODEPTR temp;
	Newnode_dms(temp);
	temp->dms=info_dms;
	temp->next=ds_dms;
	ds_dms=temp;
}

void Insert_dms_Last(NODEPTR &ds_dms, DanhMucSach info_dms)
{
	NODEPTR temp;	//tao mot bien tam
	if (ds_dms==NULL)		//neu danh sach danh muc sach NULL thi chen First 
		Insert_dms_First(ds_dms, info_dms);
	else
	{
		Newnode_dms(temp); 
		temp->dms=info_dms;
		NODEPTR last;	//tao mot con last de chay va xac dinh last dang o dau
		for(last=ds_dms;last->next!=NULL;last=last->next); //xac dinh last
		last->next=temp;		//next tro den temp
		temp->next=NULL;		//temp tro ve NULL de la phan tu cuoi cung
	}
}
//-------------------------------------------------------------------------------
void NhapInfoDanhMucSach(DanhMucSach &danhmucsach)
{
	char trang_thai;		//xet c
	string vi_tri="";
	cout<<"Nhap thong tin danh muc sach: "<<endl;
	cout<<"Nhap Ma Sach: "<<endl;
	cin>>danhmucsach.MASACH;
	cout<<"Nhap Trang Thai (trang thai la mot so nguyen): "<<endl;
	cin>>trang_thai;
	switch(trang_thai)
	{
		case '0':
			{
				danhmucsach.trangthai=ChoMuonDuoc;
				break;
			}
		case '1':
			{
				danhmucsach.trangthai=DaDuocMuon;
				break;
			}
		case '2':
			{
				danhmucsach.trangthai=DaThanhLy;
				break;
			}
		default:
			{
				cout<<"Loi. "<<endl;
				break;
			}
	}
	cout<<"Nhap Vi Tri: "<<endl;
	fflush(stdin);
	getline(std::cin, vi_tri);	//ham lum tren mang
	//fflush(stdin);
	//cin>>danhmucsach.ViTri;
	danhmucsach.ViTri=vi_tri;
	
}

void DuaDanhMucSachVaoDanhSach(NODEPTR &ds_dms)
{
	char yeucau;
	bool exit_input=true;
	DanhMucSach danhmucsach;
	do
	{
		NhapInfoDanhMucSach(danhmucsach);
		Insert_dms_Last(ds_dms,danhmucsach);
		cout<<"Ban co muon tiep tuc khong: "<<endl;
		cout<<"1/Co. "<<endl;
		cout<<"2/Khong. "<<endl;
		cin>>yeucau;
		if(yeucau=='1')
		{
			exit_input=false;
		}
		else
		{
			exit_input=true;
		}
	}while(exit_input==false);
	cout<<endl;
}
//-------------------------------------------------------------------------
void ShowInfoDanhMucSach(DanhMucSach danhmucsach)
{
	cout<<"Thong Tin Danh Muc Sach: "<<endl;
	cout<<"Ma Danh Muc Sach: ";
	cout<<danhmucsach.MASACH<<endl;
	cout<<"Trang Thai Sach: ";
	switch(danhmucsach.trangthai)
	{
		case 0:
			{
				cout<<"Chua Muon Duoc. "<<endl;
				break;
			}
		case 1:
			{
				cout<<"Da Duoc Muon "<<endl;
				break;
			}
		case 2:
			{
				cout<<"Da Thanh Ly. "<<endl;
				break;
			}
		default:
			{
				cout<<"Loi Nhap Lieu. "<<endl;
				break;
			}
	}
	cout<<"Vi Tri Sach: ";
	cout<<danhmucsach.ViTri<<endl;
	//fflush(stdin);
}

void ShowDanhSachDanhMucSachDaNhap(NODEPTR ds_dms)
{
	cout<<"\t\t\t\t Cac Danh Muc Sach Da Nhap: "<<endl;
	cout<<endl;
	//ham duyet
	if (ds_dms == NULL)
		cout<<" Danh Sach Rong. ";
	else
	{
		for (NODEPTR i = ds_dms ; i !=NULL ; i = i -> next)
		{
			ShowInfoDanhMucSach(i->dms);
			cout<<"-----------------------------"<<endl;
		}
	}
}

//----------viet_doc file
void WriteList_dms(NODEPTR ds_dms)
{
	fstream f;
	f.open(dms_file,ios::out);	//mo file, duoi dang ghi ra ngoai(out)
	
	for(NODEPTR i=ds_dms;i!=NULL;i=i->next)
	{
		f<<i->dms.ViTri<<endl;	//ViTri dac biet xet rieng
		f<<i->dms.MASACH<<endl;
		f<<i->dms.trangthai;		//khong cho endl ngay
		if(i->next!=NULL)
		{
			f<<endl;		//tach endl ra thanh 1 lenh khac kem theo dieu kien kiem tra, neu con du lieu thi ghi tiep, neu ko con thi moi endl
		}
	}
	cout<<"Luu file thanh cong! "<<endl;
	f.close();		//dong file
}

void ReadList_dms(NODEPTR &ds_dms)
{
	//string n; // de nhan gia tri enum
	//int n;
	DanhMucSach danhmucsach;
	string s;
	//char c[10];
	string trangthaisach;	//1 bien trang thai sach tam thoi
	fstream f;
	f.open(dms_file,ios::in); //dua vao de doc (in)
	while(f.eof()==false)		//loi vong lap while cua phan doc file 
	//doc cho den khi khong con thay gi de doc thi bien thanh "true"
	{
		//f>>danhmucsach.ViTri;
		getline(f,danhmucsach.ViTri);
		//cout<<"1"<<endl;
		//cout<<s<<endl;
		//danhmucsach.ViTri=s;
		//cout<<"3"<<endl;
		//cout<<danhmucsach.ViTri<<endl;
		//f>>danhmucsach.MASACH;
		getline(f,danhmucsach.MASACH);
		//cout<<danhmucsach.MASACH<<endl;
		//getline(f,n);
		getline(f,trangthaisach);		//doc trang thai
		int tt;	//tt la 1 so nguyen
		tt=atoi(trangthaisach.c_str());	//doi "string" sang mang ky tu/ "atoi" dung mang ky tu, can 1 bien nhan gia tri
		//c_str la ham doi string sang mang ky tu
		danhmucsach.trangthai= (TrangThai)tt;	//TrangThai la 1 trong 3 so nguyen, tt la 1 so nguyen => ep kieu cho tt
		//getline(f,c,'\n');
		Insert_dms_Last(ds_dms,danhmucsach);	
	}
		//cout<<danhmucsach.trangthai<<endl;
		//cout<<"2"<<endl;
	f.close();
	cout<<"Doc file thanh cong!"<<endl;
	cout<<endl;
}

