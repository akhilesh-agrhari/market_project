using namespace std;
void add(ofstream & );

class item;
void remove(int ,fstream & );
void admin()
{
	char task;
	admin:system("cls");
	gotoxy(30,6);
	printf("ADMINISTRATOR");
	gotoxy(28,7);
	printf("_________________");
	gotoxy(30,9);
	printf("1-Add item");
	gotoxy(30,10);
	printf("2-View items");
	gotoxy(30,11);
	printf("3-Remove items");
	gotoxy(30,12);
	printf("4-logout");
	gotoxy(30,13);
	printf("Enter numeric value : ");
	gotoxy(52,13);
	task=getch();
	if(task=='4')
	{
		//logout
		return;
	}
	else if(task=='3')
	{
		//remove item from the item file
		int i;
		char choice;
		fstream delcon;
		delcon.open("item.txt");
		do{
		system("cls");
		gotoxy(30,6);
		cout<<"~~REMOVE~~";
		gotoxy(28,7);
		cout<<"Enter product id which you wants to delete : ";
		cin>>i;
		remove(i,delcon);
		gotoxy(28,9);
		cout<<"Remove one more item y/n : ";
		choice=getch();
		}while(choice=='y');
	}
	else if(task=='2')
	{
		//view items of the item file
		char choice;
		view();
		getch();
		goto admin;
	}
	else if(task=='1')
	{
		//add item to the item file
		char choice;
		ofstream outfile;
		outfile.open("item.txt",ios::app | ios::out | ios::binary);
		do
		{
			system("cls");
			gotoxy(28,7);
			cout<<"~~Add new product into the data base~~";
			gotoxy(30,8);
			add(outfile);
			gotoxy(30,13);
			cout<<"Add more items in the shop y/n :";
			choice=getch();
		}while(choice=='y');
		outfile.close();
	}
	else
	{
		//wronge choice, jada syanpanti nai, hehehe
		system("color 47");
		system("cls");
		gotoxy(30,12);
		printf("Invalid choice, You are logged out");
		getch();
		return;
	}
}
void add(ofstream &outfile)
{
	item get;           //object of item file
	get.getdata();     //inputing data
	outfile.write((char *)&get,sizeof(get)); //f.write((char*)&arts[i],sizeof(arts[i])); writing data into the file
}

void view()
{
	item get;
	system("cls");
	cout<<"Product ID"<<"\t\t"<<"Name"<<"\t\t"<<"Available"<<"\t\t"<<"Rate"<<endl;
	ifstream readfile;
	readfile.open("item.txt",ios::binary | ios::in);
	while(readfile)
	{
		
		readfile.read((char *)&get,sizeof(get));    //file.read((char *)&obj, sizeof(obj));
		get.showdata();
		cout<<endl;
	}
	readfile.close();
	return;
}
void remove(int i, fstream &delcon)
{
	item get;
	while(!delcon.eof())
	{
		delcon.read((char *)&get,sizeof(get));    //file.read((char *)&obj, sizeof(obj));
		if(get.productid==i)
		{
			                                   //incomplete
		}
	}
	
}
