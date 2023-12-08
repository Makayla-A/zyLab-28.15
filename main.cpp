//STEP 8: Implement the "Remove song" menu option


else if(option == 'd') {
    string songID;
    cout << "REMOVE SONG\nEnter song's unique ID:\n";
    cin >> songID;

    PlaylistNode* curr = headNode;
    while(curr->GetNext() != nullptr) {
        if(curr->GetNext()->GetID() == songID) {
            cout << "\"" << curr->GetNext()->GetSongName() << "\" removed.\n\n";
            curr->SetNext(curr->GetNext()->GetNext());
            break;
        } else {
            curr = curr->GetNext();
        }
    }
}


//STEP 10: Implement the "Output songs by specific artist" menu option

else if(option == 's') {
    string dummyRead; // used for getting rid of newline char
    string name;
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST\nEnter artist's name:\n";
    getline(cin, dummyRead);
    getline(cin, name);

    PlaylistNode* curr = headNode->GetNext(); 
    int songNum = 1; 
    while(curr != nullptr) {
        if(curr->GetArtistName() == name) {
            cout << songNum << ".\n";
            curr->PrintPlaylistNode();
            cout << endl; 
        }
        songNum++;
        curr = curr->GetNext();
    }
}



//STEP 11: Implement the "Output total time of playlist" menu option

else if(option == 't') {
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\nTotal time: ";

    PlaylistNode* curr = headNode->GetNext(); 
    int timeSum = 0; 
    while(curr != nullptr) {
        timeSum += curr->GetSongLength();
        curr = curr->GetNext();
    }

    cout << timeSum << " seconds\n\n";
}
