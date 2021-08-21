.default: all

all: qwirkle

clean:
	rm -rf qwirkle *.o *.dSYM

qwirkle: bag.o board.o coloursEmoji.o credits.o gameEngine.o help.o linkedList.o loadGame.o menu.o newGame.o node.o player.o qwirkle.o tile.o userPrompt.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
