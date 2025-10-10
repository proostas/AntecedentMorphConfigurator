#include "lineedit.hpp"
#include <QContextMenuEvent>
#include <QMenu>

LineEdit::LineEdit(QWidget *parent)
    : QLineEdit{parent},
      m_insertReturnAction{new QAction{"Insert ⏎", this}},
      m_insertLeftAction{new QAction{"Insert ←", this}},
      m_insertTabAction{new QAction{"Insert ⇥", this}}
{
    m_insertReturnAction->setShortcut(QKeySequence{"Alt+R"});
    m_insertReturnAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
    addAction(m_insertReturnAction);
    m_insertLeftAction->setShortcut(QKeySequence{"Alt+L"});
    m_insertLeftAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
    addAction(m_insertLeftAction);
    m_insertTabAction->setShortcut(QKeySequence{"Alt+T"});
    m_insertTabAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
    addAction(m_insertTabAction);
    connect(m_insertReturnAction, &QAction::triggered, this, [=](){
        insert("⏎");
    });
    connect(m_insertLeftAction, &QAction::triggered, this, [this](){
        insert("←");
    });
    connect(m_insertTabAction, &QAction::triggered, this, [this](){
        insert("⇥");
    });
}

void LineEdit::contextMenuEvent(QContextMenuEvent *event)
{
    auto *menu = createStandardContextMenu();
    menu->addSeparator();
    menu->addAction(m_insertReturnAction);
    menu->addAction(m_insertLeftAction);
    menu->addAction(m_insertTabAction);
    menu->exec(event->globalPos());
}
