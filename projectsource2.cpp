#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
//#include<string.h>
#include<fstream>
#include<ctime>
#include<windows.h>
#include"gotoxy.cpp"
#include"classes.cpp"
#include"loginpage.cpp"
#include"adminpage.cpp"
#include"userpage.cpp"


#define MAX 100

using namespace std;
void view();
//Price list of Items
//Each array index value is used as an identifier for item codes 
int size=25;
float price_list[MAX]={865, 2.25, 44, 10, 20, 7710, 33.33, 48.97, 8, 0.5, 0.01, 88, 999, 25000, 87, 4, 22, 200, 20, 150, 5.8, 11, 92, 34, 9};
string item_name[MAX]={"Honey", "Wheat", "Sugar", "Pen", "Notebook", "AC", "Rice", "Milk", "Pencil", "Eraser", "Sticker", "Sketch", "Book", "Cupboard", "Cell", "Biscuit", "Phone", "Sim", "Tea", "Chocolate", "Coffee", "Candy", "Sweets", "Flash", "Eggs"};

class po; //Forward Declaration of po class(needed while using friend function)


/*Class Definations*/
class order
{
	/*Defining data members for storing order details*/
	static int req_no;
	int item_code[MAX];
	int qty[MAX];
	int num;
	string delivery_date;
	
	public:
		/*Class function declarations*/
		void get_data();
		void display();
		void showitem();
		friend void generate(order, po);
			friend void generate2(order, po); //friend function declaration
	};
	
	/*Function for adding items*/
	void add_items()
	{
		system("cls");
		system("color fc");
		string name;
		float price;
		char choice;
		do
		{
		cout<<"\n\n\tItem name: ";
		cin>>name;
		item_name[size]=name;
		cout<<"\tItem price: ";
		cin>>price;
		price_list[size]=price;
		size++;
		cout<<"\n\tAdd another item? y/n: ";
		cin>>choice;
	    }
	    while(choice=='y');
		
	}
	
	/*Function for receiving order details*/
	void order:: get_data()
	{   
		char choice;
		system("cls");
		system("color fc");
		req_no++;
		num=0;
		do
		{
		cout<<"\n\tProduct Item code: ";
		cin>>item_code[num];
		if(item_code[num]>size||item_code[num]<1)
		{
			cout<<"\tItem not in stock.\n"<<endl;
		}
		else
		{
		cout<<"\tQuantity: ";
		cin>>qty[num];
		if(qty[num]==0)
		{	
		cout<<"\tAdd item? y/n ";
		cin>>choice;
		continue;
	    }
		num++;
		}
		cout<<"\tAdd item? y/n ";
		cin>>choice;
		}
		while(choice=='y');
		cout<<endl<<"\tDelivery Date: ";
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, delivery_date);
	}
	
	//Defining static data member
	int order:: req_no;
	
	//Function for displaying order details
	void order::display()
	{
		system("cls");
		int i=0;
		cout<<"\n\tOrder Number: "<<req_no<<"\n"<<endl;
		cout<<"\t"<<setw(10)<<"Item Code"<<"\t\t"<<setw(10)<<"Item Name"<<"\t\t"<<setw(7)<<"Price"<<endl;
		cout<<"\t"<<setw(10)<<"_________"<<"\t\t"<<setw(10)<<"_________"<<"\t\t"<<setw(7)<<"_____"<<endl;
		cout<<endl;
		while(i<num)
		{
		cout<<"\t"<<setw(10)<<item_code[i]<<"\t\t"<<setw(10)<<item_name[item_code[i]-1]<<"\t\t"<<setw(7)<<price_list[item_code[i]-1]<<endl;
		i++;
		}
		cout<<"\n\tDelivery Date: "<<delivery_date<<endl;
		cout<<"\n\n\n\tPress enter to go to main menu. ";
		getch();
	}
	
		//Function for displaying item details
	void order::showitem()
	{
		system("cls");
		int i=0;
	    cout<<"\n\n\tThe availaible items are:"<<endl;
	    cout<<endl;
	    cout<<"\t"<<setw(7)<<"Item no"<<"\t\t"<<setw(9)<<"Item Name"<<"\t\t"<<setw(7)<<"Price"<<endl;
	    cout<<"\t"<<setw(7)<<"_______"<<"\t\t"<<setw(9)<<"_________"<<"\t\t"<<setw(7)<<"_____"<<endl;
	    cout<<endl;
	    for(i=0;i<size;i++)
	    {
	    	cout<<"\t"<<setw(7)<<(i+1)<<"\t\t"<<setw(9)<<item_name[i]<<"\t\t"<<setw(7)<<price_list[i]<<endl;
		}
		cout<<"\n\n\n\tPress enter to go to main menu. ";
		getch();
	}
	
	class po
	{
		static int po_no;
		public:
			//Constructor is used for incrementing the static variable po_no
			po()
			{
				po_no++;
			}
			
			friend void generate(order, po);
				friend void generate2(order, po); //friend function declaration
	};
	
	//Defining static data member
	int po::po_no;
	
	//Defining friend function generate()
	void generate(order r, po p)
	{
		float total=0;
		int i=0;
		ofstream fout;
		//Retreiving system date and time
		time_t current = time(0);
		char* dt = ctime(&current);
		//Opening the Current_PO.txt file in which PO details are stored
		fout.open("Current_PO.txt");
		//Generating the PO and storing it in the Current_PO.txt file in a formatted manner
		fout<<"\t\t\t  Purchase Order " <<"\n";
		fout<<"\t\t\t  ______________\n\n";
		fout<<"Order#:  "<<r.req_no<<"\t\t\t\t Issue Date:"<<dt<<"\n\n";
		fout<<"Delivery Date:  "<<r.delivery_date<<"\n\n";
		fout<<"-----------------------------------------------------------------------------\n";
		fout<<"\t\t\t\t**Line Items**\t\t\t\t\t\n";
		fout<<"-----------------------------------------------------------------------------\n";
		fout<<"Item Code\tItem Name\tQuantity\tPrice\t\tTotal\n";
		fout<<"_________\t_________\t________\t_____\t\t_____\n\n";
		
		while(i<r.num)
		{
		total=total+ price_list[r.item_code[i]-1]*r.qty[i];
		fout<<setw(9)<<r.item_code[i]<<"\t"<<setw(9)<<item_name[r.item_code[i]-1]<<"\t"<<setw(8)<<r.qty[i]<<"\t";
		if(r.item_code[i]>=1&&r.item_code[i]<=size)
		fout<<setw(5)<<price_list[r.item_code[i]-1]<<"\t\t"<<setw(5)<<price_list[r.item_code[i]-1]*r.qty[i]<<"\n\n\n";
		else
		fout<<"_ _ _\t\t_ _ _\n\n\n";
		i++;
		}
		ifstream fin;
		char line[80];
		//Opening the terms.txt file from where standard terms and conditions are copied into the PO
		fin.open("terms.txt");
		while(fin)
		{
			fin.getline(line,80);
			fout<<line<<"\n";
		}
		fin.close();
		fout<<"\n\n\nAuthorized Signatory:\t\t\t\t  Amount: RS "<<total;
		fout.close();
}

