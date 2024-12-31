#ifndef _BOOK_H_
#define _BOOK_H_

#include <string>

class Book
{
private:
  std::string title;
  std::string author;
  int totalPage;

public:
  Book(std::string title, std::string author, int totalPage) : title(title), author(author), totalPage(totalPage) {};
  void getInfo() const;
  std::string toString() const;
};

#endif