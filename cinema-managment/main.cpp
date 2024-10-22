#include <iostream>
#include <string>
#include "Cinema.h"

using namespace std;
Cinema cinema;

// Util Functions
void clear();
void waitForEnter();
bool hasTheaters();

// Cinema Management Functions
void addTheater();
void listTheaters();
void booksSeat();
void startMovie();
void endMovie();
void printTheaterSeats();

int main()
{
  int choice;

  do
  {
    clear();
    cout << "Welcome to the Cinema Management System" << endl;
    cout << "1: Add a Theater" << endl;
    cout << "2: List Theaters" << endl;
    cout << "3: Book Seats for a Theater" << endl;
    cout << "4: Start Movie in a Theater" << endl;
    cout << "5: End Movie in a Theater" << endl;
    cout << "6: Print Theater Seats" << endl;
    cout << "7: Quit the program" << endl;
    cout << "Choose an option: ";
    cin >> choice;

    // Switch
    switch (choice)
    {
    case 1:
      addTheater();
      break;
    case 2:
      listTheaters();
      break;
    case 3:
      booksSeat();
      break;
    case 4:
      startMovie();
      break;
    case 5:
      endMovie();
      break;
    case 6:
      printTheaterSeats();
      break;
    case 7:
      cout << "Closing the cinema..." << endl;
      break;
    default:
      cout << "Not a valid option!" << endl;
      break;
    }

    if (choice != 7)
      waitForEnter();

  } while (choice != 7);

  return 0;
}

void clear()
{
#ifdef _WIN32
  system("cls");
  return;
#endif
  system("clear");
  return;
}

void waitForEnter()
{
  cout << "Press Enter to continue...";
  cin.ignore(); // Clear the newline character from the input buffer
  cin.get();    // Wait for any key press
}

void addTheater()
{
  int rows{0};
  int numsSeat{0};
  cout << "How many rows? ";
  cin >> rows;
  cout << "How many seats per row? ";
  cin >> numsSeat;

  cinema.addTheater(rows, numsSeat);
}

void listTheaters()
{
  if (!hasTheaters())
    return;
  cinema.printList();
}

void booksSeat()
{
  if (!hasTheaters())
    return;
  int numBooks{0};
  int theater{0};
  listTheaters();
  cout << "Which theater do you want to book seats for? ";
  cin >> theater;
  cout << "How many seats do you want to book? ";
  cin >> numBooks;

  cinema.booksSeatsInTheater(theater, numBooks);
}

void startMovie()
{
  if (!hasTheaters())
    return;
  int theater{0};
  listTheaters();
  cout << "Which theater do you want to start the movie in? ";
  cin >> theater;
  cinema.startMovieInTheater(theater);
}

void endMovie()
{
  if (!hasTheaters())
    return;
  int theater{0};
  listTheaters();
  cout << "Which theater do you want to end the movie in? ";
  cin >> theater;
  cinema.endMovieInTheater(theater);
}

void printTheaterSeats()
{
  if (!hasTheaters())
    return;
  int theater{0};
  listTheaters();
  cout << "Which theater's seats do you want to print? ";
  cin >> theater;
  cinema.displayTheater(theater);
}

bool hasTheaters()
{
  if (cinema.get_nums_theaters() <= 0)
  {
    cout << "No theaters available..." << endl;
    return false;
  }

  return true;
}