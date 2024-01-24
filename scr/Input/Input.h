#pragma once
#include"../../Core/Global.h"
#include<GLFW/glfw3.h>
#include"Rendererpch.h"
namespace SpriteRenderer
{
	enum KeyCodeEnum
	{
		KEY_SPACE =GLFW_KEY_SPACE,
		KEY_APOSTROPHE =GLFW_KEY_APOSTROPHE,
		KEY_COMMA =GLFW_KEY_COMMA,
		KEY_MINUS =GLFW_KEY_MINUS,
		KEY_PERIOD =GLFW_KEY_PERIOD,
		KEY_SLASH =GLFW_KEY_SLASH,
		KEY_KEY_0 = GLFW_KEY_0,
		KEY_KEY_1 = GLFW_KEY_1,
		KEY_KEY_2 = GLFW_KEY_2,
		KEY_KEY_3 = GLFW_KEY_3,
		KEY_KEY_4 = GLFW_KEY_4,
		KEY_KEY_5 = GLFW_KEY_5,
		KEY_KEY_6 = GLFW_KEY_6,
		KEY_KEY_7 = GLFW_KEY_7,
		KEY_KEY_8 = GLFW_KEY_8,
		KEY_KEY_9 =GLFW_KEY_9,
		KEY_SEMICOLON =GLFW_KEY_SEMICOLON,
		KEY_EQUAL =GLFW_KEY_EQUAL,
		KEY_A = GLFW_KEY_A,
		KEY_B = GLFW_KEY_B,
		KEY_C = GLFW_KEY_C,
		KEY_D = GLFW_KEY_D,
		KEY_E = GLFW_KEY_E,
		KEY_F = GLFW_KEY_F,
		KEY_G = GLFW_KEY_G,
		KEY_H = GLFW_KEY_H,
		KEY_I = GLFW_KEY_I,
		KEY_J = GLFW_KEY_J,
		KEY_K = GLFW_KEY_K,
		KEY_L = GLFW_KEY_L,
		KEY_M = GLFW_KEY_M,
		KEY_N = GLFW_KEY_N,
		KEY_O = GLFW_KEY_O,
		KEY_P = GLFW_KEY_P,
		KEY_Q = GLFW_KEY_Q,
		KEY_R = GLFW_KEY_R,
		KEY_S = GLFW_KEY_S,
		KEY_T = GLFW_KEY_T,
		KEY_U = GLFW_KEY_U,
		KEY_V = GLFW_KEY_V,
		KEY_W = GLFW_KEY_W,
		KEY_X = GLFW_KEY_X,
		KEY_Y = GLFW_KEY_Y,
		KEY_Z =GLFW_KEY_Z,
		KEY_LEFT_BRACKET =GLFW_KEY_LEFT_BRACKET,
		KEY_BACKSLASH =GLFW_KEY_BACKSLASH,
		KEY_RIGHT_BRACKET =GLFW_KEY_RIGHT_BRACKET,
		KEY_GRAVE_ACCENT =GLFW_KEY_GRAVE_ACCENT,
		KEY_WORLD_1 = GLFW_KEY_WORLD_1,
		KEY_WORLD_2 =GLFW_KEY_WORLD_2,
		KEY_ESCAPE = GLFW_KEY_ESCAPE,
		KEY_ENTER = GLFW_KEY_ENTER,
		KEY_TAB = GLFW_KEY_TAB,
		KEY_BACKSPACE = GLFW_KEY_BACKSPACE,
		KEY_INSERT = GLFW_KEY_INSERT,
		KEY_DELETE = GLFW_KEY_DELETE,
		KEY_RIGHT = GLFW_KEY_RIGHT,
		KEY_LEFT = GLFW_KEY_LEFT,
		KEY_DOWN = GLFW_KEY_DOWN,
		KEY_UP = GLFW_KEY_UP,
		KEY_PAGE_UP = GLFW_KEY_PAGE_UP,
		KEY_PAGE_DOWN = GLFW_KEY_PAGE_DOWN,
		KEY_HOME = GLFW_KEY_HOME,
		KEY_END = GLFW_KEY_END,
		KEY_CAPS_LOCK = GLFW_KEY_CAPS_LOCK,
		KEY_SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK,
		KEY_NUM_LOCK = GLFW_KEY_NUM_LOCK,
		KEY_PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN,
		KEY_PAUSE = GLFW_KEY_PAUSE,
		KEY_F1 = GLFW_KEY_F1,
		KEY_F2 = GLFW_KEY_F2,
		KEY_F3 = GLFW_KEY_F3,
		KEY_F4 = GLFW_KEY_F4,
		KEY_F5 = GLFW_KEY_F5,
		KEY_F6 = GLFW_KEY_F6,
		KEY_F7 = GLFW_KEY_F7,
		KEY_F8 = GLFW_KEY_F8,
		KEY_F9 = GLFW_KEY_F9,
		KEY_F10 = GLFW_KEY_F10,
		KEY_F11 = GLFW_KEY_F11,
		KEY_F12 = GLFW_KEY_F12,
		KEY_F13 = GLFW_KEY_F13,
		KEY_F14 = GLFW_KEY_F14,
		KEY_F15 = GLFW_KEY_F15,
		KEY_F16 = GLFW_KEY_F16,
		KEY_F17 = GLFW_KEY_F17,
		KEY_F18 = GLFW_KEY_F18,
		KEY_F19 = GLFW_KEY_F19,
		KEY_F20 = GLFW_KEY_F20,
		KEY_F21 = GLFW_KEY_F21,
		KEY_F22 = GLFW_KEY_F22,
		KEY_F23 = GLFW_KEY_F23,
		KEY_F24 = GLFW_KEY_F24,
		KEY_F25 = GLFW_KEY_F25,
		KEY_KP_0 = GLFW_KEY_KP_0,
		KEY_KP_1 = GLFW_KEY_KP_1,
		KEY_KP_2 = GLFW_KEY_KP_2,
		KEY_KP_3 = GLFW_KEY_KP_3,
		KEY_KP_4 = GLFW_KEY_KP_4,
		KEY_KP_5 = GLFW_KEY_KP_5,
		KEY_KP_6 = GLFW_KEY_KP_6,
		KEY_KP_7 = GLFW_KEY_KP_7,
		KEY_KP_8 = GLFW_KEY_KP_8,
		KEY_KP_9 = GLFW_KEY_KP_9,
		KEY_KP_DECIMAL = GLFW_KEY_KP_DECIMAL,
		KEY_KP_DIVIDE = GLFW_KEY_KP_DIVIDE,
		KEY_KP_MULTIPLY = GLFW_KEY_KP_MULTIPLY,
		KEY_KP_SUBTRACT = GLFW_KEY_KP_SUBTRACT,
		KEY_KP_ADD = GLFW_KEY_KP_ADD,
		KEY_KP_ENTER = GLFW_KEY_KP_ENTER,
		KEY_KP_EQUAL = GLFW_KEY_KP_EQUAL,
		KEY_LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT,
		KEY_LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL,
		KEY_LEFT_ALT = GLFW_KEY_LEFT_ALT,
		KEY_LEFT_SUPER = GLFW_KEY_LEFT_SUPER,
		KEY_RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT,
		KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL,
		KEY_RIGHT_ALT = GLFW_KEY_RIGHT_ALT,
		KEY_RIGHT_SUPER = GLFW_KEY_RIGHT_SUPER,
		KEY_MENU =GLFW_KEY_MENU
	};

