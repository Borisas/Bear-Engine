#ifndef BEARENGINE_CMAKE_EVENTHANDLERS_H
#define BEARENGINE_CMAKE_EVENTHANDLERS_H

#include <vector>
#include <functional>
#include <map>
#include <memory>
#include <sstream>

#include "SDL.h"

#include "Util.h"
#include "Macros.h"
#include "Structures.h"

namespace BearEngine {

	class EventHandler {
	public:

		virtual bool init(){};

		virtual void handleEvents(std::vector<SDL_Event>&, BearEngine::NodeTransform) = 0;
	};

	class MouseEventHandler : public BearEngine::EventHandler{

	public:

		CREATE_FUNC(BearEngine::MouseEventHandler);

		MouseEventHandler(){};
		virtual ~MouseEventHandler(){};


		void handleEvents(std::vector<SDL_Event>&, BearEngine::NodeTransform) override;

		void setOnMouseClick(std::function<void(const SDL_Event & e, BearEngine::NodeTransform)>);
		void setOnMouseRelease(std::function<void(const SDL_Event & e, BearEngine::NodeTransform)>);
		void setOnMouseMove(std::function<void(const SDL_Event & e, BearEngine::NodeTransform)>);

	protected:

		std::function<void(const SDL_Event & e, BearEngine::NodeTransform)> _on_mouse_click    = [](const SDL_Event & e, BearEngine::NodeTransform){};
		std::function<void(const SDL_Event & e, BearEngine::NodeTransform)> _on_mouse_release  = [](const SDL_Event & e, BearEngine::NodeTransform){};
		std::function<void(const SDL_Event & e, BearEngine::NodeTransform)> _on_mouse_move     = [](const SDL_Event & e, BearEngine::NodeTransform){};
	};

	class KeyboardEventHandler : public BearEngine::EventHandler{

	public:

		CREATE_FUNC(BearEngine::KeyboardEventHandler);

		KeyboardEventHandler(){};
		virtual ~KeyboardEventHandler(){};

		void handleEvents(std::vector<SDL_Event>&, BearEngine::NodeTransform) override;

		void setKeyEvent(Uint32, std::function< void() >);
		void unsetKeyEvent(Uint32);

	private:
		std::map< Uint32, std::function< void() > > _key_map;
	};

	class SimpleKeyboardEventHandler : public BearEngine::EventHandler {

	public:

		struct Key{
			Key(Uint32 a, char b, bool c, bool d, bool e, const char* f)
					: code(a), letter(b), isShiftDown(c), isCtrlDown(d), isAltDown(e), scancodeName(f){};
			Uint32 code;
			char letter;
			bool isShiftDown;
			bool isCtrlDown;
			bool isAltDown;
			const char* scancodeName;

			std::string getString() {
				std::ostringstream ss;

				ss << "Key {\n"
				   << "\tcode : " << code << ",\n"
				   << "\tletter : " << (letter == 0 ? ' ' : letter) << ",\n"
				   << "\tisShiftDown : " << isShiftDown << ",\n"
				   << "\tisCtrlDown : " << isCtrlDown << ",\n"
				   << "\tisAltDown : " << isAltDown << ",\n"
				   << "\tscancodeName : " << scancodeName << "\n"
				   << "};\n";

				return ss.str();
			}
		};

		CREATE_FUNC(BearEngine::SimpleKeyboardEventHandler);

		SimpleKeyboardEventHandler();
		virtual ~SimpleKeyboardEventHandler();

		void handleEvents(std::vector<SDL_Event>&, BearEngine::NodeTransform) override;


		std::function<void(Key)> onKeyDown   = [](Key){};
		std::function<void(Key)> onKeyUp     = [](Key){};


	private:
		bool _shift = false;
		bool _ctrl = false;
		bool _alt = false;
	};

}


#endif //BEARENGINE_CMAKE_EVENTHANDLERS_H
