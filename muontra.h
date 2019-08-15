#pragma once
#include <iostream>
#include <math.h>
#include <time.h>
#include <string.h>
#include "date.h"
#include <graphics.h>
#define muontra_file "dsmuontra.txt"
using namespace std;
//--------------------------------------------
//Khai bao
//--------------------------------------------------------------
void Init_DanhSachMuonTra(DanhSachMuonTra &dsmuontra);
void Newnode_DanhSachMuonTra(DanhSachMuonTra &dsmuontra);

void Insert_dsmuontra_First(DanhSachMuonTra &dsmuontra_first, DanhSachMuonTra &dsmuontra_last,MuonTra info_muontra);
int Insert_dsmuontra_Left(DanhSachMuonTra &dsmuontra_first,DanhSachMuonTra &dsmuontra_last, DanhSachMuonTra &p, MuonTra info_muontra);
int Insert_dsmuontra_Right(DanhSachMuonTra &p, DanhSachMuonTra &dsmuontra_last, MuonTra info_muontra);
void Insert_dsmuontra_Order(DanhSachMuonTra &dsmuontra_first, DanhSachMuonTra &dsmuontra_last, MuonTra info_muontra);

void NhapChiTietMuonTra(MuonTra &muontra);
void NhapDanhSachMuonTra(DanhSachMuonTra &dsmuontra_first, DanhSachMuonTra &dsmuontra_last);

void ShowInfoMuonTra(MuonTra muontra);
void ShowDanhSachMuonTra(DanhSachMuonTra dsmuontra_first);

//----------------------------------------------------------------
/*Khoi tao dsach va cap phat vung nho*/
void Init_DanhSachMuonTra(DanhSachMuonTra &dsmuontra)
{
	dsmuontra=NULL;
}
void Newnode_DanhSachMuonTra(DanhSachMuonTra &dsmuontra)
{
	dsmuontra = new struct node_muontra;
}
//------------------------------------------------------------------
/*Chen`*/
void Insert_dsmuontra_First(DanhSachMuonTra &dsmuontra_first, DanhSachMuonTra &dsmuontra_last,MuonTra info_muontra)
{
	DanhSachMuonTra temp;
	Newnode_DanhSachMuonTra(temp);
	temp->ChiTietMuonTra=info_muontra;
	temp->left=NULL;
	//temp->left=NULL;
	//temp->right=dsmuontra_first;
	if (dsmuontra_first==NULL)	//kiem tra xem First co NULL ko
	{
		dsmuontra_last = temp;
		temp->right=NULL;
	}
	else			//First da co 1 phan tu, tao lien ket giua temp va phan tu do
	{
		temp->right=dsmuontra_first;
		dsmuontra_first->left=temp;
	}
	
	dsmuontra_first=temp;
	
}

//chen` trai'
int Insert_dsmuontra_Left(DanhSachMuonTra &dsmuontra_first,DanhSachMuonTra &dsmuontra_last, DanhSachMuonTra &p, MuonTra info_muontra)
{
	DanhSachMuonTra temp,r;	//temp la nut can them vao, r la nut truoc, temp la nut sau
	//p
	if(p ==NULL)	return 0;

	if(p == dsmuontra_first)
			Insert_dsmuontra_First(dsmuontra_first,dsmuontra_last,info_muontra);
			
		else
		{
			cout<<"Insert Left!"<<endl;
			
			Newnode_DanhSachMuonTra(temp);	//khoi tao
			
			temp->ChiTietMuonTra=info_muontra; //do du lieu
			
			//r lay du lieu cua p -> left (truoc p)
			r =p->left;	
			
			//tao lien ket  giua nut truoc (r) cua p
			r->right=temp;		
			temp->left=r;
			
			//tao lien ket giua nut sau (temp) cua p
			temp->right=p;
			p->left=temp;
		}
	return 1;
}

//chen` phai?
int Insert_dsmuontra_Right(DanhSachMuonTra &p, DanhSachMuonTra &dsmuontra_last, MuonTra info_muontra)
{
	DanhSachMuonTra temp,r;	//q,r
	//dsmuontra_after p
	if(p ==NULL)	return 0;
	else
	{
			//cout<<"Insert Right 1"<<endl;
			Newnode_DanhSachMuonTra(temp);	//khoi tao
			temp->ChiTietMuonTra=info_muontra; //do du lieu
			
			//cout<<"Insert Right 2"<<endl;
			//dsmuontra_before lay du lieu cua dsachmuontra_after -> left
			r =p->right;	
			
			//quan trong, ham Insert Last
				cout<<"Insert Right!"<<endl;
				
				if(r!=NULL)	
					r->left=temp;
				
				temp->right=r;
				temp->left=p;
				p->right=temp;
				
				if(p==dsmuontra_last)	
					dsmuontra_last=temp;
	}
}

