/*
CSC099 Group Assignment

Group member :
1. Mohamad Zuhaily Bin Mahmud
2. Safwat Bin Farid

Group : E25

lecturer : Madam Noorazaida

Notes :
password is in main_menu function
current password : "test"

*************************************************************************
	Index
*************************************************************************
1.Global variable........................................49
2.Food Variable..........................................57
3.Program Backbone.......................................70
4.Main Menu..............................................215
5.Choosing Menu and Logic Process........................252
6.Calculation............................................470
7.Return Menu Option.....................................483
8.Admin Logic Process (add/edit/delete)..................502
************************************************************************
*/
#include <stdio.h>
#include <string.h>

#define row 10
#define col 30

int main_menu();//identify user and admin 
void main_loop(int x);//Handling our unique looping process
void menu(int x);// Menu to select food category (food / drinks / dessert)
void food(int x);//To handle food process
void dessert(int x);//To handle dessert process
void drinks(int x);//To handle drinks process
int calc(float x,int y);//Handle total sum of purchase for customer
void to();//display option for looping process
void edit(int x);//function to edit menu
void add(int x);//function to add new menu
void _delete(int x);//function to delete current menu

/*
************************************************************************
	Global Variable
************************************************************************
*/
float tot=0,prize[40];//Total price Variable
char round_uni,buy[40][col];//Return Menu Option Variable
int count=0,k=0,item[40],t,mf=4,mde=4,mdr=4;//Item Purchased Count Variable
/*
************************************************************************
	Food Varible ( We set food variable as global because of our looping
	system kept resetting the varible)
************************************************************************
*/
char food_vari[row][col]={{"Nasi Lemak"},{"Roti Canai"},{"Nasi Ayam"},{"Burger"}};
float food_price[row]={3.00,3.00,4.50,4.00};
char dessert_vari[row][col]={{"Ice cream"},{"Karipap"},{"Dadih"},{"Donut"}};
float dessert_price[row]={4.00,3.00,4.00,3.00};
char drinks_vari[row][col]={{"Pepsi\t"},{"Milo(ice/hot)"},{"Tea(ice/hot) "},{"Marinda\t"}};
float drinks_price[row]={2.00,4.00,4.00,2.00};

/*
************************************************************************
	Program Backbone (Handle Startup / looping process / identification)
************************************************************************
*/

int main()//Act as the statup program
{
	int x;//identifiyer code for type of user
	/*
	1 : Admin
	2 : Customer
	3 : Shut down system
	*/
	printf("\n\n\n\t\t\t\t\tBooting Up\n\n\n");
	system("pause");
	//system("cls");
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	do
	{
		//system("cls");
		printf("**********************************************************************\n");
		printf("                        Welcome to Diner Hotel                        \n");
		printf("**********************************************************************\n");
		x=main_menu();//identify user
		if(x!=3)
			main_loop(x);//looping system / our system blood circulation
	}while(x!=3);
	printf("\n\n\n\t\t\t\tShutting Down.\n\n\n");
	system("pause");
	return 0;
}

int main_menu()//identify user and verify admin
{
	int x,check,check2;
	char input[20],password[]={"test"},back[]={"-1"};
	do
	{
		printf("1. Admin\n2. Customer\n3. Shut off\n");
		printf(">>>");
		scanf("%d",&x);
		if(x==1)//test admin identity
		{
			do
			{
				//system("cls");
				printf("***********************\n");
				printf("         Admin         \n");
				printf("***********************\n");
				printf("Enter -1 to go back\n");
				printf("Enter password >> ");
				scanf("%s",&input);
				check=strcmp(input,password);//verify password
				check2=strcmp(input,back);//verify back option
				
				if(check==0)//if password correct
					x=1;
				else if(check2==0)//if back option is input
					x=-1;
				else if (check!=0&&check2!=0)//error value
				{
					printf("Wrong Password.\n\n");
					x=4;
				}
			}while(x!=1 && x!= -1);
		}//if
		else if(x==3)//verify password to shut down
		{
			do
			{
				//system("cls");
				printf("***************************\n");
				printf("         Shut Down         \n");
				printf("***************************\n");
				printf("Enter -1 to go back\n");
				printf("Enter password >> ");
				scanf("%s",&input);
				check=strcmp(input,password);//verify password
				check2=strcmp(input,back);//verify back option
				
				if(check==0)//if password is correct
					x=3;
				else if(check2==0)//if back option is input
					x=-1;
				else if (check!=0&&check2!=0)//error value
				{
					printf("Wrong Password.\n\n");
					x=4;
				} 
			}while(x!=3 && x!= -1);
		}//else if
	}while(x!=1&&x!=2&&x!=3);
	return x;
}//main_menu

