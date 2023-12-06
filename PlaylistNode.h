#define PLAYLISTNODEH

#include <string>
#include "iostream"

using namespace std;

class PlaylistNode
{
     private:
      string uniqueID;
      string songName;
      string artistName;
      int songLength;
      PlaylistNode* nextNodeRef;
      
   public:
      PlaylistNode();
      PlaylistNode(string uniqueID, string songName, string artistName, int songLength);
      string GetID();
      string GetSongName();
      string GetArtistName();
      int GetSongLength();
      PlaylistNode* GetNext();
      void InsertAfter(PlaylistNode* nodeLoc);
      void SetNext(PlaylistNode* nodeLoc);
      void PrintPlaylistNode();
};
