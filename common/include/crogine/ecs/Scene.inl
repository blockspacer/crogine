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


template <typename T, typename... Args>
T& Scene::addSystem(Args&&... args)
{
    auto& system = m_systemManager.addSystem<T>(std::forward<Args>(args)...);
    if (std::is_base_of<Renderable, T>::value)
    {
        m_renderables.push_back(dynamic_cast<Renderable*>(&system));
    }
    return system;
}

template <typename T>
T& Scene::getSystem()
{
    return m_systemManager.getSystem<T>();
}

template <typename T, typename... Args>
T& Scene::addPostProcess(Args&&... args)
{
    static_assert(std::is_base_of<PostProcess, T>::value, "Must be a post process type");
    auto size = App::getWindow().getSize();
    if (!m_sceneBuffer.available())
    {
        if (m_sceneBuffer.create(size.x, size.y))
        {
            //set render path
            currentRenderPath = std::bind(&Scene::postRenderPath, this);
        }
        else
        {
            Logger::log("Failed settings scene render buffer - post process is disabled", Logger::Type::Error, Logger::Output::All);
        }
    }
    m_postEffects.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
    m_postEffects.back()->resizeBuffer(size.x, size.y);

    //create intermediate buffers if needed
    switch (m_postEffects.size())
    {
    case 2:
        m_postBuffers[0].create(size.x, size.y, false);
        break;
    case 3:
        m_postBuffers[1].create(size.x, size.y, false);
        break;
    default: break;
    }

    return *dynamic_cast<T*>(m_postEffects.back().get());
}