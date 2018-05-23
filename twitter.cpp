#include <iostream>
#include <string>
#include "twitter.hpp"
using namespace std;

void splitTweets(string twe,string arr [],int *count)
{
  //Variables used in the splitTweets function
  //String variable equal to the twe
  string tweets = twe;
  //Char 's' represents the space character
  char s = ' ';
  //Char '!' represents the exclamation mark character
  char e = '!';
  //Char '?' represents the Question mark character
  char q = '?';
  //Char '.' represents the Period character
  char p = '.';
  //int counter is set to zero for the counter
  int counter = 0;
  //Total tweets length < 280 then store entire thing in array 0
  if((twe.length()) < 280)
  {
      //Stores in first array also known as arr[0] and stores all 280 characters
      arr[0] = twe.substr(0,280);
      //set count as one
      *count = 1;
  }
  //Goes here when total tweet length is bigger than 280
  else
  {
    //While loop when the tweet is bigger than zero
    while (twe.length() > 0)
    {
            //Tweet is less than 279 then stores in the first array
            if(twe.length() < 279)
            {
                arr[*count] = twe;
                //erases from the total tweet
                twe.erase(0, twe.length());
            }
            //if the 279 character in the tweet is a space
            else if(twe[279] == s)
            {
              //store in the array

                arr[*count] = twe.substr(0,280);
                twe.erase(0,280);
            }
            //If the 279 character is an exlamation mark
            else if(twe[279] == e)
            {
                arr[*count] = twe.substr(0,280);
                twe.erase(0,280);
            }
            //If the 279 character is a question mark
            else if(twe[279] == q)
            {
                arr[*count] = twe.substr(0,280);
                twe.erase(0,280);
            }
            //If the 279 character is a period
            else if(twe[279] == p)
            {
                arr[*count] = twe.substr(0,280);
                twe.erase(0,280);
            }
            //If the no puncuation or space is found at 279
            //search for the largest position that has one
            else
            {     //Set counter to position 279
                  counter = twe.rfind(' ',279);
                  arr[*count] = twe.substr(0,counter+1);
                  twe.erase(0, counter+1);
            }
            //If period is the largest position then set the end to that position
            if (tweets.rfind(p) > tweets.rfind(e) && tweets.rfind(p) > tweets.rfind(q) && tweets.rfind(p) > tweets.rfind(s) && tweets.rfind(p) < 280)
            {
                //Set counter to the position of that period
                counter = tweets.rfind(p);
                arr[*count] = twe.substr(0,counter+1);
                twe.erase(0,counter+1);
            }
            //If question mark is the largest position then set the end to that position
            else if (tweets.rfind(q) > tweets.rfind(e) && tweets.rfind(q) > tweets.rfind(p) && tweets.rfind(q) > tweets.rfind(s) && tweets.rfind(q) < 280)
            {
                //Set counter to the position of that question mark
                counter = tweets.rfind(q);
                arr[*count] = twe.substr(0,counter+1);
                twe.erase(0,counter+1);
            }
            //If exclamtion mark is the largest position then set the end to that position
            else if (tweets.rfind(e) > tweets.rfind(p) && tweets.rfind(e) > tweets.rfind(q) && tweets.rfind(e) > tweets.rfind(s) && tweets.rfind(e) < 280)
            {
                //Set counter to the position of that exclamtion mark
                counter = tweets.rfind(e);
                arr[*count] = twe.substr(0,counter+1);
                twe.erase(0,counter+1);
            }
            //If a space is the largest position then set the end to that posittion
            else if (tweets.rfind(s) > tweets.rfind(e) && tweets.rfind(s) > tweets.rfind(q) && tweets.rfind(s) > tweets.rfind(p) && tweets.rfind(s) < 280)
            {
                //Set counter to the position of that space
                counter = tweets.rfind(s);
                arr[*count] = twe.substr(0,counter+1);
                twe.erase(0,counter+1);
            }
            //increments counter to one
            (*count)++;
     }
   }
 }


void displaySplitTweet(string arr [], int count, string username)
{
  //counter is set to one
    int x = 1;
    //if statement for if count is greater than one
    if (count > 1)
    {
      //for loop to print out the @ symbol with username and the tweet in the array
      //Also prints out the counter
        for (int i = 0; i < count; i++)
        {
            cout << "@" << username << ": " << arr[i] << " (" << x << "/" << count << ")";
            cout << endl;
            x++;
        }
    }
    else
    {
      //else prints out the entire tweet
        cout << "@" << username << ": " << arr[0];
        cout << endl;
    }
}
