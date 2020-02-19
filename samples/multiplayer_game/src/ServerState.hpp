/*-----------------------------------------------------------------------

Matt Marchant 2020
http://trederia.blogspot.com

crogine application - Zlib license.

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

#pragma once

#include "CommonConsts.hpp"

#include <crogine/network/NetData.hpp>
#include <crogine/network/NetHost.hpp>

#include <cstdint>
#include <array>

namespace Sv
{
    struct ClientConnection final
    {
        bool ready = false;
        bool connected = false;
        cro::NetPeer peer;
    };

    struct SharedData final
    {
        cro::NetHost host;
        std::array<Sv::ClientConnection, ConstVal::MaxClients> clients;
    };

    namespace StateID
    {
        enum
        {
            Lobby,
            Game
        };
    }

    class State
    {
    public:
        virtual void netUpdate(const cro::NetEvent&) = 0;
        virtual std::int32_t process(float) = 0;

        virtual std::int32_t stateID() const = 0;
    };

    class LobbyState final : public State
    {
    public:
        explicit LobbyState(SharedData&);

        void netUpdate(const cro::NetEvent&) override;
        std::int32_t process(float) override;

        std::int32_t stateID() const override { return StateID::Lobby; }

    private:
        std::int32_t m_returnValue;
        SharedData& m_sharedData;
    };

    class GameState final : public State
    {
    public:
        explicit GameState(SharedData&);

        void netUpdate(const cro::NetEvent&) override;
        std::int32_t process(float) override;

        std::int32_t stateID() const override { return StateID::Game; }

    private:
        std::int32_t m_returnValue;
        SharedData& m_sharedData;

        void sendInitialGameState(std::uint8_t);
        void handlePlayerInput(const cro::NetEvent::Packet&);
    };
}