	 enum KeyStateEnum {
		KEY_NONE = GLFW_KEY_UNKNOWN,
		KEY_RELEASED = GLFW_RELEASE,
		KEY_PRESSED = GLFW_PRESS,
		KEY_HELD = GLFW_REPEAT
	};

	 enum MouseButton {

		 MOUSE_LEFT_BUTTON   = GLFW_MOUSE_BUTTON_1,
		 MOUSE_RIGHT_BUTTON	  = GLFW_MOUSE_BUTTON_2,
		 MOUSE_MIDDLE_BUTTON  = GLFW_MOUSE_BUTTON_3,
		 MOUSE_EXTRA_1_BUTTON = GLFW_MOUSE_BUTTON_4,
		 MOUSE_EXTRA_2_BUTTON = GLFW_MOUSE_BUTTON_5,
		 MOUSE_EXTRA_3_BUTTON = GLFW_MOUSE_BUTTON_6,
		 MOUSE_EXTRA_4_BUTTON = GLFW_MOUSE_BUTTON_7,
		 MOUSE_EXTRA_5_BUTTON = GLFW_MOUSE_BUTTON_8,
	};

	 class InputManager {
	 public:
		 /// <summary>
		 /// Checks to see if this key is currently beeing pressed down.
		 /// <returns>Returns true if its pressed and false if its not.</returns>
		 /// </summary>
		 static bool IsButtonPressed(KeyCodeEnum key) { return GetInstance().isKeyPressed(key); }
		 /// <summary>
		 /// Checks to see if the key is pressed on this frame only.
		 /// </summary>
		 /// <returns>Returns true if its pressed or held and false if its not.</returns>
		 static bool IsButtonDown(KeyCodeEnum key) { return GetInstance().isKeyDown(key); }
		 /// <summary>
		 /// Checks to see if this mouse key is currently beeing pressed down.
		 /// <returns>Returns true if its pressed and false if its not.</returns>
		 /// </summary>
		 static bool IsMouseButtonPressed(MouseButton button) { return GetInstance().isMouseButtonPressed(button); }
		 /// <summary>
		 /// Checks to see if this mouse key is pressed on this frame only.
		 /// </summary>
		 /// <returns>Returns true if its pressed or held and false if its not.</returns>
		 static bool IsMouseButtonDown(MouseButton button) { return GetInstance().isMouseButtonDown(button); }
		 static InputManager& GetInstance() { return inputManager; }
		 static std::unordered_map<KeyCodeEnum, KeyStateEnum>& GetKeyHash() { return GetInstance().keyState; }
		 static std::unordered_map<MouseButton, KeyStateEnum>& GetMouseHash() { return GetInstance().mouseButtonStates; }
		 static std::pair<float, float> GetMousePosition() { return GetInstance().getMousePosition(); }
		 static void SetMousePosition(std::pair<float, float> newPosition) { GetInstance().setMousePosition(newPosition); }
	 private:
		 static InputManager inputManager;
		 std::unordered_map<KeyCodeEnum, KeyStateEnum> keyState = std::unordered_map<KeyCodeEnum, KeyStateEnum>(
			 {
			  {KEY_SPACE, KEY_RELEASED },
			  {KEY_APOSTROPHE, KEY_RELEASED},
			  {KEY_COMMA, KEY_RELEASED},
			  {KEY_MINUS, KEY_RELEASED},
			  {KEY_PERIOD, KEY_RELEASED},
			  {KEY_SLASH, KEY_RELEASED},
			  {KEY_KEY_0, KEY_RELEASED},
			  {KEY_KEY_1, KEY_RELEASED},
			  {KEY_KEY_2, KEY_RELEASED},
			  {KEY_KEY_3, KEY_RELEASED},
			  {KEY_KEY_4, KEY_RELEASED},
			  {KEY_KEY_5, KEY_RELEASED},
			  {KEY_KEY_6, KEY_RELEASED},
			  {KEY_KEY_7, KEY_RELEASED},
			  {KEY_KEY_8, KEY_RELEASED},
			  {KEY_KEY_9, KEY_RELEASED},
			  {KEY_SEMICOLON, KEY_RELEASED},
			  {KEY_EQUAL, KEY_RELEASED},
			  {KEY_A, KEY_RELEASED},
			  {KEY_B, KEY_RELEASED},
			  {KEY_C, KEY_RELEASED},
			  {KEY_D, KEY_RELEASED},
			  {KEY_E, KEY_RELEASED},
			  {KEY_F, KEY_RELEASED},
			  {KEY_G, KEY_RELEASED},
			  {KEY_H, KEY_RELEASED},
			  {KEY_I, KEY_RELEASED},
			  {KEY_J, KEY_RELEASED},
			  {KEY_K, KEY_RELEASED},
			  {KEY_L, KEY_RELEASED},
			  {KEY_M, KEY_RELEASED},
			  {KEY_N, KEY_RELEASED},
			  {KEY_O, KEY_RELEASED},
			  {KEY_P, KEY_RELEASED},
			  {KEY_Q, KEY_RELEASED},
			  {KEY_R, KEY_RELEASED},
			  {KEY_S, KEY_RELEASED},
			  {KEY_T, KEY_RELEASED},
			  {KEY_U, KEY_RELEASED},
			  {KEY_V, KEY_RELEASED},
			  {KEY_W, KEY_RELEASED},
			  {KEY_X, KEY_RELEASED},
			  {KEY_Y, KEY_RELEASED},
			  {KEY_Z, KEY_RELEASED},
			  {KEY_LEFT_BRACKET, KEY_RELEASED},
			  {KEY_BACKSLASH, KEY_RELEASED},
			  {KEY_RIGHT_BRACKET, KEY_RELEASED},
			  {KEY_GRAVE_ACCENT, KEY_RELEASED},
			  {KEY_WORLD_1, KEY_RELEASED},
			  {KEY_WORLD_2, KEY_RELEASED},
			  {KEY_ESCAPE, KEY_RELEASED},
			  {KEY_ENTER, KEY_RELEASED},
			  {KEY_TAB, KEY_RELEASED},
			  {KEY_BACKSPACE, KEY_RELEASED},
			  {KEY_INSERT, KEY_RELEASED},
			  {KEY_DELETE, KEY_RELEASED},
			  {KEY_RIGHT, KEY_RELEASED},
			  {KEY_LEFT, KEY_RELEASED},
			  {KEY_DOWN, KEY_RELEASED},
			  {KEY_UP, KEY_RELEASED},
			  {KEY_PAGE_UP, KEY_RELEASED},
			  {KEY_PAGE_DOWN, KEY_RELEASED},
			  {KEY_HOME, KEY_RELEASED},
			  {KEY_END, KEY_RELEASED},
			  {KEY_CAPS_LOCK, KEY_RELEASED},
			  {KEY_SCROLL_LOCK, KEY_RELEASED},
			  {KEY_NUM_LOCK, KEY_RELEASED},
			  {KEY_PRINT_SCREEN, KEY_RELEASED},
			  {KEY_PAUSE, KEY_RELEASED},
			  {KEY_F1, KEY_RELEASED},
			  {KEY_F2, KEY_RELEASED},
			  {KEY_F3, KEY_RELEASED},
			  {KEY_F4, KEY_RELEASED},
			  {KEY_F5, KEY_RELEASED},
			  {KEY_F6, KEY_RELEASED},
			  {KEY_F7, KEY_RELEASED},
			  {KEY_F8, KEY_RELEASED},
			  {KEY_F9, KEY_RELEASED},
			  {KEY_F10, KEY_RELEASED},
			  {KEY_F11, KEY_RELEASED},
			  {KEY_F12, KEY_RELEASED},
			  {KEY_F13, KEY_RELEASED},
			  {KEY_F14, KEY_RELEASED},
			  {KEY_F15, KEY_RELEASED},
			  {KEY_F16, KEY_RELEASED},
			  {KEY_F17, KEY_RELEASED},
			  {KEY_F18, KEY_RELEASED},
			  {KEY_F19, KEY_RELEASED},
			  {KEY_F20, KEY_RELEASED},
			  {KEY_F21, KEY_RELEASED},
			  {KEY_F22, KEY_RELEASED},
			  {KEY_F23, KEY_RELEASED},
			  {KEY_F24, KEY_RELEASED},
			  {KEY_F25, KEY_RELEASED},
			  {KEY_KP_0, KEY_RELEASED},
			  {KEY_KP_1, KEY_RELEASED},
			  {KEY_KP_2, KEY_RELEASED},
			  {KEY_KP_3, KEY_RELEASED},
			  {KEY_KP_4, KEY_RELEASED},
			  {KEY_KP_5, KEY_RELEASED},
			  {KEY_KP_6, KEY_RELEASED},
			  {KEY_KP_7, KEY_RELEASED},
			  {KEY_KP_8, KEY_RELEASED},
			  {KEY_KP_9, KEY_RELEASED},
			  {KEY_KP_DECIMAL, KEY_RELEASED},
			  {KEY_KP_DIVIDE, KEY_RELEASED},
			  {KEY_KP_MULTIPLY, KEY_RELEASED},
			  {KEY_KP_SUBTRACT, KEY_RELEASED},
			  {KEY_KP_ADD, KEY_RELEASED},
			  {KEY_KP_ENTER, KEY_RELEASED},
			  {KEY_KP_EQUAL, KEY_RELEASED},
			  {KEY_LEFT_SHIFT, KEY_RELEASED},
			  {KEY_LEFT_CONTROL, KEY_RELEASED},
			  {KEY_LEFT_ALT, KEY_RELEASED},
			  {KEY_LEFT_SUPER, KEY_RELEASED},
			  {KEY_RIGHT_SHIFT, KEY_RELEASED},
			  {KEY_RIGHT_CONTROL, KEY_RELEASED},
			  {KEY_RIGHT_ALT, KEY_RELEASED},
			  {KEY_RIGHT_SUPER, KEY_RELEASED},
			  {KEY_MENU,KEY_RELEASED} });
		 std::unordered_map<MouseButton, KeyStateEnum> mouseButtonStates = std::unordered_map<MouseButton, KeyStateEnum>(
			 {
			 {MOUSE_LEFT_BUTTON    , KEY_RELEASED},
			 {MOUSE_RIGHT_BUTTON   , KEY_RELEASED},
			 {MOUSE_MIDDLE_BUTTON  , KEY_RELEASED},
			 {MOUSE_EXTRA_1_BUTTON , KEY_RELEASED},
			 {MOUSE_EXTRA_2_BUTTON , KEY_RELEASED},
			 {MOUSE_EXTRA_3_BUTTON , KEY_RELEASED},
			 {MOUSE_EXTRA_4_BUTTON , KEY_RELEASED},
			 {MOUSE_EXTRA_5_BUTTON , KEY_RELEASED}
			});
		float mouseXPos, mouseYPos;
	private:
		InputManager();
		InputManager(InputManager& copy) = delete;
		bool isKeyDown(KeyCodeEnum key);
		bool isKeyPressed(KeyCodeEnum key);
		bool isMouseButtonPressed(MouseButton button);
		bool isMouseButtonDown(MouseButton button);
		std::pair<float, float> getMousePosition() { return std::pair<float,float>(this->mouseXPos, this->mouseYPos); }
		void setMousePosition(std::pair<float, float> newPosition);
	};

	inline InputManager InputManager::inputManager;
}
