#pragma once
#include <string>
#include <queue>

class People
{
  std::string lastName;
  std::string firstName;
  int age;
  int height;
  int weight;
public:
  People(std::string lastName = std::string(), std::string firstName = std::string(), int age = 0, int height = 0, int weight = 0)
  {
    this->lastName = lastName;
    this->firstName = firstName;
    this->age = age;
    this->height = height;
    this->weight = weight;
  }
  ~People()
  {

  }
  void setlastName(std::string lastName = std::string())
  {
    this->lastName = lastName;
  }
  void setfirstName(std::string firstName = std::string())
  {
    this->firstName = firstName;
  }
  void setAge(int age = 0)
  {
    this->age = age;
  }
  void setHeight(int height = 0)
  {
    this->height = height;
  }
  void setWeight(int weight = 0)
  {
    this->weight = weight;
  }
  std::string getlastName()
  {
    return lastName;
  }
  std::string getfirstName()
  {
    return firstName;
  }
  int getAge()
  {
    return age;
  }
  int getHeight()
  {
    return height;
  }
  int getWeight()
  {
    return weight;
  }
};

class Patient : public People
{
  int patientNum;
  int assignedDocID;
public:
  Patient(int pnum = 0, int aDocID = 0)
  {
    this->patientNum = pnum;
    this->assignedDocID = aDocID;
  }
  ~Patient()
  {

  }
  void setPatientNumber(int pnum = 0)
  {
    this->patientNum = pnum;
  }
  void setAssignedDocID(int aDocID = 0)
  {
    this->assignedDocID = aDocID;
  }
  int getPatientNumber()
  {
    return patientNum;
  }
  int getAssignedDocID()
  {
    return assignedDocID;
  }
  void clear()
  {
    this->setAge(0);
    this->setHeight(0);
    this->setWeight(0);
    this->setlastName("");
    this->setfirstName("");
    this->assignedDocID = -1;
    this->patientNum = -1;
  }
  bool operator==(Patient pat)
  {
    if (this->patientNum == pat.getPatientNumber())
      return true;
    return false;
  }
};

class Appointment
{
  int time;
  Patient pat;
  int day;
  int month;
  int year;
public:
  Appointment(int time = 0, Patient pat = Patient(), int day = 0, int month = 0, int year = 0)
  {
    this->time = time;
    this->pat = pat;
    this->day = day;
    this->month = month;
    this->year = year;
  }
  void setTime(int time = 0) { this->time = time; }
  void setPatient(Patient pat = Patient()) { this->pat = pat; }
  void setDay(int day = 0) { this->day = day; };
  void setMonth(int month = 0) { this->month = month; }
  void setYear(int year = 0) { this->year = year; }
  int getTime() { return time; }
  Patient getPatient() { return pat; }
  int getDay() { return day; }
  int getMonth() { return month; }
  int getYear() { return year; }
  bool operator==(Appointment a)
  {
    if (this->day == a.day && this->month == a.month && this->year == a.year && this->time == a.time && this->pat == a.pat)
      return true;
    return false;
  }
};

class Doctor : public People
{
  struct linkedAppointment
  {
    Appointment value;
    linkedAppointment* next;
  };
  struct PatientList
  {
    int patientID;
    PatientList* next;
  };
  int IDNumber;
  int AppSize;
  int PatSize;
  linkedAppointment* frontApp;
  PatientList* frontPat;
public:
  Doctor(std::string name = std::string(), int age = 0, int height = 0, int weight = 0, int ID = 0)
  {
    frontApp = nullptr;
    frontPat = nullptr;
    this->setlastName(name);
    this->setfirstName(name);
    this->setAge(age);
    this->setHeight(height);
    this->setWeight(weight);
    IDNumber = ID;
    AppSize = 0;
    PatSize = 0;
  }
  ~Doctor()
  {
    while (frontApp)
    {
      linkedAppointment* Apptemp = frontApp;
      frontApp = frontApp->next;
      delete Apptemp;
    }
    while (frontPat)
    {
      PatientList* Pattemp = frontPat;
      frontPat = frontPat->next;
      delete Pattemp;
    }
  }
  void setDoctorNumber(int dnum = 0)
  {
    this->IDNumber = dnum;
  }
  int getDoctorNumber()
  {
    return IDNumber;
  }
  void addAppointment(Appointment a = Appointment())
  {
    linkedAppointment* newApp = new linkedAppointment;
    newApp->value = a;
    newApp->next = frontApp;
    frontApp = newApp;
    AppSize++;
  }
  void addPatient(int patientID = 0)
  {
    PatientList* newPat = new PatientList;
    newPat->patientID = patientID;
    newPat->next = frontPat;
    frontPat = newPat;
    PatSize++;
  }
  void removeAppointment(bool& found, Appointment a = Appointment())
  {
    linkedAppointment* previous = nullptr;
    int counter = 0;
    while (counter != AppSize && !found)
    {
      linkedAppointment* Apptemp = frontApp;
      if (Apptemp->value == a)
      {
        found = true;
        if (previous)
        {
          previous->next = Apptemp->next;
        }
        else
        {
          frontApp = Apptemp->next;
        }
        delete Apptemp;
      }
      previous = Apptemp;
      Apptemp = Apptemp->next;
      counter++;
    }
  }
  void removePatient(bool& found, int patientID = 0)
  {
    PatientList* previous = nullptr;
    int counter = 0;
    while (counter != PatSize && !found)
    {
      PatientList* Pattemp = frontPat;
      if (Pattemp->patientID == patientID)
      {
        found = true;
        if (previous)
        {
          previous->next = Pattemp->next;
        }
        else
        {
          frontPat = Pattemp->next;
        }
        delete Pattemp;
      }
      previous = Pattemp;
      Pattemp = Pattemp->next;
      counter++;
    }
  }
  std::queue<int> getpatientIDList()
  {
    std::queue<int> temp;
    PatientList* Pattemp = frontPat;
    int counter = 0;
    while (counter != PatSize)
    {
      temp.push(Pattemp->patientID);
      Pattemp = Pattemp->next;
      counter++;
    }
    return temp;
  }
  std::queue<Appointment> getAppointmentList()
  {
    std::queue<Appointment> temp;
    linkedAppointment* Apptemp = frontApp;
    int counter = 0;
    while (counter != AppSize)
    {
      temp.push(Apptemp->value);
      Apptemp = Apptemp->next;
      counter++;
    }
    return temp;
  }
  void clear()
  {
    this->setAge(0);
    this->setHeight(0);
    this->setWeight(0);
    this->setlastName("");
    this->setfirstName("");
    while (frontApp)
    {
      linkedAppointment* Apptemp = frontApp;
      frontApp = frontApp->next;
      delete Apptemp;
    }
    while (frontPat)
    {
      PatientList* Pattemp = frontPat;
      frontPat = frontPat->next;
      delete Pattemp;
    }
    this->IDNumber = 0;
    this->AppSize = 0;
    this->PatSize = 0;
  }
};
