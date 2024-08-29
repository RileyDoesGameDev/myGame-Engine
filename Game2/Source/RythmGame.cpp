#include "RythmGame.h"
#include "Engine.h"

#include <string>

enum GameState
{
    Title, GameStart, Game, GameEnd
};

GameState state = Title;

bool RythmGame::Initialize()
{

    m_scene = std::make_unique<Scene>(m_engine);
    std::string sceneNames[] = { "scenes/Menu.json" , "scenes/game.json" };
        rapidjson::Document document;

    switch(state)
    {
    case Title:
    {
        Json::Load(sceneNames[0], document);
        m_scene->Read(document);
        if (m_scene->engine->GetInput().GetKeyDown(SDLK_SPACE))
        {
            state = GameStart;
        }
       
        break;
    }
    case GameStart:
    {
       // rapidjson::Document document;
        Json::Load(sceneNames[1], document);
        m_scene->Read(document);
        break;
    }
    }
        m_scene->Initialize();

   //
   // for (auto sceneName : sceneNames)
   // {
   //     rapidjson::Document document;
   //     Json::Load(sceneName, document);
   //     m_scene->Read(document);
   // }
   // m_scene->Initialize();

    return true;
}

void RythmGame::Shutdown()
{
    m_scene->RemoveAll(true);
}

void RythmGame::Update(float dt)
{
   
    m_scene->Update(dt);
}

void RythmGame::Draw(Renderer& renderer)
{

    m_scene->Draw(renderer);
    
}
