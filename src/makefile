NAME = JSint

NO_WARNING =  -Wno-return-type \
	-Wno-c++11-compat-deprecated-writable-strings \
	-Wno-deprecated-register \
	-Wno-switch \

CXXFLAGS = -std=c++11 $(NO_WARNING)

OBJS = parser.o tokenizer.o ast.o utils.o main.o  ccalc.o varlist.o DeclaredFunction.o Object.o

all: $(NAME)

parser.cpp: ${NAME}.y
	bison -d -o parser.cpp ${NAME}.y

parser.hpp: parser.cpp

tokenizer.cpp: ${NAME}.l
	flex -o tokenizer.cpp ${NAME}.l

%.o: %.cpp ast.h utils.h ccalc.h varlist.hpp
	g++ -c $(CXXFLAGS) -g -o $@ $<


$(NAME): $(OBJS)
	g++ -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

# make debug - check the bison output report
debug:
	bison -d -o parser.cpp ${NAME}.y -v

clean:
	@rm -f parser.output *.o parser.cpp parser.hpp tokenizer.cpp
