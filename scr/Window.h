#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer {
	struct WindowSize {
		int winHeight, winWidth;
	};
	//Singleton class representing window.
	class MainWindow {
	public:
		static void CreateWindow(int width = 1000, int height = 1000) { instance.createWindow(width, height); }
		static void DeleteWindow() { instance.deleteWindow(); }
		static GLFWwindow* GetGLFWWindow(){ return instance.m_mainWindow; }
		static WindowSize GetWindowSize(){ return instance.m_mainWinSize; }
		static void SetWindowSize(int newWidth, int newHeight) { instance.m_mainWinSize = { newWidth,newHeight }; }
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