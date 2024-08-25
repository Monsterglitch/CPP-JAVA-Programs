#include <bits/stdc++.h>

using namespace std;

// Passenger Class
class Passenger
{
public:
    static int id;
    int passengerId, passengerAge, seatNumber;
    char passengerGender;
    string preferredBerth, allotted, passengerName;

    Passenger() : passengerId(-1), passengerAge(0), seatNumber(-1), passengerGender(' '), preferredBerth(""), allotted("-"), passengerName("") {}

    Passenger(int age, string name, char gender, string berth)
    {
        passengerId = id++;
        passengerName = name;
        preferredBerth = berth;
        passengerAge = age;
        passengerGender = gender;
        allotted = "~~";
        seatNumber = -1;
    }
};
int Passenger::id = 1;

// Global declarations
unordered_map<int, Passenger> mp;
list<int> bookedPassengers;
int lowerBerthsCount = 1, middleBerthsCount = 1, upperBerthsCount = 1, racTickets = 1, waitingListTickets = 1;
queue<int> racPassengers, waitingListPassengers, lowerBerths, middleBerths, upperBerths, racPositions, waitingListPositions;

// Printing Ticket
void printTicket(Passenger& p, string Type = "None")
{
    cout << "~~~~~~~~~~TICKET~~~~~~~~~~" << endl
         << "Your Name: " << p.passengerName << endl
         << "Your Age: " << p.passengerAge << endl
         << "Your Gender: " << p.passengerGender << endl
         << "Your Ticket Id (Kindly note this down somewhere safe): " << p.passengerId << endl;

    if (Type == "RAC")
        cout << "You are in RAC" << endl;
    else if (Type == "Waiting List")
        cout << "You are in Waiting List" << endl;
    else
        cout << "Your Seat Number: " << p.allotted << p.seatNumber << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

// Booker Class
class Booker
{
private:

public:
    Booker ()
    {
        // Initial Tickets
        // for (int i = 1; i <= 10; ++i)
        // {
        //     lowerBerths.push(i);
        //     middleBerths.push(i);
        //     upperBerths.push(i);
        //     if (i < 5)
        //     {
        //         racPositions.push(i);
        //         waitingListPositions.push(i);
        //     }
        // }
        lowerBerths.push(1);
        middleBerths.push(1);
        upperBerths.push(1);
        racPositions.push(1);
        waitingListPositions.push(1);
    }
    void bookTicket(Passenger& p)
    {
        if (waitingListTickets == 0)
        {
            cout << "Sorry, No Tickets Available" << endl;
            return;
        }
        if ((p.preferredBerth == "L" && lowerBerthsCount > 0) || (p.preferredBerth == "M" && middleBerthsCount > 0) || (p.preferredBerth == "U" && upperBerthsCount > 0))
        {
            cout << "Preferred Berth available ..." << endl;
            if (p.preferredBerth == "L")
            {
                p.seatNumber = lowerBerths.front();
                lowerBerths.pop();
                lowerBerthsCount -= 1;
                p.allotted = "L";
            }
            else if (p.preferredBerth == "M")
            {
                p.seatNumber = middleBerths.front();
                middleBerths.pop();
                middleBerthsCount -= 1;
                p.allotted = "M";
            }
            else if (p.preferredBerth == "U")
            {
                p.seatNumber = upperBerths.front();
                upperBerths.pop();
                upperBerthsCount -= 1;
                p.allotted = "U";
            }
            mp[p.passengerId] = p;
            bookedPassengers.push_back(p.passengerId);
            cout << "Ticket Booked Successfully!!" << endl;
            printTicket(p);
            return;
        }

        // Assign berth if preferred not available
        cout << "Oops, Preferred Berth not available ..." << endl
            << "Assigning Available Berth ..." << endl;
        if (lowerBerthsCount > 0)
        {
            p.seatNumber = lowerBerths.front();
            lowerBerths.pop();
            lowerBerthsCount -= 1;
            p.allotted = "L";
            bookedPassengers.push_back(p.passengerId);
        }
        else if (middleBerthsCount > 0)
        {
            p.seatNumber = middleBerths.front();
            middleBerths.pop();
            middleBerthsCount -= 1;
            p.allotted = "M";
            bookedPassengers.push_back(p.passengerId);
        }
        else if (upperBerthsCount > 0)
        {
            p.seatNumber = upperBerths.front();
            upperBerths.pop();
            upperBerthsCount -= 1;
            p.allotted = "U";
            bookedPassengers.push_back(p.passengerId);
        }
        else
        {
            string Type = "";
            if (racTickets > 0)
            {
                p.seatNumber = racPositions.front();
                racPositions.pop();
                racTickets -= 1;
                Type = "RAC";
                p.allotted = Type;
                racPassengers.push(p.passengerId);
                cout << "You've been added to RAC successfully ..." << endl;
            }
            else if (waitingListTickets > 0)
            {
                p.seatNumber = waitingListPositions.front();
                waitingListPositions.pop();
                waitingListTickets -= 1;
                Type = "Waiting List";
                p.allotted = Type;
                waitingListPassengers.push(p.passengerId);
                cout << "You've been added to WAITING LIST successfully ..." << endl;
            }
            mp[p.passengerId] = p;
            printTicket(p, Type);
            return;
        }
        mp[p.passengerId] = p;
        printTicket(p);
    }
    void cancelTicket(int id)
    {
        Passenger cancellingPassenger = mp[id];
        mp.erase(id);
        bookedPassengers.remove(id);
        int bookedPosition = cancellingPassenger.seatNumber;
        cout<<"Ticket Cancelled Successfully ..."<<endl;
        if (cancellingPassenger.allotted == "L")
        {
            lowerBerthsCount += 1;
            lowerBerths.push(bookedPosition);
        }
        else if (cancellingPassenger.allotted == "M")
        {
            middleBerthsCount += 1;
            middleBerths.push(bookedPosition);
        }
        else if (cancellingPassenger.allotted == "U")
        {
            upperBerthsCount += 1;
            upperBerths.push(bookedPosition);
        }
        if (racPassengers.size() > 0)
        {
            // Removing passenger from racPositions and map
            Passenger& passengerFromRac = mp[racPassengers.front()];
            mp.erase(passengerFromRac.id);
            racPassengers.pop();
            racTickets += 1;

            if (waitingListPassengers.size() > 0)
            {
                Passenger& passengerFromWaitingList = mp[waitingListPassengers.front()];
                mp.erase(passengerFromWaitingList.id);
                waitingListPassengers.pop();
                waitingListTickets += 1;

                racPassengers.push(passengerFromWaitingList.id);
                passengerFromWaitingList.allotted = "RAC";
                mp[passengerFromWaitingList.id] = passengerFromWaitingList;
                racTickets -= 1;
            }

            bookTicket(passengerFromRac);
        }

    }
    void availableSpots()
    {
        cout<<"Available Lower Berths: "<<lowerBerthsCount<<endl
            <<"Available Middle Berths: "<<middleBerthsCount<<endl
            <<"Available Upper Berths: "<<upperBerthsCount<<endl
            <<"Available RACs: "<<racTickets<<endl
            <<"Available Waiting Lists: "<<waitingListTickets<<endl;
    }
    void printAllPasengers()
    {
        if (mp.size() == 0)
        {
            cout<<"Details of passengers is unavailable"<<endl;
        }
        else
        {
            for (auto itr = mp.begin(); itr != mp.end(); ++itr)
            {
                printTicket(itr->second, itr->second.allotted);
            }
        }
    }
};

// Driver Code
int main()
{
    Booker B;
    bool loop = true;
    do
    {
        int choice;
        cout<<"~~~~~~~~~~WELCOME~~~~~~~~~~"<<endl;
        cout<<"Enter your choice"<<endl
            <<"(1) Book Ticket: "<<endl
            <<"(2) Cancel Ticket: "<<endl
            <<"(3) Print Available Spots: "<<endl
            <<"(4) Print your Ticket: "<<endl
            <<"(5) Print Passenger Details: "<<endl
            <<"(6) Exit: "<<endl<<">";
        cin>>choice;
        switch (choice)
        {
            case 1:
            {
                int age;
                char gender;
                string name, berth;
                cout<<"Enter your name: ";
                cin>>name;
                cout<<"Enter your age: ";
                cin>>age;
                cout<<"Enter your gender: ";
                cin>>gender;
                cout<<"Enter preferred berth (L -> Lower, M -> Middle, U -> Upper): ";
                cin>>berth;
                Passenger p(age, name, gender, berth);
                B.bookTicket(p);
                break;
            }
            case 2:
            {
                int id;
                cout<<"Enter your id: ";
                cin>>id;
                if (mp.find(id) != mp.end())
                {
                    B.cancelTicket(id);
                }
                else
                {
                    cout<<"Passenger detail unknown"<<endl;
                }
                break;
            }
            case 3:
            {
                B.availableSpots();
                break;
            }
            case 4:
            {
                int currId;
                cout<<"Enter your id: ";
                cin>>currId;
                Passenger& currentPassenger = mp[currId];
                printTicket(currentPassenger, currentPassenger.allotted);
                break;
            }
            case 5:
            {
                B.printAllPasengers();
                break;
            }
            case 6:
            {
                loop = false;
                break;
            }
            default:
                cout<<"Enter valid option"<<endl;
                break;
        }
    } while(loop != false);
    cout<<"~~~~~~~~~~THANK YOU~~~~~~~~~~"<<endl;
    return 0;
}