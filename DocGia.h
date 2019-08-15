#pragma once
#include "config.h"
#include <string>
#include<cstdio>
#include <iomanip>
#include<fstream> // du dung cho do ghi file
#define TRUE 1
#define FALSE 0 
using namespace std;


void KhoitaoDSDG(TREE &listDG)
{
	listDG = NULL;
}

void NhapDG (DocGia &dg)
{
	fflush(stdin);
	cout<<"Nhap ma the: ";
	cin>>dg.MATHE;
	fflush(stdin);
	cout<<"Nhap Ho: ";
	getline(cin,dg.Ho);
	cout<<"Nhap Ten: ";
	getline(cin,dg.Ten);
	fflush(stdin);
	cout<<"Nhap Phai: ";
	getline(cin,dg.Phai);
	cout<<"Nhap tran thai the: ";
	cin>>dg.TrangThaiThe;
	fflush(stdin);
}
int AddDSDG(TREE &k, DocGia x)
{
	if (k == NULL) {
		k= new NodeDG;
		k->data = x;
		k->pLeft = NULL;
		k->pRight = NULL;
	}
	else if (k->data.MATHE > x.MATHE)  AddDSDG(k->pLeft, x);
	else if (k->data.MATHE < x.MATHE)  AddDSDG(k->pRight, x);
	else if (k->data.MATHE == x.MATHE)
	{
		return 0;
	}
}

TREE TimDG(TREE p, int x)
{
	while (p != NULL)
	{
		if (x < p->data.MATHE)
			p = p->pLeft;
		else if (p->data.MATHE == x)
			return p;
		else
			p = p->pRight;
	}
	return 0;
}

int XoaKey(TREE &T, int x)     // xoa nut co key x
{
    if (T==NULL) return 0;
    else if (T->data.MATHE > x) return XoaKey(T->pLeft, x);
    else if (T->data.MATHE < x) return XoaKey(T->pRight, x);
    else 
    {
        NodeDG *P = T;
        if (T->pLeft == NULL) T = T->pRight;    // Node chi co cay con phai
        else if (T->pRight == NULL) T = T->pLeft;   // Node chi co cay con trai
        else // Node co ca 2 con
        {
            NodeDG *S = T, *Q = S->pLeft;
            // S la cha cua Q, Q la Node phai nhat cua cay con trai cua P
            while (Q->pRight != NULL)
            {
                S = Q;
                Q = Q->pRight;
            }
            P->data.MATHE = Q->data.MATHE;
            S->pRight = Q->pLeft;
            delete Q;
        }
    }
    return 1;
}

int SoluongDG(TREE l)
{
	int n = 0;
	const int STACKSIZE = 100;
	TREE Stack[STACKSIZE];
	int sp = -1;
	do
	{
		while (l != NULL)
		{
			Stack[++sp] = l;
			l = l->pLeft;
		}
		if (sp != -1)
		{
			l = Stack[sp--];
			n++;
			l = l->pRight;
		}
		else break;
	} while (1);
	return n;
}

void Duyet_LNR(TREE t, DocGia a[], int &sp)
{
	if (t == NULL)
	{
		cout<<"Khong duyet duoc cay";
		return;
	}else
	{
		Duyet_LNR(t->pLeft, a, sp);
		a[++sp] = t->data;
		Duyet_LNR(t->pRight, a, sp);
	}
}

void XuatMangDG(DocGia a[], int n)
{
	cout<<"\t\t\t\t\t======DANH SACH CAC DOC GIA======\n\n";
	cout<<setw(10)<<"Ma The"<<setw(40)<<"Ho"<<setw(15)<<"Ten"<<setw(25)<<"Gioi Tinh"<<setw(10)<<"Trang Thai The"<<endl;
		
	for(int i=0; i<n ; i++)
	{
		cout<<setw(10)<< a[i].MATHE<<setw(40)<<a[i].Ho<<setw(15)<<a[i].Ten<<setw(25)<<a[i].Phai<<setw(10)<<a[i].TrangThaiThe<<endl;
	}
}
void Ghi(TREE &t, ofstream &f)
{
	if(t != NULL)
		{
			f << t->data.MATHE << endl;
			f << t->data.Ho << endl;
			f << t->data.Ten << endl;
			f << t->data.Phai << endl;
			f << t->data.TrangThaiThe << endl;
//			if(t->data.sosachmuon > 0)
//			{
//				for(NodeMuonTra *p = t->MT.pHead; p!=NULL; p=p->pRight)
//				{
//					f << p->data.MASACH << endl;
//					f << p->data.trangthai << endl;
//					f << p->data.ngaymuon.ngay << endl;
//					f << p->data.ngaymuon.thang << endl;
//					f << p->data.ngaymuon.nam << endl;
//					f << p->data.ngaytra.ngay << endl;
//					f << p->data.ngaytra.thang << endl;
//					f << p->data.ngaytra.nam << endl;	
//				}
//			}
			Ghi(t->pLeft,f);
			Ghi(t->pRight,f);
		}
}

void GhiFileDG(TREE &l)
{
	ofstream f("DocGia.txt");
	int n;
	n = SoluongDG(l);
	f << n << endl;
	Ghi(l, f);
}

void LoadtuFile_DSDG(TREE &l)
{
	ifstream f("DocGia.txt");
	MuonTra t;
	DocGia s;
	int n = 0;
	f >> n;
	for (int j = 0; j < n; j++)
	{
			f >> s.MATHE;
			f >> s.Ho;
			f >> s.Ten;
			f >> s.Phai;
			f >> s.TrangThaiThe;
		//	f >> s.sosachmuon;
			AddDSDG(l, s);
//			Tree dg = timDG(l,s.MADG);
//			KhoiTaoMT(dg->MT);
//			for (int i = 0; i < s.sosachmuon; i++)
//			{
//				f >> t.MASACH; 
//				f >> t.trangthai;
//				f >> t.ngaymuon.ngay;
//				f >> t.ngaymuon.thang;
//				f >> t.ngaymuon.nam;
//				f >> t.ngaytra.ngay;
//				f >> t.ngaytra.thang;
//				f >> t.ngaytra.nam;
//				AddTailMT(dg->MT, CreateNodeMT(t));
//			}
	}
	f.close();
}