//Defining friend function generate()
	void generate2(order r, po p)
	{
		//Retreiving system date and time
					int i=0;
					float total=0;
					time_t current = time(0);
					char* dt = ctime(&current);
					cout<<"\t\t\t  Purchase Order "<<"\n";
					cout<<"\t\t\t  ______________\n\n";
					cout<<"Order#:  "<<r.req_no<<"\t\t\t\t Issue Date:"<<dt<<"\n\n";
					cout<<"Delivery Date:  "<<r.delivery_date<<"\n\n";
				     for(int cou=0;cou<80;cou++)
				    cout<<"-";
				    cout<<"\n";
					cout<<"\t\t\t\t**Line Items**\t\t\t\n";
				    for(int cou=0;cou<80;cou++)
				    cout<<"-";
				    cout<<"\n";
					cout<<"Item Code\tItem Name\tQuantity\tPrice\t\tTotal\n";
					cout<<"_________\t_________\t________\t_____\t\t_____\n\n";
			
						while(i<r.num)
						{
							total=total+ price_list[r.item_code[i]-1]*r.qty[i];
							cout<<setw(9)<<r.item_code[i]<<"\t"<<setw(9)<<item_name[r.item_code[i]-1]<<"\t"<<setw(8)<<r.qty[i]<<"\t";
							if(r.item_code[i]>=1&&r.item_code[i]<=size)
							cout<<setw(5)<<price_list[r.item_code[i]-1]<<"\t\t"<<setw(5)<<price_list[r.item_code[i]-1]*r.qty[i]<<"\n\n\n";
							else
							cout<<"_ _ _\t\t_ _ _\n\n\n";
							i++;
						}
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
					cout<<"\n\n\nAuthorized Signatory:\t\t\t\t\t  Amount: RS "<<total;
					cout<<"\n\n\n\n";
					cout<<"Press enter to go to main menu. ";
	}
	
				
//*Main Function*//
int main()
{
	order r;
	char flag='f',log;
	char ch;
	//system("wmic");
	//Displaying a menu to accept user commands
	restart: log=login();         //login page
	while(log=='4')
	{
		log=login();
	}
	return 0;
}//End of main()