//chen` co' thu' tu.
void Insert_dsmuontra_Order(DanhSachMuonTra &dsmuontra_first, DanhSachMuonTra &dsmuontra_last, MuonTra info_muontra)
{
	DanhSachMuonTra dsmuontra_before;
	DanhSachMuonTra p;
	DanhSachMuonTra temp;
	
	if(dsmuontra_first==NULL)
	{
		cout<<"Insert First!"<<endl;
		
		Insert_dsmuontra_First(dsmuontra_first,dsmuontra_last,info_muontra);
		
		return ;
	}
	
	int sosanhngaythangnam;	//so sánh ngày
	for (p = dsmuontra_first;p!=NULL; p=p->right)
	{
		cout<<"Insert Order 1"<<endl;
		
		sosanhngaythangnam = SoSanhNgayThangNam(p->ChiTietMuonTra.NgayMuon,info_muontra.NgayMuon);

		if (sosanhngaythangnam>=0)
		{
			cout<<"Insert Left!"<<endl;
			
			Insert_dsmuontra_Left(dsmuontra_first,dsmuontra_last,p,info_muontra);
			return;
		}
	
	}
	cout<<"Insert Right!"<<endl;
	
	Insert_dsmuontra_Right(dsmuontra_last,dsmuontra_last,info_muontra);
	
}

//---------------------------------------------------------------
/*Nhap*/
void NhapChiTietMuonTra(MuonTra &muontra)
{
	bool KiemTraNgayThangNam=false;
	char c;		//xet c
	cout<<"---------------------------"<<endl;
	cout<<"Nhap Ma Sach: "<<endl;
	cin>>muontra.MASACH;
	int n;
	int result;
	//do
	//{
		do
		{
			cout<<"Nhap Ngay Muon: "<<endl;
			NhapNgayThangNam(muontra.NgayMuon);
			KiemTraNgayThangNam = RangBuocNgayThangNam(muontra.NgayMuon);
			if (KiemTraNgayThangNam==false)
				cout<<"Ngay thang nam sai, nhap lai ngay thang nam cua Ngay Nhap!"<<endl;
		}while(KiemTraNgayThangNam == false);
	
	muontra.NgayTra=TinhNgayTra(muontra.NgayMuon);
//		do
//		{
//			cout<<"Nhap Ngay Tra: "<<endl;
//			NhapNgayThangNam(muontra.NgayTra);
//			exit_input=RangBuocNgayThangNam(muontra.NgayTra);
//		}while(exit_input==false);
//		result =SoSanhNgayThangNam(muontra.NgayMuon,muontra.NgayTra);
//		//cout<<result<<endl;
//		if(result>0)
//		{
//			cout<<"Ngay muon nho hon ngay tra. Nhap lai: "<<endl;
//		}
//	}while(result >0);
	
//	cout<<"Nhap Trang Thai Muon_Tra Sach: "<<endl;
//	cin>>c;
//	
//	switch(c)
//	{
//		case '0':
//			{
//				muontra.trangthaimuontra = ChuaTra;
//				break;
//			}
//		case '1':
//			{
//				muontra.trangthaimuontra = DaTra;
//				break;
//			}
//		case '2':
//			{
//				muontra.trangthaimuontra = MatSach;
//				break;
//			}
//		default:
//			{
//				cout<<"Loi. "<<endl;
//				break;
//			}
//	}
}



void NhapDanhSachMuonTra(DanhSachMuonTra &dsmuontra_first, DanhSachMuonTra &dsmuontra_last)
{
	//bool exit_input=false;
	char c;
	//int sophantu;
	MuonTra muontra;
	
	do
	{
		NhapChiTietMuonTra(muontra);
		//cout<<"Insert Order"<<endl;
		//DUYET DS THEO MASACH
		//TRA VE PHAN TU TRUOC DO
		//ham kt
		Insert_dsmuontra_Order(dsmuontra_first,dsmuontra_last,muontra);
		
		cout<<"Nhap tiep khong? "<<endl;
		cout<<"1/Co."<<endl;
		cout<<"2/Khong."<<endl;
		cin>>c;
		
		if(c=='2')	return;
	}while(1);
}

//---------------------------------------------------------
/*Xuat*/
void ShowInfoMuonTra(MuonTra muontra)
{
	cout<<"--------------------------"<<endl;
	cout<<"Thong Tin Muon Tra Sach: "<<endl;
	cout<<"Ma Sach dang muon: "<<endl;
	cout<<muontra.MASACH<<endl;
	cout<<"Ngay Muon: "<<endl;
	ShowNgayThangNam(muontra.NgayMuon);
	cout<<"Ngay Tra: "<<endl;
	ShowNgayThangNam(muontra.NgayTra);
	cout<<"Trang Thai Muon_Tra: ";
	switch(muontra.trangthaimuontra)
	{
		case 0:
			{
				cout<<"Dang Muon. "<<endl;
				break;
			}
		case 1:
			{
				cout<<"Da Tra. "<<endl;
				break;
			}
		case 2:
			{
				cout<<"Da Mat. "<<endl;
				break;
			}
		default:
			{
				cout<<"Loi. "<<endl;
				break;
			}
	}
	cout<<"--------------------------------"<<endl;
}

