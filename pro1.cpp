#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define NUM_CITIES 15
#define INFINITY_COST 999999999

using namespace std;

struct Store
{
    long long int cost[NUM_CITIES];
    int array[NUM_CITIES];
};

struct InitialData
{
    long long int cost[NUM_CITIES];
};

class DataModule
{
public:
    string city[NUM_CITIES];

    DataModule() : city{"Delhi", "Mumbai", "Chennai", "Kolkata", "Kerala", "Hyderabad", "Pune", "Goa", "Bangalore",
                            "Amritsar", "Jaipur", "Patna", "Puducherry", "Srinagar", "Bhopal"} {}

    void CostDeclaration(Store travel[], InitialData ini[])
    {
        int N = NUM_CITIES;

        long long int arr[NUM_CITIES][NUM_CITIES] =
        {
            {
                0, 3500, 2000, INFINITY_COST, 1000, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, 7000, 4000,
                1500, INFINITY_COST, 6500, INFINITY_COST
            },
            {
                3500, 0, INFINITY_COST, 1520, INFINITY_COST, INFINITY_COST, INFINITY_COST, 2500, INFINITY_COST, INFINITY_COST,
                INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, 5000
            },
            {
                2000, INFINITY_COST, 0, 1500, INFINITY_COST, 3000, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST,
                2000, 1000, INFINITY_COST, INFINITY_COST, 1500
            },
            {
                INFINITY_COST, 1520, 1500, 0, INFINITY_COST, 1200, 4500, INFINITY_COST, 6000, INFINITY_COST, INFINITY_COST,
                INFINITY_COST, INFINITY_COST, INFINITY_COST, 1000
            },
            {
                1000, INFINITY_COST, INFINITY_COST, INFINITY_COST, 0, 1500, INFINITY_COST, INFINITY_COST, INFINITY_COST,
                INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST
            },
            {
                INFINITY_COST, INFINITY_COST, 3000, 1200, 1500, 0, 1950, INFINITY_COST, INFINITY_COST, INFINITY_COST,
                INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST
            },
            {
                INFINITY_COST, INFINITY_COST, INFINITY_COST, 4500, INFINITY_COST, 1950, 0, INFINITY_COST, INFINITY_COST,
                2050, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST
            },
            {
                INFINITY_COST, 2500, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, 0, 5000,
                INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST
            },
            {
                INFINITY_COST, INFINITY_COST, INFINITY_COST, 6000, INFINITY_COST, INFINITY_COST, INFINITY_COST, 5000, 0,
                7000, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST
            },
            {
                7000, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, 2050, INFINITY_COST, 7000, 0,
                INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST
            },
            {
                4000, INFINITY_COST, 2000, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST,
                INFINITY_COST, INFINITY_COST, 0, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST
            },
            {
                1500, INFINITY_COST, 1000, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST,
                INFINITY_COST, INFINITY_COST, INFINITY_COST, 0, INFINITY_COST, INFINITY_COST, INFINITY_COST
            },
            {
                INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST,
                INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, 0, INFINITY_COST, INFINITY_COST
            },
            {
                6500, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST,
                INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, 0, INFINITY_COST
            },
            {
                INFINITY_COST, 5000, 1500, 1000, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST,
                INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, INFINITY_COST, 0
            }
        };

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                travel[i].cost[j] = arr[i][j];
                travel[i].array[j] = j;
                ini[i].cost[j] = arr[i][j];
            }
        }
    }
};

class BellmanFordAlgorithm : public DataModule
{
public:
    void AlgorithmicImplementation(Store travel[])
    {
        int N = NUM_CITIES;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    if (travel[i].cost[j] > travel[i].cost[k] + travel[k].cost[j])
                    {
                        travel[i].cost[j] = travel[i].cost[k] + travel[k].cost[j];
                        travel[i].array[j] = k;
                    }
                }
            }
        }
    }
};

class FileHandlingModule
{
public:
    string username1, password1;

    bool LogIn(string username, string password)
    {
        ifstream fileRead;
        fileRead.open("login.txt");
        while (fileRead >> username1 >> password1)
        {
            if ((username == username1) && (password == password1))
            {
                cout << endl << "Account Login Successful..." << endl;
                return true;
            }
        }
        cout << endl << "Account Login Failed..." << endl;
        return false;
    }

    void CreateAccount(string username, string password)
    {
        ofstream fileWrite;
        fileWrite.open("login.txt", ios::app);
        fileWrite << username << " " << password << "\n";
        fileWrite.close();
        cout << endl << "Account Created..." << endl;
    }

    void Ticket(string username, string firstname[], string lastname[], string sex[], int age[], int no)
    {
        ofstream fileWrite;
        fileWrite.open("ticket.txt", ios::app);
        for (int i = 0; i < no; i++)
        {
            fileWrite << username << " " << firstname[i] << " " << lastname[i] << " " << sex[i] << " " << age[i] << "\n";
        }
        fileWrite.close();
    }
};

