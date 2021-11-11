#include "MenuEntity.h"

#include <gf/Coordinates.h>
#include <gf/RenderTarget.h>

namespace flo {
  MenuEntity::MenuEntity(gf::ResourceManager& resources, MenuChoice& choice)
  : m_font(resources.getFont("LiberationSans-Regular.ttf"))
  , m_startWidget("Start", m_font)
  , m_quitWidget("Quit", m_font) {
    m_startWidget.setCallback([&choice]() { choice = MenuChoice::Start; });
    m_container.addWidget(m_startWidget);

    m_quitWidget.setCallback([&choice]() { choice = MenuChoice::Quit; });
    m_container.addWidget(m_quitWidget);
  }

  void MenuEntity::pointTo(gf::Vector2f coords) {
    m_container.pointTo(coords);
  }

  void MenuEntity::triggerAction() {
    m_container.triggerAction();
  }

  void MenuEntity::render(gf::RenderTarget& target, const gf::RenderStates& states) {
    gf::Coordinates coords(target);
    unsigned characterSize = coords.getRelativeCharacterSize(0.1f);

    auto renderTextWidget = [&coords, &characterSize, &target, &states](const gf::Vector2f& position, gf::TextWidget& widget) {
      auto widgetPosition = coords.getRelativePoint(position);
      widget.setCharacterSize(characterSize);
      widget.setAnchor(gf::Anchor::Center);
      widget.setPosition(widgetPosition);
      widget.setDefaultTextColor(gf::Color::Black);
      target.draw(widget, states);
    };

    renderTextWidget(gf::vec(0.5f, 0.4f), m_startWidget);
    renderTextWidget(gf::vec(0.5f, 0.6f), m_quitWidget);
  }
}