void main_loop(int x)//Handling the looping process of the program
{	
	int prin;
	menu(x);//Go to menu function (line 219)
	
	while(round_uni!='t' && round_uni!='T')
	{
		//system("cls");
		if(round_uni=='q' || round_uni=='Q' )
			menu(x);//line 206
		else if(round_uni=='w' || round_uni=='W')
			food(x);//line 256
		else if(round_uni=='e' || round_uni=='E')
			drinks(x);//line 398
		else if (round_uni=='S'||round_uni =='s')
			dessert(x);//line 328
		else
			{
				printf("Invalid input.\n");
				to();//line 487
				scanf(" %c",&round_uni);
			}	
	}
	if(x==2)//display recipt for customer
	{
		//system("cls");
		printf("*****************************************\n");
		printf("                 Receipt                 \n");
		printf("*****************************************\n");
		printf("Item purchased :\n");
		for(k;k>0;k--)
		{
			printf("%s\tx%d\tRM %3.2f\n",buy[t],item[t],prize[t]);
			t++;
		}
		printf("*****************************************\n");
		printf("Total price = RM %3.2f\n",tot);
		printf("Thank You And Do Come Again.\n");
		printf("*****************************************\n\n");
		k=0;
		tot=0;
		t=0;
		printf("Print. 1 - Yes , 2 - No\n");
		scanf("%d",&prin);
		system("pause");
	}
	
}

/*
************************************************************************
	Main Menu
************************************************************************
*/

void menu(int x)//main menu category menu
{
	
	char men;
	//system("cls");
	printf("****************\n");
	printf("      Menu      \n");
	printf("****************\n");
	printf("a. Food\nb. Drinks\nc. Dessert\n");
	printf("****************\n");
	printf("Choosen menu:");
	scanf(" %c",&men);
	if (men=='a' ||men=='A' )
	{
		food(x);//Go to food function (line 243)
	}
	else if (men=='b'|| men=='B')
	{
		drinks(x);//Go to drinks function (line 385)
	}
	else if(men=='C'||men=='c')
	{
		dessert(x);//Go to dessert function (line 315)
	}
	else
	{
		round_uni='l';//Make sure that it goes to invalid value in main_loop
	}
//return to main_loop function	
}

/*
************************************************************************
	Choosing Menu and Logic Process
************************************************************************
*/

void food(int x)//food section
{
	int i,option,amt;
	//system("cls");
	printf("**************************************\n");
	printf("                 Food                 \n");
	printf("**************************************\n");
	for(i=0;i<mf;i++)//display menu
	{
		printf("%d. %s\t\tRM %3.2f\n", i+1, food_vari[i],food_price[i]);
	}//for
	printf("**************************************\n");
	
	if (x==1)//admin logic
	{
		printf("1. Add (Max : 10)\n2. Edit\n3. Delete\n>>");
		scanf("%d",&option);
		if (option>=1 && option<=mf)//correct option input
		{
			switch(option)
			{
				case 1:
					add(1);//580
					break;
				case 2:
					edit(1);//506
					break;
				case 3:
					_delete(1);//655
					break;
			}//switch
		}//if option
		
		else
			printf("Invalid Order.\n");
			
	}//x==1
	
	else if (x==2)//customer logic
	{
		printf("Enter item code you want to buy >>  ");
		scanf("%d",&option);
		if (option>=1 && option<=mf)//correct option input
		{
		printf("Enter amount: ");
		scanf("%d",&amt);
		}//scan amt
		if (amt>0)//correct amount input
		{
			if(option>=1 && option<=mf)
			{
					calc(food_price[option-1],amt);//calculate sum (line 474)
					strcpy(buy[k],food_vari[option-1]);//save item name
					item[k]=amt;//save item amount
					prize[k]=food_price[option-1]*amt;//save item cost
					printf("**************************************\n");	
					printf("%s\t%d\tRM %3.2f\n",buy[k],item[k],prize[k]);//validate
			}
			else
					printf("Invalid Order.\n");
		}//amt>0
		else
			printf("Invalid Order.\n");
		
		printf("Total = RM %3.2f\n\n",tot);
		k++;
	}//x==2
	
	to();//display back menu (line 487)
	scanf(" %c",&round_uni);	
}//food

