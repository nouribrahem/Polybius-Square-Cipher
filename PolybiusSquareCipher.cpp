/*
POLYBIUS SQUARE CIPHER
Author: Nourhan Elsayed Hassan, FCAI-CU(faculty of computers and artificial intelligence - cairo university).
Purpose: Encryption and decryption for text programs.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void messageDecipher(string message);
void messageCipher(string message);
char arr[5][5];
string message;
int main() 
{
    int i, j, operation;
    int a = 97;
    j = 0;
    
    while (a <= 122) // while loop appending lowercase alphabets in a 2D array of row number = i, and column number = j.
    {
        i = j/5;
        if (a != 106)
        {
            char alpha = a;
            arr[i][j%5] = alpha;
            j++;
        }
        a++;
    }
    cout << "Hello user! please select the number of operation: 1)Cipher a message, 2)Decipher a message, 3)Exit " << endl;
    cin >> operation; // takes the number of operation chosen by user.
    if (operation == 1) // takes message and calls cipher function.
    {
        cout << "please enter a message you want to cipher" << endl;
        cin.ignore();
        getline(cin, message);
        messageCipher(message);
    }
    else if (operation == 2)  // takes message and calls decipher function.
    {
        cout << "please enter a message you want to cipher" << endl;
        cin.ignore();
        getline(cin, message);
        messageDecipher(message);
    }
    else if (operation == 3) // performs choice"EXIT".
    {
        cout << "THANK YOU" << endl;
        return 0;
    }
    else // tells user if operation number is invalid and takes another input.
    {
        cout << "Invalid input" << endl;
        getline(cin, message);
    }
}

void messageCipher(string message)
{    
    message.erase(remove(message.begin(), message.end(), ' '), message.end()); // removes whitespaces from message.
    for_each(message.begin(), message.end(), [](char & c) // converts characters of message to lowercase.
    {
            c = tolower(c);
         
    });
    for (int n = 0; n <= message.length(); n++) // loops on each index of string(message).
    {
    for (int i = 0; i < 5; i++) // loops on each row of 2D array(arr).
    {
        for (int j = 0; j < 5; j++) // loops on each column of 2D array(arr).
        {
          if (message[n] == arr[i][j]) // checks if a char in message is equal to an element in arr.
          {
            cout << (i+1) << (j+1); // prints row index of element + 1, column index of element + 1.
          }
        }
    }
    } 
}

void messageDecipher(string message)
{
    string deciphered = "";
    for (int i = 0; i < message.length() ; i+=2) // loops on every 2 chars in message.
    {
        int a = message[i] - '0'; // gets row index for element+1.
        int b = message[i+1] - '0'; // gets column index for element+1.
        deciphered += arr[a-1][b -1]; // appends element of [row index][column index] to string(deciphered).
    }
    cout << deciphered << endl; // prints deciphered message.
}