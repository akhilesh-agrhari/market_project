using namespace std;
class order;
int calbill(order);
void generatePO(order,char [],int);          //to generate PO
void view();
int access();
void signup();
void user(string , char []);
class users;
static int orderno=0;
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
	cout<<productid<<"\t"<<setw(10)<<proname<<"\t"<<setw(9)<<stock<<"\t"<<setw(4)<<price;
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
		friend void generatePO(order,char[], int);
	public:
		int createoreder(item [],int);
		void showdata();
		friend int calbill(order);
		
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
	//cout<<"ID"<<"\t"<<"Name      "<<"\t\t"<<"Available"<<"\t\t"<<"Rate"<<endl;
	cout<<id<<"\t"<<name<<"\t"<<price<<"\t"<<quantity<<"\t\t"<< price*quantity<<endl;
}

int calbill(order odr)
{
	return (odr.quantity)*(odr.price);
}

void generatePO(order odr,char delivery_date[],int totalbill)
{
	system("cls");
	time_t now = time(0);
	char* dt=ctime(&now);
	ofstream POfile;
	ifstream odrout;
	odrout.open("order.txt");
	POfile.open("PO.txt");
	//..........................INCOMPLETE
		cout<<"\t\t\t  Purchase Order#: " <<orderno<<"\n";
		cout<<"\t\t\t  ________________\n\n";
		cout<<"Order#:  "<<orderno<<"\t\t\t\t Issue Date:"<<dt<<"\n\n";
		cout<<"Delivery Date:  "<<delivery_date<<"\n";
		cout<<"--------------------------------------------------------------------------------\n";
		cout<<"\t\t\t\t**Line Items**\t\t\t\t\t\n";
		cout<<"--------------------------------------------------------------------------------\n";
		cout<<"Item Code\t\tQuantity\t\tPrice\t\t\tTotal\n";
		cout<<"_________\t\t________\t\t_____\t\t\t_____\n";
//myIn.peek() != EOF)		
		while(odrout.peek() !=EOF)
		{
			odrout.read((char *)&odr,sizeof(odr));
			cout<<setw(9)<<odr.id<<"\t\t"<<setw(8)<<odr.quantity<<"\t\t"<<setw(5)<<odr.price<<"\t\t\t"<<setw(5)<<(odr.price)*(odr.quantity)<<endl;
		}
		odrout.close();
		ifstream fin;
		char line[80];
		//Opening the terms.txt file from where standard terms and conditions are copied into the PO
		fin.open("terms.txt");
		while(fin)
		{
			fin.getline(line,80);
			cout<<line<<"\n";
		}
		fin.close();
		cout<<"\n\nAuthorized Signatory:\t\t\t\t\t  Total: "<<totalbill;
		POfile.close();
		getch();
		return;
}