void dessert(int x)//Malay Cuisine Section
{
	int i,option,amt;
	//system("cls");
	printf("**************************************\n");
	printf("               Dessert                \n");
	printf("**************************************\n");
	for(i=0;i<mde;i++)//display menu
	{
		printf("%d. %s\t\tRM %3.2f\n", i+1, dessert_vari[i],dessert_price[i]);
	}//for
	printf("**************************************\n");
	
	if (x==1)//admin logic
	{
		printf("1. Add (Max : 10)\n2. Edit\n3. Delete\n>>");
		scanf("%d",&option);
		if (option>=1 && option<=mf)//correct option input
		{
			switch(option)
			{
				case 1:
					add(2);//line 580
					break;
				case 2:
					edit(2);//506
					break;
				case 3:
					_delete(2);//655
					break;
			}//switch
		}//if option
		
		else
			printf("Invalid Order.\n");
	}//x==1
	
	else if (x==2)//customer logic
	{
		printf("Enter item code you want to buy >>  ");
		scanf("%d",&option);
		if (option>=1 && option<=mde)//correct input
		{
		printf("Enter amount: ");
		scanf("%d",&amt);
		}//scan amt
		if (amt>0)//correct amount input
		{
			if(option>=1 && option<=mde)
			{
					calc(dessert_price[option-1],amt);//calculate sum (line 474)
					strcpy(buy[k],dessert_vari[option-1]);//save item name
					item[k]=amt;//save item amount
					prize[k]=dessert_price[option-1]*amt;//save item cost
					printf("**************************************\n");
					printf("%s\t%d\tRM %3.2f\n",buy[k],item[k],prize[k]);//validate
			}
			else
					printf("Invalid Order.\n");
		}//amt>0
		else
			printf("Invalid Order.\n");
			
		printf("Total = RM %3.2f\n\n",tot);
		k++;
	}//x==2
	to();//display back menu (line 487)
	scanf(" %c",&round_uni);	
}//dessert

void drinks(int x)//drinks section
{
	int i,option,amt;
	//system("cls");
	printf("**************************************\n");
	printf("                Drinks                \n");
	printf("**************************************\n");
	for(i=0;i<mdr;i++)//display menu
	{
		printf("%d. %s\t\tRM %3.2f\n", i+1, drinks_vari[i],drinks_price[i]);
	}//for
	printf("**************************************\n");
	
	if (x==1)//admin logic
	{
		printf("1. Add (Max : 10)\n2. Edit\n3. Delete\n>>");
		scanf("%d",&option);
		if (option>=1 && option<=mdr)//correct option input
		{
			switch(option)
			{
				case 1:
					add(3);//line 580
					break;
				case 2:
					edit(3);//line 506
					break;
				case 3:
					_delete(3);//line 655
					break;
			}//switch
		}//if option
		
		else
			printf("Invalid Order.\n");
	}//x==1
	
	else if (x==2)//customer logic
	{
		printf("Enter item code you want to buy >>  ");
		scanf("%d",&option);
		if (option>=1 && option<=mdr)//coreect input
		{
		printf("Enter amount: ");
		scanf("%d",&amt);
		}//scan amt
			if (amt>0)//correct amount input
		{
			if(option>=1 && option<=mf)
			{
					calc(drinks_price[option-1],amt);//calculate sum (line 474)
					strcpy(buy[k],drinks_vari[option-1]);//save item name
					item[k]=amt;//save item amount
					prize[k]=drinks_price[option-1]*amt;//save item cost
					printf("**************************************\n");
					printf("%s\t%d\tRM %3.2f\n",buy[k],item[k],prize[k]);//validate
			}
			else
					printf("Invalid Order.\n");
		}//amt>0
		else
			printf("Invalid Order.\n");
	
		printf("Total = RM %3.2f\n\n",tot);
		k++;
	}//x==2
	to();//display back menu (line 487)
	scanf(" %c",&round_uni);	
}//drinks

