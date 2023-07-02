#include "People.h"
#include "AssociativeArray.h"
#include <iostream>
#include <string>
using namespace std;
void sortedByLastName(AssociativeArray<int, Patient> a);
void sortedByIDNumber(AssociativeArray<int, Patient> a);
void sortedByLastName(AssociativeArray<int, Doctor> a);
void sortedByIDNumber(AssociativeArray<int, Doctor> a);
void findByLastName(AssociativeArray<int, Patient> a, string key);
void findByID(AssociativeArray<int, Patient> a, int key);

int main()
{
  AssociativeArray<int, Patient> patientList;
  AssociativeArray<int, Doctor> doctorList;

  People tempPeople;
  Patient tempPatient;
  Doctor tempDoctor;
  Appointment tempAppointment;

  char answer;
  do
  {
    cout << endl;
    cout << "What would you like to do?\n"
      << "A. Add new patient\n"
      << "B. Add new doctor\n"
      << "C. Print out list of patients\n"
      << "D. Print out list of doctors\n"
      << "E. Link patient to doctor\n"
      << "F. Unlink patient to doctor\n"
      << "G. Search for a patient in database\n"
      << "H. Print out list of patients assigned to a doctor\n"
      << "I. Add appointment\n"
      << "J. Print table of appointments for a doctor\n"
      << "Q. Quit\n"
      << "Enter your input here:";
    cin >> answer;
    cout << endl;
    switch (answer)
    {
    case 'A':
    case 'a':
    {
      string lastnametemp, firstnametemp;
      int agetemp, heighttemp, weighttemp, IDtemp, assignedID;
      cout << "Please input patient first name:" << endl;
      cin >> firstnametemp;
      tempPatient.setfirstName(firstnametemp);
      cout << "Please input patient last name:" << endl;
      cin >> lastnametemp;
      tempPatient.setlastName(lastnametemp);
      cout << "Please input patient age:" << endl;
      cin >> agetemp;
      tempPatient.setAge(agetemp);
      cout << "Please input patient height(In inches):" << endl;
      cin >> heighttemp;
      tempPatient.setHeight(heighttemp);
      cout << "Please input patient weight(In lbs):" << endl;
      cin >> weighttemp;
      tempPatient.setWeight(weighttemp);
      cout << "Please input patient ID:" << endl;
      cin >> IDtemp;
      tempPatient.setPatientNumber(IDtemp);
      cout << "Please input patient assigned Doctor's ID (Enter 0 if don't know):" << endl;
      cin >> assignedID;
      tempPatient.setAssignedDocID(assignedID);
      doctorList[assignedID].addPatient(IDtemp);
      patientList[IDtemp] = tempPatient;
      tempPatient.clear();
      break;
    }
    case 'B':
    case 'b':
    {
      string lastNameTemp, firstNametemp;
      int  IDtemp;
      cout << "Please input doctor first name:" << endl;
      cin >> firstNametemp;
      tempDoctor.setfirstName(firstNametemp);
      cout << "Please input doctor last name:" << endl;
      cin >> lastNameTemp;
      tempDoctor.setlastName(lastNameTemp);
      cout << "Please input doctor ID:" << endl;
      cin >> IDtemp;
      tempDoctor.setDoctorNumber(IDtemp);
      doctorList[IDtemp] = tempDoctor;
      tempDoctor.clear();
      break;
    }
    case 'C':
    case 'c':
    {
      int choice = 0;
      while (choice != 1 || choice != 2)
      {
        cout << "Enter 1 to sort by last name" << endl;
        cout << "Enter 2 to sort by ID" << endl;
        cout << "Input here:";
        cin >> choice;
        if (choice == 1)
        {
          cout << "The patient list by last name is:" << endl;
          sortedByLastName(patientList);
          break;
        }
        else if (choice == 2)
        {
          cout << "The patient list by ID is:" << endl;
          sortedByIDNumber(patientList);
          break;
        }
        cout << endl << "Please enter a valid choice." << endl;
      }
      break;
    }
    case 'D':
    case 'd':
    {
      int choice = 0;
      while (choice != 1 || choice != 2)
      {
        cout << "Enter 1 to sort by name" << endl;
        cout << "Enter 2 to sort by ID" << endl;
        cout << "Input here:";
        cin >> choice;
        if (choice == 1)
        {
          cout << "The doctor list by name is:" << endl;
          sortedByLastName(doctorList);
          break;
        }
        else if (choice == 2)
        {
          cout << "The doctor list by ID is:" << endl;
          sortedByIDNumber(doctorList);
          break;
        }
        cout << endl << "Please enter a valid choice." << endl;
      }
      break;
    }
    case 'E':
    case 'e':
    {
      int DoctorID;
      int PatientID;
      cout << "Please enter the doctor ID number:";
      cin >> DoctorID;
      cout << "Please enter the patient ID number:";
      cin >> PatientID;
      patientList[PatientID].setAssignedDocID(DoctorID);
      doctorList[DoctorID].addPatient(PatientID);
      break;
    }
    case 'F':
    case 'f':
    {
      int DoctorID;
      int PatientID;
      bool found;
      cout << "Please enter the doctor ID number:";
      cin >> DoctorID;
      cout << "Please enter the patient ID number:";
      cin >> PatientID;
      doctorList[DoctorID].removePatient(found, PatientID);
      if (!found)
        cout << "Doctor " << DoctorID <<  " did not have the patient\n";
      break;
    }
    case 'G':
    case 'g':
    {
      int choice = 0;
      string name;
      int ID;
      while (choice != 1 || choice != 2)
      {
        cout << "Enter 1 to search by last name" << endl;
        cout << "Enter 2 to search by ID" << endl;
        cout << "Input here:";
        cin >> choice;
        if (choice == 1)
        {
          cout << "Enter patient's last name to search:";
          cin >> name;
          findByLastName(patientList, name);
          break;
        }
        else if (choice == 2)
        {
          cout << "Enter patient's ID to search:";
          cin >> ID;
          if (patientList[ID].getfirstName() != string())
          {
            cout << "Patient Name: " << patientList[ID].getfirstName()
              << " " << patientList[ID].getlastName() << "\n"
              << "Patient ID: " << patientList[ID].getPatientNumber() << "\n"
              << "Weight: " << patientList[ID].getWeight() << "\n"
              << "Height: " << patientList[ID].getHeight() << "\n"
              << "Age: " << patientList[ID].getAge() << "\n"
              << "Assigned Doctor: " << patientList[ID].getAssignedDocID() << "\n";
          }
          else
            cout << "Patient not in database\n";
          break;
        }
        cout << endl << "Please enter a valid choice." << endl;
      }
      break;
    }
    case 'H':
    case 'h':
    {
      int choice = 0;
      while (choice != 1 || choice != 2)
      {
        cout << "Enter 1 to search patient by doctor's last name" << endl;
        cout << "Enter 2 to search patient by doctor's ID" << endl;
        cout << "Input here:";
        cin >> choice;
        if (choice == 1)
        {
          string DoctorName;
          cout << "Please enter doctor's last name:";
          cin >> DoctorName;
          queue<int> k = doctorList.keys(), possibleDoc;
          int qsize = k.size();
          bool qfound = false;
          for (int i = 0; i < qsize; i++)
          {
            if (doctorList[k.front()].getlastName() == DoctorName)
            {
              qfound = true;
              possibleDoc.push(k.front());
            }
            k.pop();
          }
          if (qfound)
          {
            int pdsize = possibleDoc.size();
            for (int i = 0; i < pdsize; i++)
            {
              cout << "Doctor ID: " << possibleDoc.front() << "\n";
              queue<int> prt = doctorList[possibleDoc.front()].getpatientIDList();
              int qsize = prt.size();
              cout << "Names: ";
              for (int i = 0; i < qsize; i++)
              {
                cout << patientList[prt.front()].getfirstName()
                  << " " << patientList[prt.front()].getlastName() << "\n";
                prt.pop();
              }
              possibleDoc.pop();
            }
          }
          tempDoctor.getpatientIDList();
          break;
        }
        else if (choice == 2)
        {
          int DoctorID;
          cout << "Please enter doctor's ID:";
          cin >> DoctorID;
          queue<int> prt = doctorList[DoctorID].getpatientIDList();
          int qsize = prt.size();
          cout << "Names: ";
          for (int i = 0; i < qsize; i++)
          {
            cout << patientList[prt.front()].getfirstName() 
              << " " << patientList[prt.front()].getlastName() << "\n";
            prt.pop();
          }
          break;
        }
        cout << endl << "Please enter a valid choice." << endl;
      }
      break;
    }
    case 'I':
    case 'i':
    {
      string tempstr;
      int tempInt, tempDocID;
      cout << "Please input patient ID:" << endl;
      cin >> tempInt;
      tempAppointment.setPatient(patientList[tempInt]);
      tempDocID = patientList[tempInt].getAssignedDocID();
      cout << "Please input the time(hour(0-23)):" << endl;
      cin >> tempInt;
      tempAppointment.setTime(tempInt);
      cout << "Please input the day of the month(1-31):" << endl;
      cin >> tempInt;
      tempAppointment.setDay(tempInt);
      cout << "Please input the month(1-12):" << endl;
      cin >> tempInt;
      tempAppointment.setMonth(tempInt);
      cout << "Please input the year:" << endl;
      cin >> tempInt;
      tempAppointment.setYear(tempInt);
      doctorList[tempDocID].addAppointment(tempAppointment);
      break;
    }
    case 'J':
    case 'j':
    {
      int tempDocID, qsize;
      cout << "Which doctor's appointments would you like(ID): ";
      cin >> tempDocID;
      queue<Appointment> prnt = doctorList[tempDocID].getAppointmentList();
      qsize = prnt.size();
      for (int i = 0; i < qsize; i++)
      {
        cout << "Patient Name: " << prnt.front().getPatient().getfirstName()
          << " " << prnt.front().getPatient().getlastName() << "\n"
          << "Day/Month/Year: " << prnt.front().getDay() << "/"
          << prnt.front().getMonth() << "/" << prnt.front().getYear() << "\n"
          << "At time: " << prnt.front().getTime() << "\n";
        prnt.pop();
      }
      break;
    }
    case 'Q':
    case 'q':
      return 0;
    }
  } while (answer != 'Q');
  return 0;
}

