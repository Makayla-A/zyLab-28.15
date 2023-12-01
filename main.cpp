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
        << "q - Quit";  
}
PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   //STEP 4 (complete)
   if (char == 'a'){
    //ADD SONG (STEP 7) 
    cout << "Enter song's unique ID: " << endl;
    cin >> uniqueID;
    cout << "Enter song's name: " << endl;
    cin >> songName;
    cout << "Enter artist's name: " << endl;
    cin >> artistName;
    cout << "Enter song's length (in seconds): " << endl;
    cin >> songLength;
   }else if (char == 'd'){
    //REMOVE SONG (STEP 8) 
   }else if (char == 'c'){
    //CHANGE POSITION OF SONG (STEP 9) 
   } else if (char == 's'){
    //OUTPUT SONGS BY SPESIFIC ARTIST (STEP 10)  
   }else if (char == 't'){
    //OUTPUT TOTAL TIME OF PLAYLIST (STEP 11)
   }else if (char == 'o'){
    //OUTPUT FULL PLAYLIST (STEP 6)
   }else if (char == 'q'){
    //QUIT (i think this should just be a break statement?)
   }
   
}//end of ExecuteMenu

int main() {
   //STEP 2 (complete)
   cout << " Enter playlist's title: :" << endl;
   cin >> playlistTitle;
   
   return 0; 
}

