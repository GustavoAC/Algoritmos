### Programas
CXX = g++
DEL = /bin/rm 

### Flags de compilação
CFLAGS = -Wall -std=c++11

### O alvo do makefile (executável)
BIN_DIR = bin
TARGET = drive_compact
SRC_DIR = src
INCLUDE_DIR = include

### --------------------------------------------------------------------
### VAR = valor
### Cada entrada do Makefile/makefile segue a seguinte sintaxe:
### Regras: Dependencia_1 Dependencia_2 ...
### <tab>Comando_1
### <tab>Comando_2
### ...
###
### Uma regra pode ser um arquivo ou uma outra regra.
### --------------------------------------------------------------------

# A primeira entrada eh para o primeiro programa alvo
all: $(BIN_DIR)/$(TARGET)

# Resolvendo 1ra dependência do primeiro programa alvo.
# Essa entrada define como produzir o arquivo
$(BIN_DIR)/$(TARGET): $(BIN_DIR)/$(TARGET).o
	@echo "(2) Vou ligar!!!!"
	$(CXX) $(CFLAGS) $(BIN_DIR)/$(TARGET).o -o $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET).o: $(SRC_DIR)/$(TARGET).cpp 
	@echo "(1) Vou compilar!!!!"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(TARGET).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(TARGET).o

### Entrada principal #3
# a entrada seguinte elimina os arquivos inuteis.
clean:
	$(DEL) $(BIN_DIR)/$(TARGET) $(BIN_DIR)/$(TARGET).o
