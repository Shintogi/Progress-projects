#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

std::string generate_password(int length) {
    static const char alphabet[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "!@#$%^&*()";
    static const int alphabet_size = sizeof(alphabet) - 1;
    std::string password;
    password.reserve(length);
    for (int i = 0; i < length; ++i) 
    {
        int index = std::rand() % alphabet_size;
        password += alphabet[index];
    }
    return password;
}

int main() {
    // Set the seed for the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random password with 12 characters
    std::string password = generate_password(12);

    // Output the password
    std::cout << "The password is: " << password << std::endl;

    return 0;
}
