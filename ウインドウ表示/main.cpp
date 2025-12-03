#include "window.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	Window* win = new Window();
	MSG msg = {};  //メッセージを格納する構造体

	//ウインドウ表示
	ShowWindow(win->get(), SW_SHOW);

	while (msg.message != WM_QUIT) {
		//送信されたメッセージを取得
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);  //文字メッセージに変換
			DispatchMessage(&msg);   //ウインドウプロシージャにメッセージを送信
		}
	}

	delete win;

	return 0;
}