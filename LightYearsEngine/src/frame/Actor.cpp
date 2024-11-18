#include <frame/Actor.h>
#include <frame/Core.h>

namespace ly
{
    Actor::Actor(ly::World *owningWorld)
          : mOwningWorld(owningWorld),
            mHasBeganPlay(false)
    {

    }

    void Actor::BeginPlayInternal()
    {
        if (mHasBeganPlay)
        {
            mHasBeganPlay = true;
            BeginPlay();
        }
    }

    void Actor::BeginPlay()
    {
        LOG("Actor begin play!");
    }

    void Actor::Tick(float deltaTime)
    {
        LOG("Actor ticking!");
    }

    Actor::~Actor()
    {

    }
}