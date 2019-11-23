# TerminalMenu.h
A c++ Library that can create a Selection menu in termial
In this header file there are function (Compatible with Mac OSX and Windows) for create the Menu:

- MenuCreate(const std::vector<std::string> &voice,const char* intestation="",int n=0,const char* arrsym="<-")

For example: MenuCreate(v,"SELECT THE ANSWERE","<<:-|",1);
The is the principal function that create the menu and return the number of the position of the voice in the vector
This function is thinked to use with a switch case:

## IMPORTANT
### IF YOU WANT TO USE INPUT WHILE USING MENU CREATE FUNCTION YOU MUST USE "getLine(cin,{string})"

### Example of code
```
switch(MenuCreate(...)){
  case 0:
    break;
  case 1 [...]
}
```
- ToVec(std::string arr[],int len) 
Simple function for convert Array of strings in vector of string

### Example of code
```
char *selection[]={"sel 1","sel 2","sel 3",};
int answer = MenuCreate( ToVec(selection) );
```

- SysPause() 
Stupid function that simulate -> system("pause") (In windows this command corrispond to that)


- getch() 
Getch function (normaly present in conio.h) in MacOs

## Other Function

- detectKey()
- PrintLineMenu(const std::vector<std::string> &lines,int pos,int arrow,const char *SymArrow="<-")
- PrintMenu(const std::vector<std::string> &lines,int arrow,const char* intestation="",const char* arrsym="<-")
