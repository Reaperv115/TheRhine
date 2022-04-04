#pragma once

#ifdef TR_PLATFORM_WINDOWS

extern Rhine::Application* Rhine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Rhine::CreateApplication();
	app->Run();
	delete app;
}

#endif // TR_PLATFORM_WINDOWS
