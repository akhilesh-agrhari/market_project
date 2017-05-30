using namespace std;
void purchase(userinfo );
void user(string username, char password[])
{
	userinfo userinfo_obj;
	int i,flag=0;
	ifstream userinfofile;
	userinfofile.open("alluser.txt", ios::binary);
	i=0;
	while(userinfofile.peek()!=EOF)
	{
		
		userinfofile.read((char *)&userinfo_obj,sizeof(userinfo_obj));      //readfile.read((char *)&get,sizeof(get));
		if(userinfo_obj.username==username)
		{
			flag=1;
			break;
		}
		i++;
	}
	userinfofile.close();
	if(flag==1 && strcmp(password,userinfo_obj.password)==0)
	{
		purchase(userinfo_obj);
	}
	else
	{
		system("cls");
		system("color 47");
		gotoxy(30,7);
		cout<<"User or Password is incorrect";
		getch();
	}
	return;
}

void purchase(userinfo userin)
{
	int bill=0;
	char ch , delivery_date[9];
	order odr ;
	item allitems[25];
	ifstream fileitem;
	fileitem.open("item.txt",ios::binary | ios::in );
	int i=0;
	fileitem.seekg(ios::beg);
	ofstream orderin("order.txt", ios::trunc |ios::binary);
	orderin.close();
	while(fileitem.peek()!=EOF)
	{
		fileitem.read((char *)&allitems[i],sizeof(allitems[i])); //file.read((char *)&obj, sizeof(obj));
	i++;
	}
	int j=i;
/*myIn.peek() != EOF)
    {
        */

do{ system("cls");
	system("color fc");
	gotoxy(32,6);
	cout<<"Logged in "<<userin.username;
	
	gotoxy(32,8);
	cout<<"______________";
	gotoxy(32,8);
	cout<<"Purchase Order";
	

	gotoxy(22,11);
	cout<<"1 - View Items";
	gotoxy(22,12);
	cout<<"2 - Create New Order";
	gotoxy(22,13);
	cout<<"3 - Display Order details";
	gotoxy(22,14);
	cout<<"4 - Generate PO";
	gotoxy(22,15);
	cout<<"5 - Add item";
	gotoxy(22,16);
	cout<<"6 - Logout";
	gotoxy(22,19);
	cout<<"Select an option by typing the numeric code: ";
	ch=getch();
	if(ch=='1')
	{
		//displaying available items in the store
		system("cls");
		cout<<"ID\t\t"<<setw(10)<<"Name"<<"\t\t"<<"Price"<<endl;;
		for(i=0;i<j;i++)
		{
			cout<<allitems[i].productid<<"\t\t"<<setw(10)<<allitems[i].proname<<"\t\t"<<setw(4)<<allitems[i].price<<endl;
		}
		cout<<"Press any key to go back";
		getch();
	}
	else if(ch=='2')
	{
		//create new order .............
			orderno++;
			system("cls");
			ofstream orderin("order.txt", ios::trunc |ios::binary);
		int i;
		char choice;
		do
		{
			int flag,temp;
			flag = odr.createoreder(allitems,j);
			if(flag==1) {
			orderin.write((char *)&odr, sizeof(odr)); //f.write((char*)&arts[i],sizeof(arts[i])); 
			temp=calbill(odr);
			bill=bill+ temp;
			cout<<endl<<"bill so far : "<<bill;
			}	
			cout<<endl<<endl<<"Purchase one more item ? y/n : ";
			choice=getch();
		}while(choice=='y');
		cout<<endl<<endl;
		cout<<"Delivery date : ";
		cin>>delivery_date;
		orderin.close();
	}
	else if(ch=='3')
	{
		//display order detail ................
		system("cls");
		ifstream orderout("order.txt");
		cout<<"ID\t"<<"Name\t"<<"Price\t"<<"Quantity\t"<<"Cost"<<endl;
		while(orderout.peek()!=EOF)
		{
			orderout.read((char *)&odr, sizeof(odr));
			odr.showdata();
		}
		orderout.close();
		cout<<"----------------------------------------------"<<endl;
		cout<<"Total\t\t\t\t\t"<<bill<<endl<<endl;
		cout<<"Press any key to go back ";
		getch();
	}
	else if(ch=='4')
	{
		//Generate PO ..........................
		generatePO(odr,delivery_date,bill);
	}
	else if(ch=='5')
	{
		//add items to the cart.................
		system("cls");
		ofstream orderin("order.txt",ios::binary |ios::app);
		int i;
		char choice;
		do
		{
			int flag,temp;
			flag = odr.createoreder(allitems,j);
			if(flag==1) {
			orderin.write((char *)&odr, sizeof(odr)); //f.write((char*)&arts[i],sizeof(arts[i])); 
			temp=calbill(odr);
			bill=bill+ temp;
			cout<<endl<<"bill so far : "<<bill;
			}	
			cout<<endl<<endl<<"Purchase one more item ? y/n : ";
			choice=getch();
		}while(choice=='y');
		cout<<endl<<endl;
		cout<<"Delivery date : ";
		cin>>delivery_date;
		orderin.close();

		
	}
	else if(ch=='6')
	{
		//logout
		return;
	}
	else
	{
		return;
	}
}while(1);

}
