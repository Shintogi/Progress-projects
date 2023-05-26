#include <iostream>
#include <cstdlib>


int main (){

     srand(time(NULL)); // Null initialzies a random number using srand witht the current time.

    int random = rand() % 1783642 + 1;
    bool test = false;
    bool test2 = true;

    std::cout << "Random = " << random << '\n';
    std::cout << test2 << '\n';
    std::cout<< "elijah is gay";
    return 0; 
    
   /*
    srand(time(NULL)); // initialize the random number generator with the current time
    int randomNumber = rand() % 10 + 1; // generate a random number between 1 and 10
    std::cout << "Random number: " << randomNumber << '\n';
    return 0; 
    */
   
}