
#include "Engine.h"
#include "Components/PlayerComponent.h"

#include <fmod.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include <cassert>


using namespace std;




int main(int argc, char* argv[])
{
   // FACTORY_REGISTER(Actor); add this 
                                    

   
   
 
  
    
  // auto a = Factory::Instance().Create<Actor>("Actor");



    std::unique_ptr<Engine> engine = std::make_unique<Engine>();

   engine->Initialize();
   std::unique_ptr<Scene> scene = std::make_unique<Scene>(engine.get());
  // ResourceManager rm = ResourceManager();


    File::SetFilePath("Assets");

    std::string buffer;
    File::ReadFile("Scenes/scene.json", buffer);
    


    //std::string s;
    //File::ReadFile("test.txt", s);
    //std::cout << s;
  //
  //  rapidjson::Document document;
  //  Json::Load("Scenes/test.txt", document);
  //
  //  std::string name;
  //  int age;
  //  bool isAlive;
  //
  //  READ_DATA(document, name);
  //  READ_DATA(document, age);
  //  READ_DATA(document, isAlive);
  //  Json::Read(document, "name", name);
  //  Json::Read(document, "age", age);
  //  Json::Read(document, "isAlive", isAlive);
  //  std::cout << name << std::endl;
  //  std::cout << age << std::endl;
  //  std::cout << isAlive << std::endl;

    {
        // create texture, using shared_ptr so texture can be shared
       // std::shared_ptr<Texture> texture = std::make_shared<Texture>();
       //  //texture = ResourceManager::Instance().Get<Texture>("../Assets/image0.jpg", engine->GetRenderer());
       // texture->Load("image0.png", engine->GetRenderer());
       //
       // Transform t{ Vector2{30,30} };
       // std::unique_ptr<Actor> actor = Factory::Instance().Create<Actor>(Actor::GetTypeName());
       // actor->transform = Transform({ { 30,30 } });
       //
       // auto component = Factory::Instance().Create<TextureComponent>("TextureComponent");
       // component->texture = texture;
       // actor->AddComponent(std::move(component));
       // 
       //
       // res_t<Font> font = ResourceManager::Instance().Get<Font>("Quick Dragon.otf", 50);
       // std::unique_ptr<Text> text = std::make_unique<Text>(font);
       // text->Create(engine->GetRenderer(), "Hello!", { 255, 1, 255, 1 });


        while (!engine->IsQuit())
        {
            engine->Update();
            scene->Update(engine->GetTime().GetDeltaTime());


          // auto* actor =  scene->GetActor<Actor>("Text");
          // if (actor)
          // {
          //     actor->transform.rotation += 0.1f;
          // }

            //actor->Update(engine->GetTime().GetDeltaTime());
            engine->GetRenderer().SetColor(1, 0, 0, 0);
            engine->GetRenderer().BegineFrame();

            scene->Draw(engine->GetRenderer());
            engine->GetRenderer().EndFrame();

        }
    }
    scene->RemoveAll();
    ResourceManager::Instance().Clear();
    engine->Shutdown();
    return 0;
}