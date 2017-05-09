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

#ifndef TL_TERRAIN_CHUNK_HPP_
#define TL_TERRAIN_CHUNK_HPP_

#include <crogine/ecs/System.hpp>

#include <array>

struct TerrainChunk final
{
    static const std::size_t PointCount = 200;
    std::array<float, PointCount> points{};
};

class ChunkSystem final : public cro::System
{
public:
    ChunkSystem(cro::MessageBus&);

    void process(cro::Time) override;

    void handleMessage(const cro::Message&) override;

private:

    float m_speed;
    float m_currentSpeed;

    float m_topX;
    float m_bottomX; //noise coordinate

    void rebuildChunk(cro::Entity);
};

#endif //TL_TERRAIN_CHUNK_HPP_