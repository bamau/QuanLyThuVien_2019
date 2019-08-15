#include<iostream>
#include "config.h"
#include "DauSach.h"
#include "DocGia.h"
#include <windows.h>

using namespace std;
int main() {
	
	resizeConsole(1300, 700);
	
	char key;
	int choice;
	do
	{
		choice=MenuDong(thucdon);
		switch(choice)
		{
			case 1://quan ly danh sach the doc gia
				{
					Normal();
					system("cls");
					TREE listDG;
					KhoitaoDSDG(listDG);
				//	LoadtuFile_DSDG(listDG);
					int choice1;
					char key1;
					do
					{
						choice1=MenuDong(thucdon1);
						switch(choice1)
						{
							case 1:
								{
									Normal();
									system("cls");
									int n;
									DocGia dg;
									fflush(stdin);
									cout<<"Nhap so the muon them: ";
									cin>>n;
									for(int i=0; i<n; i++)
									{
										cout<<"Nhap doc gia thu: "<<i+1<<": \n";
										NhapDG(dg);
										AddDSDG(listDG,dg);
									}
									//GhiFileDG(listDG);
									cout<<"Da them "<<n<<" doc gia!"<<endl;
									break;
								}
							case 2:
								{
									Normal();
									system("cls");
									fflush(stdin);
									cout<<"Nhap vao ten doc gia can sua: ";				
									
									break;
								}
							case 3:
								{
									Normal();
									system("cls");
									
									fflush(stdin);
									cout<<"Nhap vao ten doc gia can xoa: ";
									
									break;
								}
							case 4:
								{
									Normal();
									system("cls");
									int n = SoluongDG(listDG);
									cout<<n<<endl;
									DocGia a[n];
									Duyet_LNR(listDG,a,n);
									XuatMangDG(a,n);
									break;
								}
							case 5:
								{
									Normal();
									break;
								}
							case 6:
								{
									Normal();
									system("cls");
									cout<<"Ban muon thoat?. Nhan 'ENTER' de xac nhan hoac 'BACK' de quay lai: ";
									key1=getch();
									if(key1==ENTER)
									{
										system("cls");
										cout<<"\n\t\t\t\tCam on ban!. Hen gap lai!\n";
										return 0;
									}
									break;
								}
						}
						if(choice1==1 || choice1 == 2 || choice1 == 3 || choice1 == 4)
							system("pause");
						else if(choice1==5)
								break;	
					}while(choice1!=5);
					break;
				}
			case 2:
				{
					Normal();
					system("cls");
					list listDS;
					KhoitaoDS(listDS);
					LoadFileDS(listDS);	
					int choice5;
					char key5;
					do
					{
						choice5=MenuDong(thucdon2);
						switch(choice5)
						{
							case 1:
								{
									Normal();
									system("cls");
									DauSach ds;
									fflush(stdin);
									int m;							
									cout<<"Muon them bao nhieu dau sach: ";
									cin>>m;
									for(int i =0 ; i<m; i++)
									{
										cout<<"Nhap dau sach thu "<<i+1<<" :"<<endl;
										NhapDauSach(ds);
										ThemDS(listDS,ds);
										//InsertDS(listDS, i, ds);
									}
									
									cout<<"Ban da them "<<m<<" dau sach!"<<endl;
									system("cls");
									GhiFileDS(listDS);
									break;
								}
							case 2:
								{
									Normal();
									system("cls");
									fflush(stdin);
									
									XuatListDS(listDS);
								//	cout<<"Nhap the loai muon in: ";
									
								//	system("cls");
								
									
						
									break;
								}
							case 3:
								{
									Normal();
									system("cls");
									fflush(stdin);
									string tensach;					
									cout<<"Nhap ten sach muon tim: ";
									getline(cin,tensach);
									int flag=TimKiemTenSach(listDS,tensach);
									if(flag==-1){
										cout<<"Khong tim thay";
									}else cout<<"Tim thay";
								
									break;
								}				
							case 4:
								{
									Normal();
									break;
								}
							case 5:
								{
									Normal();
									system("cls");
									cout<<"Ban muon thoat?. Nhan 'ENTER' de xac nhan hoac 'BACK' de quay lai: ";
									key5=getch();
									if(key5==ENTER)
									{
										system("cls");
										cout<<"\n\t\t\t\tCam on ban!. Hen gap lai!\n";
										return 0;
									}
									break;
								}
						}
						if(choice5==1 || choice5 == 2 || choice5 == 3 || choice5 == 4)
							system("pause");
						else if(choice5==5)
								break;		
					}while(choice5!=5);
				
					break;	
				}
			case 3:
				{
					Normal();
					system("cls");
					int choice6;
					char key6;
					
					break;
				}
			case 4:
				{
					Normal();
					system("cls");
					
					int choice7;
					char key7;
					break;
				}
			case 5:
			{
				Normal();
				system("cls");
				
				int choice8;
				char key8;
				break;
			}
			case 6:
			{
				Normal();
				system("cls");
				
				int choice9;
				char key9;
				break;
			}
			case 7:
			{
				Normal();
				system("cls");
				
				int choice10;
				char key10;
				break;
			}
			case 8:
				{
					Normal();
					system("cls");
					int check;
					cout<<"Ban muon thoat?. Nhan 'ENTER' de xac nhan hoac 'BACK' de quay lai: ";
					key=getch();
					if(key==ENTER)
					{
						system("cls");
						cout<<"\n\t\t\t\tCam on ban!. Hen gap lai!\n";
						return 0;
					}
					break;
				}
		}
	}while(choice==8||choice!=1||choice!=2||choice!=3||choice!=4||choice!=5||choice!=6||choice!=7);
	return 0;
}

