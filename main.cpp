#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

DICT dictionary;  //your dictionary
WORD word;        //
int count[MAX];   //tracks word frequencies



int main (void) {
    int pos;

    while (1) {
       word = GetNextWord();

       if ( 0 == word )  {
           DumpDictionary(dictionary,count);
           break;
       }

       if ((pos = LocateWord(dictionary,word)) >=  0 ) 
           count[pos]++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
    }
    return 0;
}


