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
   } 
   } else if (option == 'q'){
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
