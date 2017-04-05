#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Call {
  private:
  string caller;
  enum Issue { Email, Wireless, VPN, Auth };
  Issue issue;
  Call(string caller, Issue issue) {
    this->caller = caller;
    this->issue = issue;
  }
};

class Employee {
  private:
  string firstName;
  string lastName;
  Call* call = nullptr;
  public:
  Employee(string firstName, string lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
  }
  string getName() {
    return firstName + " " + lastName;
  }
  bool isAvailable() {
    return call == nullptr;
  }
  bool beginCall(Call* call) {
    if (!isAvailable())
      return false;
    else {
      this->call = call;
      return true;
    }
  }
  bool endCall() {
    if (isAvailable())
      return false;
    else {
      call = nullptr;
      return true;
    }
  }
};

class Director : public Employee {
  public:
  Director(string firstName, string lastName) : Employee(firstName, lastName)
  {}
};

class Manager : public Employee {
  private:
  vector<Director>* directors;
  public:
  Manager(string firstName, string lastName, vector<Director>* directors) : 
          Employee(firstName, lastName)
  {
    this->directors = directors;
  }
  bool escalateCall(Call* call) {
    for (auto director : *directors) {
      if (director.isAvailable()) {
        director.beginCall(call);
        endCall();
        return true;
      }
    }
    return false;
  }
};

class Respondent : public Employee {
  private:
  vector<Manager>* managers;
  vector<Director>* directors;
  public:
  Respondent(string firstName, string lastName, vector<Manager>* managers, 
             vector<Director>* directors) :
             Employee(firstName, lastName) {
    this->managers = managers;
    this->directors = directors;
  }
  bool escalateCall(Call* call) {
    for (auto manager : *managers) {
      if (manager.isAvailable()) {
        manager.beginCall(call);
        endCall();
        return true;
      }
    }
    // no managers are free if we get to here; try directors
    for (auto director : *directors) {
      if (director.isAvailable()) {
        director.beginCall(call);
        endCall();
        return true;
      }
    }
    return false;
  }
};

class CallCenter {
  private:
  static CallCenter* _instance = nullptr;
  vector<Respondent> respondents;
  vector<Manager> managers;
  vector<Director> directors;
  queue<Call*> callQueue;
  public:
  static CallCenter* getInstance() {
    if (_instance == nullptr) {
      _instance = new CallCenter();
    }
    return _instance;
  }
  Employee* dispatchCall(Call* call) {
    for (auto respondent : respondents) {
      if (respondent.isAvailable()) {
        respondent.beginCall(call);
        return &respondent;
      }
    }
    // no one is available at the moment; add call to queue
    callQueue.push(call);
    return nullptr;
  }
};