using namespace std;
void view();
int access();
void signup();
void user(string , char []);
class users;
class item
{
	public:
	int productid;
	char proname[10];
	int stock;
	int price;
		void getdata();
		void showdata();
		int access(int); 
};
void item::getdata()
{
	gotoxy(30,9);
	cout<<"Product ID : ";
	cin>>productid;
	gotoxy(30,10);
	cout<<"Product Name : ";
	cin>>proname;
	gotoxy(30,11);
	cout<<"Stock : ";
	cin>>stock;
	gotoxy(30,12);
	cout<<"Rate : ";
	cin>>price;
}
void item::showdata()
{
	cout<<productid<<"\t\t\t"<<proname<<"\t\t"<<stock<<"\t\t\t"<<price;
}

class userinfo
{
	public:
		char username[10];
		char password[8];
//	void setuser();
};
/*void users::setuser()
{
	username[]="hello";
	username[5]='\0';
	password[]="null"
	password[4]='\0';
}*/



