#include "specialButton.h"

//×¢²áÓÎÏ·°´Å¥

RegisterGameButton::RegisterGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
    :Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {}

RegisterGameButton::~RegisterGameButton() = default;
void RegisterGameButton::OnClick()
{
    is_to_play = true;
}

