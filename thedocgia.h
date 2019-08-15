#pragma once
#include <iostream>
#include <math.h>
#include <time.h>
#include <string.h>
#include "date.h"

using namespace std;

enum Phai
{
	nam,
	nu,
}
struct TheDocGia		//quy dinh thuoc tinh cua 1 TheDocGia
{
	int MATHE;
	string Ho;
	string Ten;
	Phai phai;
	int TrangThaiThe;
	listMT listmt;		//List MuonTra
}

struct node		//mot node trong 1 cay
{
	TheDocGia ThongTin;
	struct node *pleft;
	struct node *pright;
}
typedef struct node NODEPTR;
typedef NODEPTR* TREE;


