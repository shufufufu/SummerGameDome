#include "specialButton.h"

//ÍË³öÓÎÏ·°´Å¥

QuitGameButton::QuitGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
        :Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {}

QuitGameButton::~QuitGameButton() = default;
void QuitGameButton::OnClick()
    {
        running = false;
        PostQuitMessage(0);
    }

