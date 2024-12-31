#ifndef _FILE_MANAGMENT_H_
#define _FILE_MANAGMENT_H_

#include "Book.h"
#include <vector>
#include <string>

class FileManagment
{
private:
  std::string filePath;

public:
  FileManagment(const std::string &filePath) : filePath(filePath) {};
  void addBook(const Book &book);
  std::vector<Book> getAllBooks() const;
  void clearBooks();
};

#endif