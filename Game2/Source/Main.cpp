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
#include "Resorce/ResourseManager.h"
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

   //ResourceManager rm = ResourceManager();


    File::SetFilePath("Assets");
    {
        // create texture, using shared_ptr so texture can be shared
        std::shared_ptr<Texture> texture = std::make_shared<Texture>();
        // texture = ResourceManager::Instance().Get<Texture>("../Assets/image0.jpg", engine->GetRenderer());
        texture->Load("image0.png", engine->GetRenderer());

        Transform t{ Vector2{30,30} };
        std::unique_ptr<Actor> actor = std::make_unique<Actor>(t);
        std::unique_ptr<TextureComponent> component = std::make_unique<TextureComponent>();
        component->texture = texture;
        actor->AddComponent(std::move(component));


        res_t<Font> font = ResourceManager::Instance().Get<Font>("Quick Dragon.otf", 12);
        std::unique_ptr<Text> text = std::make_unique<Text>(font);
        text->Create(engine->GetRenderer(), "Hello!", { 1, 1, 0, 1 });


        while (!engine->IsQuit())
        {
            engine->Update();
            actor->Update(engine->GetTime().GetDeltaTime());
            engine->GetRenderer().SetColor(1, 0, 0, 0);
            engine->GetRenderer().BegineFrame();
            text->Draw(engine->GetRenderer(), 200, 200);

            engine->GetRenderer().DrawTexture(texture.get(), 200, 90, 0);
            actor->Draw(engine->GetRenderer());
            engine->GetRenderer().EndFrame();

        }
    }
    ResourceManager::Instance().Clear();
    engine->Shutdown();
    return 0;
}