#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> //for std::ostringstream
#include <iomanip> //for std::setw, std::hex, and std::setfill
#include <cstring>
#include "HashLib/sha3.h"
#include "bigInt/uint256_t.h"

using namespace std;
using std::fstream;

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

//perform the SHA3-256 hash
std::string sha3_256(const std::string& input)
{
    SHA3   digestSha3(SHA3::Bits256);
    std:string result = digestSha3(input);
    return result;
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

    unsigned long long int g;
    fgets(buffer, MAX_LENGTH, fptr);
    // close the file
    fclose(fptr);

    char* pEnd;
    g = std::strtoull(buffer, &pEnd, 10);
    //end proses g file

    //open n file
    if ((fptr = fopen("server/server values/n64.txt", "r")) == NULL) {
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    memset(buffer, 0, sizeof buffer);
    unsigned long long int n;
    fgets(buffer, MAX_LENGTH, fptr);
    // close the file
    fclose(fptr);
    n = std::strtoull(buffer, &pEnd, 10);
    //end proses n file

    string user;
    cout << "enter your username: ";
    cin >> user;

    string pass, pass2;
    cout << "Register your password with the system: ";
    cin >> pass;

    while (pass.length() < 8) {
        cout << "Password must be more than 8 characters ";
        cin >> pass;
    }

    cout << "Please confirm password: ";
    cin >> pass2;

    if (pass == pass2) {
        cout << "Password set!\n";
        cout << "..........................\n";
        cout << "..........................\n";
        cout << "Password saved to system\n";
        cout << "Please run logon script to provide logon details\n";
        cout << "..........................\n";
    }
    else {
        cout << "Passwords dont match!";

        while (pass != pass2) {
            cout << "Register your password with the system: ";
            cin >> pass;

            while (pass.length() < 8) {
                cout << "Password must be more than 8 characters ";
                cin >> pass;
            }

            cout << "Please confirm password: ";
            cin >> pass2;

            if (pass == pass2) {
                cout << "Password set!\n";
                cout << "..........................\n";
                cout << "..........................\n";
                cout << "Password saved to system\n";
                cout << "Please run logon script to provide logon details\n";
                cout << "..........................\n";
            }
        }
    }
    clock_t start = clock();
    std::string output = sha3_256(pass);
    std::cout << "SHA2-256 : " << output << "\n";

    // unsigned long long int x;
    // x = std::strtoull(output.c_str(), &pEnd, 16);
    uint256_t  x = uint256_t(output, 16);
    std::cout << "lo : " << x << "\n";

    // uint256_t A = g ^ x;
    // A = A % n;
    uint256_t A = power(g,x,n);
    std::cout << "A : " << A << "\n";

    string loc = "server/user data/user data" + user + ".txt";
    ofstream datauserfile;

    datauserfile.open(loc);
    datauserfile << A;
    datauserfile.close();

    string locscreet = "client/client" + user + "pass.txt";
    ofstream datscreetfile;

    datscreetfile.open(locscreet);
    datscreetfile << x;
    datscreetfile.close();

    clock_t end = clock();
    cout << "---------------------\n";
    cout << "Time to complete calculations :\n";
    cout << end - start << "(ms)\n";

    return -1;
}