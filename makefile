main.exe:Dictionary.cpp User.cpp recite.cpp Interface.cpp Set.cpp Word.cpp Entry.cpp Factory.cpp main.cpp Test.cpp Question.cpp
	g++ Dictionary.cpp Set.cpp Interface.cpp recite.cpp User.cpp Word.cpp Entry.cpp Factory.cpp Test.cpp Question.cpp main.cpp -g -o main.exe
clean:
	del *.exe *.o *.out