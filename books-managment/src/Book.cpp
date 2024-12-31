#include "Book.h"
#include <iostream>

using namespace std;

void Book::getInfo() const
{
  cout << "Title: \t\t" << title << endl;
  cout << "Author: \t" << author << endl;
  cout << "Pages: \t\t" << totalPage << endl;
}

std::string Book::toString() const
{
  return title + "|" + author + "|" + std::to_string(totalPage);
}