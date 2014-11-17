#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <iomanip>



/*
Author: Logan Clarke
Dictionary Assignment 2
Purpose: The purpose of this porgram is to read a text file and 
build a dictionary of words found in that file. The dictionary will
output the words found in the file as well as the frequency of those
words. The dictionary will not be case sensitive and will have a
max word size and a max allowed number of words. This one uses strings
and a predefined template.
*/




using namespace std;
using std::string;

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];


/*
  you will have to write code for these 5 functions.
*/
int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT ,int[]);


/*
  note that these are global variables so that they are already initialized to 0
*/
DICT dictionary;  //your dictionary
WORD word;        //
int count[MAX];   //tracks word frequencies

DICT idict;
DICT sdict;

string wrd;

char ch;
char nxtwrd=[100];
int scount=[100];

int num;
int i = 0;
int numWord = 0;
int newline = 0;
int location;
int check = 0;
int x= 0;
int y= -1;





/*
  adds word to dictionary , if word can't be added returns 0 else returns 1
*/

BOOL InsertWord(DICT dict, WORD word)
{

	if (FullDictionary(dict)==0) {               //inserts a word at the next available position
	dict[numWord] = word;                        // as long as the dictionary is not full
        numWord++;
        return 1;
        }
	else return 0;

}




/*
  will sort the dictionary, and display the contents
*/
void DumpDictionary(DICT dict, int count[]) {

   



	for(int i = 0; i<MAX; i++){                    
                                                        //Nested for loop to sort the unsorted
		for(int j = 0; j<MAX;j++){              //array of strings, runs through putting
							// each string in apporpraite location
                if( dict[i]>dict[j] )     		              
                num++;				       
		}

        sdict[num] = dict[i];
        scount[num]= count[i];
        num=0;
	}




	cout << "Word                    Frequency"<<endl;
	cout << "---------------------------------" <<endl;          //table and output for the dictionary
                                                                     //with the appropriate spacing
	for(int i =0;i<max;i++){
    cout << setw(15) << sdict[i].data << "          " << setw(5) << scount[i];      
    }								      




}





/*
   will retrieve next word in input stream. Word is defined just as in assignment #1
   returns WORD or 0 if no more words in input stream
*/

WORD GetNextWord(void){

    
   if (check == 0){
	while( cin.good() ){

   		ch = cin.get();

    		if ( isalpha(ch) ) {            /* function test is ch  is A-Z, a-z */
       		ch = char(tolower(ch));
                nxtwrd[i] = ch;             //char array nxtwrd that gets the new word
        	newline = 1;
   		i++;
                }

   		else if (newline){
       		newline = 0;
        	string str(nxtwrd);         //string str that the new word goes into
		idict[x] = str;             // put into an array, once all words processed fall out
                x++;
                i=0;                
		}

        }
    }
    y++;
    check = 1;                             //then the appropraite word is returned 
    if (y<=100)return idict[y];            // when the function is called or 0 if none left
    else return 0;
}





/*
   if dictionary is full, return 1 else 0
*/
BOOL FullDictionary(DICT dict) {


	if(numWord == MAX) return 1;                //uses variable that counts the number of
	else return 0;				   //words in the dict to determine if its full
}






/*
   will determine if dictionary contains word. if found, returns position else returns value < 0
*/

int LocateWord(DICT dict, WORD word) {
        
         location = -1;
  

	for (int i = 0; i < numWord; i++){
		wrd = dict[i];                   //compares each word to word of interest           
		if ( word==wrd){                 //returns the location if found else returns -1
		location = i;
		}
	

	}

 return location;



}


































