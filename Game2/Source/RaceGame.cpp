#include "RaceGame.h"
#include "Engine.h"

#include <string>
bool RaceGame::Initialize()
{
    //rapidjson::Document document;
   // Json::Load("Scenes/scene.json", document);



    m_scene = std::make_unique<Scene>(m_engine);

    std::string sceneNames[] = { "scenes/tilemap.json" , "scenes/scene.json"};
    for (auto sceneName : sceneNames)
    {
        rapidjson::Document document;
        Json::Load(sceneName, document);
        m_scene->Read(document);
    }
    m_scene->Initialize();

    return true;
}

void RaceGame::Shutdown()
{
    m_scene->RemoveAll(true);
}

void RaceGame::Update(float dt)
{
    m_scene->Update(dt);
}

void RaceGame::Draw(Renderer& renderer)
{
    m_scene->Draw(renderer);
}

void RaceGame::OnPlayerDead(const Event& event)
{

    std::cout << " game Player dead\n";
}
