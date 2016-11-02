all:
	clang++ -w main.cpp assets.cpp fileReader.cpp player.cpp words.cpp -o hangmancpp

clean:
	rm hangmancpp
