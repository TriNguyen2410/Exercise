#include <iostream>
#include <vector>
#include <time.h>
#include <assert.h>
#include <string>
#include <string.h>
#include <iomanip>
#define LOSE 0
#define WIN 1

using namespace std;

struct CodeNPresent
{
	string Present[100];
	int NumberCode[100];
};

struct Package
{
	vector<string> Item;
	int money;
};

struct Shop
{
	string Item_Name;
	int price;
};

struct Profile
{
	float win_percentage;
	int VIP;
	int Level;
	int Coin;
};

void Init_Character(Profile &character)
{
	character.win_percentage = 100.00;
	character.VIP = 0;
	character.Level = 1;
	character.Coin = 0;
}

void Set_Present(string *&present)				//duplicate the name of the memory location in this function to main function by using ampersand character.
{
	present = new string[5];
	present[0] = "Thien Su Ban Phuc";
	present[1] = "Minotaure";
	present[2] = "Lengend - Ca Chep";
	present[3] = "Wow - No Than";
	present[4] = "Super - Thuong Co";
}

bool Get_Lucky(int &lucky_number, int &number)			//we must check this line first if want to get the code.
{
	srand(time(NULL));
	lucky_number = (rand() % 5);
	number = rand() % 5;
	if (lucky_number == number)
	{
		return true;
	}
	return false;	//because return above is end program, if the condition above is occur, the code will return true, if not, goes to this line and return false.
}

void Item_Iconic(Shop *&shop)
{
	shop = new Shop[5];
	shop[0].Item_Name = "Wow-Bumerang + 12 (GOLD)";
	shop[0].price = 10000;
	shop[1].Item_Name = "Super-Thien Su Ban Phuc + 12";
	shop[1].price = 20000;
	shop[2].Item_Name = "Toc Mohican";
	shop[2].price = 3000;
	shop[3].Item_Name = "Ao Can Sa";
	shop[3].price = 7000;
	shop[4].Item_Name = "Giay Nam Tuoc";
	shop[4].price = 5000;
}

void Shopping(Profile &player, Shop *&shop, Package &Bag)			//because we set the name and the price of the item, this function is add after above function, that we just pass by value this function.
{
	string Item_name;
	int quantity;
	shop = new Shop[5];			//allocate for the array of the item on the shop, shop = new Shop[5] is allocate for 5 separate product contained in the array Shop[].
	Item_Iconic(shop);			//set the price and name for the products. We must push this line after above line, because it we do the contrast, the name and price will access in another memory, that the system is access in garbage value.
	for (int i = 0; i < 5; i++)
	{
		cout << setw(8) << "Name Item 1: " << shop[i].Item_Name << setw(20) << "Price: " << shop[i].price << endl;
	}
	char choose;
	rewind(stdin);
	cout << "Are U want to buy some: ";
	choose = getc(stdin);
	if (choose == 'y')
	{
		char name[30];
		rewind(stdin);
		cout << "Name: ";
		getline(cin, Item_name);
		//bool check_duplicate;
		int save_index_duplicate;
		for (int i = 0; i < 5; i++)
		{
			//check_duplicate = shop[i].Item_Name.find(Item_name);
			if (Item_name == shop[i].Item_Name)			//compare in string in C++, we using the compare operator == like compare with interger.
			{
				if (player.Coin < 0)			//money user have now is nothing, get out of shop.
				{
					cout << "Sorry, the money you have is not enough to buy this product, please visit us next time." << endl;
					return;
				}
				else		//if the user is enough money and we find the name of the product duplicate the name we input in, then save that index and changed the money in the bag is the available minus to that product price.				{
				{
					save_index_duplicate = i;		//save that index to the save_index_duplicate.
				}
			}
		}
		//when get out the loop, we total that we spend for any and we spend what item to push in the bag.
		cout << "You Buy: " << shop[save_index_duplicate].Item_Name << endl;
		cout << endl << "with quantity: ";
		cin >> quantity;
		Bag.Item.push_back(shop[save_index_duplicate].Item_Name);				//push the item you buy to the bag. (not calculate the gift code present.
		int cost;
		cost = player.Coin - (quantity * shop[save_index_duplicate].price);			//the money we have now is the minus of available money with the price of the product.
		if (cost < 0)
		{
			cout << "Sorry, Your money is not enough to buy those item!!" << endl;
			return;
		}
		else
		{
			Bag.money = cost;
		}
		
		Bag.Item.push_back("x");
		Bag.Item.push_back(to_string(quantity));		//to_string() function is use to convert the interger to be a character by using ASCII table in C++.
		
		/*if(st)*/
	}
}
/*---------------------------------------------NOTE-------------------------------------------------*/

