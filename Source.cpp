//int reverse(int n)
//{
//	int digit;
//	int temp = 0;
//	while (n != 0)
//	{
//		digit = n % 10;
//		temp = temp * 10 + digit;
//		n = n / 10;		//get next digit.
//	}
//	return temp;			//return the reverse of the number.
//}
//
//int beautifulDays(int &n1, int &n2, int &k)
//{
//	int count_interval = 0;
//	//input the variable.
//	do
//	{
//		cout << "Get 1: ";
//		cin >> n1;
//		cout << "Get 2: ";
//		cin >> n2;
//	} while (n1 > n2);		//if n1 > n2, then return the loop.
//	cout << "Input divisor: ";
//	cin >> k;
//	
//	
//	for (int i = n1; i <= n2; i++)
//	{
//		int result;
//		//save the minus of number i and reverse of it to result variable.
//		result = abs(i - reverse(i));
//		//check condition.
//		//if modulus of result and the divisor is 0, or the result divide k get the number not equal with floating or double, the counting variable increase to 1.
//		if (result % k == 0)			
//		{
//			count_interval++;
//		}
//	}
//	return count_interval;
//}

#include <iostream>

using namespace std;

struct Obstacle					//declare a struct contain two elements is the row and col of obstacles. 
{
	int row;
	int col;
};
//because the queen row and queen column will change value after we increase it to check are duplicate with the obstacle or not.
				/*BUG RIGHT HERE, INT THE ARGUMENT OF THIS CHECK OUT, IS NOT CHANGED AFTER PERFORN IN CALLED FUNCTION.*/
					//ALREADY FIXED... 
					//NOTE: THE AMPERSAND IS CHANGED THE VALUEIN THAT MEMORY REGARDLESS THEY USE THE COPY TO EXECUTE IN THE 
//in this boolean function is using the argument not use ampersand because in the calling function will changed value after loop or doing anything else, that we just pass by value to check the value in that moment.
bool IsEncounter_Obs(int queen_row, int queen_col, Obstacle *obs_coord, int n_obs)		//n_obs is quantity of obstacle.+		//the function will return true if the coordinate of the queen is duplicate with the coordinate of the obstacle.
{			//the argument queen_row and queen_col just pass by value. In below this function is the string function that argument using queen_row and queen_col have changed all the time to count the coordinate that queen can attack.
	for (int i = 0; i < n_obs; i++)				//check the queen coordinate with all the coordinate of obstacle, if the coor queen is duplicate with one of them, that mean the both of that is encountered, then return true if occur this case, contrast is false. 
	{
		if (queen_row == obs_coord[i].row && queen_col == obs_coord[i].col)
		{
			return true;
		}
	}
	return false;
}

//in below function, the queen row and queen column 
int fcount_vertical(int n_matrix, int &queen_row, int &queen_col, Obstacle *obs_coord, int n_obs)			//f in name is mean 'function', to make different with the count_vertical variable inside the function.
{
	int count_vertical = 0;			//this count is count any coordinate that the queen can attack.
	int check_north_Oy = queen_row;			//check on the side of the queen row.
	while (check_north_Oy > 0)  //check in above of the Oy queen or in north
	{
		check_north_Oy--;					//back to 1 row to check that coordinate of the queen can attack are the coordinate of obstacle or not, if yes, the count not perform and stop loop, if not, the count continue increase to 1 and go to the next loop.
		if (IsEncounter_Obs(check_north_Oy, queen_col, obs_coord, n_obs) == true)		//next step of check the Oy vertical bar that the queen coordinate are duplicate with the obs coordinate or not.
		{
			break;		//if yes, break the loop and count variable not perform.
		}
		count_vertical ++;		//if not, the count increase to 1.
	}
	int check_south_Oy = queen_row;			//check in below of the queen row.
	while (check_south_Oy < n_matrix - 1)			//n is the limit of the matrix size.
	{
		check_south_Oy++;			//increase the Oy to check,
		if (IsEncounter_Obs(check_south_Oy, queen_col, obs_coord, n_obs) == true)				//this condition is cover all the coordinate of the obstacle. in first program we do is just check ONE coordinate.
		{
			break;
		}
		count_vertical++;
	}
	return count_vertical;			//return the count of the row of column that the queen can attack.
}