/*
************************************************************************
	Calculation
************************************************************************
*/

int calc(float x,int y)//Mathematical Operators
{
	tot = tot+x*y;
	count+=y;
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
	printf("\tw. To food menu\n");
	printf("\te. To drinks menu\n");
	printf("\ts. To dessert menu\n");
	printf("\tt. Finalize\n");
	printf("\t************************\n");
	printf(">>");
}

/*
************************************************************************
	Admin Logic Process (add/edit/delete)
************************************************************************
*/

void edit(int x)//function to edit menu
{
	int option,i;
	
	printf("Enter -1 to end\n");
	printf("Select menu you want to change >>");
	scanf("%d",&option);
	
	while(option!=-1)//sentinel loop
	{
		if(option>=1 && option<=mf)//correct value
		{
			if(x==1)//food
			{
				printf("\nEnter new menu >>");
				scanf("\n");
				gets(food_vari[option-1]);//new name
				printf("\nEnter new price >>");
				scanf("%f",&food_price[option-1]);//new price
				//system("cls");
				printf("************************\n");
				printf("New menu : \n");
				for(i=0;i<mf;i++)//dispplay new menu
				{
					printf("%d. %s\tRM %3.2f\n",i+1,food_vari[i],food_price[i]);
				}//for
				printf("************************\n\n");
			}//x=1
			
			else if(x==2)//dessert
			{
				printf("\nEnter new menu >>");
				scanf("\n");
				gets(dessert_vari[option-1]);//new name
				printf("\nEnter new price >>");
				scanf("%f",&dessert_price[option-1]);//new price
				//system("cls");
				printf("************************\n");
				printf("New menu : \n");
				for(i=0;i<mde;i++)//display new menu
				{
					printf("%d. %s\tRM %3.2f\n",i+1,dessert_vari[i],dessert_price[i]);
				}//for
				printf("************************\n\n");
			}//x=2
			
			else if(x==3)//drinks
			{
				printf("\nEnter new menu >>");
				scanf("\n");
				gets(drinks_vari[option-1]);//new name
				printf("\nEnter new price >>");
				scanf("%f",&drinks_price[option-1]);//new price
				//system("cls");
				printf("************************\n");
				printf("New menu : \n");
				for(i=0;i<mdr;i++)//display new menu
				{
					printf("%d. %s\tRM %3.2f\n",i+1,drinks_vari[i],drinks_price[i]);
				}//for
				printf("************************\n\n");
			}//x=3
			
		}//if option
		
		else//error value
			printf("Invalid input\n\n");
			
		printf("Enter -1 to end\n");
		printf("Select menu you want to change >>");
		scanf("%d",&option);
	}
}//edit

