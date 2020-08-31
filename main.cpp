#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;
const int TRIES = 5;
int Found(char guess, string secretword, string &guessword)
{
    int a;
    int word_match = 0;
    int len = secretword.length();
    for (a = 0; a< len; a++)
    {
        if (guess == guessword[a])
            return 0;

        if (guess == secretword[a])
        {
            guessword[a] = guess;
            word_match++;
        }
    }
    return word_match;
}
int main()
{
    char letter;
    int Wrong_Tries = 0;
    string word;
    string name[] =
    { "malaika","maaz","rimsha","hafsa","rizwan","rauf","aminah","areesha","neha","Rahima","marium","maham", "mohsin","rajesh", "varda" };
    string place[] =
    {"pakistan", "london","iraq","germany","america","europe","holand","afghanistan","india","munic","france"
,"kenya","austrailia","canada","south africa"   };
    string animal[] =
  {"horse","donkey","elephent","lion","tiger","fox","snake","giraffe","buffalo","baboon","leopard",
"cow","wolf","ox","polarbear"   };
    string colour[] =
    {"red","green","golden","silver","indigo","orange","purple","pink","yellow","blue","black","grey",
"maroon","ruby","azure"  };
    string flower[]={ "jasmine","rose","sunflower","tulip","aster","lily","daisy","carnation","daffodil","hibiscus", "iris","jonquil","marigold","orchid","pansy" };
    string book[]={
"harrypotter","carrywar","vampirediaries","wrongside","shadesofgrey","newmoon","eclipse",
     "pusandboots","fantasticbeast","treasureisland","frankenstein","matilda","dracula","junglebook",
        "catinhat"};
    while (1)
    {
        Wrong_Tries = 0;
        srand(time(NULL));
        string wordType = "";
        int c;
        int n = rand() % 6;
        int nRand;
        switch (n)
        {
        case 1:
            nRand = rand() % 15;
            wordType = "Name";
            word = name[nRand];
            break;
        case 2:
            nRand = rand() % 15;
            wordType = "Place";
            word = place[nRand];
            break;
        case 3:
            nRand = rand() % 15;
            wordType = "Animal";
            word = animal[nRand];
            break;
        case 0:
            nRand = rand() % 15;
            wordType = "Colour";
            word = colour[nRand];
            break;
        case 4:
            nRand=rand() % 15;
            wordType="Flower";
            word = flower[nRand];
            break;
        case 5:
            nRand=rand() % 15;
            wordType="Book";
            word = book[nRand];
            break;
        default:
            break;
        }
        string UnknownLetter(word.length(), '-');
        cout << "\n\t\t\tHangaroo..." << endl;
        cout<<"\nPresented By Malaika Khalid & Maaz Ahmed"<<endl;
        cout << "\nGUESS A WORD..." << endl;
        cout << "\nEach Letter Is Represented By A Dash!";
        cout << "\nPress One Letter At A Time...";
        cout << "\nYou Have " << TRIES << " Tries " << endl;
        cout << "Now Guess The Word...";
        cout << "\n=======================================";
        while (Wrong_Tries < TRIES)
        {
            cout << "\n\n" << UnknownLetter;
            cout << "\n\Word Type: " << wordType;
            cout << "\n\nGuess a letter: ";
           // cout << UnknownLetter << endl;
            cin >> letter;
            int res = Found(letter, word, UnknownLetter);
            if (res == 0) {
                cout << endl << "OOPS! The letter isn't in the word!" << endl;
                Wrong_Tries++;  }
            else
            {
                cout << endl << "You found "<< res<< "  letter...!" << endl;
            }
            cout << "You have " << TRIES - Wrong_Tries;
            cout << " Tries Left." << endl;
            if (word == UnknownLetter)  {
                cout << word << endl;
                cout << "Yeah! You got the word!" << endl;
                break;  }
            else if (Wrong_Tries == TRIES)  {
                cout << "\nSORRY, you lost...YOU DIDN'T SEARCH THE WORD.." << endl;
                cout << "The word was : " << word << endl;   }   }
        cout << "Do you wnat to play again ? " << endl << "1 (YES)/ 0 (No)" << endl;
        cin >> c;
        if (c == 1)
            continue;
        else
            break;    }
    return 0;    }
