#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include<windows.h>
#include<memory>
#include<thread>
#include "table.h"
#include "Piece.h"
#include "Knight.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "My_Exception.h"
#include "Mutari.h"

class Game
{
    Game();
    Game(const Game&)=delete;
    Game& operator=(const Game&)=delete;
    static Game* Instance;


public:

static    constexpr int tablecoords_x(int a)
{
    return a/75;
}

static constexpr int tablecoords_y(int a)
{
    return a/68;
}

static constexpr int sfmlcoords_x(int a)
{
    return 75*a;
}

static constexpr int sfmlcoords_y(int a)
{
    return 68*a;
}

static constexpr double poscoords_x(int a)
{
    return 75*tablecoords_x(a);
}

static constexpr double poscoords_y(int a)
{
    return 68*tablecoords_y(a);
}
    void afisare_logo()
{
    std::cout<< "||=====          // \\         |      |    | \n" <<
                "||              //   \\        |      |    |   \n" <<
                "||=====        // === \\       |======|    |        \n" <<
                "      ||      //       \\      |      |    |        \n" <<
                " =====||     //         \\     |      |    .           \n\n\n";
}

void loading()
{
    std::cout << "<";
    for (int i = 50; i > 0; i--)
    {
        std::cout << "=";
        std::this_thread::sleep_for(std::chrono::nanoseconds(50000000));
    }
    std::cout << "> \n\n";

    std::cout << "Sistem Initializat!\n\n\n";
}
    static Game& getInstance();

};

#endif // GAME_H
