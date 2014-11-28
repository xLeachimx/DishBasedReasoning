COMPILEDFILES = Case.o CaseLibrary.o CaseNode.o DBR.o DishLibrary.o Dish.o Util.o CSV.o
TEMPFOLDER = temp
PROGNAME = DishBasedReasoner

all: main

main: copy $(COMPILEDFILES)
	cd $(TEMPFOLDER) && \
	g++ $(COMPILEDFILES) main.cpp -o $(PROGNAME)
	cp $(TEMPFOLDER)/$(PROGNAME) ./

Case.o:
	cd $(TEMPFOLDER) && \
	g++ Case.cpp -c

CaseLibrary.o:
	cd $(TEMPFOLDER) && \
	g++ CaseLibrary.cpp -c

CaseNode.o:
	cd $(TEMPFOLDER) && \
	g++ CaseNode.cpp -c

DBR.o:
	cd $(TEMPFOLDER) && \
	g++ DBR.cpp -c

Dish.o:
	cd $(TEMPFOLDER) && \
	g++ Dish.cpp -c

DishLibrary.o:
	cd $(TEMPFOLDER) && \
	g++ DishLibrary.cpp -c

Util.o:
	cd $(TEMPFOLDER) && \
	g++ Util.cpp -c

CSV.o:
	cd $(TEMPFOLDER) && \
	g++ CSV.cpp -c

copy:
	mkdir $(TEMPFOLDER)
	cp Case/* $(TEMPFOLDER)
	cp CaseLibrary/* $(TEMPFOLDER)
	cp DBR/* $(TEMPFOLDER)
	cp Dish/* $(TEMPFOLDER)
	cp DishLibrary/* $(TEMPFOLDER)
	cp Utilities/* $(TEMPFOLDER)
	cp CSV/* $(TEMPFOLDER)

clean:
	rm -rf $(TEMPFOLDER)