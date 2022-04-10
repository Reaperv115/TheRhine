#pragma once
#include "DXApp.h"

extern Rhine::DXApp* Rhine::CreateDXApp();

int wWinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR    lpCmdLine,
    int       nCmdShow)
{
    auto app = Rhine::CreateDXApp();
    app->RunMessageLoop();
    delete app;
}
