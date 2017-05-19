using namespace std;
void purchase(userinfo );
void user(string username, char password[])
{
	userinfo userinfo_obj;
	int i,flag=0;
	ifstream userinfofile;
	userinfofile.open("alluser.txt", ios::binary);
	for(i=0;!userinfofile.eof();i++)
	{
		userinfofile.read((char *)&userinfo_obj,sizeof(userinfo_obj));      //readfile.read((char *)&get,sizeof(get));
		if(userinfo_obj.username==username)
		{
			system("cls");
			cout<<"username found";
			getch();
			flag=1;
			break;
		}
	}
	userinfofile.close();
	if(flag==1 && strcmp(password,userinfo_obj.password)==0)
	{
		system("cls");
		cout<<"password matched";
		getch();
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
	char ch;
	item allitems[100];
	ifstream fileitem;
	fileitem.open("item.txt");
	int i;
	for(i=0;!fileitem.eof();i++);
	{
		fileitem.read((char *)&allitems[i],sizeof(allitems[i])); //file.read((char *)&obj, sizeof(obj));
	}
	
	system("cls");
		system("color fc");
		gotoxy(32,6);
		cout<<"Purchase Order";
		gotoxy(32,8);
		cout<<"______________";
		gotoxy(32,8);
		cout<<"Logged in "<<userin.username;
		
	
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
		while(1){
		switch(ch)
		{
			case('1'):
				{
					//view();     //view the items
					break;
				}
			case('2'):
				{
					//r.get_data();          //create order
					//flag='t';
					break;
				}
			case('3'):                  //display order
				{
				/*	if(flag=='f')
					{
						gotoxy(22,20);
						cout<<"Order details not yet entered!";
						gotoxy(22,21);
						cout<<"Press any key to continue..";	
						getch();
					}
					else
					r.display();*/
					break;
				}
			case('4'):                //generate PO	
				{/*	if(flag=='f')
					{
						gotoxy(22,20);
						cout<<"Order details not yet entered!";
						gotoxy(22,21);
						cout<<"Press any key to continue..";	
					}
					else
					{
						po p;
						generate(r,p);
						system("cls");
						generate2(r,p);
					}
					getch();*/
					break;
				}
				
			case('5'):
				{
				//	add_items();
					break;
				}
			case('6'):
				{
					return;
				}
			default:
				{
					gotoxy(22,8);
					system("cls");
					cout<<"Invalid Choice! YOU are logged out";
					getch();
					return;
				}
			}
		}
	
}
