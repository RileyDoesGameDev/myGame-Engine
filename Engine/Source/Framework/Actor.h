#pragma once
#include "../Math/Transform.h"
#include <string>

#include "Components/Component.h"
#include "vector"
#include <memory>
class Model;
class Renderer;
class Scene;

class Actor : public Object
{
public:
	Actor() = default;
	Actor(const Transform& transform) : m_transform{ transform } {}

	CLASS_DECLARATION(Actor)



	void Initialize() override;
	virtual void Update(float dt);
	virtual void Draw(Renderer& renderer);
	void SetDamping(float damping) { m_damping = damping; }
	void SetLifespan(float lifespan) { m_lifespan = lifespan; }


	void SetTag(const std::string& tag) { m_tag = tag; }


	const std::string GetTag() { return m_tag; }
	const Transform& GetTransform() { return m_transform; }
	void SetTransform(const Transform& transform) { m_transform = transform; }
	void AddComponent(std::unique_ptr<Component> comonent);
	virtual void OnCollision(Actor* actor) {}
	//float GetRadius() {return (m_model) ? m_model->GetRadius() :}

	friend class Scene;
protected:
	std::string m_tag;
	bool m_destroyed = false;
	float m_lifespan = 0;


	Transform m_transform;
	Vector2 m_velocity{0,0};

	float m_damping{ 0 };

	Model* m_model{ nullptr };
	Scene* m_scene{ nullptr };

	std::vector<std::unique_ptr<Component>> m_components;




};

