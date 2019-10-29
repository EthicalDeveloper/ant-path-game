#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void findRowMax(int numbers[][8],int rowMax[],int numRows)
{
	int max;
	
	
	for (int i = 0; i < numRows; ++i)
	{
		
		max = numbers[i][0];
		
		for (int j = 0; j < 8; ++j)
		{
			
			if (numbers[i][j] > max)
			{
				
				max = numbers[i][j];
				
			}
			
			rowMax[i] = max;
			
		}
		
	}
	
}





int main()
{
	
	int matrix[5][8];
	int storeMaxArray[5];
	int randomNumber;
	srand(time(0));
	
	for (int i = 0; i < 5; ++i)
	{
		
		for (int j = 0; j < 8; ++j)
		{
			
			
			randomNumber = (rand()%401) + 100;
			
			matrix[i][j] = randomNumber;
			
		}
			
	}
	
	findRowMax(matrix, storeMaxArray, 5);
	
	
	for ( int i = 0; i < 5; ++i)
	{
		
		for (int j = 0; j < 8; ++j)
		{
			
			cout << matrix[i][j] << " ";
			
		}
		
		
		cout << endl;
		
		
	}
	
	
	cout << "The maximum in each row is: " << endl;
	
	
	for (int i = 0; i < 5; ++i)
	{
		
		
		cout << storeMaxArray[i] << " " ;
		
	}
	
	
	
	
	return 0;
}