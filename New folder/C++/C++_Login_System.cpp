#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLoggedIN(){

 string username, password, un,pw;
 cout << "Enter username: "; cin >> username;
 cout << "Enter password: "; cin >> password; 

 // reading a file
 ifstream read( username + ".txt");
 getline(read, un);
 getline(read, pw);

 return un == username && pw == password;
}
 int main(){
    while (true){
        
        int choice{};
        
        cout << "1:Register\n2:Login\nYour choice: "; cin >> choice;
        
        if (choice == 1)
        {
            
         string username, password;
        
            cout << "Create a username: "; cin >> username;
            cout << "Create a password: "; cin >> password;

            ofstream file;
            file.open("E:" + username + ".txt");
            file << username <<endl <<password;
            file.close();
            

            main();
        }
        else if (choice == 2)
        {
            bool status {isLoggedIN()};
            {
                if (!status)
                {
                cout << "False Login!" << endl;
                std::cin.get();
                return EXIT_FAILURE;
                }
                else
                {
                cout << "Successfully logged in!" << endl;
                std::cin.get();
                return EXIT_SUCCESS;
                }
            }   
        }
    }
        system("pause");
        return 0;
 }
     

    
