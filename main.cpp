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

   //step 6: makayla
   if (option == 'o') {
     if (headNode == nullptr) {
        cout << "\nPlaylist is empty" << endl << endl;
        return headNode;
     }
     cout << playlistTitle << " - OUTPUT FULL PLAYLIST";
     
     PlaylistNode* curr = headNode->GetNext();
     
     if (curr == nullptr) {
      cout << "\nPlaylist is empty" << endl << endl;  
      return headNode;
     }
     cout << endl;
    int songNum = 1;
    while (curr != nullptr) {
    cout << songNum << ".\n";
    curr -> PrintPlaylistNode();
    cout << endl;
    
    songNum++;
    curr = curr->GetNext();  
   }
   
   } else if (option == 'a'){     //end of option o 

   string test = ""; 
   
   PlaylistNode* curr = headNode;
   
   while (curr->GetNext() != nullptr) {
      curr = curr->GetNext();
   }
   
   string uniqueID, songName, artistName;
   int songLength;
   
   cout << "ADD SONG" << endl << "Enter song's unique ID:" << endl; //ADD SONG  (STEP 7)
      cin >> uniqueID;
      getline (cin, test);
    
    cout << "Enter song's name:" << endl;
    //cin.ignore();
    getline(cin, songName);
    
    cout << "Enter artist's name:" << endl;
    //cin.ignore();
    getline(cin, artistName);
    
    cout << "Enter song's length (in seconds):" << endl;
    cin >> songLength;
    getline(cin, test);
    
    // add the new node to the playlist 
    curr->SetNext(new PlaylistNode (uniqueID, songName, artistName, songLength));
    
    cout << endl;
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
    return headNode;
}   
int main() {
  //STEP 2
   string playlistTitle;
   cout << "Enter playlist's title:" << endl;
   
   getline(cin, playlistTitle);
   
   cout << endl; 
   
   PlaylistNode* headNode = new PlaylistNode();
   
   char userChoice = '0';
   while(userChoice != 'q'){

     PrintMenu(playlistTitle);

   //Step 5, makayla 
   while (input != 'q')
   {
      PrintMenu(playlistTitle);
      cout << "\nChoose an option:\n";
      cin >> input;
      ExecuteMenu(input, playlistTitle, head);
   }
   
   return 0;
}
