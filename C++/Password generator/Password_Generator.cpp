#include <iostream> 
#include <cstdlib>
#include<string>
#include<ctime>
using namespace std;

// Function to generate a random password of a given
std::string mainpassword(int length)
{
    //array of the characters that can be randomly selected
    static const char alphabet[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "!@#$%^&*()";
    static const int alphabet_size = sizeof(alphabet) - 1;
    //empty string to hold the passowrd
    std::string password;
    password.reserve(length);
    for (int i = 0; i < length; ++i)
    {
        int index = std::rand() % alphabet_size;
        password += alphabet[index];
    }
    return password;
    
}

int main ()// generating random numbers between 0-1000, but it generates incramenting upwards
{
    //std::srand(time(0));
    //int number = 3;
    //std::cout << (rand()%1000) <<endl;
    //return 0;

    // Set the seed for the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random password with 12 characters
    std::string password = mainpassword(27);

    // Output the password
    std::cout << "The password is: " << password << std::endl;

    return 0;
} 