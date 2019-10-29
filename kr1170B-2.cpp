#include <iostream>
#include <cstring>
using namespace std;


int countWords(char array[], int length)
{
	
	int words = 1;
	
	for (int i = 0; i < length; ++i)
	{
		
		if (array[i] == ' ')
		{
			
			words = words + 1;
			
		}
		
	}
	
	
	return words;
	
	
}



int main()
{
	char array[51] = {};
	int length;
	int words;
	
	cout << "Enter a sentence up to 50 characters: " ;
	
	cin.getline(array,51);
	
	length = strlen(array);
	
	words = countWords(array, length);
	
	length = length - words;
	
	cout << "The phrase has " << length + 1 << " letters with " << words << " words." ;
	
	
	
	
	
	
	
	
	
	
	return 0;
}