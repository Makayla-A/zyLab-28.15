//Maki Girma
//Makayla Alston
//Cameron Tofani

#include <iostream>
#include "PlaylistNode.h"

using namespace std;


void PrintMenu(const string playlistTitle) {
   //STEP 3
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song\n"
        << "d - Remove song\n"
        << "c - Change position of song\n"
        << "s - Output songs by specific artist\n"
        << "t - Output total time of playlist (in seconds)\n"
        << "o - Output full playlist\n"
        << "q - Quit" << endl;
   
}

//STEP 4 
PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   
   //ADD SONG  (STEP 7)
   if (option == 'a'){
    cout << "ADD SONG: " << endl;
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
   
    cout << "Enter song's unique ID: " << endl;
    cin.ignore();
    getline(cin, uniqueID);
    
    cout << "Enter song's name: " << endl;
    cin.ignore();
    getline(cin, songName);
    
    cout << "Enter artist's name: " << endl;
    getline(cin, artistName);
    
    cout << "Enter song's length (in seconds): " << endl;
    cin >> songLength;
    
    // add the new node to the playlist 
    
   PlaylistNode* newNode = new PlaylistNode(uniqueID, songName, artistName, songLength);
   
   // if the list is empty, make the new node the head
        if (headNode == nullptr) {
            headNode = newNode;
        } else {
            // go through the list to find the last node
            PlaylistNode* current = headNode;
            while (current->GetNext() != nullptr) {  
                current = current->GetNext();   //go through all of the nodes until the last one 
            } 
            // Add the new node after the last node
            current->InsertAfter(newNode);
        }
      // STEP 8: Implement the "Remove song" menu option in ExecuteMenu()
    else if (option == 'd') {
         string uniqueID;
         cout << "REMOVE SONG" << endl << "Enter song's unique ID:" << endl;
         cin >> uniqueID;
      
      // if the list is empty, make the new node the head
         PlaylistNode* curr = headNode;
         while (curr->GetNext() != nullptr){
            if (curr->GetNext()->GetID() == uniqueID){
               cout << "\"" << curr->GetNext()->GetSongName()<< "\" removed.\n" << endl;
               
               curr->SetNext(curr->GetNext()->GetNext());
            }else{
               
               curr = curr->GetNext();
            }
         }
      }
     
   //STEP 10: Implement the "Output songs by specific artist" menu option in ExecuteMenu()
   else if (option =='s') {
        string test;
        string name;
        cout <<"OUTPUT SONGS BY SPECIFIC ARTIST" << endl << "Enter artist's name:\n" << endl;
        getline(cin, test);
        getline(cin, name);
        
        PlaylistNode* curr = headNode->GetNext();
        int songNum = 1;
        
        while (curr != nullptr){
           if(curr->GetArtistName() == name) {
            cout << songNum << "." << endl;
            curr->PrintPlaylistNode();
            cout<<endl;
           }
           songNum++; //increment song num
           curr = curr->GetNext();
        }
      } 

   //STEP 11: Implement the "Output total time of playlist" menu option in ExecuteMenu()
   else if (option == 't') {
         cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\nTotal time: ";
         
         PlaylistNode* curr = headNode ->GetNext();
         int sum = 0;
         while(curr != nullptr) {
            sum += curr->GetSongLength();
            
            curr = curr->GetNext();
         }
         cout << sum << " seconds\n" << endl;
      }

   if (headNode == nullptr)
   {
      cout << "Playlist is empty" << endl;
      return headNode;
   }
   
   cout << playlistTitle << "- OUTPUT FULL PLAYLIST";
   PlaylistNode* curr = headNode->GetNext();
   
   if (curr == nullptr)
   {
      cout << "Playlist is empty" << endl;
      return headNode;
   }
   
   cout << endl;
   
   int index = 1;
   while (curr != nullptr)
   {
      cout << index << ".\n";
      curr->PrintPlaylistNode();
      cout << endl;
      
      index++;
      curr = curr->GetNext();
   }
    else if (option == 'q'){
    //QUIT 
    }
    return headNode;
}
   
   

int main() 
{
   string playlistTitle;
   cout << "Enter playlist's title:" << endl << endl;
   getline(cin, playlistTitle);
   
   PlaylistNode* head = new PlaylistNode();
   
   char input;
   
   while (input != 'q')
   {
      PrintMenu(playlistTitle);
      cout << "\nChoose an option:\n";
      cin >> input;
      ExecuteMenu(input, playlistTitle, head);
   }
   
   return 0;
}
