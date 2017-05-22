using namespace std;
class users;
void admin();
void users(string , char []);
char login()
{
	char loginas;
	system("cls");
	system("color fc");
	gotoxy(32,8);
	printf("WELCOME");
	gotoxy(30,9);
	printf("___________");
	gotoxy(30,11);
	printf("1-Login as USER");               //1-login as user
	gotoxy(30,12);
	printf("2-Login as ADMINISTRATOR");     //2-login as admin
	gotoxy(30,13);
	printf("3-Sign up");
	gotoxy(30,14);
	printf("4-Exit");                      //3-exit from the program
	                        				 //4- login page again
	gotoxy(30,16);
	printf("Enter numeric value : ");
	gotoxy(52,16);
	loginas=getch();
	if(loginas=='4')
	{
		return '5';                //shutdown the program
	}
	else if(loginas=='2')      //login as admin
	{
		system("color E1");
		char pass[5],matc[5]="1234";
		matc[4]='\0';
		gotoxy(30,17);
		printf("Password : ");
		gets(pass);             //Entering password
		gotoxy(30,17);
		int i;
		for(i=0;i<4;i++)     //matching
		{
			if(pass[i]!=matc[i])
			break;
		}
		if(i==4)         
		{
			admin();           //password matched and going to admin page
			return '4';
		}
		else{                     //password not match ...dang error message
			system("color 47");
			gotoxy(30,16);
			printf("Wrong password !");       
			gotoxy(30,17);
			printf("Please try again");
			getch();
			return '4';
		}
		
	}
	else if(loginas=='1') 
	{
		string username;
		char password[8];
		system("cls");
		gotoxy(30,7);
		cout<<"~~User login~~";
		gotoxy(28,9);
		cout<<"Enter username : ";
		cin>>username;
		gotoxy(28,10);
		cout<<"Password : ";
		cin>>password;
		user(username,password);
		return '4';               //login as user going to main function.
	}
	
	else if(loginas=='3')
	{
		signup();
		return '4';
		
	}
	else
	{
		gotoxy(30,16);
		printf("Invalid option ! Please try again");
		return '4';
		
	}
	return loginas;
}

void signup()
{
	userinfo inuser;
	string username;
	char password[8];
	system("cls");
	system("color 90");
	gotoxy(30,7);
	cout<<"Signup";
	gotoxy(28,8);
	cout<<"YOUR NAME : ";
	cin>>inuser.username;
	gotoxy(28,9);
	cout<<"Set a password : ";
	cin>>inuser.password;
	ofstream reg_user;
	reg_user.open("alluser.txt",ios::binary | ios::app);
		reg_user.write((char *)&inuser, sizeof(inuser));       //file.write((char *)&obj, sizeof(obj));
	reg_user.close();
	return;	
}
