/*-----------------------------------------------------------------------

Matt Marchant 2017
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

#ifndef CRO_UTIL_MATRIX_HPP_
#define CRO_UTIL_MATRIX_HPP_

#include <crogine/detail/glm/vec3.hpp>
#include <crogine/detail/glm/mat4x4.hpp>

namespace cro
{
    namespace Util
    {
        namespace Matrix
        {
            static inline glm::vec3 getForwardVector(const glm::mat4& mat)
            {
                return glm::vec3(-mat[2][0], -mat[2][1], -mat[2][2]);
            }

            static inline glm::vec3 getUpVector(const glm::mat4& mat)
            {
                return glm::vec3(mat[1][0], mat[1][1], mat[1][2]);
            }

            static inline glm::vec3 getRightVector(const glm::mat4& mat)
            {
                return glm::vec3(mat[0][0], mat[0][1], mat[0][2]);
            }
        }
    }
}

#endif //CRO_UTIL_MATRIX_HPP_