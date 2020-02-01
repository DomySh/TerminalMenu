from pynput.keyboard import Key, Listener
import os, time, platform

downComm = False
upCommand = False
returnCommand = False
Arrow = "<-"
ClearComm = "clear"

if platform.system() == "Windows":
	ClearComm="cls"

def on_press(key):
	global upCommand,downComm,returnCommand
	if key == Key.up:
		upCommand = True
		return False
	elif key == Key.down:
		downComm = True
		return False
	elif key == Key.enter:
		returnCommand = True
		return False


def StartListener():
	global upCommand,downComm,returnCommand
	downComm = False
	upCommand = False
	returnCommand = False
	with Listener(on_press=on_press) as listener:
		listener.join()

def PrintLineMenu(line,pos,arrow,SymArrow=Arrow):
	ToPrint = line
	if pos == arrow:
		ToPrint+=" "+SymArrow
	print(ToPrint)

def PrintMenu(lines,arrow,intestation,SymArrow=Arrow):
	global ClearComm
	os.system(ClearComm)
	print(intestation)
	for n in range(0,len(lines)):
		PrintLineMenu(lines[n],n,arrow,SymArrow)

def MenuCreate(voice,intestation="",SymArrow=Arrow,start=0):
	global returnCommand,upCommand,downComm
	n = start
	while not returnCommand:
		PrintMenu(voice,n,intestation,SymArrow)
		time.sleep(0.1)
		StartListener()
		if upCommand:
			if n>0:n-=1
			else:n = len(voice)-1
		elif downComm:
			if n<(len(voice)-1):n+=1
			else:n=0
	input()
	returnCommand = upCommand = downComm = False
	return n
