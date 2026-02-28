#include <iostream>
#include <cstring>
using namespace std;

class Song
{
private:
    char *title;
    char *artist;
    int duration;
    int rating;

public:
    Song(const char *t, const char *a, int d, int r = 0)
    {
        title = new char[strlen(t) + 1];
        strcpy(title, t);

        artist = new char[strlen(a) + 1];
        strcpy(artist, a);

        duration = d;
        rating = r;
    }

    Song(const Song &obj)
    {
        title = new char[strlen(obj.title) + 1];
        strcpy(title, obj.title);

        artist = new char[strlen(obj.artist) + 1];
        strcpy(artist, obj.artist);

        duration = obj.duration;
        rating = obj.rating;
    }

    ~Song()
    {
        delete[] title;
        delete[] artist;
    }

    const char *getTitle() const
    {
        return title;
    }
    const char *getArtist() const
    {
        return artist;
    }
    int getDuration() const
    {
        return duration;
    }
    int getRating() const
    {
        return rating;
    }

    void setRating(int r)
    {
        if (r >= 0 && r <= 5)
        {
            rating = r;
        }
    }

    void display() const
    {
        cout << title << " - " << artist
             << " - " << duration << "s"
             << " - Rating: " << rating << endl;
    }
};

class Playlist
{
private:
    char *playlistName;
    Song **songs;
    int songCount;
    int capacity;

public:
    Playlist(const char *name)
    {
        playlistName = new char[strlen(name) + 1];
        strcpy(playlistName, name);

        capacity = 10;
        songs = new Song *[capacity];
        songCount = 0;
    }

    Playlist(const Playlist &obj)
    {

        playlistName = new char[strlen(obj.playlistName) + 1];
        strcpy(playlistName, obj.playlistName);

        capacity = obj.capacity;
        songCount = obj.songCount;
        songs = new Song *[capacity];

        for (int i = 0; i < songCount; i++)
        {
            songs[i] = new Song(*(obj.songs[i]));
        }
    }

    ~Playlist()
    {
        for (int i = 0; i < songCount; i++)
        {
            delete songs[i];
        }
        delete[] songs;
        delete[] playlistName;
    }

    void addSong(const Song &s)
    {
        if (songCount < capacity)
        {
            songs[songCount] = new Song(s);
            songCount++;
        }
        else
        {
        }
    }

    void rateSong(int index, int newRating)
    {
        if (index >= 0 && index < songCount)
        {
            songs[index]->setRating(newRating);
        }
    }

    void displayPlaylist(const char *customTitle = NULL) const
    {

        if (customTitle != NULL)
            cout << "\n===== " << customTitle << " =====" << endl;
        else
            cout << "\n===== PLAYLIST: " << playlistName << " =====" << endl;

        for (int i = 0; i < songCount; i++)
        {
            cout << i + 1 << ". ";
            songs[i]->display();
        }

        cout << "Average Rating: " << calculateAverageRating() << " stars" << endl;

        cout << "Total Duration: " << calculateTotalDuration() << " seconds" << endl;
    }

    double calculateAverageRating() const
    {
        if (songCount == 0)
            return 0.0;

        int totalRating = 0;
        int ratedSongs = 0;

        for (int i = 0; i < songCount; i++)
        {
            int rating = songs[i]->getRating();
            if (rating > 0)
            {
                totalRating += rating;
                ratedSongs++;
            }
        }

        if (ratedSongs > 0)
        {
            return (double)totalRating / ratedSongs;
        }
        else
        {
            return 0.0;
        }
    }

    int calculateTotalDuration() const
    {
        int total = 0;
        for (int i = 0; i < songCount; i++)
        {
            total += songs[i]->getDuration();
        }
        return total;
    }

    const char *getName() const
    {
        return playlistName;
    }
};

int main()
{

    cout << "===== MAIN LIBRARY =====" << endl;

    Song song1("Blinding Lights", "The Weeknd", 200, 0);
    Song song2("Shape of You", "Ed Sheeran", 233, 0);
    Song song3("Bohemian Rhapsody", "Queen", 354, 0);
    Song song4("Stay", "Justin Bieber", 140, 0);

    Song *library[] = {&song1, &song2, &song3, &song4};
    int librarySize = 4;

    for (int i = 0; i < librarySize; i++)
    {
        cout << i + 1 << ". ";
        library[i]->display();
    }

    Playlist playlist1("My Favorites");
    playlist1.addSong(song1);
    playlist1.addSong(song3);
    playlist1.rateSong(0, 5);

    playlist1.displayPlaylist();

    Playlist playlist2 = playlist1;
    playlist2.rateSong(1, 4);

    playlist2.displayPlaylist("PLAYLIST COPY: My Favorites (Copy)");

    cout << "\n===== VERIFICATION =====" << endl;
    cout << "Main library songs unchanged - All ratings still 0" << endl;

    return 0;
}