class InputModule
{
public:
    string source, destination;
    string username, password;

    void UserInput(string userChoice[])
    {
        system("CLS");
        cout << "\n\n**************************** Welcome to Travel Management System ****************************" << endl;
        cout << endl;
        cout << "*****************************************" << endl;
        cout << "Enter Your City:";
        cin >> source;
        cout << "*****************************************" << endl;
        cout << "Enter Your Destination:";
        cin >> destination;
        cout << "*****************************************" << endl;
        userChoice[0] = source;
        userChoice[1] = destination;
    }

    string Login()
    {
        while (1)
        {
            cout << "\n\n**************************** Welcome to Travel Management System ****************************" << endl;
            cout << "\n\n\n\n";
            cout << "ENTER" << endl;
            cout << "*****************************************" << endl;
            cout << "****   1. To Login                  *****" << endl;
            cout << "*****************************************" << endl;
            cout << "****   2. To Create New Account     ****" << endl;
            cout << "*****************************************" << endl;
            cout << "\nEnter Your Choice:";
            int choice;
            bool result;
            FileHandlingModule fileObj;

            cin >> choice;
            switch (choice)
            {
            case 1:
                system("CLS");
                cout << "\n\n**************************** Welcome to Travel Management System ****************************" << endl;
                cout << endl;
                cout << "*****************************************" << endl;
                cout << "Enter Username:";
                cin >> username;
                cout << "*****************************************" << endl;
                cout << "Enter Your Password:";
                cin >> password;
                cout << "*****************************************" << endl;
                result = fileObj.LogIn(username, password);
                break;
            case 2:
                system("CLS");
                cout << "\n\n**************************** Welcome to Travel Management System ****************************" << endl;
                cout << endl;
                cout << "*****************************************" << endl;
                cout << "Enter Username:";
                cin >> username;
                cout << "*****************************************" << endl;
                cout << "Enter Your Password:";
                cin >> password;
                cout << "*****************************************" << endl;
                fileObj.CreateAccount(username, password);
                break;
            }
            if (result == true)
                return username;
        }
    }

    int NoOfPassenger()
    {
        int no;
        cout << endl << "Enter the no of passengers:";
        cin >> no;
        return no;
    }
};

class OutputModule
{
public:
    string source, destination;

    void Initial()
    {
        system("CLS");
        cout << "\n\n**************************** Welcome to Travel Management System ****************************" << endl;
        cout << "\n\n";
        cout << "***************************" << endl;
        cout << "*  Facilities Available:  *" << endl;
        cout << "***************************" << endl;
        cout << "\n\n";
        cout << "ENTER" << endl;
        cout << "*****************************************" << endl;
        cout << "****   1. To Display List of Cities  ****" << endl;
        cout << "*****************************************" << endl;
        cout << "****   2. To Book Ticket             ****" << endl;
        cout << "*****************************************" << endl;
    }

    void ListCities(int N)
    {
        DataModule o;
        cout << endl;
        system("CLS");
        cout << "\n\n**************************** Welcome to Travel Management System ****************************" << endl;
        cout << "\n\n";
        cout << "The listed cities are:" << endl;
        cout << "*****************************************" << endl;
        for (int i = 0; i < N; i++)
        {
            cout << "*          " << o.city[i] << "            " << endl;
            cout << "*" << endl;
        }
        cout << "*****************************************" << endl;
    }

    void Ticket(int totalPrice, int no, string source, string destination, string username)
    {
        system("CLS");
        cout << "\n\n**************************** E-TICKET ****************************" << endl;
        cout << endl << "This Ticket is issued for: " << username << endl;
        cout << endl << "Source: " << source << endl;
        cout << endl << "Destination: " << destination << endl;
        cout << endl << "Total No of Passengers: " << no << endl;
        cout << endl << "Total Cost: " << totalPrice << endl;
        cout << "\n****************************************************************************" << endl;
    }

    void PassengerDetailedTicket(int no, string firstname[], string lastname[], string sex[], int age[])
    {
        for (int i = 0; i < no; i++)
        {
            cout << "Passenger " << (i + 1) << " Details:" << endl << endl;
            cout << "First Name: " << firstname[i] << endl;
            cout << "Last Name: " << lastname[i] << endl;
            cout << "Sex: " << sex[i] << endl;
            cout << "Age: " << age[i] << endl;
            cout << "\n****************************************************************************" << endl;
        }
        int ch;
        cout << endl << "Enter 1 to continue:";
        cin >> ch;
        if (ch == 1)
        {
            Initial();
        }
    }

