#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

string Upper(string str)		//ham in hoa cac chu
{
	for(int i=0 ; i<str.length() ; i++)
	{
		str[i]=toupper(str[i]);
	}
	return str;
}


