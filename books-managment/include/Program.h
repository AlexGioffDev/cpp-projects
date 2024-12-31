#ifndef _PROGRAM_H_
#define _PROGRAM_H_

class Program
{
private:
  bool status;

public:
  Program(bool status = true) : status(status) {};
  bool getStatus();
  void run();
};

#endif