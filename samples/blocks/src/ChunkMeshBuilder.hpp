/*-----------------------------------------------------------------------

Matt Marchant 2017 - 2020
http://trederia.blogspot.com

crogine - Zlib license.

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

#include <crogine/graphics/MeshBuilder.hpp>

/*
custom mesh builder creates an empty mesh with the
correct attributes for a chunk mesh. The VBO itself
is updated by the ChunkRenderer system.
*/
class ChunkMeshBuilder final : public cro::MeshBuilder
{
public:
    ChunkMeshBuilder();

    //return 0 and each mesh gets an automatic ID
    //from the mesh resource, prevents returning the
    //same instance each time...

    //TODO could also use the chunk position hash here
    //but it's unlikely a chunk gets completely recreated
    std::size_t getUID() const override { return 0; }

private:

    cro::Mesh::Data build() const override;
};