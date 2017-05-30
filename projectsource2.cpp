#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<ctime>
#include<windows.h>
#include<algorithm>
#include"gotoxy.cpp"
#include"classes.cpp"
#include"loginpage.cpp"
#include"adminpage.cpp"
#include"userpage.cpp"

using namespace std;

//Main Function
int main()
{   //font size and style increase
	CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 0;                   // Width of each character in the font
cfi.dwFontSize.Y = 24;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	char flag='f',log;
	restart: log=login();         //login page
	while(log=='4')
	{
		log=login();
	}
	system("cls");
	gotoxy(30,9);
	cout<<" THANK YOU ! "<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	return 0;
}
