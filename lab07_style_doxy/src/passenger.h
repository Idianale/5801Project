#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
/**
@brief this is the passenger class
*/
class Passenger { // : public Reporter {
 public:
  Passenger(int = -1, std::string = "Nobody");
  /** this updates the passenger*/
  void Update();
  void GetOnBus();
  /** @brief gets the wait
  @return int*/
  int GetTotalWait() const;
  bool IsOnBus() const;
  int GetDestination() const;
  void Report() const;
 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  // global count, used to set ID for new instances

};
#endif
