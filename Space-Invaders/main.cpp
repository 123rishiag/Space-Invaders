#include <iostream>

#include "Header/GameService.h"

using namespace std;

int main()
{
    GameService* gameService = new GameService();

    gameService->Ignite();

    while (gameService->IsRunning())
    {
        gameService->Update();
        gameService->Render();
    }

    return 0;
}
