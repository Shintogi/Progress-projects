#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//using a struct to make the first nodes of the tree
struct node{
    int data; // The data of the node

    //How to write the left and right nodes
    struct node* left; 
    struct node* right;

    node(int value)
    {
        data = value;
        
        left = Null;
        right = Null;
    } 
    
};

int main()
{
    //creating the root of the tree
    Node* root = new Node(1):

    /*visualizing the tree
    1                          Since we init. the left and right nodes to null they have nothing in them 
    /\
Null  Null
*/

    //giving the left and right nodes values
    root->left = new Node(2);
    root->right = new Node(3);

       /*visualizing the tree
    1                        (now the left and right nodes have values of 2 and 3) 
    /\                        and we can keep going for a as long as we want the tree to be
   2   3
*/ 

return 0;
}