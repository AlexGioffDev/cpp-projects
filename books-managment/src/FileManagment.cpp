#include "FileManagment.h"

#include <fstream>
#include <iostream>
#include <sstream>

void FileManagment::addBook(const Book &book)
{
  std::ofstream outfile(filePath, std::ios::app);
  if (outfile.is_open())
  {
    outfile << book.toString() << "\n";
    outfile.close();
    std::cout << "Book Added successfully!\n";
  }
  else
  {
    std::cerr << "Error: Could not open file" << std::endl;
  }
}

std::vector<Book> FileManagment::getAllBooks() const
{
  std::vector<Book> books;

  std::ifstream inFile(filePath);
  if (inFile.is_open())
  {
    std::string line;
    while (std::getline(inFile, line))
    {
      std::istringstream ss(line);
      std::string title, author, pageStr;
      if (std::getline(ss, title, '|') && std::getline(ss, author, '|') && std::getline(ss, pageStr, '|'))
      {
        int totalPage = std::stoi(pageStr);
        books.emplace_back(title, author, totalPage);
      }
    }
    inFile.close();
  }
  else
  {
    std::cerr << "Error: Could not open file" << std::endl;
  }

  return books;
}

void FileManagment::clearBooks()
{
  std::ofstream outfile(filePath, std::ios::trunc);
  if (outfile.is_open())
  {
    outfile.close();
    std::cout << "Books Cleared\n";
  }
  else
  {
    std::cerr << "Error: Could not open file" << std::endl;
  }
}