.PHONY: clean all

all:
	@ clang -dynamiclib codesign_fix.cpp -L. -lsubstrate -o codesign_fix.dylib
	
clean:
	@ rm -f codesign_fix.dylib
