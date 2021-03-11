a.out: main.c
	clang --target=arm64-apple-darwin20.1.0 -O main.c -g
	codesign -s - a.out
