#include <windows.h>
#include <commctrl.h>

#define ID_BUTTON 1
#define ID_TIMER 2

// props
// http://zetcode.com/gui/winapi/firststeps/

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CenterWindow(HWND);
HINSTANCE g_hinst;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow)
{
  MSG  msg;    
  WNDCLASSW wc = {0};
  wc.lpszClassName = L"Center";
  wc.hInstance     = hInstance;
  //wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
  wc.lpfnWndProc   = WndProc;
 // wc.hCursor       = LoadCursor(0, IDC_ARROW);
  
  RegisterClassW(&wc);
  CreateWindowW(wc.lpszClassName, 
  			    L"Type",
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                100, 100,
			    260, 170,
			    NULL,
			    NULL,
			    hInstance, 
			    NULL);  

  while( GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, 
    WPARAM wParam, LPARAM lParam)
{
 static HWND hwndPrgBar;
  static int i = 1;
 
  INITCOMMONCONTROLSEX InitCtrlEx;

  InitCtrlEx.dwSize = sizeof(INITCOMMONCONTROLSEX);
  InitCtrlEx.dwICC  = ICC_PROGRESS_CLASS;
  InitCommonControlsEx(&InitCtrlEx);

  switch(msg)  
  {
      case WM_CREATE:
		  CenterWindow(hwnd);
          hwndPrgBar = CreateWindowEx(0, PROGRESS_CLASS, NULL, 
                WS_CHILD | WS_VISIBLE | PBS_SMOOTH, // pbs_smooth makes no difference when manifest sets new windows styles
                30, 20, 190, 25, hwnd, NULL, g_hinst, NULL);   

          CreateWindow(TEXT("button"), TEXT("Start"), 
                WS_CHILD | WS_VISIBLE,
                85, 90, 80, 25, hwnd, (HMENU) 1, g_hinst, NULL);  

          SendMessage(hwndPrgBar, PBM_SETRANGE, 0, MAKELPARAM(0, 150));
          SendMessage(hwndPrgBar, PBM_SETSTEP, 1, 0 );
          break;


      case WM_TIMER:
          SendMessage( hwndPrgBar, PBM_STEPIT, 0, 0 );
          i++;
          if ( i == 150 ) 
              KillTimer(hwnd, ID_TIMER);
          break;
              
      case WM_COMMAND:
          i = 1;
          SendMessage( hwndPrgBar, PBM_SETPOS, 0, 0 );
          SetTimer(hwnd, ID_TIMER, 5, NULL);
          break;

      case WM_DESTROY:
          KillTimer(hwnd, ID_TIMER);
          PostQuitMessage(0);
          break; 
  }
  return DefWindowProc(hwnd, msg, wParam, lParam);
}

void CenterWindow(HWND hwnd)
{
    RECT rc;
    
    GetWindowRect(hwnd, &rc) ;
    
    SetWindowPos(hwnd, 0, 
        (GetSystemMetrics(SM_CXSCREEN) - rc.right)/2,
        (GetSystemMetrics(SM_CYSCREEN) - rc.bottom)/2,
         0, 0, SWP_NOZORDER|SWP_NOSIZE);
}
