#ifndef __SEAT_H__
#define __SEAT_H__



class Seat
{
  private:
    bool occupied;

  public:
    Seat(): occupied{false} {}
    void book();
    void free();
    bool isFree() const;
    char displayStatus() const;
};

#endif