void sortedByLastName(AssociativeArray<int, Patient> a)
{
  string* name = new string[a.size()];
  queue<int> names = a.keys();
  queue<Patient> ret;
  for (int i = 0; i < a.size(); i++)
  {
    name[i] = a[names.front()].getlastName();
    names.pop();
  }
  for (int i = 0; i < a.size(); i++)
    for (int j = i + 1; j < a.size(); j++)
      if (name[i] > name[j])
        swap(name[i], name[j]);

  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < a.size(); j++)
    {
      if (name[i] == "")
        break;
      if (a[j].getlastName() == name[i])
        ret.push(a[j]);
    }
  delete[] name;
  long size = ret.size();
  Patient tempP;
  int* ids = new int[ret.size()];
  bool alreadyPrinted = false;
  for (int i = 0; i < size; i++)
  {
    tempP = ret.front();
    alreadyPrinted = false;
    for (int j = 0; j < size; j++)
    {
      if (tempP.getPatientNumber() == ids[j])
        alreadyPrinted = true;
    }
    if (alreadyPrinted)
      continue;
    cout << "Last Name: " << tempP.getlastName() << "\t\t";
    cout << "First Name: " << tempP.getfirstName() << "\t\t";
    cout << "ID: " << tempP.getPatientNumber() << "\t\t";
    ids[i] = tempP.getPatientNumber();
    cout << "Age: " << tempP.getAge() << "\t\t";
    cout << "Height: " << tempP.getHeight() << "\t\t";
    cout << "Weight: " << tempP.getWeight() << "\t\t";
    cout << "Assigned Doctor ID: " << tempP.getAssignedDocID() << "\n";
    ret.pop();
  }
}
void sortedByIDNumber(AssociativeArray<int, Patient> a)
{
  int* IDs = new int[a.size()];
  queue<int> IDfrom = a.keys();
  queue<Patient> ret;
  for (int i = 0; i < a.size(); i++)
  {
    IDs[i] = IDfrom.front();
    IDfrom.pop();
  }
  for (int i = 0; i < a.size(); i++)
    for (int j = i + 1; j < a.size(); j++)
      if (IDs[i] > IDs[j])
        swap(IDs[i], IDs[j]);
  for (int i = 0; i < a.size(); i++)
    ret.push(a[IDs[i]]);
  delete[] IDs;
  long size = ret.size();
  Patient tempP;
  for (int i = 0; i < size; i++)
  {
    tempP = ret.front();
    cout << "ID: " << tempP.getPatientNumber() << "\t\t";
    cout << "Last Name: " << tempP.getlastName() << "\t\t";
    cout << "First Name: " << tempP.getfirstName() << "\t\t";
    cout << "Age: " << tempP.getAge() << "\t\t";
    cout << "Height: " << tempP.getHeight() << "\t\t";
    cout << "Weight: " << tempP.getWeight() << "\t\t";
    cout << "Assigned Doctor ID: " << tempP.getAssignedDocID() << "\n";
    ret.pop();
  }
}
void sortedByLastName(AssociativeArray<int, Doctor> a)
{
  string* name = new string[a.size()];
  queue<int> names = a.keys();
  queue<Doctor> ret;
  for (int i = 0; i < a.size(); i++)
  {
    name[i] = a[names.front()].getlastName();
    names.pop();
  }
  for (int i = 0; i < a.size(); i++)
    for (int j = i + 1; j < a.size(); j++)
      if (name[i] > name[j])
        swap(name[i], name[j]);

  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < a.size(); j++)
    {
      if (name[i] == "")
        break;
      else if (a[j].getlastName() == name[i])
        ret.push(a[j]);
    }
  delete[] name;
  long size = ret.size();
  Doctor tempD;
  int* ids = new int[ret.size()];
  bool alreadyPrinted = false;
  for (int i = 0; i < size; i++)
  {
    tempD = ret.front();
    alreadyPrinted = false;
    for (int j = 0; j < size; j++)
    {
      if (tempD.getDoctorNumber() == ids[j])
        alreadyPrinted = true;
    }
    if (alreadyPrinted)
      continue;
    cout << "Last Name: " << tempD.getlastName() << "\t\t";
    cout << "First Name: " << tempD.getfirstName() << "\t\t";
    cout << "ID: " << tempD.getDoctorNumber() << "\n";
    ids[i] = tempD.getDoctorNumber();
    ret.pop();
  }
}
void sortedByIDNumber(AssociativeArray<int, Doctor> a)
{
  int* IDs = new int[a.size()];
  queue<int> IDfrom = a.keys();
  queue<Doctor> ret;
  for (int i = 0; i < a.size(); i++)
  {
    IDs[i] = IDfrom.front();
    IDfrom.pop();
  }
  for (int i = 0; i < a.size(); i++)
    for (int j = i + 1; j < a.size(); j++)
      if (IDs[i] > IDs[j])
        swap(IDs[i], IDs[j]);
  for (int i = 0; i < a.size(); i++)
    ret.push(a[IDs[i]]);
  delete[] IDs;
  long size = ret.size();
  Doctor tempD;
  for (int i = 0; i < (size); i++)
  {
    tempD = ret.front();
    cout << "ID: " << tempD.getDoctorNumber() << "\t\t";
    cout << "Last Name: " << tempD.getlastName() << "\t\t";
    cout << "First Name: " << tempD.getfirstName() << "\n";
    ret.pop();
  }
}
void findByLastName(AssociativeArray<int, Patient> a, string key)
{
  string* name = new string[a.size()];
  queue<int> names = a.keys();
  queue<Patient> ret;
  for (int i = 0; i < a.size(); i++)
  {
    name[i] = a[names.front()].getfirstName();
    names.pop();
  }
  for (int i = 0; i < a.size(); i++)
    for (int j = i + 1; j < a.size(); j++)
      if (name[i] > name[j])
        swap(name[i], name[j]);

  for (int j = 0; j < a.size(); j++)
  {
    if (a[j].getlastName() == key)
      ret.push(a[j]);
  }

  delete[] name;
  long size = ret.size();
  Patient tempP;
  for (int i = 0; i < size; i++)
  {
    tempP = ret.front();
    if (tempP.getlastName() != key)
    {
      ret.pop();
      continue;
    }
    cout << "ID: " << tempP.getPatientNumber() << "\t\t";
    cout << "Last Name: " << tempP.getlastName() << "\t\t";
    cout << "First Name: " << tempP.getfirstName() << "\t\t";
    cout << "Age: " << tempP.getAge() << "\t\t";
    cout << "Height: " << tempP.getHeight() << "\t\t";
    cout << "Weight: " << tempP.getWeight() << "\t\t";
    cout << "Assigned Doctor ID: " << tempP.getAssignedDocID() << "\n";
    ret.pop();
  }

}
void findByID(AssociativeArray<int, Patient> a, int key)
{
  int* IDs = new int[a.size()];
  queue<int> IDfrom = a.keys();
  queue<Patient> ret;
  for (int i = 0; i < a.size(); i++)
  {
    IDs[i] = IDfrom.front();
    IDfrom.pop();
  }
  for (int i = 0; i < a.size(); i++)
    if (IDs[i] == key)
      ret.push(a[IDs[i]]);
  delete[] IDs;
  Patient tempP;
  tempP = ret.front();
  cout << "ID: " << tempP.getPatientNumber() << "\t\t";
  cout << "Last Name: " << tempP.getlastName() << "\t\t";
  cout << "First Name: " << tempP.getfirstName() << "\t\t";
  cout << "Age: " << tempP.getAge() << "\t\t";
  cout << "Height: " << tempP.getHeight() << "\t\t";
  cout << "Weight: " << tempP.getWeight() << "\t\t";
  cout << "Assigned Doctor ID: " << tempP.getAssignedDocID() << "\n";
  ret.pop();
}
