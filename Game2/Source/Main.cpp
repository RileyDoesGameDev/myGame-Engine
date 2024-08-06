#include "Renderer/Renderer.h"
#include "Math/Vector2.h"
#include "Renderer/Particle.h"
#include "Core/Etimer.h"
#include "Input/Input.h"
#include "Math/Random.h"
#include "math/MathUtils.h"
#include "Renderer/Model.h"
#include "Renderer/Color.h"
#include "Math/Transform.h"
#include "Engine.h"
#include "Framework/Scene.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Recorse/ResourseManager.h"
#include "Renderer/Texture.h"

#include <fmod.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include <cassert>


using namespace std;




int main(int argc, char* argv[])
{

    std::unique_ptr<Engine> engine = std::make_unique<Engine>();

   engine->Initialize();

   ResourceManager rm = ResourceManager();


    File::SetFilePath("Assets");

    // create texture, using shared_ptr so texture can be shared



   std::shared_ptr<Texture> texture = std::make_shared<Texture>();

    // texture = ResourceManager::Instance().Get<Texture>("../Assets/image0.jpg", engine->GetRenderer());
    texture->Load("image0.png", engine->GetRenderer());

   


    while (!engine->IsQuit())
    {
        engine->Update();
        engine->GetRenderer().SetColor(1, 0, 0, 0);
        engine->GetRenderer().BegineFrame();
        engine->GetRenderer().DrawTexture(texture.get(),200, 90, 0);

        engine->GetRenderer().EndFrame();

    }
    engine->Shutdown();
    return 0;
}