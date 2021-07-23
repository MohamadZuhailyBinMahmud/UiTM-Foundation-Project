/*
************************************************************************

Name : Mohamad Zuhaily Bin Mahmud
Student Id : 2019215818
Group : E25	
Lecturer : Encik Zamani
Lab Lecturer : Puan Norazida

************************************************************************

GUIDE
This program can be divided into 8 section
1.Libraries And Function Declaration - Declare all the fuction prototype
2.Universal Variable - Declare all the universal function
3.Program Backbone - Controlling the flow and loop of the program
4.Main Menu - Display food category of choice
5.Choosing Menu And Logic Process - Menu section for all the catogorized food types
6.Logic Testing And Calculations - Process of tataling rhe prices and counting the item purchased
7.Return Menu Option - Menu to guide users in menuevering the program flow
8.Menu Display Section - Display function for all menu

#NOTE
In order to change menu,you need to change in both "Menu Display Section"
and the price in the "Choosing Menu And Logic Process section"

************************************************************************
*/

/*
************************************************************************
LIBRARIES AND FUNCTION DECLARATION
************************************************************************
*/
#include <stdio.h>

void main_loop();
void menu();
void cuisine();
void drinks();
void dessert();
void malay();
void chinese();
void indian();
void italian();
void cold();
void hot();
void malay_menu();
void chinese_menu();
void indian_menu();
void italian_menu();
void cold_menu();
void hot_menu();
void dessert_menu();
int calc(float x,int y);
void to();

/*
************************************************************************
	Universal Variable
************************************************************************
*/
float tot=0;//Total price Variable
char round_uni;//Return Menu Option Variable
int i=0;//Item Purchased Count Variable

/*
************************************************************************
	Program Backbone
************************************************************************
*/

int main()//Act as the statup program
{
	printf("**********************\nWelcome to Diner Hotel\n**********************\n");
	main_loop();//Go to main_loop function
	//system("cls");
	printf("**************** Receipt ****************\n");
	printf("Total item purchased : %d\n",i);
	printf("Total price = RM %3.2f\n",tot);
	printf("Thank You And Do Come Again.\n");
	return 0;
}

void main_loop()//Handling the looping process of the program
{	
	menu();//Go to menu function
	
	while(round_uni!='t' && round_uni!='T')
	{
		//system("cls");
		if(round_uni=='q' || round_uni=='Q' )
			menu();
		else if(round_uni=='w' || round_uni=='W')
			cuisine();
		else if(round_uni=='e' || round_uni=='E')
			drinks();
		else if (round_uni=='S'||round_uni =='s')
			dessert();
		else
			{
				printf("Invalid input.\n");
				to();
				scanf(" %c",&round_uni);
			}	
	}
	
}

/*
************************************************************************
	Main Menu
************************************************************************
*/

void menu()//Food Category Menu
{
	
	char men;
	printf("***** Menu *****\n");
	printf("a. Food\nb. Drinks\nc. Dessert\n");
	printf("****************\n");
	printf("Choosen menu:");
	scanf(" %c",&men);
	if (men=='a' ||men=='A' )
	{
		cuisine();//Go to cuisine function
	}
	else if (men=='b'|| men=='B')
	{
		drinks();//Go to drinks function
	}
	else if(men=='C'||men=='c')
	{
		dessert();//Go to dessert function
	}
	else
	{
		round_uni='l';//Make sure that it goes to invalid value in main_loop
	}
//return to main_loop function	
}


void cuisine() // Cuisine Menu
{
	char cui,round_c;
	//system("cls");
	printf("***** Cuisine *****\n");
	printf("a. Malay\nb. Chinese\nc. Indian\nd. Italian\n");
	printf("*******************\n");
	printf("Choosen cuisine:");
	scanf(" %c",&cui);
	switch(cui)//Test variable cui value
	{
		case 'a':
		case 'A':
			malay();//Go to malay function
			break;
			
		case 'b':
		case 'B':	
			chinese();//Go to chinese function
			break;
			
		case 'c':
		case 'C':
			indian();//Go to indian function
			break;
			
		case 'd':
		case 'D':
			italian();//Go to italian function
			break;
			
		default:
			round_uni='l';//Make sure that it goes to invalid value in main_loop function
			break;
	}
//return to menu function	
}

