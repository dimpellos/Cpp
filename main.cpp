#include <iostream>
#include <string>
#include <deque>
#include <limits>

const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;

using namespace std;

struct Patient{
    short specialization;
    string name;
    bool status; //0=regular, 1=urgent

    Patient(short speciali, string nam, bool statu)
    {
        specialization = speciali;
        name = nam;
        status = statu;
    }
};

class IFHospital {

    public:
        static deque<Patient> specializations[MAX_SPECIALIZATION];
        static int doctors[MAX_SPECIALIZATION];//0=available, 1=occupied

        static void printPatients() {
            for (int i=0;i<MAX_SPECIALIZATION;++i)
            {
                if (specializations[i].size() > 0)
                {
                    cout << "Specialization No" << i << endl;
                    for(Patient p1 : specializations[i])
                    {
                        cout << "Name: " << p1.name << " Status:" << p1.status << endl;
                    }
                }
                cout << endl;
            }
        }

        static void addPatient(const Patient & p) {
            if (specializations[p.specialization].size() < MAX_QUEUE)
            {
                if(!p.status) {
                    specializations[p.specialization].push_back(p);
                } else {
                    specializations[p.specialization].push_front(p);
                }
            } else {
                cout << "Unfortunately, the specialization is full. Please, try later." << endl;
            }
        }

        static void DrPickupPatient(short speciali) {
            if(specializations[speciali].size() < 1)
            {
                cout << "There are no patients in this queue." << endl << endl;
            } else {
                if(!doctors[speciali])
                {
                    specializations[speciali].pop_front();
                    cout << "Patient served." << endl << endl;
                } else {
                    cout << "Dr. is Occupied. Please, wait.";
                }
            }
        }
    };

    deque<Patient> IFHospital::specializations[MAX_SPECIALIZATION];
    int IFHospital::doctors[MAX_SPECIALIZATION] = {0};




int main()
{
    char option;
    short specialization;
    string name;
    int status;

    do {

        cout << "Provide option 1-4:" << endl;
        cout << "1. Print patients number for each specialization" << endl;
        cout << "2. Add patient" << endl;
        cout << "3. Doctor pickup" << endl;
        cout << "4. Exit" << endl;
        cin >> option;

        switch(option)
        {
            case '1':
                {
                    IFHospital::printPatients();
                    break;
                }

            case '2':
                {
                    cout << "Give patient specialization, name and status." << endl;
                    cin >> specialization;
                    cin >> name;
                    cin >> status;
                    //cin >> specialization >> name >> status;
                    Patient p(specialization, name, status);
                    IFHospital::addPatient(p);
                    break;
                }

            case '3':
                {
                    cout << "Give Doctor specialization." << endl;
                    cin >> specialization;
                    IFHospital::DrPickupPatient(specialization);
                    break;
                }
            default:
                break;
        }

          if (cin.fail())
          {
             cout << "ERROR -- You did not enter an integer";
             cin.clear();
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          }

    } while(option != '4');

    cout << "Leaving Hospital.." << endl;
    return 0;
}