int fcount_horizontal(int n_matrix, int queen_row, int queen_col, Obstacle *obs_coord, int n_obs)
{
	int count_horizontal = 0;			//this count is count any coordinate that the queen can attack.
	int check_west_Ox = queen_col;		//check in leftside of the queen column
	while (check_west_Ox > 0)  //check in above of the Oy queen or in north
	{
		check_west_Ox--;					//back to 1 row to check that coordinate of the queen can attack are the coordinate of obstacle or not, if yes, the count not perform and stop loop, if not, the count continue increase to 1 and go to the next loop.
		if (IsEncounter_Obs(queen_row, check_west_Ox, obs_coord, n_obs) == true)		//next step of check the Oy vertical bar that the queen coordinate are duplicate with the obs coordinate or not.
		{
			break;		//if yes, break the loop and count variable not perform.
		}
		count_horizontal++;		//if not, the count increase to 1.
	}
	int check_east_Ox = queen_col;		//BUG OCCUR AT HERE, THIS ASSIGNMENT WILL BE A QUEEN COLUMN, NOT QUEEN ROW, BECAUSE WE WANT TO CHECK TO COLUMN CORESSPOND WITH HORIZONTAL BAR, NOT A VERTICAL BAR WITH QUEEN ROW.		//check in rightside of the queen column		//count the under coordinate that the queen can attack.
	while (check_east_Ox < n_matrix - 1)			//n is the limit of the matrix size.
	{
		check_east_Ox++;			//increase the Oy to check,
		if (IsEncounter_Obs(queen_row, check_east_Ox , obs_coord, n_obs) == true)				//this condition is cover all the coordinate of the obstacle. in first program we do is just check ONE coordinate.
		{
			break;
		}
		count_horizontal++;
	}
	return count_horizontal;			//return the count of the column of row that the queen can attack.
}

//Ox use to check the column accross the row, Oy use to check the row in cross of the col 
int fcount_left_diagonal(int n_matrix, int queen_row, int queen_col, Obstacle *obs_coord, int n_obs)			//đếm đường chéo phụ ( sub diagonal) dọc theo bên trái (không phải đường chéo chính) của queen.
{
	int count_sub_diagonal = 0;			//this count is count any coordinate that the queen can attack.
	int check_north_west_Oy = queen_row;		//check in leftside of the queen column
	int check_north_west_Ox = queen_col;		//check in leftside of the queen column
	while (check_north_west_Ox > 0 && check_north_west_Oy > 0)			//if one in two condition is imediately happen, then loop will perform, it one of two this condition is not occur, the loop will break out.  //check in above of the Oy queen or in north
	{
		check_north_west_Ox--;					//back to 1 row to check that coordinate of the queen can attack are the coordinate of obstacle or not, if yes, the count not perform and stop loop, if not, the count continue increase to 1 and go to the next loop.
		check_north_west_Oy--;					//back to 1 row to check that coordinate of the queen can attack are the coordinate of obstacle or not, if yes, the count not perform and stop loop, if not, the count continue increase to 1 and go to the next loop.
		
		if (IsEncounter_Obs(check_north_west_Oy, check_north_west_Ox, obs_coord, n_obs) == true)		//next step of check the Oy vertical bar that the queen coordinate are duplicate with the obs coordinate or not.
		{
			break;		//if yes, break the loop and count variable not perform.
		}
		count_sub_diagonal++;		//if not, the count increase to 1.
	}
	int check_south_east_Ox = queen_col;			//check in rightside of the queen column		//count the under coordinate that the queen can attack.
	int check_south_east_Oy = queen_row;			//check in rightside of the queen column		//count the under coordinate that the queen can attack.
	while (check_south_east_Ox < n_matrix - 1 && check_south_east_Oy < n_matrix - 1)			//n is the limit of the matrix size.
	{
		check_south_east_Ox++;			//increase the Oy to check,
		check_south_east_Oy++;			//increase the Oy to check,
		if (IsEncounter_Obs(check_south_east_Oy, check_south_east_Ox, obs_coord, n_obs) == true)	//if one in two condition is imediately happen, then loop will perform, it one of two this condition is not occur, the loop will break out.  			//this condition is cover all the coordinate of the obstacle. in first program we do is just check ONE coordinate.
		{
			break;
		}
		count_sub_diagonal++;
	}
	return count_sub_diagonal;			//return the count of the column of row that the queen can attack.
}

