#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   //STEP 3
   cout << playlistTitle << "PLAYLIST MENU" << endl;
   cout << "a - Add song\n"
        << "d - Remove song\n"
        << "c - Change position of song\n"
        << "s - Output songs by specific artist\n"
        << "t - Output total time of playlist (in seconds)\n"
        << "o - Output full playlist\n"
        << "q - Quit" << endl;
}
PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   //STEP 4 
   if (option == 'a'){   //ADD SONG  (STEP 7)
      
    cout << "Enter song's unique ID: " << endl;
    cin >> uniqueID;
    
    cout << "Enter song's name: " << endl;
    cin.ignore();
    getline(cin, songName);
    
    cout << "Enter artist's name: " << endl;
    cin.ignore();
    getline(cin, artistName);
    
    cout << "Enter song's length (in seconds): " << endl;
    cin >> songLength;
    
    // create a new PlaylistNode with the entered info
    
   PlaylistNode* newNode = new PlaylistNode(uniqueID, songName, artistName, songLength);
   
   // If the list is empty, make the new node the head
        if (headNode == nullptr) {
            headNode = newNode;
        } else {
            // Traverse the list to find the last node
            PlaylistNode* current = headNode;
            while (current->GetNext() != nullptr) {  //while the next node is not empty
                current = current->GetNext();   //go through all of the nodes until the last one 
            } 
            // Add the new node after the last node
            current->SetNext(newNode);
        }

   }else if (option == 'd'){
    //REMOVE SONG  
   }else if (option == 'c'){
    //CHANGE POSITION OF SONG  
   } else if (option == 's'){
    //OUTPUT SONGS BY SPESIFIC ARTIST   
   }else if (option == 't'){
    //OUTPUT TOTAL TILE OF PLAYLIST  
   }else if (option == 'o'){
    //OUTPUT FULL PLAYLIST 
   }else if (option == 'q'){
    //QUIT 
   }
   
}

int main() {
   //STEP 2
   cout << " Enter playlist's title: :" << endl;
   cin >> playlistTitle;
   
   return 0;
}

