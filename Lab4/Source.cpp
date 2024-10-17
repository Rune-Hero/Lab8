#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

class SPORT_GAME {
protected:
    string name;
    int numberOfPlayers;
public:
    SPORT_GAME(string gameName, int players) : name(gameName), numberOfPlayers(players) {};

    ~SPORT_GAME() {
        cout << "Робота деструктора SPORT_GAME\n"; 
    };

    virtual void displayInfo(ofstream &file)
    {
        file << "\nНазва гри: " << name << endl;
        file << "\nКількість гравців: " << numberOfPlayers << endl;
    }
};

class FOOTBALL : public SPORT_GAME {
private:
    int duration;
public:
    FOOTBALL(int matchDuration, int players) : duration(matchDuration), SPORT_GAME("Футбол", players)
    {
        cout << "\nСтворено " << name << " із тривалістю матчу " << matchDuration << " хвилин";
    }

    ~FOOTBALL() {
        cout << "Робота деструктора FOOTBALL\n";
    };

    void displayInfo(ofstream &file) override
    {
        SPORT_GAME::displayInfo(file);
        file << "Тривалість матчу: " << duration << " хвилин" << endl;
    }

};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FOOTBALL footballGame(90, 11);
    
    ofstream OutputFile("D:/sport_game_info.txt");
    if (OutputFile.is_open())
    {
        footballGame.displayInfo(OutputFile);
        OutputFile.close();
        cout << "Інформація про гру записана у файл sport_game_info.txt\n";
    }
    else cout << "Не вдалося відкрити файл для запису.\n";

    return 0;
}