void drinks() //Drinks Type Menu
{
	char ty;
	//system("cls");
	printf("********** Menu *********\n");
	printf("a. Cold\t\t\n");
	printf("b. Hot\t\t\n");
	printf("*************************\n");
	printf("Enter your choice:");
	scanf(" %c",&ty);
	switch(ty)
	{
		case 'a':
		case 'A':
			cold();//Go to cold function
			break;
		case 'b':
		case 'B':
			hot();//Go to hot function
			break;
		default:
			round_uni='l';//Make sure that it goes to invalid value in main_loop function
			break;
			
	}
//return to menu function	
}

/*
************************************************************************
	Choosing Menu abd Logic Process (Act as price bank)
************************************************************************
*/

void dessert()//Dessert Section
{
	char des;
	const float a=4.00,b=4.00,c=2,d=2.50,e=2.50;//price of the food
	int amt=0;//amount of item user want to buy
	do{
		//system("cls");
		dessert_menu();
		scanf(" %c",&des);
		
		if (des =='a'||des =='A'||des =='b'||des =='B'||des =='c'||des =='C'||des =='d'||des =='D'||des =='e'||des =='E')
		{
		printf("Enter amount:");
		scanf("%d",&amt);
		}
		if (amt>0)
		{
			switch(des)
			{
				case 'a':
				case 'A':
					calc(a,amt);
					break;
				case 'b':
				case 'B':
					calc(b,amt);
					break;
				case 'c':
				case 'C':	
					calc(c,amt);
					break;
				case 'd':
				case 'D':	
					calc(d,amt);
					break;
				case 'e':
				case 'E':
					calc(e,amt);
					break;
				default:
					printf("Invalid Order.\n");
					break;
			}	
		}
		else
			printf("Invalid Order.\n");
		printf("Total = RM %3.2f\n\n",tot);	
		to();
		scanf(" %c",&round_uni);
		
	}while(round_uni=='r'||round_uni=='R');
}

void malay()//Malay Cuisine Section
{
	char c_m;
	const float a=2.00,b=1.00,c=1.00,d=1.00,e=3.00;
	int amt=0;
	do
	{
		//system("cls");
		malay_menu();
		scanf(" %c",&c_m);
		if (c_m =='a'||c_m =='A'|| c_m =='b'||c_m =='B'||c_m =='c'||c_m =='C'||c_m =='d'||c_m =='D'||c_m =='e'||c_m =='E')
		{
		printf("Enter amount:");
		scanf("%d",&amt);
		}
		if (amt>0)
		{
			switch(c_m)
			{
				case 'a':
				case 'A':
					calc(a,amt);
					break;
				case 'b':
				case 'B':
					calc(b,amt);
					break;
				case 'c':
				case 'C':	
					calc(c,amt);
					break;
				case 'd':
				case 'D':	
					calc(d,amt);
					break;
				case 'e':
				case 'E':
					calc(e,amt);
					break;
				default:
					printf("Invalid Order.\n");
					break;
			}	
		}
		else
			printf("Invalid Order.\n");
	
		printf("Total = RM %3.2f\n\n",tot);
		to();
		scanf(" %c",&round_uni);	
		
	}while(round_uni=='r'||round_uni=='R');
	

}

void chinese()//Chinese Cuisine Section
{
	char c_c;
	const float a=5.00,b=4.00,c=3.00,d=2.00,e=4.50;
	int amt=0;
	do
	{
		//system("cls");
		chinese_menu();
		scanf(" %c",&c_c);
		if(c_c=='a'||c_c=='A'||c_c=='b'||c_c=='B'||c_c=='c'||c_c=='C'||c_c=='d'||c_c=='D'||c_c=='e'||c_c=='E')
		{
		printf("Enter amount:");
		scanf("%d",&amt);
		}
		if(amt>0)
		{
			switch(c_c)
			{
				case 'a':
				case 'A':
					calc(a,amt);
					break;
				case 'b':
				case 'B':
					calc(b,amt);
					break;
				case 'c':
				case 'C':	
					calc(c,amt);
					break;
				case 'd':
				case 'D':	
					calc(d,amt);
					break;
				case 'e':
				case 'E':
					calc(e,amt);
					break;
				default:
					printf("Invalid Order.\n");
					break;
			}	
		}
		else
			printf("Invalid Order.");
		printf("Total = RM %3.2f\n\n",tot);
		to();
		scanf(" %c",&round_uni);
		
	}while(round_uni=='r'||round_uni=='R');
	
	
}