    int DisplayPrice(string source, string destination, int N, string username, Store travel[], InitialData ini[])
    {
        source = source;
        destination = destination;
        DataModule o;
        InputModule in;
        int i, j, choiceOfPassenger;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (source == o.city[i] && destination == o.city[j])
                {
                    cout << endl;
                    if (ini[i].cost[j] == INFINITY_COST)
                    {
                        cout << "There is no direct flight from " << source << " to " << destination
                             << ". So, travel via other cities is only possible." << endl;
                        cout << "The Price is: " << travel[i].cost[j] << endl << endl;
                        cout << "The Route is: " << source;
                        int c1 = i, c2 = j;
                        while (c1 != c2)
                        {
                            cout << "-->" << o.city[travel[c1].array[j]];
                            c1 = travel[c1].array[j];
                        }
                        cout << endl << endl;
                    }
                    else if ((ini[i].cost[j] != INFINITY_COST) && (ini[i].cost[j] == travel[i].cost[j]))
                    {
                        cout << "There is a direct flight available from " << source << " to " << destination
                             << " and it is the cheapest among all other paths..." << endl;
                        cout << "The Price is: " << travel[i].cost[j] << endl;
                    }
                    else if ((ini[i].cost[j] != INFINITY_COST) && (ini[i].cost[j] > travel[i].cost[j]))
                    {
                        cout << "There is a direct flight available from " << source << " to " << destination << "."
                             << endl;
                        cout << "The Price is: " << ini[i].cost[j] << endl << endl;
                        cout << "*****************************************" << endl << endl;
                        cout << "You can go via other cities that will cost you less than a direct flight." << endl;
                        cout << "The Price is: " << travel[i].cost[j] << endl << endl;
                        cout << "The Route is: " << source;
                        int c1 = i, c2 = j;
                        while (c1 != c2)
                        {
                            cout << "-->" << o.city[travel[c1].array[j]];
                            c1 = travel[c1].array[j];
                        }
                        cout << endl << endl;
                        cout << "Press 1 to go by direct flight and Press 2 to go via other cities: ";
                        cin >> choiceOfPassenger;
                    }
                    char c;
                    cout << endl;
                    cout << "Do You want to Continue(Y/N)?";
                    cin >> c;
                    if (c == 'Y')
                    {
                        int no = in.NoOfPassenger();
                        string firstname[no], lastname[no], sex[no];
                        int age[no];
                        for (int i = 0; i < no; i++)
                        {
                            cout << endl;
                            cout << "*****************************************" << endl;
                            cout << "Passenger " << (i + 1) << ":" << endl << endl;
                            cout << "First Name:";
                            cin >> firstname[i];
                            cout << endl << "Last Name:";
                            cin >> lastname[i];
                            cout << endl << "Sex(Male/Female/Other):";
                            cin >> sex[i];
                            cout << endl << "Age:";
                            cin >> age[i];
                        }
                        int totalPrice;
                        if (choiceOfPassenger == 1)
                        {
                            totalPrice = no * ini[i].cost[j];
                        }
                        else
                        {
                            totalPrice = no * travel[i].cost[j];
                        }
                        cout << endl << "The total Price is: " << totalPrice << endl;
                        char y;
                        cout << "Do You want to confirm Your Ticket(Y/N)?";
                        cin >> y;
                        if (y == 'Y')
                        {
                            FileHandlingModule f;
                            f.Ticket(username, firstname, lastname, sex, age, no);
                            Ticket(totalPrice, no, source, destination, username);
                            PassengerDetailedTicket(no, firstname, lastname, sex, age);
                        }
                        else
                        {
                            cout << endl << "Thank You For choosing Us..." << endl;
                            cout << endl << "Do You Want to Continue(Y/N)?";
                            char ch;
                            cin >> ch;
                            if (ch == 'Y')
                            {
                                Initial();
                            }
                            return 0;
                        }
                    }
                    else
                    {
                        cout << endl << "Thank You For choosing Us..." << endl;
                        cout << endl << "Do You Want to Continue(Y/N)?";
                        char ch;
                        cin >> ch;
                        if (ch == 'Y')
                        {
                            Initial();
                        }
                        return 0;
                    }
                    return 0;
                }
            }
        }
        cout << "Sorry, There are no flights available connecting the cities..." << endl;
        cout << endl << "Do You Want to Continue(Y/N)?";
        char ch;
        cin >> ch;
        if (ch == 'Y')
        {
            Initial();
        }
        return 0;
    }
};

int main()
{
    int N = NUM_CITIES;

    Store travel[N];
    InitialData ini[N];

    DataModule obj;
    obj.CostDeclaration(travel, ini);

    BellmanFordAlgorithm ob;
    ob.AlgorithmicImplementation(travel);

    string userChoice[2];

    InputModule obj1;
    string username;
    username = obj1.Login();

    OutputModule object;
    object.Initial();

    while (1)
    {
        int choice;
        cout << "\nEnter Your Choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            object.ListCities(N);
            cout << "\nPress 1 to Continue...";
            int cont;
            cin >> cont;
            if (cont == 1)
            {
                object.Initial();
            }
            break;
        case 2:
            obj1.UserInput(userChoice);
            object.DisplayPrice(userChoice[0], userChoice[1], N, username, travel, ini);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}

