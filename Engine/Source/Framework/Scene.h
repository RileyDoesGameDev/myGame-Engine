#pragma once
#include "Object.h"
#include <list>
#include <memory>
class Renderer;
class Game;
class Actor;
class Engine;

class Scene : public Object

{
public:
	void Initialize() override;
	Scene(Engine* engine, Game* game = nullptr) : engine{ engine }, game{ game } {}
	Scene(const Scene& other);

	CLASS_DECLARATION(Scene)
	CLASS_PROTOTYPE(Scene)
	void Update(float dt);
	void Draw(Renderer& renderer);
	void AddActor(std::unique_ptr<Actor> actor, bool initialize = false);
	
	void RemoveAll(bool force);
	template<typename T>
	T* GetActor();


	template<typename T>
	T* GetActor( const std::string& name);

protected:
	std::list<std::unique_ptr<Actor>> actors;



public:
	Engine* engine{ nullptr };
	Game* game{ nullptr };


};
template<typename T>
T* Scene::GetActor()
{
	for (auto& actor : actors)
	{
		T* result = dynamic_cast<T*>(actor.get());
		if (result) return result;
	}
	return nullptr;
}

template<typename T>
inline T* Scene::GetActor(const std::string& name)
{
	for (auto& actor : actors)
	{
		T* result = dynamic_cast<T*>(actor.get());
		if (result && IsEqualIgnoreCase(result->name, name)) return result;
	}

	return nullptr;
}
