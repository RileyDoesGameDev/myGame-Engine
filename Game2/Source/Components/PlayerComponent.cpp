#include "PlayerComponent.h"
#include "Engine.h"
#include "Components/AudioComponent.h"

FACTORY_REGISTER(PlayerComponent);

void PlayerComponent::Read(const json_t& value)
{
	READ_DATA(value, speed);
}

void PlayerComponent::Write(json_t& value)
{
	//	
}

void PlayerComponent::Initialize()
{
	owner->OnCollisionEnter = std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1);
}

void PlayerComponent::Update(float dt)
{
	
   
   
   float rotate = 0;
   float thrust = 0;
   
   
   if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
   if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = 1;
   if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = 1;
   if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -1;
   
   	owner->GetComponent<PhysicsComponent>()->ApplyTorque(rotate * 30 * dt);
   	Vector2 direction = Vector2{ 0, 1 }.Rotate(Math::DegToRad(owner->transform.rotation));
   	owner->GetComponent<PhysicsComponent>()->ApplyForce(direction * speed * thrust);
   	
	
		

}

void PlayerComponent::OnCollisionEnter(Actor* actor)
{
	
	std::cout << "Player hit\n";
}
