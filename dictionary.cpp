
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <string>
#include <iomanip>


/*
Author: Logan Clarke
Dictionary Assignment 3
Purpose: The purpose of this porgram is to read a text file and 
build a dictionary of words found in that file. The dictionary will
output the words found in the file as well as the frequency of those
words. The dictionary will not be case sensitive and will have a
max word size and a max allowed number of words. This one uses linked lists
and a predefined template.
*/


using namespace std;
const int MAX = 100;

typedef string STRING;
typedef bool BOOL;
typedef string WORD;    


STRING idict[999];                                                 //all these variable are used for my funtion
char nxtwrd[100]={0};                                              // where i get words from the input stream   
char ch;
int newline = 0;                                 
int a =0;
int b = 0;
int c=-1;
bool check = false;





/*
    structure describing a word entry in the dictionary
*/


typedef struct entry {

      int count;                                                          /* frequency count for a particular word */
      WORD w;                                                             /* the word itself */
      struct entry *next;                                                 /* pointer to next entry */

}ENTRY;


/*
    structure describing the dictionary
*/


typedef struct dict {

     int maxEntries;	                                                  /* maximum number of entries allowed; this is an artificial limit */
                                                                          /* link lists can be as big as you want. This limit ensures that   */
                                                                          /* this code tries to behave like the previous ones */
                                

    int numWords;                                                        /* number of words in the dictionary */
    ENTRY *Words;                                                        /* pointer to the entries in the dictionary */

}DICT;




/* 
  adds word to dictionary , if word can't be added 
  returns false else returns true
*/

BOOL InsertWord(DICT &dict, WORD word) {

  ENTRY *p;
  

   
         if(dict.numWords==0){
         	dict.Words = new ENTRY;					//If there are no words in the dict
         	dict.Words->w= word;					//The first word is put in
                dict.Words->count= 1;
         	dict.Words->next = 0;
         	dict.numWords=1;
                return true;
         }

         else if (dict.numWords>0) {
	 							        //Otherwise the list is traversed until
         	p=dict.Words;						//i can add an entry to the next location

         	while (p->next!=0){					
	 		p= p->next;
	 	}

         	p->next = new ENTRY;
	 	p=p->next;
	 	p->w = word;
                p->count= 1;
	 	p->next=0;
		dict.numWords=(dict.numWords) +1;
		return true;
	}
	else if(dict.numWords == dict.maxEntries) return false;

 }




/* 
  will sort the dictionary, and display the contents
*/

void DumpDictionary(DICT &dict) {

  int x=0;
  int y=0;
  ENTRY *temp;
  temp = new ENTRY;
  temp->next=0;
  ENTRY *p;
  
  ENTRY *q;
 

  if(dict.numWords>1){

 	while(x<=dict.numWords){
	
        	p=dict.Words;
        	q=dict.Words->next;      
        	x++;
		y=0;

     		while(y<=(dict.numWords-x-1)){                             
					                                   
		if(p->w > q->w){	                                   //if entries are out order        

			temp->w = p->w;					   //the contents of two entries
                	p->w = q->w;					   //in the linked list are swapped
                	q->w = temp->w;                                    
									  
			temp->count = p->count;				   
                	p->count = q->count;
                	q->count = temp->count;


                	p=p->next;
			q=q->next;
			y++;
                	}

 		else {
			p=p->next;
			q=q->next;	
			y++;
			}


       		}

   	}
  }




 
  p=dict.Words;

  cout << "Word                    Frequency"<<endl;
  cout << "---------------------------------" <<endl;      


       for(int i =0; i < dict.numWords; i++){
        cout <<left << setw(15) << p->w << "          " 
                          << setw(5) << (p->count)<<endl;      
         p=p->next;
        }

 	


        p=dict.Words;

	while (p !=0){					//destructor
	temp= p->next;					
        delete p;	
        p=temp;
	}
       						              
	delete temp;
	
	
	

}




/* 
   will retrieve next word in input stream. Word is defined 
   just as in assignment #1 returns WORD or empty string if no 
   more words in input stream
*/

WORD GetNextWord(void){

   


   if (check == 0){
	while( cin.good() ){

   		ch = cin.get();

    		if ( isalpha(ch) ) {                                           /* function test is ch  is A-Z, a-z */
       		ch = char(tolower(ch));
                nxtwrd[a] = ch;                                                //char array nxtwrd that gets 
        	newline = 1;						       //takes the new input
   		a++;
                }

   		else if (newline){
       		newline = 0;
        	string str(nxtwrd);                                            //string str that the new word goes into
		str= str.substr(0,10);					       //is put into the array of strings idict
                idict[b] = str; 
       
                for(int p=0;p<a;p++) nxtwrd[p]= '\0';           
		b++;							       //the array of char nxtwrd is reset 
                a=0; 							       //so that its empty
		}

        }
    }
    c++;
    check = 1;                                                                 //then the appropraite word is returned 
    if (c<=100)return idict[c];                                                // when the function is called or 0 if none left
    else return "";
}





/* 
   if dictionary is full, return true else false 
*/

BOOL FullDictionary(DICT &dict) {


	if(dict.numWords == dict.maxEntries) return 1;                         //uses variable that counts the number of
	else return 0;				                               //words in the dict to determine if its full
}



/*
   will determine if dictionary contains word. if found, returns 
   pointer to entry else returns  0
*/

ENTRY *LocateWord(DICT &dict, WORD word) {

  ENTRY *p;
 
  
  p = dict.Words;
  WORD theWord;
  bool found=false;
  
           
	for (int i = 0; i < dict.numWords; i++){
        
		WORD theWord = p->w;                                           //compares each word to word of interest           
		if ( word==theWord){                                           //returns the location if found else returns -1
                found=true;
                break;
		}
	        else {
		p= p->next;   
                }

	}
       

  if(found==true) return p;
  else return 0;

}


















