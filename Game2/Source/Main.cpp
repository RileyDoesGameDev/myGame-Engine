
#include "Engine.h"
#include "Components/PlayerComponent.h"
#include "RaceGame.h"
#include <fmod.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include <cassert>


#include "Components/TextComponent.h"
#include "Components/Component.h"

using namespace std;






int main(int argc, char* argv[])
{
   File::SetFilePath("Assets");

   std::unique_ptr<Engine> engine = std::make_unique<Engine>();
   engine->Initialize();
   
   std::unique_ptr<RaceGame> game = std::make_unique<RaceGame>(engine.get());
   game->Initialize();


   // std::string buffer;
   
    while (!engine->IsQuit())
    {

        engine->Update();
        game->Update(engine->GetTime().GetDeltaTime());

        engine->GetRenderer().SetColor(1, 0, 0, 0);
        engine->GetRenderer().BegineFrame();

        game->Draw(engine->GetRenderer());
        engine->GetRenderer().EndFrame();
    }

    game->Shutdown();
    ResourceManager::Instance().Clear();
    engine->Shutdown();
    return 0;
}