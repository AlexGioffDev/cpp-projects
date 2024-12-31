#include "Program.h"
#include <iostream>
#include "Book.h"
#include "FileManagment.h"

void clear();
void pressEnter();

bool Program::getStatus()
{
  return status;
}

void Program::run()
{
  FileManagment fileManagment("./data/books.txt");
  int choice;

  do
  {
    clear();
    std::cout << "Welcome to the BOOK MANAGEMENT App" << std::endl;
    std::cout << "1: Add a new Book" << std::endl;
    std::cout << "2: See All Books" << std::endl;
    std::cout << "3: Delete All Books" << std::endl;
    std::cout << "4: Close" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(); // Ignore the newline character

    switch (choice)
    {
    case 1:
    {
      std::string title, author, pageStr;
      int totalPage;
      std::cout << "Enter Book Title: ";
      std::getline(std::cin, title);
      std::cout << "Enter book Author: ";
      std::getline(std::cin, author);
      std::cout << "Enter Book Pages: ";
      std::getline(std::cin, pageStr);
      totalPage = std::stoi(pageStr);
      Book book(title, author, totalPage);
      fileManagment.addBook(book);
      pressEnter();
      break;
    }
    case 2:
    {
      auto books = fileManagment.getAllBooks();
      if (books.empty())
      {
        std::cout << "No Books found.\n";
      }
      else
      {
        for (const auto &book : books)
        {
          book.getInfo();
          std::cout << "----------------------------------------------------------" << std::endl;
        }
      }
      pressEnter();
      break;
    }
    case 3:
    {
      fileManagment.clearBooks();
      pressEnter();
      break;
    }
    case 4:
    {

      status = false;
      std::cout << "Goodbye" << std::endl;
      break;
    }
    default:
      break;
    }

  } while (choice != 4);
}

void clear()
{
  /*
    Check the OS if windows use cls otherwise
    use clear to clear the console
  */
#if defined _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void pressEnter()
{
  std::cout << "Press Enter to continue";
  std::cin.get();
}