//Ox use to check the column accross the row, Oy use to check the row in cross of the col 
int fcount_right_diagonal(int n_matrix, int queen_row, int queen_col, Obstacle *obs_coord, int n_obs)			//đếm đường chéo chính( main diagonal) dọc theo bên phải (không phải đường chéo phụ) của queen.
{
	int count_main_diagonal = 0;			//this count is count any coordinate that the queen can attack.
	int check_north_east_Oy = queen_row;		//check in leftside of the queen column
	int check_north_east_Ox = queen_col;		//check in leftside of the queen column
	while (check_north_east_Ox < n_matrix - 1 && check_north_east_Oy > 0)			//if one in two condition is imediately happen, then loop will perform, it one of two this condition is not occur, the loop will break out.  //check in above of the Oy queen or in north
	{
		check_north_east_Ox++;					//back to 1 row to check that coordinate of the queen can attack are the coordinate of obstacle or not, if yes, the count not perform and stop loop, if not, the count continue increase to 1 and go to the next loop.
		check_north_east_Oy--;					//back to 1 row to check that coordinate of the queen can attack are the coordinate of obstacle or not, if yes, the count not perform and stop loop, if not, the count continue increase to 1 and go to the next loop.
		
		if (IsEncounter_Obs(check_north_east_Oy, check_north_east_Ox, obs_coord, n_obs) == true)		//next step of check the Oy vertical bar that the queen coordinate are duplicate with the obs coordinate or not.
		{
			break;		//if yes, break the loop and count variable not perform.
		}
		count_main_diagonal++;		//if not, the count increase to 1.
	}
	int check_south_west_Ox = queen_col;			//check in rightside of the queen column		//count the under coordinate that the queen can attack.
	int check_south_east_Oy = queen_row;			//check in rightside of the queen column		//count the under coordinate that the queen can attack.
	while (check_south_west_Ox > 0 && check_south_east_Oy < n_matrix - 1)			//n is the limit of the matrix size.
	{
		check_south_west_Ox--;			//increase the Oy to check,
		check_south_east_Oy++;			//increase the Oy to check,
		if (IsEncounter_Obs(check_south_east_Oy, check_south_west_Ox, obs_coord, n_obs) == true)	//if one in two condition is imediately happen, then loop will perform, it one of two this condition is not occur, the loop will break out.  			//this condition is cover all the coordinate of the obstacle. in first program we do is just check ONE coordinate.
		{
			break;
		}
		count_main_diagonal++;
	}
	return count_main_diagonal;			//return the count of the column of row that the queen can attack.
}

int queenAttack(int n_matrix, int queen_row, int queen_col, Obstacle *obs, int n_obs)
{
	int count_vertical;
	int count_horizontal;
	int count_sub_diagonal;
	int count_main_diagonal;
	int count_all_the_move_that_queen_can_attack = 0;

	count_vertical = fcount_vertical(n_matrix, queen_row, queen_col, obs, n_obs);
	count_horizontal = fcount_horizontal(n_matrix, queen_row, queen_col, obs, n_obs);
	count_sub_diagonal = fcount_left_diagonal(n_matrix, queen_row, queen_col, obs, n_obs);
	count_main_diagonal = fcount_right_diagonal(n_matrix, queen_row, queen_col, obs, n_obs);

	count_all_the_move_that_queen_can_attack = count_vertical + count_horizontal + count_sub_diagonal + count_main_diagonal;			//this count total of all the case happen.
	return count_all_the_move_that_queen_can_attack;			//return the count of the all step that 
}

void input(int &n_matrix, int &queen_row, int &queen_col, Obstacle *&obs, int &n_obs)				//it just have a reference of the array like pointer, not have a reference of the array like usual.
{
	cout << "Input the limit quantity of the 2 dimensional array: ";
	cin >> n_matrix;
	cout << endl << "Input the quantity of the obstacle: ";
	cin >> n_obs;
	cout << endl << "Input the coordinate of queen: ";
	cout << endl << " Queen row: ";
	cin >> queen_row;
	cout << endl << "Queen column: ";
	cin >> queen_col;

	//allocate memory for the array of struct consist the row and the col of the obstacle.
	obs = new Obstacle[n_obs];			//allocate the struct implement array.
	for (int i = 0; i < n_obs; i++)
	{
		cout << endl << "Input a coordinate of the " << i + 1 << " obstacle: ";
		cin >> obs[i].row >> obs[i].col;
	}
}

int main()
{
	int n_matrix;
	int queen_row;
	int queen_col;
	Obstacle *obs;
	int n_obs;
	input(n_matrix, queen_row, queen_col, obs, n_obs);
	cout << "The number of step that queen can attack is: " << queenAttack(n_matrix, queen_row, queen_col, obs, n_obs) << endl;
	system("pause");
}

