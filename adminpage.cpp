using namespace std;
void add();

class item;
int remove(item [],int [],int ,int);
void admin()
{
	char task;
	do{
	system("cls");
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
		int i=0,j,del[10],countdel=0;
		char choice;
		item *allitems = new item[100];
		ifstream itemin("item.txt");
		while(itemin.peek()!=EOF)
		{
			itemin.read((char *)&allitems[i],sizeof(allitems[i]));
			i++;
		}
		itemin.close();
		j=i;
		fstream delcon;
		delcon.open("item.txt");
		do{
		system("cls");
		gotoxy(30,6);
		cout<<"~~REMOVE~~";
		gotoxy(22,7);
		cout<<"Enter product id which you wants to delete : ";
		cin>>i;
		int find,flag=0;
		for(find=0;find<j;find++)
		{
			if(i==allitems[find].productid)
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			del[countdel]=i;
			countdel++;
		gotoxy(28,9);
		cout<<"Remove one more item y/n : ";
		choice=getch();
		}
		else
		{
			gotoxy(28,9);
			cout<<"INVALID Product ID ";
			gotoxy(28,10);
			cout<<"Remove another ? y/n :  ";
			choice=getch();
		}
		}while(choice=='y');
		remove(allitems,del,countdel,j);
	}
	else if(task=='2')
	{
		//view items of the item file
		char choice;
		view();
		getch();
	}
	else if(task=='1')
	{
		//add item to the item file
		char choice;
		/*ofstream outfile;
		outfile.open("item.txt",ios::app | ios::out | ios::binary);*/
		do
		{
			system("cls");
			gotoxy(28,7);
			cout<<"~~Add new product into the data base~~";
			gotoxy(30,8);
			add();
			gotoxy(30,13);
			cout<<"Add more items in the shop y/n :";
			choice=getch();
		}while(choice=='y');
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
}while(1);
}
void add()
{
	item get;           //object of item file
	get.getdata();     //inputing data
	ofstream outfile;
	outfile.open("item.txt",ios::app | ios::out | ios::binary);
	outfile.write((char *)&get,sizeof(get)); //f.write((char*)&arts[i],sizeof(arts[i])); writing data into the file
	outfile.close();
}

void view()
{
	item get;
	system("cls");
	cout<<"ID"<<"\t"<<setw(10)<<"Name"<<"\t"<<setw(9)<<"Available"<<"\t"<<"Rate"<<endl;
	ifstream readfile;
	readfile.open("item.txt",ios::binary | ios::in);
	while(readfile.peek()!=EOF)
	{
		
		readfile.read((char *)&get,sizeof(get));    //file.read((char *)&obj, sizeof(obj));
		get.showdata();
		cout<<endl;
	}
	readfile.close();
	return;
}
int remove(item allitems[],int del[],int countdel, int lenallitems)
{
	int i=0,j;
	int flag=1;
	sort(del,del + countdel);
	ofstream itemout("item.txt", ios::trunc);
	while(i<lenallitems)
	{
		for(j=0;(j<countdel) && (flag==1) ;j++)     //to check whethere the product code is in del[] or not
		{
		
			if(allitems[i].productid==del[j])     // yes.... it means item should not written in the file
			{
			flag=0;
			}
		}
		if(flag==1)                      // yes ..... it means item is not in del[]....and data should be written into the file
		{
			itemout.write((char *)&allitems[i], sizeof(allitems[i]));
		}
		i++;
		flag=1;
	}
	itemout.close();
}
