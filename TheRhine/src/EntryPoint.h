#pragma once

#ifdef TR_PLATFORM_WINDOWS

extern Rhine::DXApp* Rhine::CreateDXApp();


int main(int argc, char** argv)
{
	auto app = Rhine::CreateDXApp();
	app->Run();
	delete app;
}

#endif // TR_PLATFORM_WINDOWS
