#pragma once
#include <Windows.h>

const int WHITE = 0xFFFFFF;

const long WINDOW_WIDTH = 500;
const long WINDOW_HEIGHT = 300;

class Window {
public:
	Window();   //コンストラクタ
	~Window();  //デストラクタ

	HWND get() const;  //ウインドウハンドルの取得

private:
	WNDCLASSEX window; //ウインドウの情報を持つ構造体
	RECT rect;  //ウインドウのサイズを持つ構造体
	HWND handle;  //ウインドウハンドル

	static LRESULT WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);  //ウインドウプロシージャ
	void SetWindow();  //ウインドウ情報のセット、生成
};
