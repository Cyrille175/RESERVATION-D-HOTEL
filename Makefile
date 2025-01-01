# Nom de l'exécutable

TARGET = exe


# Compilateur

CXX = g++


# Options du compilateur

CXXFLAGS = -Wall -Wextra -std=c++17


# Fichiers sources et objets

SRC = main.cpp reservation.cpp date.cpp hotel.cpp client.cpp chambre.cpp

OBJ = $(SRC:.cpp=.o)


# Règle par défaut

all: $(TARGET)


# Règle pour créer l'exécutable

$(TARGET): $(OBJ)

	$(CXX) $(CXXFLAGS) -o $@ $^


# Règle pour compiler les fichiers objets

%.o: %.cpp

	$(CXX) $(CXXFLAGS) -c $< -o $@


# Nettoyage des fichiers générés

clean:

	rm -f $(OBJ) $(TARGET)


# Phonies pour éviter les conflits avec des fichiers existants

.PHONY: all clean

