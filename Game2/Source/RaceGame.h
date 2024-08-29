#pragma once
#include"Framework/Game.h"
#include "Events/EventSystem.h"
#include "Engine.h"
#include <memory>
class RaceGame : public Game
{
public:
	RaceGame() = default;
	RaceGame(Engine* engine) : Game{ engine } {}

	
public:

	

	// Inherited via Game
	bool Initialize() override;

	void Shutdown() override;

	void Update(float dt) override;

	void Draw(Renderer& renderer) override;

	void OnPlayerDead(const Event& event);

	
private:
	std::unique_ptr<class Scene> m_scene;

};