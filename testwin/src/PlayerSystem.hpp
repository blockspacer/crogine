/*-----------------------------------------------------------------------

Matt Marchant 2017
http://trederia.blogspot.com

crogine test application - Zlib license.

This software is provided 'as-is', without any express or
implied warranty.In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions :

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.

-----------------------------------------------------------------------*/

#ifndef TL_PLAYER_SYSTEM_HPP_
#define TL_PLAYER_SYSTEM_HPP_

#include <crogine/ecs/System.hpp>

struct PlayerInfo final
{
    enum class State
    {
        Spawning, Alive, Dying, Dead
    }state = State::Spawning;
    cro::uint32 shieldEntity = 0;
    float health = 100.f;
    float maxParticleRate = 0.f;
    bool hasBombs = false;
    bool hasEmp = false;
    cro::int32 lives = 3;
};

class PlayerSystem final : public cro::System
{
public:
    PlayerSystem(cro::MessageBus&);

    void handleMessage(const cro::Message&) override;
    void process(cro::Time) override;

private:

    float m_accumulator;
    float m_respawnTime;
    float m_shieldTime;
    cro::int32 m_score;

    void updateSpawning(cro::Entity);
    void updateAlive(cro::Entity);
    void updateDying(cro::Entity);
    void updateDead(cro::Entity);

    void onEntityAdded(cro::Entity) override;
};

#endif //TL_PLAYER_SYSTEM_HPP_
