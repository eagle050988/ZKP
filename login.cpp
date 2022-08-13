// Login.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "bigInt/uint256_t.h"

using namespace std;

/// <summary>
/// calculate power
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="p">modulo</param>
/// <returns></returns>
uint256_t power(uint256_t x, uint256_t y, uint256_t p)
{

    uint256_t res = 1;     // Initialize result 


    x = x % p; // Update x if it is more than or 

                // equal to p



    if (x == 0) return 0; // In case x is divisible by p;


    while (y > 0)

    {

        // If y is odd, multiply x with result 

        if (y & 1)

            res = (res * x) % p;


        // y must be even now 

        y = y >> 1; // y = y/2 

        x = (x * x) % p;

    }

    return res;
}

int main()
{
    FILE* fptr;
    //open g file;
    if ((fptr = fopen("server/server values/g64.txt", "r")) == NULL) {
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    // reading line by line, max 256 bytes
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];

    uint256_t g;
    fgets(buffer, MAX_LENGTH, fptr);
    // close the file
    fclose(fptr);

    char* pEnd;
    g = uint256_t(buffer, 10);
    //end proses g file

    //open n file
    if ((fptr = fopen("server/server values/n64.txt", "r")) == NULL) {
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    memset(buffer, 0, sizeof buffer);
    uint256_t n;
    fgets(buffer, MAX_LENGTH, fptr);
    // close the file
    fclose(fptr);
    n = uint256_t(buffer, 10);
    //end proses n file

    //open y file
    if ((fptr = fopen("server/server values/y.txt", "r")) == NULL) {
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    memset(buffer, 0, sizeof buffer);
    uint256_t y;
    fgets(buffer, MAX_LENGTH, fptr);
    // close the file
    fclose(fptr);
    y = uint256_t(buffer, 10);
    //end proses y file

    string user;
    cout << "enter your username: ";
    cin >> user;

    //open A file
    string loc = "server/user data/user data" + user + ".txt";
    if ((fptr = fopen(loc.c_str(), "r")) == NULL) {
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    memset(buffer, 0, sizeof buffer);
    uint256_t A;
    fgets(buffer, MAX_LENGTH, fptr);
    // close the file
    fclose(fptr);
    A = uint256_t(buffer, 10);
    //end proses A file

    //open X file
    string locscreet = "client/client" + user + "pass.txt";
    if ((fptr = fopen(locscreet.c_str(), "r")) == NULL) {
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    memset(buffer, 0, sizeof buffer);
    uint256_t X;
    fgets(buffer, MAX_LENGTH, fptr);
    // close the file
    fclose(fptr);
    X = uint256_t(buffer, 10);
    //end proses X file

    clock_t start = clock();
    uint256_t q = (X + y) % (n - 1);
    // uint256_t val1 = g ^ q;
    // val1 = val1 % n;
    uint256_t val1 = power(g, q, n);
    cout << "val1=" << val1<< endl;

    // uint256_t c = g ^ y;
    // c = c % n;
    uint256_t c = power(g, y, n);
    cout << "c=" << c <<endl;

    string locvalue = "server/user data/user data" + user + "value.txt";
    ofstream datauservaluefile;

    datauservaluefile.open(locvalue);
    datauservaluefile << val1;
    datauservaluefile.close();

    string locchalenge = "server/user data/user data" + user + "challenge.txt";
    ofstream datauserchalengefile;

    datauserchalengefile.open(locchalenge);
    datauserchalengefile << c;
    datauserchalengefile.close();

    clock_t end = clock();
    cout << "logon information provided. Please run 'authorise' script to authenticate\n";
    cout << "Time to complete calculations :\n";
    cout << end - start << "(ms)\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
