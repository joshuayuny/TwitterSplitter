#include <iostream>
#include <string>
#include "twitter.hpp"
using namespace std;

int main()
{
    //Split = 0
    int split = 0;
    //String variables for username and twe
    string username;
    string twe;
    //Asking username for name
    //Storing username string
    cout << "Please enter your username: ";
    cin >> username;
    //Asking username for message
    cout << "Please enter your message: ";
    cin.ignore();
    //Storing message string
    getline(cin,twe);
    //Creating an new datatype array
    string *arr = new string[100];
    //Calling splitTweets function
    splitTweets(twe,arr,&split);
    //Calling displaySplitTweet function
    displaySplitTweet(arr,split,username);
    //Deleting new array datatype
    delete [] arr;
    //Set arr to zero
    arr = nullptr;
    return 0;
}
