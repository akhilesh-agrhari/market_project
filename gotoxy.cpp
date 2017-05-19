/*Function defination for setting cursor position in the console window*/
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X= x;
	coord.Y= y;
	SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE), coord);
}

