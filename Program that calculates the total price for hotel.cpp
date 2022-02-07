#include <iostream>
#include <new>
#include <cstring>
using namespace std;
struct room {
    double room_id;
    string type;
    double price;
   // int n_rooms;
};
struct customer {
    string customer_name;
    double room_id;
    double number_nights;
};

//const int SIZE = 3;
int main() {
    room* rooms;
    customer* customers;
    int  tot_room;
    int tol_cust_sp;
    cout << "Enter the number of rooms:\n";
    cin >> tot_room;
    cout << "Enter the total customers:\n";
    cin >> tol_cust_sp;
    int i;
    try {

        rooms = new room[tot_room];
        customers = new customer[tol_cust_sp];

    }
    catch (bad_alloc& xa) {
        cout << "Memory allocation Failed!";
        return 1;
    }

    for (int i = 0; i < tot_room; i++)
    {
        cout << "Enter the room id:\n";
        cin >> rooms[i].room_id, '\n';
        cout << "Enter the type of the room:\n";
        cin >> rooms[i].type, '\n';
        cout << "Enter the price of the room (in Euros):\n";
        cin >> rooms[i].price, '\n';
        cout << "-X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X-";
        cout << endl << endl;
    }
    cout << "Available room Ids are:\n";
    for (int i = 0; i < tot_room; i++)
    {
       
        cout << rooms[i].room_id<<"("<< rooms[i].type<< ")\t";
        cout << endl << endl;
     
    }
    cout << "-X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X-" << endl;
   
    
    for (int i = 0; i < tol_cust_sp; i++)
    {
        cout << "Enter the customer name:\n";
        cin >> customers[i].customer_name, '\n';
        cout << "Enter the room id for customer:\n";
        cin >> customers[i].room_id, '\n';
        cout << "Enter the nights booked by customer:\n";
        cin >> customers[i].number_nights, '\n';
        cout << "-X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X--X-";
        cout << endl << endl;
    }
    cout << "The room_ids with customer_information is:"<<endl;
    for (int i = 0; i < tol_cust_sp; i++)
    {
        cout << "room_id" << "\t" << "\t" << "customer name" << "\t" << "\t" << "number of nights" << "\t" << "\t" << "\t" << "price 1 night (in Euros)  : \n";
        cout << customers[i].room_id << "\t" << "\t" << customers[i].customer_name << "\t" << "\t" << "\t" << customers[i].number_nights << "\t" << "\t" << "\t";
        for (int x = 0; x < tot_room; x++)
        {
            if (customers[i].room_id == rooms[x].room_id)
            {
                cout << "\t" << "\t" << "\t"<< rooms[x].price;
                cout << endl << endl;

            }
            else
                continue;
        }
    }

       
       rooms = NULL;
       customers = NULL;
       delete[] rooms;
       delete[] customers;
       return 0;
    }
