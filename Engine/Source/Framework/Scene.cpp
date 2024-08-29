#include "Scene.h"
#include "Actor.h"
#include "../Renderer/Model.h"
#include "Core/Factory.h"
#include <algorithm>
#include "Components/CollisionComponent.h"
#include "Core/EAssert.h"
void Scene::Initialize()
{
	for (auto& actor : actors)
	{
		actor->Initialize();
	}
}


Scene::Scene(const Scene& other)
{
	ASSERT(false);
}

void Scene::Read(const json_t& value)
{
	if (HAS_DATA(value, actors) && GET_DATA(value, actors).IsArray())
	{
		for (auto& actorValue : GET_DATA(value, actors).GetArray())
		{
			
			auto actor = Factory::Instance().Create<Actor>(Actor::GetTypeName());
			actor->Read(actorValue);
			bool prototype = false;
			READ_DATA(actorValue, prototype);

			if (prototype) 
			{
				std::string name = actor->name;
				Factory::Instance().RegisterPrototype<Actor>(name, std::move(actor));
			}
			else
			{

			AddActor(std::move(actor));
			}
		}
	}
}
void Scene::Write(json_t& value)
{
}
void Scene::Update(float dt)
{
	for (auto& actor : actors)
	{
		if (actor->active) actor->Update(dt);
	}
	

}

void Scene::Draw(Renderer& renderer)
{
	for (auto& actor : actors)
	{
		if (actor->active) actor->Draw(renderer);
	}
}

void Scene::AddActor(std::unique_ptr<Actor> actor, bool initialize)
{
	
	actor->scene = this;
	if (initialize) actor->Initialize();
	actors.push_back(std::move(actor));
}

void Scene::RemoveAll(bool force)
{
	std::erase_if(actors, [force](auto& actor) {return (force || !actor->persistent); });
	//actors.clear();
}
