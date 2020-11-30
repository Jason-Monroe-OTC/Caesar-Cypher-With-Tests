#pragma once

#include <iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;

class Cypher 
{

    public:
        string Encode(string message)
        {
            string encodedMessage;
            srand(time(0));
            int randNum = rand() % 25 + 1;
            char c;

            for (int n = 0; n < message.length(); n++)
            {
                if (isalpha(message.at(n)))
                {
                    c = toupper(message.at(n));
                    c = (((c + 65) + randNum) % 26) + 65;
                }
                else
                {
                    c = message.at(n);
                }
                encodedMessage += c;
            }
            return encodedMessage;
        }

        vector<string> Decode(string codedMessage)
        {
            vector<string> decodedMessages;
            string decodePossibility;
            char c;

            for (int shiftNumber = 1; shiftNumber < 25; shiftNumber++)
            {
                decodePossibility = "";
                for (int letterIndex = 0; letterIndex < codedMessage.length(); letterIndex++)
                {
                    if (isalpha(codedMessage.at(letterIndex)))
                    {
                        c = toupper(codedMessage.at(letterIndex));
                        c = (((c + 65) + shiftNumber) % 26) + 65;
                    }
                    else
                    {
                        c = codedMessage.at(letterIndex);
                    }
                    decodePossibility += c;
                }
                decodedMessages.push_back(decodePossibility);
            }

            return decodedMessages;

        }

};