void indian()//Indian Cuisine Section
{
	char c_i;
	const float a=5.00,b=6.00,c=1.00,d=5.50,e=3.50;
	int amt=0;
	do
	{
		//system("cls");
		indian_menu();
		scanf(" %c",&c_i);
		if(c_i=='a'||c_i=='A'||c_i=='b'||c_i=='B'||c_i=='c'||c_i=='C'||c_i=='d'||c_i=='D'||c_i=='e'||c_i=='E')
		{
		printf("Enter amount:");
		scanf("%d",&amt);
		}
		if (amt>0)
		{
			switch(c_i)
			{
				case 'a':
				case 'A':
					calc(a,amt);
					break;
				case 'b':
				case 'B':
					calc(b,amt);
					break;
				case 'c':
				case 'C':	
					calc(c,amt);
					break;
				case 'd':
				case 'D':	
					calc(d,amt);
					break;
				case 'e':
				case 'E':
					calc(e,amt);
					break;
				default:
					printf("Invalid Order.\n");
					break;
			}	
		}
		else
			printf("Invalid Order.\n");
		printf("Total = RM %3.2f\n\n",tot);
		to();
		scanf(" %c",&round_uni);
		
	}while(round_uni=='r'||round_uni=='R');
}

void italian()//Italian Cuisine Section
{
	char c_it;
	const float a=6.00,b=5.00,c=6.00,d=12.00,e=10.00;
	int amt=0;
	do
	{
		//system("cls");
		italian_menu();
		scanf(" %c",&c_it);
		if(c_it=='a'||c_it=='A'||c_it=='b'||c_it=='B'||c_it=='c'||c_it=='C'||c_it=='d'||c_it=='D'||c_it=='e'||c_it=='E')
		{
		printf("Enter amount:");
		scanf("%d",&amt);
		}
		if (amt>0)
		{
			switch(c_it)
			{
				case 'a':
				case 'A':
					calc(a,amt);
					break;
				case 'b':
				case 'B':
					calc(b,amt);
					break;
				case 'c':
				case 'C':	
					calc(c,amt);
					break;
				case 'd':
				case 'D':	
					calc(d,amt);
					break;
				case 'e':
				case 'E':
					calc(e,amt);
					break;
				default:
					printf("Invalid Order.\n");
					break;
			}	
		}
		else
			printf("Invalid Order.\n");
		printf("Total = RM %3.2f\n\n",tot);
		to();
		scanf(" %c",&round_uni);	
		
	}while(round_uni == 'r'||round_uni=='R');
}

void cold()//Cold Drinks Section
{
	char d_c;
	const float a=2.00,b=4.50,c=5.00,d=5.00,e=1.00;
	int amt=0;
	do
	{
	//	system("cls");
		cold_menu();
		scanf(" %c",&d_c);
		if (d_c =='a'||d_c =='A'|| d_c =='b'||d_c =='B'||d_c =='c'||d_c =='C'||d_c =='d'||d_c =='D'||d_c =='e'||d_c =='E')
		{
		printf("Enter amount:");
		scanf("%d",&amt);
		}
		if (amt>0)
		{
			switch(d_c)
			{
				case 'a':
				case 'A':
					calc(a,amt);
					break;
				case 'b':
				case 'B':
					calc(b,amt);
					break;
				case 'c':
				case 'C':	
					calc(c,amt);
					break;
				case 'd':
				case 'D':	
					calc(d,amt);
					break;
				case 'e':
				case 'E':
					calc(e,amt);
					break;
				default:
					printf("Invalid Order.\n");
					break;
			}	
		}
		else
			printf("Invalid Order.\n");
		printf("Total = RM %3.2f\n\n",tot);
		to();
		scanf(" %c",&round_uni);	
	
	}while(round_uni=='r'||round_uni=='R');
}

void hot()//Hot Drinks Section
{
	char d_h;
	const float a=4.50,b=4.00,c=4.50,d=5.00,e=1.00;
	int amt=0;	
	do{
		//system("cls");
		hot_menu();
		scanf(" %c",&d_h);
		if (d_h =='a'||d_h =='A'|| d_h =='b'||d_h =='B'||d_h =='c'||d_h =='C'||d_h =='d'||d_h =='D'||d_h =='e'||d_h =='E')
		{
		printf("Enter amount:");
		scanf("%d",&amt);
		}
		if (amt>0)
		{
			switch(d_h)
			{
				case 'a':
				case 'A':
					calc(a,amt);
					break;
				case 'b':
				case 'B':
					calc(b,amt);
					break;
				case 'c':
				case 'C':	
					calc(c,amt);
					break;
				case 'd':
				case 'D':	
					calc(d,amt);
					break;
				case 'e':
				case 'E':
					calc(e,amt);
					break;
				default:
					printf("Invalid Order.\n");
					break;
			}	
		}
		else
			printf("Invalid Order.\n");
		printf("Total = RM %3.2f\n\n",tot);	
		to();
		scanf(" %c",&round_uni);
		
	}while(round_uni=='r'||round_uni=='R');
}

