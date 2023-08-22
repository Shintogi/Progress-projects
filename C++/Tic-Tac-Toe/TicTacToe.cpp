#include<iostream>
#include<string>
using namespace std;


char space [3][3]={{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; //being decalred globally
int row;
int column;
char token = 'x';
bool tie=false; 
 string n1="";
 string n2="";
//setting up the grid lines for tic tac toe
void functionOne(){

    //making the structure of the game
         
    cout<<  "     |      |      \n"; 
    cout<<  " "  <<space[0][0]<<"   |   "  <<space[0][1] <<"  |   "<<space[0][2]<<"  \n"; // The first 3 spaces of the set (1, 2, 3)
    cout<<  " ____|______|_____ \n";
    cout<<  "     |      |      \n"; 
    cout<<  " "  <<space[1][0]<<"   |   "  <<space[1][1] <<"  |   "<<space[1][2]<<"  \n"; // Second 3 spaces of the set (4, 5, 6)
    cout<<  " ____|______|_____ \n";
    cout<<  "     |      |      \n"; 
    cout<<  " "  <<space[2][0]<<"   |   "  <<space[2][1] <<"  |   "<<space[2][2]<<"  \n"; // Thrid 3 spaces of the set (7,8,9)
    cout<<  "     |      |       \n"; 
  
}

void functionTwo() {
    int digit;

    if(token == 'x' )
    {
        cout<<n1<<" Please enter ";
    }

    if(token == '0' )
    {
        cout<<n2<<" Please enter ";
    }

    cin >> digit;

    // checking the digits for each column, and making sure there is no invalid value
    if(digit==1)
    {
        row = 0;
        column = 0;

    }

    if(digit==2)
    {
        row = 0;
        column = 1;
    }

    if(digit==3)
    {
        row = 0;
        column = 2;
    }

    if(digit==4)
    {
        row = 1;
        column = 0;
    }

    if(digit==5)
    {
        row = 1;
        column = 1;
    }

    if(digit==6)
    {
        row = 1;
        column = 2;
    }

    if(digit==7)
    {
        row = 2;
        column = 0;
    }

    if(digit==8)
    {
        row = 2;
        column = 1;
    }

    if(digit==9)
    {
        row = 2;
        column = 2;
    }

    else if(digit<1 || digit>9){
        cout<<"Invalid !!!"<<endl; //if value is not a value from 1 - 9 it will print out invalid
        functionTwo();
        return;
    }

    if(space[row][column] != 'x' && space[row][column] != '0') {
        if(token== 'x') {
            space[row][column] = 'x';
            token= '0';
        }
        else if (token== '0') {
            space[row][column] = '0';
            token= 'x';
        }
        functionOne();
    }
    else {
        cout<<"There is no empty space!"<<endl;
        while(true) {
            cout << "Enter a valid digit: ";
            cin >> digit;
            if(digit>=1 && digit<=9) {
                functionTwo();
                return;
            }
        }
    }
}

    
    



bool functionThree()// setting conditions whether the game is a win or lose or draw
{
    for(int i=0;i<3;i++) // setting horizontal and vertical pairs of 3 (win)
    {
        if(space[i][0]==space[i][1] && space[i][0] == space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i]) //Checking whether the top left element is equal to both top elements on the first row
        return true;
    }

    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0]) // diagonal win condition
    {
        return true;
    }

        // checking if the game is still going on
    for(int i=0;i<3;i++) //checking for x
    {
        for(int j=0;j<3;j++) // checking for 0's
        {
            if(space[i][j] != 'x' && space[i][j] !='0') // if the value in each box isn't x or 0 the game isn't finished
            {
                return false;
            }
        }
    }

    //if its a draw return false
    tie=true;
    return false;

} 

int main()
{

    // input of players
    cout<<" Enter P1 name : \n";
    getline(cin, n1);
    cout<<" Enter P2 name : \n";
    getline(cin, n2);
    cout<<n1<< " is player1 so he/she will play first \n";
    cout<<n2<< " is player1 so he/she will play second \n";

    while(!functionThree()) // This  function will keep returning false until either player one of two wins the game
    {
        functionOne();
        functionTwo();
        functionThree();

    }
    if(token =='x' && tie == false)
    {
        cout<<n2<<"Wins!"<<endl;
    }
    else if(token == '0' && tie == false)
    {
        cout<<n1<<"Wins!"<<endl;
    }
    else
    {
        cout<<"ITS A DRAW!!"<< endl;
    }
}
