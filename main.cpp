/*   MAIN_CPP   */
/*
** Dieses Programm soll
** eine bewegbare Figur
** im Fenster darstellen.
**/
#include <iostream>
#include <print>
#include <time.h>
#include <Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
      COORD coords;
 
      HANDLE Hnd=GetStdHandle(STD_OUTPUT_HANDLE);
 
      coords.X=x -1;
      coords.Y=y -1;
      SetConsoleCursorPosition(Hnd, coords);
}

void sleep( unsigned int mseconds ){
	clock_t goal = mseconds + clock();
	while ( goal > clock() );
}

class Spielfeld{
private:
	short xProtagonist;
	short yProtagonist;
public:
	void set_xProtagonist( short xProtagonist ){
		this->xProtagonist = xProtagonist;
	}
	void set_yProtagonist( short yProtagonist ){
		this->yProtagonist = yProtagonist;
	}
	short get_xProtagonist(){
		return xProtagonist;
	}
	short get_yProtagonist(){
		return yProtagonist;
	}
	Spielfeld(){
		xProtagonist = 3;
		yProtagonist = 3;
	}
};

int main(){
	class Spielfeld spielfeld;
	const short width = 70;
	const short height = 20;
	static int counter = 0;
	short whichNumberWasPressed = 4;
	bool instructionsAreBeingRead = false;
	bool lastPressedKeyIsC = false;
	bool exit = false;
	bool pushkey = true;

	//SET CURSOR OFF

	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTitle("ArrowTracker by Robin Buck");

	ConCurInf.dwSize = 1;
	ConCurInf.bVisible = FALSE;
	
	SetConsoleCursorInfo( hOut , &ConCurInf );

	//SET CURSOR OFF END

	for( short y = 0 ; y < height ; y++ ){
		for( short x = 0 ; x < width ; x++ ){
			print(" ");
		}
		println("║");
	}
	println("══════════════════════════════════════════════════════════════════════╝");
	println("© Copyright 2011 by Robin Buck. All rights reserved.");
	print("Press i for instructions.");
	while( !exit ){
		if( GetAsyncKeyState( 0x49 ) ){
			system("cls");
			if( !instructionsAreBeingRead ){
				instructionsAreBeingRead = true;
				println("");
				println(" Use arrow keys to move the object.");
				println("");
				println(" Press 0-9 to set speed.");
				println(" 4 is set as standard speed.");
				println("");
				println(" Press c to clear the screen.");
				println("");
				print(" Press i to resume the game.");
			}
			else{
				instructionsAreBeingRead = false;
				for( short y = 0 ; y < height ; y++ ){
					for( short x = 0 ; x < width ; x++ ){
						print(" ");
					}
					println("║");
				}
				println("══════════════════════════════════════════════════════════════════════╝");
				println("© Copyright 2011 by Robin Buck. All rights reserved.");
				print("Press i for instructions.");
				pushkey = true;
			}
			sleep(100);
		}
		if( GetAsyncKeyState( 0x30 ) || GetAsyncKeyState( VK_NUMPAD0 ) ){
			whichNumberWasPressed = 0;
		}
		else if( GetAsyncKeyState( 0x31 ) || GetAsyncKeyState( VK_NUMPAD1 ) ){
			whichNumberWasPressed = 1;
		}
		else if( GetAsyncKeyState( 0x32 ) || GetAsyncKeyState( VK_NUMPAD2 ) ){
			whichNumberWasPressed = 2;
		}
		else if( GetAsyncKeyState( 0x33 ) || GetAsyncKeyState( VK_NUMPAD3 ) ){
			whichNumberWasPressed = 3;
		}
		else if( GetAsyncKeyState( 0x34 ) || GetAsyncKeyState( VK_NUMPAD4 ) ){
			whichNumberWasPressed = 4;
		}
		else if( GetAsyncKeyState( 0x35 ) || GetAsyncKeyState( VK_NUMPAD5 ) ){
			whichNumberWasPressed = 5;
		}
		else if( GetAsyncKeyState( 0x36 ) || GetAsyncKeyState( VK_NUMPAD6 ) ){
			whichNumberWasPressed = 6;
		}
		else if( GetAsyncKeyState( 0x37 ) || GetAsyncKeyState( VK_NUMPAD7 ) ){
			whichNumberWasPressed = 7;
		}
		else if( GetAsyncKeyState( 0x38 ) || GetAsyncKeyState( VK_NUMPAD8 ) ){
			whichNumberWasPressed = 8;
		}
		else if( GetAsyncKeyState( 0x39 ) || GetAsyncKeyState( VK_NUMPAD9 ) ){
			whichNumberWasPressed = 9;
		}
		if( GetAsyncKeyState( 0x43 ) && counter == 0 && !lastPressedKeyIsC && !instructionsAreBeingRead ){
			gotoxy( 1 , 1 );
			for( short y = 0 ; y < height ; y++ ){
				for( short x = 0 ; x < width ; x++ ){
					cout << ' ';
				}
				cout << endl;
			}
			gotoxy( spielfeld.get_xProtagonist() , spielfeld.get_yProtagonist() );
			print("░");
			counter += 1;
			lastPressedKeyIsC = true;
		}
		if( GetAsyncKeyState( VK_UP ) ){
			if( spielfeld.get_yProtagonist() > 1 ){
				gotoxy( spielfeld.get_xProtagonist() , spielfeld.get_yProtagonist() ) ;
				print("▲");
				spielfeld.set_yProtagonist( spielfeld.get_yProtagonist() - 1 );
			}
			pushkey = true;
		}
		else if( GetAsyncKeyState( VK_DOWN ) ){
			if( spielfeld.get_yProtagonist() < height ){
				gotoxy( spielfeld.get_xProtagonist() , spielfeld.get_yProtagonist() ) ;
				print("▼");
				spielfeld.set_yProtagonist( spielfeld.get_yProtagonist() + 1 );
			}
			pushkey = true;
		}
		else if( GetAsyncKeyState( VK_LEFT ) ){
			if( spielfeld.get_xProtagonist() > 1 ){
				gotoxy( spielfeld.get_xProtagonist() , spielfeld.get_yProtagonist() ) ;
				print("◄");
				spielfeld.set_xProtagonist( spielfeld.get_xProtagonist() - 1 );
			}
			pushkey = true;
		}
		else if( GetAsyncKeyState( VK_RIGHT ) ){
			if( spielfeld.get_xProtagonist() < width ){
				gotoxy( spielfeld.get_xProtagonist() , spielfeld.get_yProtagonist() ) ;
				print("►");
				spielfeld.set_xProtagonist( spielfeld.get_xProtagonist() + 1 );
			}
			pushkey = true;
		}
		else if( GetAsyncKeyState( VK_ESCAPE ) ){
			exit = true;
		}
		if( pushkey ){
			gotoxy( spielfeld.get_xProtagonist() , spielfeld.get_yProtagonist() );
			print("░");
			sleep( 100 / ( whichNumberWasPressed + 1 ) );
			lastPressedKeyIsC = false;
			pushkey = false;
		}
		if( 1 <= counter && counter < 40 ){
			counter += 1;
			sleep(1);
		}
		else{
			counter = 0;
		}
	}
	return 0;
}