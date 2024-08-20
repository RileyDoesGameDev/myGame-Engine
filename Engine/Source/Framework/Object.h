#pragma once
#include <string>
#include "Core/Factory.h"
#include "Core/Serializable.h"










#define CLASS_DECLARATION(className)                        \
	static const char* GetTypeName() { return #className; } \
	virtual void Read(const json_t& value);                 \
	virtual void Write(json_t& value);

#define FACTORY_REGISTER(className)								\
	class Register##className									\
	{															\
	public:														\
		Register##className()									\
		{														\
			Factory::Instance().Register<className>(#className);\
		}														\
	};															\
	static Register##className register_instance;



//#define FACTORY_REGISTER(className)                         \
//	class Register##className                               \
//{                                                           \
//public:                                                     \
//	Regiter()                                               \
//{                                                           \
//	Facotry::Instance().Regiter<className>(className)       \
//}                                                           \
//};\
static Register##className register_instance;

class Object : public Serializable
{
public:
	Object() = default;
	Object(const std::string& name) : name{name} {}
	virtual ~Object() = default;
	CLASS_DECLARATION(Object);
	virtual void Initialize() = 0;
	virtual void Activate()  { active = true; }
	virtual void Deactivate() { active = false; }




public:
	std::string name;
	bool active{ true };




};