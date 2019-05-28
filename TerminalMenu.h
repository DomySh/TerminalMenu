#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#ifdef _WIN64
	#define CLEAR_COMM "cls"
	#include <windows.h>
	int detectKey(){
		while(true){
			if(GetAsyncKeyState(VK_RETURN)<0){
				return VK_RETURN;
			}else if(GetAsyncKeyState(VK_UP)<0){
				return VK_UP;
			}else if(GetAsyncKeyState(VK_DOWN)<0){
				return VK_DOWN;
			}
		}
	}
	void SysPause(){
		std::cout<<std::endl;
		system("pause");
	}
#else
	#include <termios.h>
	#include <unistd.h>
	#define CLEAR_COMM "clear"
	#define VK_RETURN 10 
	#define VK_UP 65
	#define VK_DOWN 66
	int getch() {
		using namespace std;
		struct termios oldt,
		newt;
		int ch;
		tcgetattr( STDIN_FILENO, &oldt );
		newt = oldt;
		newt.c_lflag &= ~( ICANON | ECHO );
		tcsetattr( STDIN_FILENO, TCSANOW, &newt );
		ch = getchar();
		tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
		return ch;
	}	
	int detectKey(){
		char c;
		c = getch();
		if(c == 27){
			c = getch();
			c = getch();
		}
		return c;
	}
	void SysPause(){
		std::cout << "\nPremere un tasto per continuare...";
		getch();
		std::cout<<std::endl;
	}
#endif

std::vector<std::string> ToVec(char** arr,int len){
	using namespace std;
	vector<string> v;
	for(int i=0;i<len;i++){
		v.push_back(arr[i]);
	}
	return v;
}

void PrintLineMenu(const std::vector<std::string> &lines,int pos,int arrow,const char *SymArrow="<-"){
	using namespace std;
	cout << lines[pos];
	if(pos == arrow){
		cout << " " << SymArrow;
	}
	cout << endl;
}

void PrintMenu(const std::vector<std::string> &lines,int arrow,const char* intestation="",const char* arrsym="<-"){
	using namespace std;
	system(CLEAR_COMM);
	cout << intestation ;
	for(int i =0;i<lines.size();i++){
		PrintLineMenu(lines,i,arrow,arrsym);
	}
}

int MenuCreate(const std::vector<std::string> &voice,const char* intestation="",const char* arrsym="<-",int n=0){
	using namespace std;
	bool enter=false;
	while(!enter){
		PrintMenu(voice,n,intestation,arrsym);
		this_thread::sleep_for(chrono::milliseconds(100));
		switch(detectKey()){
			case VK_RETURN:
				enter = true;
			break;
			case VK_UP:{
				if(n>0){
					n--;
				}else{
					n=voice.size()-1;
				}
			}
			break;
			case VK_DOWN:{
				if(n<voice.size()-1){
					n++;
				}else{
					n=0;
				}
			}
			break;
		}
	}
	return n;			
}