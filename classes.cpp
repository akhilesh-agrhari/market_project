using namespace std;
class order;
int calbill(order);
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
};
class order
{
	private:
		int id;
		char name[10];
		int price;
		int quantity;
	public:
		int createoreder(item [],int);
		void showdata();
		friend calbill(order);
		
};

int order::createoreder(item allitems[], int j)
{	int i,found=0;
	cout<<endl<<"Product id : ";
	cin>>id;    //id intialized
	for(i=0;i<j;i++)
	{
		if(allitems[i].productid==id)
		{
		found=1;
		break;
		}
	}
	if(found==1)
	{
		cout<<"Product name : "<<allitems[i].proname<<endl;
		cout<<"price :"<<allitems[i].price<<endl;
		strcpy(name,allitems[i].proname);   //proname intialized
		price=allitems[i].price;        //price intialized
	}
	else{
	
	cout<<"Wrong product id"<<endl;
	return 0;
	}
	cout<<"Quantity : ";
	cin>>quantity;                 //quantity intialized
	if(quantity>allitems[i].stock)
	{
		cout<<"Only "<<allitems[i].stock<<" items are left in the stock"<<endl;
		return 0;
	}
	else{
		int confirm;
		cout<<"confirm add item to the cart ? y/n : ";
		confirm=getch();
		if(confirm=='y')
		return 1;
		else
		return 0;
	}
}

void order::showdata()
{
	cout<<id<<"\t"<<name<<"\t"<<price<<"\t"<<quantity<<"\t\t"<< price*quantity<<endl;
}

int calbill(order odr){
	return ((odr.quantity)*(odr.price));
}
