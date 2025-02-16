#include "iostream"
#include "string"
using namespace std;
class MusicPlayer
{
    private:
    string playlist[100] = {""};
    string currentSong;
    public:
    void displayPlaylist()
    {
        cout << "-----------------------------------\n";
        cout << "            Playlist\n";
        cout << "-----------------------------------\n";
        for (int i = 0, j = 1; i < 100; i++)
        {
            if (playlist[i] != "")
            {
                cout << j << " : " << playlist[i] << " " << endl;
                j++;
            }
        }
        cout << "-----------------------------------\n";
    }
    void addSong(string songname)
    {
        for (int i = 0; i < 100; i++)
        {
            if (playlist[i] == "")
            {
                playlist[i] = songname;
                cout << "Song added successfully\n";
                break;
            }
        }
    }
    void playSong(string songname)
    {
        bool found = false;
        for (int i = 0; i < 100; i++)
        {
            if (playlist[i] == songname)
            {
                currentSong = songname;
                cout << "Playing " << songname << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Song not found\n";
        }
    }
    void removeSong(string songname)
    {
        for (int i = 0; i < 100; i++)
        {
            if (playlist[i] == songname)
            {
                playlist[i] = "";
                cout << "Song removed successfully\n";
                break;
            }
        }
    }
    void Menu()
    {
        cout << "-----------------------------------\n";
        cout << "1. Add song\n";
        cout << "2. Play song\n";
        cout << "3. Remove song\n";
        cout << "4. Display playlist\n";
        cout << "5. Exit\n";
        cout << "-----------------------------------\n";
        int choice;
        cout << "Enter choice : ";
        cin >> choice;
        string songname;
        cout << "-----------------------------------\n";
        switch (choice)
        {
        case 1:
            getchar();
            cout << "Enter song name : ";
            
            getline(cin,songname) ;
            addSong(songname);
            break;
        case 2:
            displayPlaylist();
            getchar();
            cout << "Enter song name : ";
            
            getline(cin,songname) ;
            playSong(songname);
            break;
        case 3:
            displayPlaylist();
            getchar();
            cout << "Enter song name : ";
            getline(cin,songname) ;
            removeSong(songname);
            break;
        case 4:
            displayPlaylist();
            break;
        case 5:
        cout << "Exiting..............\n";

            exit(0);
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }

    }
};
int main()
{
    MusicPlayer musicPlayer;
    while (true)
    {
        musicPlayer.Menu();
    }
    return 0;
}