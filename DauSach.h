#pragma once
#include "config.h"
#include <string>
#include<cstdio>
#include <iomanip>
#include<fstream> // du dung cho do ghi file
#define TRUE 1
#define FALSE 0 
using namespace std;

int empty(list &listDS);
int full(list &listDS);
int InsertDS(list &ds, int i, DauSach info);

void KhoitaoDS(list &listDS)
{
	listDS.n = 0;
}

int empty(list &listDS)
{
	return(listDS.n==0 ? TRUE : FALSE);
}
int full(list &listDS)
{
	return(listDS.n==MAXLIST ? TRUE : FALSE);
}

void NhapDauSach(DauSach &ds)
{
	fflush(stdin);
	cout<<"Nhap ma dau sach: ";
	cin>>ds.ISBN;
	fflush(stdin);
	cout<<"Nhap ten sach: ";
	getline(cin,ds.tenSach);
	cout<<"Nhap so trang: ";
	cin>>ds.soTrang;
	fflush(stdin);
	cout<<"Nhap tac gia: ";
	getline(cin,ds.tacGia);
	cout<<"Nhap nam xuat ban: ";
	cin>>ds.namXuatBan;
	fflush(stdin);
	cout<<"Nhap the loai: ";
	getline(cin,ds.theLoai);
}

int InsertDS(list &ds, int i, DauSach info)
{
	int j;
	if(i<0||i>ds.n||(full(ds)))
		return 0;
	DauSach *p = new DauSach;
	*p=info;	
	for(j=ds.n-1; j>=i; j--)
	{
		ds.nodes[j+1]=ds.nodes[j];
	}
	ds.nodes[i]=p;
	ds.n++;
	return 1;
}

void ThemDS(list &listDS, DauSach info)
{
	if (listDS.n > MAXLIST)
	{
		return;
	}
	DauSach *p = new DauSach;
	*p=info;
	listDS.nodes[listDS.n++] = p;
}

void XoaDS(list &listDS, int x)
{
	for(int i=0; i<listDS.n; i++)
	{
		if(i == x)
		{
			for(int j= i; j < listDS.n-1; j++)
			{
				listDS.nodes[j] = listDS.nodes[j+1];
			}
			listDS.n--;
			break;
		}
	}
}

int TimKiemDS(list listDS, string a)
{
	for(int i=0; i<listDS.n ;i++)
	{
		if( listDS.nodes[i]->ISBN == a)
			return i;
	}
	return -1;
}

int TimKiemTenSach(list listDS, string a)
{
	for(int i=0; i<listDS.n ;i++)
	{
		if(listDS.nodes[i]->tenSach == a)
			return i;
	}
	return -1;
}


void XuatListDS(list listDS)
{
	if(empty(listDS)==TRUE)
	{
		cout<<"Danh sach rong\n";
	}
	else
	{
		cout<<"\t\t\t\t\t======DANH SACH CAC DAU SACH======\n\n";
		cout<<setw(10)<<"Ma Sach"<<setw(40)<<"Ten Sach"<<setw(15)<<"The Loai"<<setw(25)<<"Tac Gia"<<setw(10)<<"So Trang"<<setw(20)<<"Nam Xuat Ban"<<endl;
		DauSach *ds = new DauSach;
		for(int i=0; i<listDS.n; i++)
		{
			ds=listDS.nodes[i];
			cout<<setw(10)<< ds->ISBN<<setw(40)<<ds->tenSach<<setw(15)<<ds->theLoai<<setw(25)<<ds->tacGia<<setw(10)<<ds->soTrang<<setw(20)<<ds->namXuatBan<<endl;
		}
	}
}

void GhiFileDS(list &listDS)
{
	ofstream f("DauSach.txt");
	int n = 0;
	for (int i = 0; i < listDS.n; i++) // dem so luong doc gia
	{
		n++;
	}
	f << n << endl;
	for (int i = 0; i < n; i++)  // Ghi du lieu tung do gia vao file
	{
		f << listDS.nodes[i]->ISBN << endl;
		f << listDS.nodes[i]->tenSach << endl;
		f << listDS.nodes[i]->tacGia << endl;
		f << listDS.nodes[i]->theLoai << endl;
		f << listDS.nodes[i]->soTrang << endl;
		f << listDS.nodes[i]->namXuatBan << endl;
//		for(PTRDMS p = listDS.nodes[i]->firstDMS.pnext; p !=NULL; p=p->pNext)
//		{
//			f << p->dms.maSach << endl;
//			f << p->dms.trangThai << endl;
//			f << p->dms.viTri << endl;
//		}
	}
	f.close();
}

	
void LoadFileDS(list &listDS)
{
	DanhMucSach s;
	int soluongds;
	ifstream fi;
	fi.open("DauSach.txt");
	fi >> soluongds; // Dem so luong dau sach
	string temp; // doc xuong dong
	getline(fi,temp);
	for(int j=0; j<soluongds; j++) // Doc du lieu tung doc gia
	{
		DauSach *data;
		data = new DauSach[MAXLIST];
		fi>>data->ISBN;
		fi.ignore();
		getline(fi, data->tenSach);
		getline(fi, data->tacGia);
		getline(fi, data->theLoai);
		getline(fi, data->soTrang);
		getline(fi, data->namXuatBan);
		ThemDS(listDS,*data);
//		listDS.n++;
//		 KhoitaoLDMS(l.DS[j]->sach);
//		for(int i=0; i < data->n; i++)
//		{
//			getline(fi,s.maSach);
//			fi >> s.ttSach; getline(fi,temp);
//			fi >> s.vitri; getline(fi,temp);
//			AddTailDMS(l.DS[j]->sach,CreateDMS(s));
//		}
	}
	fi.close();
}

void SaveList (list &listDS, char *tenfile)
{
  FILE *f;
  f= fopen (tenfile, "wb"); 
  if (f==NULL) { cout<< "Loi mo file de ghi"; return ; }
  
  for (int i=0; i < listDS.n ; i++)
  {
    fwrite (&listDS.nodes[i], sizeof(listDS.nodes[i]),1,f);
  }
  fclose(f);
}

int OpenList (list &listDS, char *tenfile)
{
  FILE *f; 
  f= fopen (tenfile, "rb");
  if (f==NULL) { cout<< "\nLoi mo file de doc\n"; return -1 ; }
  else cout<<"\nLoad file thanh cong!\n";
  int i=0;
   while ( fread (&listDS.nodes[i], sizeof(listDS.nodes[i]),1,f)!=0 ) i++;
  fclose(f);
  listDS.n=i;
}