// regardless any function is have item changed, that must push the ampersand for that to changed in 
//in loop, if we use break before exit() function, the break will execute first, then go out the loop, ignore the exit() function, if they loop again, it will still do that again and again ------> the exit() put after the break in loop will not perform, it's use less.  Solution: If we want to end that function in void function without using exit(), we must use return to end that function. not all the program. (regardless in loop)
//if we push init the function, struct before allocate memory for them, the pointer of that datatype will pointing to that name location but in another memory, not the first memory, if we use it, the  
//the pointer of array changed value in memory, use & after the * character to get that and update the value of that struct or function.
//chúng ta có thể thao tác trên phần tử của vector (như trong money của vector Package bằng cách assigning phần tử đó cho 1 giá trị khác muốn replace. Example: Bag.money = cost;
//compare substring in C++ we using == operator like using to compare with the number.
/*--------------------------------------------------------------------------------------------------*/
void Present_For_Beginner(Profile &character, Package &bag)
{
	character.Level += 10;
	character.VIP = 1;
	character.Coin = 1000000;
	bag.money = character.Coin;		//push back the money into the bag.
}

void Get_Present(string *&present, Package &Bag)
{
	char agree_to_buy;
	int choose;
	Bag.Item.resize(0);			//at the first time, the bag have nothing, or the bag is have item after get the present code.
	cout << "Congratulation, You have A Code" << endl;
	Set_Present(present);
	CodeNPresent giveaway;
	int n = 5;
	int given_code;
	for (int i = 0; i < n; i++)
	{
		giveaway.NumberCode[i] = (rand() % (1000000 - 100000)) + 100000;
		giveaway.Present[i] = present[i];
	}
	given_code = giveaway.NumberCode[(rand() % 4 - 0) + 0];			//get the code is the code in between two number: 0 to n.
	cout << "Your Give Code Is: " << given_code << endl;
	int another_choose;
	int repeat = 0;
	do
	{
		cout << "Enter a code: " << endl;
		cin >> another_choose;
		for (int i = 0; i < n; i++)
		{
			if (another_choose == giveaway.NumberCode[i])
			{
				cout << "Correct" << endl;
				cout << "Your Present is: " << giveaway.Present[i] << endl;			//respective the code with the present it have.
				Bag.Item.push_back(giveaway.Present[i]);			//push the present item code to the bag
				return;		//just end this function right here, if we use exit(1) the program will end and not perform any code under this function in main.
			}
		}
		repeat++;		//if not occur the condition in loop, the count variable is increase to 1 and continue the loop do while.
		//if get out the loop but not have any correct code available, then the system let him input again.
		cout << "Sorry, You have input wrong code" << endl;
		if (repeat == 3)
		{
			cout << "Out of choose, your code will be delete." << endl;
			choose = -1;
			exit(1);
		}
	} while (repeat < 3);		//if n greater than 3, the loop end and the code given will be destroy.
}

void Check_Bag(Package Bag)		//check available bag, that not have changed any value or something, or this method is pass by value, that not need uses & to pass in argument.
{
	int choose;
	cout << "Check bag? 1- open, any number - ignore: ";
	cin >> choose;
	switch (choose)
	{
	case 1:
		for (int i = 0; i < Bag.Item.size(); i++)
		{
			// or cout << bag.Item.at(i) << endl;
			cout << Bag.Item.at(i) << " ";
		}
		cout << endl << "Coin: " << Bag.money << endl;
		break;
	default:
		break;
	}
}


//int main()
//{
//	//int i = 69;
//	//string k("I love ");
//	//string h(" with my lover");
//	//k += to_string(i);
//	//k += h;			//combine two string by addition operator.
//	//cout << k << endl;
//	//int numberpage = 73201;
//	//int pagenumber = 57075;
//	//cout << pageCount(numberpage, pagenumber) << endl;
//	Profile player;
//	Init_Character(player);
//	Shop *shopping;
//	int lucky_number;
//	int number;
//	Package bag;
//	string *present;
//	if (Get_Lucky(lucky_number, number) == true)
//	{
//		Get_Present(present, bag);
//		Present_For_Beginner(player, bag);
//		Check_Bag(bag);
//		Shopping(player, shopping, bag);
//		Check_Bag(bag);
//	}
//	else		//if we have not lucky, then ignore this lucky and goes to next action.
//	{
//		Present_For_Beginner(player, bag);		//even the player have lucky code or not, the present will give for the player.
//		Check_Bag(bag);
//		Shopping(player, shopping, bag);
//		Check_Bag(bag);
//	}
//	system("pause");
//}
