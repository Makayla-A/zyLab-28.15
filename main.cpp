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

   }else if (option == 'd'){
    //REMOVE SONG  
   }else if (option == 'c'){
    //CHANGE POSITION OF SONG  
   } else if (option == 's'){
    //OUTPUT SONGS BY SPESIFIC ARTIST   
   }else if (option == 't'){
    //OUTPUT TOTAL TILE OF PLAYLIST  
   }else if (option == 'o')
   {
      //OUTPUT FULL PLAYLIST
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
      //step 6: output full playlist
      if (headNode == nullptr)
      {
         cout << "Playlist is empty" << endl;
      }
      //PlaylistNode* curr = headNode;
      else
      {
         while (headNode != nullptr)
         {
            headNode->PrintPlaylistNode();
            headNode = headNode->GetNext();
         }
      } 
    
   } else if (option == 'q'){
    //QUIT 
    }
    return headNode;
}
   
   

int main() {
   //STEP 2
   cout << "Enter playlist's title:" << endl;
   cout << endl; 
   string playlistTitle;
   getline(cin, playlistTitle);
   
   PlaylistNode* headNode = nullptr;
   
   char option; 
   do{
     PrintMenu(playlistTitle); 
      cout << endl <<"Choose an option:"<< endl;
      cin >> option;
      
      //if an invadid character is entered, continue promting 
       while (option != 'a' && option != 'd' && option != 'c' &&
               option != 's' && option != 't' && option != 'o' && option != 'q') {
            cout << "Invalid choice. Choose a valid character: ";
            cin >> option;
               }
            headNode = ExecuteMenu(option, playlistTitle, headNode); // update head
            //PrintMenu(playlistTitle); //print menu again after they pick, keeps going till q
               
   }while (option != 'q');
   
   return 0;
}
