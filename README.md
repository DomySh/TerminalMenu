# TerminalMenu.h
A c++ Library that can create a Selection menu in termial
In this header file there are function (Compatible with Mac OSX and Windows) for create the Menu:

- MenuCreate(const std::vector<std::string> &voice,const char* intestation="",int n=0,const char* arrsym="<-")
                  ^ -> can be also an array of strings or an array of char array

For example: MenuCreate(v,"SELECT THE ANSWERE","<<:-|",1);
The is the principal function that create the menu and return the number of the position of the voice in the vector
This function is thinked to use with a switch case:

### Examples of code
```
switch(MenuCreate(...)){
  case 0:
    break;
  case 1 [...]
}
```
```
#include <iostream>
#include "TerminalMenu.h"


int main(){
  char *selection[]={"Print Hello","exit"};
  while(true){
    switch(MenuCreate( selection,2 )){
      case 0:
        std::cout << "Hello World!"<< std::endl;
        SysPause(); //Read under this example for discover this function
        break;
      case 1:
        return 0;
    }
  }
}
```

- SysPause() 
Function that simulate -> system("pause") (In windows this command corrispond to that)


- getch() 
Getch function (normaly present in conio.h) in MacOs

## Other Function

- detectKey()
- PrintLineMenu(const std::vector<std::string> &lines,int pos,int arrow,const char *SymArrow="<-")
- PrintMenu(const std::vector<std::string> &lines,int arrow,const char* intestation="",const char* arrsym="<-")
