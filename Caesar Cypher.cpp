
#include <iostream>
#include <string>
#include "Cypher.h"
using namespace std;

int main()
{
    string strChoice;
    string message = "";
    Cypher cypher;
    vector<string> decodedPossibilities;

    do {
        cout << "\t\t\tCaeser Cypher\n\n"
            << "\t1. Encode\n"
            << "\t2. Decode\n"
            << "\t3. Exit\n\n"
            << "Select a menu option: ";
        getline(cin, strChoice);

        if (strChoice == "1")
        {
            cout << "Enter a message to encode: ";
            getline(cin, message);

            message = cypher.Encode(message);
            cout << message << endl;
        }
        else if (strChoice == "2" && message == "")
        {
            cout << "Enter a message to decode: ";
            getline(cin, message);

            decodedPossibilities = cypher.Decode(message);
            for (int index = 0; index < decodedPossibilities.size(); index++)
            {
                cout << decodedPossibilities.at(index) << endl;
            }
        }
        else if (strChoice == "2" && message != "")
        {
            cout << "Decoding last encoded message " + message + ":\n\n";

            decodedPossibilities = cypher.Decode(message);
            for (int index = 0; index < decodedPossibilities.size(); index++)
            {
                cout << decodedPossibilities.at(index) << endl;
            }
        }
        else if (strChoice == "3")
        {
            return 0;
        }
        else 
        {
            cout << "Invalid choice. Chose 1 or 2.";
        }

    } while (strChoice != "1" || strChoice != "2");

    return 0;
}
