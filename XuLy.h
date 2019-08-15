#pragma once
#include <time.h>
#include <math.h>
#include <iostream>

#define nn_file "ngaunhien.txt"
using namespace std;

#define MAXLIST 10000

struct MaSachTuDong
{
	int n;
	int info_MaSach;
};

//ham hoán doi?
void Swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}

void Tao1SoNN(MaSachTuDong &masachtudong[],int N)
{
	//voi N la tong so phan tu co trong dsach do
	//MAX la so luong phan tu toi da
	
	masachtudong.n=0;
	int sonn;
	int dem=0;
	srand(time(NULL));
	for(int i= 1; i<=MAXLIST ; i++)
	{
		masachtudong.info_MaSach[i]=i;
	}
	
	while(dem<=N)
	{
		sonn=dem++;
		rand()%(MAXLIST-dem+1);
		Swap(masachtudong.info_MaSach[dem],masachtudong[sonn]);
		masachtudong.n++;
		//break;
	}
}

void WriteFile(MaSachTuDong masachtudong[],int N)
{
	fstream f;
	f.open(nn_file,ios::out);
	f<<msachtudong.n<<endl;
	for(int i=0;i<N;i++)
	{
		f<<masachtudong[i].info_MaSach<<endl;
	}
	f.close();
	cout<<"Ghi file thanh cong!"<<endl;
}


void ReadFile(MaSachTuDong masachtudong[],int N)
{
	fstream f;
	f.open(nn_file, ios::in);
	int i=0;
	f>>i;
	//while(f.eof()==false)
	for(int j=0;j<i;j++)
	{
		f>>masachtudong[j].info_MaSach;
		masachtudong.n++;
	}
}
