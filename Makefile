CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = main.cpp \
      Menus/SystemUtils.cpp \
      Menus/Recon.cpp \
      Menus/Exploitation.cpp \
      Menus/PrivilegeEscalation.cpp \
      Menus/Crypto.cpp \
      Menus/BruteForce.cpp \
      Menus/OSINT.cpp \
      Menus/Hints.cpp \
      Menus/ScriptsManager.cpp

HEADERS = Headers/SystemUtils.h \
          Headers/Recon.h \
          Headers/Exploitation.h \
          Headers/PrivilegeEscalation.h \
          Headers/Crypto.h \
          Headers/BruteForce.h \
          Headers/OSINT.h \
          Headers/ScriptsManager.h

OBJ = $(SRC:.cpp=.o)

EXEC = ctftool

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
