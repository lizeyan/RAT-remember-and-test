RAT = Dictionary.o User.o recite.o Interface.o \
	consoleInterface.o Set.o Word.o Entry.o Test.o \
	Question.o  main.o AdjEntry.o AdjEntryFactory.o \
	AdvEntry.o AdvEntryFactory.o ConjEntryFactory.o \
	ConjEntry.o EntryFactory.o NounEntry.o \
	NounEntryFactory.o PrepEntry.o PrepEntryFactory.o \
	PronEntry.o PronEntryFactory.o QuestionFirst.o \
	QuestionSecondChoose.o QuestionSecondFillBlank.o \
	VerbEntry.o VerbEntryFactory.o WordFactory.o operation.o
REMOVE = rm
TYPE = -g
main.exe:$(RAT)
	g++ -o main.exe $(RAT) $(TYPE)
AdjEntry.o:AdjEntry.cpp AdjEntry.h
	g++ AdjEntry.cpp -c $(TYPE)
AdjEntryFactory.o:AdjEntryFactory.cpp AdjEntryFactory.h
	g++ AdjEntryFactory.cpp -c $(TYPE)
AdvEntry.o:AdvEntry.cpp AdvEntry.h
	g++ AdvEntry.cpp -c $(TYPE)
AdvEntryFactory.o:AdvEntryFactory.cpp AdvEntryFactory.h
	g++ AdvEntryFactory.cpp -c $(TYPE)
ConjEntry.o:ConjEntry.cpp ConjEntry.h
	g++ ConjEntry.cpp -c $(TYPE)
ConjEntryFactory.o:ConjEntryFactory.cpp ConjEntryFactory.h
	g++ ConjEntryFactory.cpp -c $(TYPE)
NounEntry.o:NounEntry.cpp NounEntry.h
	g++ NounEntry.cpp -c $(TYPE)
NounEntryFactory.o:NounEntryFactory.cpp NounEntryFactory.h
	g++ NounEntryFactory.cpp -c $(TYPE)
VerbEntry.o:VerbEntry.cpp VerbEntry.h
	g++ VerbEntry.cpp -c $(TYPE)
VerbEntryFactory.o:VerbEntryFactory.cpp VerbEntryFactory.h
	g++ VerbEntryFactory.cpp -c $(TYPE)
PronEntry.o:PronEntry.cpp PronEntry.h
	g++ PronEntry.cpp -c $(TYPE)
PronEntryFactory.o:PronEntryFactory.cpp PronEntryFactory.h
	g++ PronEntryFactory.cpp -c $(TYPE)
PrepEntry.o:PrepEntry.cpp PrepEntry.h
	g++ PrepEntry.cpp -c $(TYPE)
PrepEntryFactory.o:PrepEntryFactory.cpp PrepEntryFactory.h
	g++ PrepEntryFactory.cpp -c $(TYPE)
Question.o:Question.cpp Question.h
	g++ Question.cpp -c $(TYPE)
QuestionFirst.o:QuestionFirst.cpp QuestionFirst.h
	g++ QuestionFirst.cpp -c $(TYPE)
QuestionSecondChoose.o:QuestionSecondChoose.cpp QuestionSecondChoose.h
	g++ QuestionSecondChoose.cpp -c $(TYPE)
QuestionSecondFillBlank.o:QuestionSecondFillBlank.cpp QuestionSecondFillBlank.h
	g++ QuestionSecondFillBlank.cpp -c $(TYPE)
Dictionary.o:Dictionary.cpp Dictionary.h
	g++ Dictionary.cpp -c $(TYPE)
Entry.o:Entry.cpp Entry.h
	g++ Entry.cpp -c $(TYPE)
EntryFactory.o:Entry.cpp EntryFactory.h
	g++ EntryFactory.cpp -c $(TYPE)
Factory.o:Factory.cpp Factory.h
	g++ Factory.cpp -c $(TYPE)
Interface.o:Interface.cpp Interface.h
	g++ Interface.cpp -c $(TYPE)
consoleInterface.o:consoleInterface.cpp consoleInterface.h
	g++ consoleInterface.cpp -c $(TYPE)
Set.o:Set.cpp Set.h
	g++ Set.cpp -c $(TYPE)
Test.o:Test.cpp Test.h
	g++ Test.cpp -c $(TYPE)
User.o:User.cpp User.h
	g++ User.cpp -c $(TYPE)
Word.o:Word.cpp Word.h
	g++ Word.cpp -c $(TYPE)
WordFactory.o:WordFactory.cpp WordFactory.h
	g++ WordFactory.cpp -c $(TYPE)
operation.o:operation.cpp operation.h
	g++ operation.cpp -c $(TYPE)
recite.o:recite.cpp recite.h
	g++ recite.cpp -c $(TYPE)
clean:
	$(REMOVE) *.exe *.o *.out
