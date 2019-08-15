#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include "date.h"
#include <mylib.h>
//#include "danhmucsach.h"
//#include "muontra.h"
#define MAXLIST 1000
const int ENTER =13;
const int SPACE=32;
const int ESC=27;
const int BACK=8;
const int dong =10;
const int cot = 40 ;
const int Up = 72;
const int Down = 80;

using namespace std;

enum TrangThai
{
	ChoMuonDuoc,
	DaDuocMuon,
	DaThanhLy,
};
//dsach lien ket don
struct DanhMucSach
{
	string MASACH;
	TrangThai trangthai;
	string ViTri;
};


struct node_danhmucsach	//1 phan tu trong dsach
{
	DanhMucSach dms;
	struct node_danhmucsach *next;
};
typedef node_danhmucsach* NODEPTR;		//dinh nghia node* thanh NODEPTR - doi ten

//Khai bao danh sach tuyen tinh mang con tro dau sach
struct DauSach
{
	char ISBN[6];
	string tenSach;
	string soTrang;
	string tacGia;
	string namXuatBan;
	string theLoai;
	NODEPTR ptr_dms;
};

struct list
{
	int n;
	DauSach *nodes[MAXLIST];
};

//dsach lien ket kep cua MuonTra
enum TrangThai_MuonTra
{
	ChuaTra,
	DaTra,
	MatSach,
};
struct MuonTra
{
	string MASACH;
	date NgayMuon;
	date NgayTra;
	TrangThai_MuonTra trangthaimuontra;

};
struct node_muontra		//dinh nghia mot nut
{
	MuonTra ChiTietMuonTra;		//chi tiet muon tra co kieu du lieu MuonTra da duoc dinh nghia
	node_muontra *left,*right;		//2 con tro trai phai
};
typedef struct node_muontra* DanhSachMuonTra;

//Khai bao cay nhi phan tim kiem the doc gia
struct DocGia
{
	int MATHE;
	string Ho;
	string Ten;
	string Phai;
	int TrangThaiThe;
	
	DanhSachMuonTra dsmuontra_first;
};
struct NodeDG
{
	DocGia data;
	struct NodeDG *pLeft;
	struct NodeDG *pRight;
};
typedef struct NodeDG NODE;
typedef NODE* TREE;




//MENU
int count_item(char td [][50])
{
	int i;
	for(i = 0; td[i][0] != NULL; ++i);
	return i;
}
//menu dong
void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(1);
}
int MenuDong(char td [][50])
{
    Normal();
    system("cls");  
    cout<<"----------------------------------------------------QUAN  LY THU VIEN-------------------------------------------------\n";
    int chon =0;
    int i; 
    int so_item=count_item(td);
    gotoxy(cot,dong-1);
    cout<<"=====================================\n";
    for ( i=0; i< so_item ; i++)
    { 
  		gotoxy(cot, dong +i);
   		cout << td[i];
    }
    gotoxy(cot,dong+so_item);
	cout<<"=====================================\n";
    HighLight();
    gotoxy(cot,dong+chon);
    cout << td[chon];
    char kytu;
	do 
	{
	   kytu = getch();
	   if (kytu==0) kytu = getch();
	   switch (kytu)
	   {
	  		case Down :if (chon+1 <=so_item)
		  			   {
		  		        	Normal();
			              	gotoxy(cot,dong+chon);
			              	cout << td[chon];
			              	chon ++;
			              	HighLight();
			              	gotoxy(cot,dong+chon);
			              	cout << td[chon];
		  			   }
		  			   if (chon+1 > so_item)
		  			   {
			  		        Normal();
			              	gotoxy(cot,dong+chon);
			              	cout << td[chon];
			              	chon=0;
			              	HighLight();
			              	gotoxy(cot,dong+chon);
			              	chon ++;
			              	cout << td[chon-1];	
			              	chon=0;
		  			   }
		  			   break;
		  	case Up :if (chon-1 >=0)
		  			   {
		  		        	Normal();
			              	gotoxy(cot,dong+chon);
			              	cout << td[chon];
			              	chon --;
			              	HighLight();
			              	gotoxy(cot,dong+chon);
			              	cout << td[chon];
		  			   }
		  			   break;
			case 13 : return chon+1;
		} 
	} while (1);
}

char thucdon [8][50] = {	  "|1. Quan ly the doc gia             |",
			                  "|2. Quan ly cac dau sach            |",
			                  "|3. Muon sach                       |",
			                  "|4. Tra sach                        |",
			                  "|5. Liet ke sach cua doc gia muon   |",
			                  "|6. Doc gia muon sach qua han       |",
			                  "|7. 10 dau sach so luong muon nhieu |",
			                  "|8. Thoat chuong trinh              |",
							 };
			                   
char thucdon1 [6][50] = {	  "|1. Them the doc gia                |",
 							  "|2. Sua the doc gia                 |",
			                  "|3. Xoa the doc gia                 |",
			                  "|4. In danh sach the doc gia        |",
			                  "|5. Quay lai                        |",
			                  "|6. Thoat                           |",
			                  };

char thucdon2 [5][50] = {     "|1. Them thong tin dau sach         |",
			                  "|2. In danh sach dau sach           |",
			                  "|3. Tim sach                        |",
			                  "|4. Quay lai                        |",
			                  "|5. Thoat                           |",
								};

