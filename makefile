main.exe:Dictionary.o User.o recite.o Interface.o Set.o Word.o Entry.o Test.o Question.o  main.o AdjEntry.o AdjEntryFactory.o AdvEntry.o AdvEntryFactory.o ConjEntryFactory.o ConjEntry.o EntryFactory.o NounEntry.o NounEntryFactory.o PrepEntry.o PrepEntryFactory.o PronEntry.o PronEntryFactory.o QuestionFirst.o QuestionSecondChoose.o QuestionSecondFillBlank.o VerbEntry.o VerbEntryFactory.o WordFactory.o operation.o
	g++ Dictionary.o User.o recite.o Interface.o Set.o Word.o Entry.o Test.o Question.o  main.o AdjEntry.o AdjEntryFactory.o AdvEntry.o AdvEntryFactory.o ConjEntryFactory.o ConjEntry.o EntryFactory.o NounEntry.o NounEntryFactory.o PrepEntry.o PrepEntryFactory.o PronEntry.o PronEntryFactory.o QuestionFirst.o QuestionSecondChoose.o QuestionSecondFillBlank.o VerbEntry.o VerbEntryFactory.o WordFactory.o operation.cpp -g -o main.exe
AdjEntry.o:AdjEntry.cpp AdjEntry.h
	g++ AdjEntry.cpp -c
AdjEntryFactory.o:AdjEntryFactory.cpp AdjEntryFactory.h
	g++ AdjEntryFactory.cpp -c
AdvEntry.o:AdvEntry.cpp AdvEntry.h
	g++ AdvEntry.cpp -c
AdvEntryFactory.o:AdvEntryFactory.cpp AdvEntryFactory.h
	g++ AdvEntryFactory.cpp -c
ConjEntry.o:ConjEntry.cpp ConjEntry.h
	g++ ConjEntry.cpp -c
ConjEntryFactory.o:ConjEntryFactory.cpp ConjEntryFactory.h
	g++ ConjEntryFactory.cpp -c
NounEntry.o:NounEntry.cpp NounEntry.h
	g++ NounEntry.cpp -c
NounEntryFactory.o:NounEntryFactory.cpp NounEntryFactory.h
	g++ NounEntryFactory.cpp -c
VerbEntry.o:VerbEntry.cpp VerbEntry.h
	g++ VerbEntry.cpp -c
VerbEntryFactory.o:VerbEntryFactory.cpp VerbEntryFactory.h
	g++ VerbEntryFactory.cpp -c
PronEntry.o:PronEntry.cpp PronEntry.h
	g++ PronEntry.cpp -c
PronEntryFactory.o:PronEntryFactory.cpp PronEntryFactory.h
	g++ PronEntryFactory.cpp -c
PrepEntry.o:PrepEntry.cpp PrepEntry.h
	g++ PrepEntry.cpp -c
PrepEntryFactory.o:PrepEntryFactory.cpp PrepEntryFactory.h
	g++ PrepEntryFactory.cpp -c
Question.o:Question.cpp Question.h
	g++ Question.cpp -c
QuestionFirst.o:QuestionFirst.cpp QuestionFirst.h
	g++ QuestionFirst.cpp -c
QuestionSecondChoose.o:QuestionSecondChoose.cpp QuestionSecondChoose.h
	g++ QuestionSecondChoose.cpp -c
QuestionSecondFillBlank.o:QuestionSecondFillBlank.cpp QuestionSecondFillBlank.h
	g++ QuestionSecondFillBlank.cpp -c
Dictionary.o:Dictionary.cpp Dictionary.h
	g++ Dictionary.cpp -c
Entry.o:Entry.cpp Entry.h
	g++ Entry.cpp -c
EntryFactory.o:Entry.cpp EntryFactory.h
	g++ EntryFactory.cpp -c
Factory.o:Factory.cpp Factory.h
	g++ Factory.cpp -c
Interface.o:Interface.cpp Interface.h
	g++ Interface.cpp -c
Set.o:Set.cpp Set.h
	g++ Set.cpp -c
Test.o:Test.cpp Test.h
	g++ Test.cpp -c
User.o:User.cpp User.h
	g++ User.cpp -c
Word.o:Word.cpp Word.h
	g++ Word.cpp -c
WordFactory.o:WordFactory.cpp WordFactory.h
	g++ WordFactory.cpp -c
operation.o:operation.cpp operation.h
	g++ operation.cpp -c
recite.o:recite.cpp recite.h
	g++ recite.cpp -c
clean:
	del *.exe *.o *.out