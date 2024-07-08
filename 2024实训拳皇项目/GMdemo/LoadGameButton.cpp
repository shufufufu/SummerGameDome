#include "specialButton.h"

//µÇÂ¼ÓÎÏ·°´Å¥

LoadGameButton::LoadGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
    :Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {}

LoadGameButton::~LoadGameButton() = default;
void LoadGameButton::OnClick()
{
    is_load = true;
}

