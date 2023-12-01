#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <conio.h>
using namespace std;

class Game
{
public: 
  static int totalGames;
  string category;
  string level;
  bool restart = 1;
  static inline void delay(int milli_seconds)
  {
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
  }
  static void loading(int milli_seconds)
  {
    system("CLS");
    cout<<"Game No."<<++totalGames<<endl;
    cout << "Loading";
    for (int i = 0; i < milli_seconds/1000; i++)
    {
      for(int i = 0;i < milli_seconds/1000;i++){
      delay(500);
      cout << ".";
      }
      for(int i = 0;i < milli_seconds/1000;i++){
        cout<<"\b \b";
      }
    }
    system("CLS");
  }
  Game()
  {
    this->category = "Animals";
    this->level = "Easy";
  }
  Game(string category, string level)
  {
    this->category = category;
    this->level = level;
  }
};

int Game::totalGames = 0;

class Word : public Game
{
public:
  Game *obj;
  int chances;
  string initialword;
  string word;
  char letter;
  
  Word()
  {
    system("CLS");
    int cat, lev;
    cout << "Enter the category\n1. Animals\n2. Birds\n3. Movies\n:";
    cin >> cat;
    cout << "Enter the level\n1. Easy\n2. Medium\n3. Hard\n:";
    cin >> lev;
    switch (cat)
    {
    case 1:
      if (lev == 1)
      {
        obj = new Game("Animals", "Easy");
      }
      else if (lev == 2)
      {
        obj = new Game("Animals", "Medium");
      }
      else if (lev == 3)
      {
        obj = new Game("Animals", "Hard");
      }
      else
      {
        obj = new Game("Animals", "Easy");
      }
      break;
    case 2:
      if (lev == 1)
      {
        obj = new Game("Birds", "Easy");
      }
      else if (lev == 2)
      {
        obj = new Game("Birds", "Medium");
      }
      else if (lev == 3)
      {
        obj = new Game("Birds", "Hard");
      }
      else
      {
        obj = new Game("Birds", "Easy");
      }
      break;
    case 3:
      if (lev == 1)
      {
        obj = new Game("Movies", "Easy");
      }
      else if (lev == 2)
      {
        obj = new Game("Movies", "Medium");
      }
      else if (lev == 3)
      {
        obj = new Game("Movies", "Hard");
      }
      else
      {
        obj = new Game("Movies", "Easy");
      }
      break;
    default:
      obj = new Game();
      break;
    }
    this->category = obj->category;
    this->level = obj->level;
    srand(time(0));
    int line = rand() % 20 + 1;
    try{
      ifstream in(this->level + this->category + ".txt");
      if(!in.is_open()){
        throw 1;
      }
      else{
      for (int i = 0; i < line; i++)
      {
        in.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      in >> initialword;
      word = string(initialword.length(), '_');
      }
    }
    catch(int){
      cout << "File Not Found" << endl;
      cout << "Please Check The File" << endl;
      cout << "Press Any Key To Exit" << endl;
      getch();
      exit(0);
    }
  }

  int getLetterPos(string initialword, char letter, string word)
  {
    int flag;
    bool placefilled = 0;
    for (int i = 0; i < initialword.length(); i++)
    {
      if (initialword[i] == letter)
      {
        if (word[i] == '_')
        {
          return i;
        }
        else
        {
          placefilled = 1;
          continue;
        }
      }
      else
      {
        flag = 0;
      }
    }
    if (placefilled == 1)
    {
      return -1;
    }
    if (flag == 0)
    {
      return -2;
    }
    return -3;
  }

  void loop()
  {
    system("CLS");
    int flag = -1;
    chances = initialword.length() * 2;
    while (chances > 0)
    {
      cout << word << endl;
      cout << "Chances Remaining: " << chances << endl;
      cout << "Enter a letter: ";
      cin >> letter;
      for (int i = 0; i < word.length(); i++)
      {
        int push = getLetterPos(initialword, letter, word);
        if (push >= 0)
        {
          flag = -1;
          system("CLS");
          word[push] = letter;
          cout << "You Guessed Correct Letter" << endl;
          chances++;
          break;
        }
        else if (push == -1)
        {
          flag = 1;
        }
        else if (push == -2)
        {
          flag = 0;
        }
      }
      if (flag == 1)
      {
        system("CLS");
        cout << "Space is Filled For The Letter You Had Guessed" << endl;
      }

      else if (flag == 0)
      {
        system("CLS");
        cout << "Wrong Guess! Please Try Again" << endl;
        chances--;
      }

      if (word == initialword)
      {
        system("CLS");
        cout << word << endl;
        cout << "Congratulations! Letter Matched" << endl;
        cout << "You Collected " << chances << " points" << endl;
        break;
      }
      if (chances <= 0)
      {
        system("CLS");
        cout << "Out of Chances" << endl;
        cout << "The Word is :" << initialword << endl;
      }
    }
  }
};

int main()
{
  bool restart = 1;
  while (restart)
  {
    Word *fi = new Word();
    Game::loading(5000);
    fi->loop();
    delete fi;
    delete fi->obj;
    cout << "Press 1 to restart and 0 to exit" << endl;
    cin >> restart;
    if (restart)
    {
      continue;
    }
    else
    {
      system("CLS");
      restart = 0;
      cout << "Game Over" << endl;
      cout << "Thank You For Playing" << endl;
      cout << "Developed By: Tejas Kakani" << endl;
    }
  }
  return 0;
}