void ShowDanhSachMuonTra(DanhSachMuonTra dsmuontra_first)
{
	DanhSachMuonTra temp;		//tao mot con tro
	if(dsmuontra_first==NULL)
		cout<<"Danh sach rong."<<endl;
	else
	{
		temp=dsmuontra_first;		//gan con tro moi tao la con tro dau` cua dsach'
		while(temp!=NULL)			//khi con tro chua = NULL
		{
			ShowInfoMuonTra(temp->ChiTietMuonTra);
			temp=temp->right;		//con tro? chay.
		}
	}
}

//-------------------------------------------------------------------
//viet_doc file
void WriteList_DanhSachMuonTra(DanhSachMuonTra dsmuontra)
{
	fstream f;
	f.open(muontra_file, ios::out);
	
	//f<<sophantu;
	//f<<endl;
	for(DanhSachMuonTra i=dsmuontra   ; i!=NULL ; i=i->right )
	{
		
		f<<i->ChiTietMuonTra.MASACH<<endl;
		f<<i->ChiTietMuonTra.NgayMuon.day<<" "<<i->ChiTietMuonTra.NgayMuon.month<<" "<<i->ChiTietMuonTra.NgayMuon.year<<endl;
//		f<<i->ChiTietMuonTra.NgayTra.day<<" "<<i->ChiTietMuonTra.NgayTra.month<<" "<<i->ChiTietMuonTra.NgayTra.year<<endl;
		f<<i->ChiTietMuonTra.trangthaimuontra;
		//f<<"---------------------------------";
		if(i->right!=NULL)
			f<<endl;
	}
	
	cout<<"Luu file thanh cong! "<<endl;
	f.close();
}

//void WriteList_DanhSachMuonTra2(DanhSachMuonTra dsmuontra)
//{
//	fstream f;
//	f.open(muontra_file, ios::out);
//	
//	//f<<sophantu;
//	for(DanhSachMuonTra i=dsmuontra   ; i!=NULL ; i=i->right )
//	{
//		
//		f<<i->ChiTietMuonTra.MASACH<<endl;
//		f<<i->ChiTietMuonTra.NgayMuon.day<<endl;
//		f<<i->ChiTietMuonTra.NgayMuon.month<<endl;
//		f<<i->ChiTietMuonTra.NgayMuon.year<<endl;
////		f<<i->ChiTietMuonTra.NgayTra.day<<" "<<i->ChiTietMuonTra.NgayTra.month<<" "<<i->ChiTietMuonTra.NgayTra.year<<endl;
//		f<<i->ChiTietMuonTra.trangthaimuontra<<endl;
//		//f<<sophantu;
//		//f<<endl;
//		f<<"----------------------------";
//		if(i->right!=NULL)
//		{
//			f<<endl;
//		}
//	}
//	
//	cout<<"Luu file thanh cong! "<<endl;
//	f.close();
//}

void ReadList_DanhSachMuonTra2(DanhSachMuonTra &dsmuontra_first,DanhSachMuonTra &dsmuontra_last)
{
	MuonTra muontra; 
	//int sophantu =0; 
	int tt_mt;
	fstream f;
	string s; // de luu dong "------------------"
	string trangthaimuontra;
	f.open(muontra_file,ios::in);
	//int id_mt=0;
	//getline(f,spt);
	//sophantu=atoi(spt.c_str());
	
	//for (DanhSachMuonTra i=dsmuontra_first;i!=NULL;i=i->right)
	while(f.eof()==false)
	{
		getline(f,muontra.MASACH);
		//f>>muontra.MASACH;
		//cout<<muontra.MASACH<<endl;
		
		f>>muontra.NgayMuon.day;
	//	cout<<muontra.NgayMuon.day<<endl;
		f>>muontra.NgayMuon.month;
		//cout<<muontra.NgayMuon.month<<endl;
		f>>muontra.NgayMuon.year;
		//cout<<muontra.NgayMuon.year<<endl;
		
//		f>>muontra.NgayTra.day;
//		f>>muontra.NgayTra.month;
//		f>>muontra.NgayTra.year;
		
		getline(f,trangthaimuontra);
		tt_mt=atoi(trangthaimuontra.c_str());
		muontra.trangthaimuontra=(TrangThai_MuonTra) tt_mt;
		//cout<<muontra.trangthaimuontra<<endl;
		
//		f>>sophantu;
//		cout<<sophantu<<endl;
//		getline(f,s);
//		sophantu=atoi(s.c_str());


		getline(f,s);
		//id_mt++;
		//cout<<id_mt<<endl;
		//delay(1000);
		Insert_dsmuontra_Order(dsmuontra_first,dsmuontra_last,muontra);
//		if(id_mt==sophantu)
//			break;
	}
	f.close();
	
	cout<<"Doc file thanh cong!"<<endl;
	
	cout<<endl;
}

