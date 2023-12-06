#include "PlaylistNode.h"
#include <iostream>
#include <iomanip>

using namespace std;

PlaylistNode::PlaylistNode()
{
   uniqueID = "none";
   songName = "none";
   artistName = "none";
   songLength = 0;
   nextNodeRef = nullptr;
}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength)
{
   this->uniqueID = uniqueID;
   this->songName = songName;
   this->artistName = artistName;
   this->songLength = songLength;
   this->nextNodeRef = nullptr;
}

string PlaylistNode::GetID()
{
   return uniqueID;
}

string PlaylistNode::GetSongName()
{
   return songName;
}

string PlaylistNode::GetArtistName()
{
   return artistName;
}

int PlaylistNode::GetSongLength()
{
   return songLength;
}

PlaylistNode* PlaylistNode::GetNext()
{
   return nextNodeRef;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc)
{
   nodeLoc->nextNodeRef = nextNodeRef;
   nextNodeRef = nodeLoc;
}

void PlaylistNode::SetNext(PlaylistNode* node)
{
   nextNodeRef = node;
}

void PlaylistNode::PrintPlaylistNode()
{
   cout << "Unique ID: " << uniqueID << endl;
   cout << "Song Name: " << songName << endl;
   cout << "Artist Name: " << artistName << endl;
   cout << "Song Length (in seconds): " << songLength << endl;
}
