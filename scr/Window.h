#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer {
	struct WindowSize {
		int winHeight, winWidth;
	};
	class MainWindow {
	public:
		static void CreateWindow(int widht = 1000, int height = 1000) { instance.createWindow(widht, height); }
		static void DeleteWindow() { instance.deleteWindow(); }
		static GLFWwindow* GetGLFWWindow(){ return instance.m_mainWindow; }
		static WindowSize GetWindowSize(){ return instance.m_mainWinSize; }
		static void SetWindowSize(int newWidht, int newheight) { instance.m_mainWinSize = { newWidht,newheight }; }
	private:
		 void createWindow(int widht = 1000, int height = 1000);
		 void deleteWindow();
	private:
		GLFWwindow* m_mainWindow;
		WindowSize m_mainWinSize;
		static MainWindow instance;
	};
	inline MainWindow MainWindow::instance;
}