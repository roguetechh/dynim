#pragma once

#include "VertexArray.hpp"

#include <functional>
#include <glm/vec2.hpp>

namespace Dynim {

class GameObject {
public:
  GameObject(glm::vec2 transform, VertexArray &vao) : m_Transform(transform), m_Vao(vao){};

  inline void OnUpdate(std::function<void(void *app, double delta_time)> on_update_callback) { m_On_Update_Callback = on_update_callback; };
  inline void Update(void *app, double delta_time) {
    if (m_On_Update_Callback == nullptr) {
      return;
    }
    m_On_Update_Callback(app, delta_time);
  };

  inline void Move(glm::vec2 translation) { m_Transform += translation; }
  inline glm::vec2 GetTransform() const { return m_Transform; }

  inline VertexArray *GetVao() { return &m_Vao; }

private:
  std::function<void(void *app, double delta_time)> m_On_Update_Callback;
  glm::vec2 m_Transform;
  VertexArray m_Vao;
};

} // namespace Dynim