/*
************************************************************************
	Logic Testing and Calculation
************************************************************************
*/

int calc(float x,int y)//Mathematical Operators
{
	tot = tot+x*y;
	i+=y;
	return;
}

/*
************************************************************************
	Return Menu Option
************************************************************************
*/

void to()
{
	
	printf("\t************************\n");
	printf("\tq. To main menu\n");
	printf("\tw. To cuisine menu\n");
	printf("\te. To drinks menu\n");
	printf("\ts. To dessert menu\n");
	printf("\tr. Buy more food/drinks from this menu section\n");
	printf("\tt. Finalize order\n");
	printf("\t************************\n");
}

/*
************************************************************************
	Menu Display Section
	#NOTE : Whenever any menu is changed, the constant value for prices in
			choosing menu section must also be changed.
************************************************************************
*/

void malay_menu()
{
	printf("********** Malay Cuisine *********\n");
	printf("a. Nasi Lemak\t\tRM 2.00\n");
	printf("b. Ketupat\t\tRM 1.00\n");
	printf("c. Telur Dadar\t\tRM 1.00\n");
	printf("d. Telur Mata Lembu\tRM 1.00\n");
	printf("e. Rendang\t\tRM 3.00\n");
	printf("**********************************\n");
	printf("Enter your choice >>");
}

void chinese_menu()
{
	printf("********** Chinese Cuisine *********\n");
	printf("a. Chicken Rice\t\tRM 5.00\n");
	printf("b. Chao Mien\t\tRM 4.00\n");
	printf("c. Won Ton Soup\t\tRM 3.00\n");
	printf("d. Chicken Dumplings\tRM 2.00\n");
	printf("e. Peking Roasted Duck\tRM 4.50\n");
	printf("************************************\n");
	printf("Enter your choice >>");
}

void indian_menu()
{
	printf("********** Indian Cuisine *********\n");
	printf("a. Tandoori Chicken\tRM 5.00\n");
	printf("b. Chicken Tikka Masala\tRM 6.00\n");
	printf("c. Naan\t\t\tRM 1.00\n");
	printf("d. Biryani\t\tRM 5.50\n");
	printf("e. Butter Paneer\tRM 3.50\n");
	printf("***********************************\n");
	printf("Enter your choice >>");
}

void italian_menu()
{
	printf("********** Italian Cuisine *********\n");
	printf("a. Spaghetti Bolognese\tRM 6.00\n");
	printf("b. Aglio e Olio\t\tRM 5.00\n");
	printf("c. Spaghetti Carbonara\tRM 6.00\n");
	printf("d. Neopolitan Pizza\tRM 12.00\n");
	printf("e. Lasagna\t\tRM 10.00\n");
	printf("************************************\n");
	printf("Enter your choice >>");
}

void cold_menu()
{
	printf("********** Cold Drinks *********\n");
	printf("a. Pepsi\t\tRM 2.00\n");
	printf("b. Iced Milo\t\tRM 4.50\n");
	printf("c. Iced Tea\t\tRM 5.00\n");
	printf("d. Iced Coffee\t\tRM 5.00\n");
	printf("e. Water\t\tRM 1.00\n");
	printf("********************************\n");
	printf("Enter your choice >>");
}

void hot_menu()
{
	printf("********** Hot Drinks *********\n");
	printf("a. Tea\t\t\tRM 4.50\n");
	printf("b. Milo\t\t\tRM 4.00\n");
	printf("c. Horlicks\t\tRM 4.50\n");
	printf("d. Coffee\t\tRM 5.00\n");
	printf("e. Water\t\tRM 1.00\n");
	printf("*******************************\n");
	printf("Enter your choice >> ");
}

void dessert_menu()
{
	printf("**************** Dessert ***************\n");
	printf("a. Creme Glacee Au Chocolat\tRM 4.00\n");
	printf("b. Glace A La Vanille\t\tRM 4.00\n");
	printf("c. Red Bean Bun\t\t\tRM 2.00\n");
	printf("d. Kuih Talam\t\t\tRM 2.50\n");
	printf("e. Karipap\t\t\tRM 2.50\n");
	printf("****************************************\n");
	printf("Enter your choice >> ");
}

