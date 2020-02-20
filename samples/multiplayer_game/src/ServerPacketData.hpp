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

#include <crogine/detail/glm/vec3.hpp>
#include <array>

using CompressedQuat = std::array<std::int16_t, 4u>;

struct PlayerInfo final
{
    CompressedQuat rotation{};
    glm::vec3 spawnPosition = glm::vec3(0.f);
    std::uint8_t playerID = ConstVal::MaxClients;
};

struct PlayerUpdate final
{
    CompressedQuat rotation{};
    glm::vec3 position = glm::vec3(0.f);
    std::uint32_t timestamp = 0;
};