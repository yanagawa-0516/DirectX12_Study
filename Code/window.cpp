#include "window.h"
#include <tchar.h>

//コンストラクタ
Window::Window() {
	SetWindow();
}

//デストラクタ
Window::~Window() {
	//ウインドウの解放
	UnregisterClass(window.lpszClassName, window.hInstance);
}

//ウインドウハンドルの取得
HWND Window::get() const {
	return handle;
}

//ウインドウプロシージャ
LRESULT CALLBACK Window::WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	//ウインドウが破棄された場合はアプリケーション終了をOSに伝える
	if (msg == WM_DESTROY) {
		PostQuitMessage(0);
		return 0;
	}

	//何もない場合は既定の処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

//ウインドウ情報のセット、生成
void Window::SetWindow() {
	window.cbSize = sizeof(WNDCLASSEX);  //ウインドウ情報のサイズ(WNDCLASSEXのサイズ)
	window.cbClsExtra = 0;  //構造体側で確保される予備メモリ(基本的には0)
	window.cbWndExtra = 0;  //ウインドウ側で確保される予備メモリ(基本的には0)
	window.hbrBackground = CreateSolidBrush(WHITE);  //ウインドウの背景色
	window.hCursor = LoadCursor(NULL, IDC_ARROW);  //カーソルの設定
	window.hIcon = LoadIcon(NULL, IDI_APPLICATION);    //ショートカットアイコンの設定
	window.hIconSm = LoadIcon(NULL, IDI_APPLICATION);  //タイトルバーアイコンの設定
	window.hInstance = GetModuleHandle(0);  //インスタンスハンドルの指定
	window.lpfnWndProc = (WNDPROC)WindowProcedure;  //ウインドウプロシージャのアドレス
	window.lpszClassName = _T("DirectX12");   //登録時のクラス名
	window.lpszMenuName = NULL;  //タイトルメニューの設定
	window.style = CS_HREDRAW | CS_VREDRAW;   //ウインドウスタイル

	//ウインドウの登録
	RegisterClassEx(&window);

	//ウインドウサイズの設定
	rect.left = 0;
	rect.right = WINDOW_WIDTH;    //横幅
	rect.top = 0;
	rect.bottom = WINDOW_HEIGHT;  //縦幅

	//サイズの補正
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	
	//ウインドウ生成
	handle = CreateWindow(
		window.lpszClassName,
		_T("DX12 SAMPLE"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		rect.right - rect.left,
		rect.bottom - rect.top,
		nullptr,
		nullptr,
		window.hInstance,
		nullptr
	);

}