void add(int x)//function to add new menu
{
	int reserve,i;
	
	if(x==1)//food
	{
		if(mf<10)//do not exceed maximum value
		{
			mf++;//handling the total item on menu
			printf("\nEnter new menu >>");
			scanf("\n");
			gets(food_vari[mf-1]);//new name
			printf("\nEnter new price >>");
			scanf("%f",&food_price[mf-1]);//new price
			//system("cls");
			printf("************************\n");
			printf("New menu : \n");
			for(i=0;i<mf;i++)//display new menu
			{
				printf("%d. %s\tRM %3.2f\n",i+1,food_vari[i],food_price[i]);
			}//for
			printf("************************\n\n");
		}
		else//exceed maximum value
			printf("Already reached max limit of menu");
	}//x==1
	
	else if(x==2)//dessert
	{
		if(mde<10)//do not exceed maximum value
		{
			mde++;//handling the total item on menu
			printf("\nEnter new menu >>");
			scanf("\n");
			gets(dessert_vari[mde-1]);//new name 
			printf("\nEnter new price >>");
			scanf("%f",&dessert_price[mde-1]);//new price
			//system("cls");
			printf("************************\n");
			printf("New menu : \n");
			for(i=0;i<mde;i++)//display new menu
			{
				printf("%d. %s\tRM %3.2f\n",i+1,dessert_vari[i],dessert_price[i]);
			}//for
			printf("************************\n\n");
		}
		else//exceed maximum value
			printf("Already reached max limit of menu");
	}//x==2
	
	else if(x==3)//drinks
	{
		if(mdr<10)//do not exceed maximum value
		{
			mdr++;//handling the total item on menu
			printf("\nEnter new menu >>");
			scanf("\n");
			gets(drinks_vari[mdr-1]);//new name
			printf("\nEnter new price >>");
			scanf("%f",&drinks_price[mdr-1]);//new price
			//system("cls");
			printf("************************\n");
			printf("New menu : \n");
			for(i=0;i<mdr;i++)//display new menu
			{
				printf("%d. %s\tRM %3.2f\n",i+1,drinks_vari[i],drinks_price[i]);
			}//for
			printf("************************\n\n");
		}
		else//exceed maximum value
			printf("Already reached max limit of menu");
	}//x==3

}//add

void _delete(int x)//function to delete current menu
{
	int c,i;
	if(x==1)//food
	{
		if(mf>0)//do not exceed minimum value
		{
			printf("\nEnter menu you want to delete >> ");
			scanf("%d",&c);//item to delete
			if(c>mf || c<1)//error value
				printf("Deletion not possible.\n");
			else if (c>=1 && c<=mf)//valid value
			{
				 for (i = c - 1; i < mf - 1; i++)
				 	strcpy(food_vari[i],food_vari[i+1]);//rearrange the menu
				mf--;//handling the total item on menu
				printf("************************\n");
				printf("New menu : \n");
				for(i=0;i<mf;i++)//display new menu
				{
					printf("%d. %s\tRM %3.2f\n",i+1,food_vari[i],food_price[i]);
				}//for
				printf("************************\n\n");	
			}//else
		}
		else//exceed mimimum value
			printf("Already reached minimum limit of menu");
	}//x==1
	
	else if(x==2)//dessert
	{
		if(mde>0)//do not exceed minimum value
		{
			printf("\nEnter menu you want to delete >> ");
			scanf("%d",&c);//item to delete
			if(c>mde || c<1)//error value
				printf("Deletion not possible.\n");
			else if (c>=1 && c<=mde)//valid value
			{
				 for (i = c - 1; i < mf - 1; i++)
				 	strcpy(dessert_vari[i],dessert_vari[i+1]);//rearrange the menu
				mde--;//handling the total item on menu
				printf("************************\n");
				printf("New menu : \n");
				for(i=0;i<mf;i++)//display new menu
				{
					printf("%d. %s\tRM %3.2f\n",i+1,dessert_vari[i],dessert_price[i]);
				}//for
				printf("************************\n\n");	
			}//else
		}
		else//exceed mimimum value
			printf("Already reached minimum limit of menu");
	}//x==2
	
	else if(x==3)//drinks
	{
		if(mdr>0)//do not exceed minimum value
		{
			printf("\nEnter menu you want to delete >> ");
			scanf("%d",&c);//item to delete
			if(c>mdr || c<1)//error value
				printf("Deletion not possible.\n");
			else if (c>=1 && c<=mdr)//valid value
			{
				 for (i = c - 1; i < mf - 1; i++)
				 	strcpy(drinks_vari[i],drinks_vari[i+1]);//rearrange the menu
				mdr--;//handling the total item on menu
				printf("************************\n");
				printf("New menu : \n");
				for(i=0;i<mf;i++)//display new menu
				{
					printf("%d. %s\tRM %3.2f\n",i+1,drinks_vari[i],drinks_price[i]);
				}//for
				printf("************************\n\n");	
			}//else
		}
		else//exceed mimimum value
			printf("Already reached minimum limit of menu");
	}//x==3
}//delete


