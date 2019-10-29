#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
using namespace std;


const int SIZE = 10; // global decleration of an array's size
enum antColony { A, B, C, D, E, F, G, H, I, J }; // enumeration for different ant calonies 






void studentInfo()

{
	
	
   cout << endl;
   cout << endl;
   cout << endl;
	
	
	
   cout << "           +----------------------------------------------------+          " << endl;
   cout << "           |          Computer Science and Engineering          |          " << endl;
   cout << "           |           CSCE 1030 - Computer Science I           |          " << endl;
   cout << "           |  Kerimjan Rejepov     kr1170    kr1170@my.unt.edu  |          " << endl;
   cout << "           +----------------------------------------------------+          " << endl;
   
   cout << endl;
   cout << endl;
   cout << endl;
	
	
	
	
	
}


void programDescription()
{
	
   
   
   
   cout << "           W e l c o m e   t o   A n t h o n y's   h u n c h                " << endl;
   cout << "   ------------------------------------------------------------------------ " << endl;
   cout << "    This program will set up a matrix that represents the pheromone levels  " << endl;
   cout << "    between ant colonies. Anthony's objective is to the find a path least   " << endl;
   cout << "    taken by the other ants in the hopes of finding food to last through the" << endl;
   cout << "    winter                                                                  " << endl;
   cout << "   ------------------------------------------------------------------------ " << endl;
   
   
   cout << endl;
   cout << endl;
   cout << endl;
	
	
	
	
}








void makeArray(int MATRIX[SIZE][SIZE]) // initialize the 2-D array. Have to make random numbers
{
   srand(time(0));   // seed. Prints different random number every loop
   
   
   
   for(int i = 0; i < SIZE; i++)
   {
      for(int j = 0; j < SIZE; j++)
      {
         if(i == j)
         {			      
         
		    MATRIX[i][j] = 0;  // makes all the diagonal numbers zero. When both indexes same it initializes to zero
		 
		 }
         
		 else
		 {
            
			MATRIX[i][j] = ((rand() % 20) + 1); // generates the number between 1 - 20 and fills the whole matrix
         
		 } 
	  }
   }


}




void showArray(int MATRIX[][SIZE]) // func outputs the whole array to the screen
{
   
   
   cout << endl;
   cout << "Ant Colonies : \n ";
   cout << endl;
   
   
   
   
   
   
   
   cout << "    A  B  C  D  E  F  G  H  I  J " ;   // prints the calonies horizontally
   
   
   
   
   cout<<"\n   -------------------------------\n";


   for(int i = 0; i < SIZE; i++)
   {
      cout << (char)('A'+i) <<" | "; // prints the ant calonies vertically
      
	  for(int j = 0; j < SIZE; j++)
      {  
  
           if (MATRIX[i][j] < SIZE)
		   {
			   
			   cout << "0" << MATRIX[i][j] << " "; 
			   
		    }
		   
		   else
			   
			{
				   
				   
				   
		       cout << MATRIX[i][j] << " ";
				   
				   
			}
		   

      }
	  
	  
     cout << endl;
   }
   
   
   cout << endl;
}


bool visitedArray(int A[], int column) // returns true if column visited. Otherwise return false
{
	for(int i = 0; i < SIZE; i++)
	{
		if(A[i] == column) 
		return true;
	}
		return false; 
}


int lowestPheromone(int MATRIX[][SIZE], int A[], int column) // extract lowest pheromone from the row
{
	int temp  = 100;
	int index = -1;
	for(int i = 0; i < SIZE; i++)
	{
		if(i == column)
		continue;
		if(visitedArray(A, i)) // visited row not selected
		continue;
		if(MATRIX[column][i] < temp) // row selected
		{
			temp  = MATRIX[column][i];
			index = i;
		}
	}
	return index;
}


void outputA(int Y[]) // output visited array
{
	cout << endl;
	cout << "The path followed by Anthony is :\n";
	cout << endl;
	
	
	for(int i = 0; i < SIZE; i++)
	{
		antColony colony = (antColony)Y[i];
		switch(colony)
		{
			case A: 
		 
		 
				cout << "A";
         
		 
				break;
			
			
 
			case B: 
		
		
				cout << "B";


				break;
			
			
     
			case C: 
		
		
		
				cout << "C";



				break;
		   
		   

			case D: 
		
		
		
				cout << "D";


  
				break;
		   
		   

			case E: 
		
		
		
				cout << "E";



				break;



			case F: 
	   
	   
	   
				cout << "F";



				break;
			
			

			case G: 
		
		
		
				cout << "G";



				break;



			case H: 
		
		
		
				cout << "H";



				break;



			case I: 
		
		
				cout << "I";



				break;



			case J: 
		
		
				cout << "J";



				break;
		}
	if(i != SIZE-1)
		cout << "--> ";
	}
	
	
cout << endl;
cout << endl;
cout << endl;
}
int main()
{
	
	studentInfo();
	programDescription();
	
	
	
	int MATRIX[SIZE][SIZE]; // 2-D array 
	int A[SIZE]; // 1-D array 
	memset(A, -1, sizeof(A));
	
	makeArray(MATRIX); // initalize 2-d array 
	showArray(MATRIX); // output 2-d array
	
	A[0] = 0; // Starting point
	
	int current = 0;
	int i       = 1;
	
	while(A[SIZE-1] == -1) // while all colonies are not visited
	{
		int nextIndex = lowestPheromone(MATRIX, A, current); // find next row
		current       = nextIndex; 
		A[i]          = nextIndex; 
		i++;
	}
	
	outputA(A); // output the Anthony's path
	
	return 0;
	
	
	
}