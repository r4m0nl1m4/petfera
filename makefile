
#Makefile for "concessionarias" C++ application
#Created by r4m0nl1m4 29/10/2019

#executável
PROG = concessionarias								
#compilador
CC = g++
#diretorio
DIR = pwd
#diretivas de compilação
CPPFLAGS = -O0       \
           -g        \
           -Wall     \
           -ansi     \
           -pedantic \
           -DIR      
#diretivas para o ligador (linker)
LDFLAGS = -DIR
#arquivos objetos definidos como pré-requisito
OBJS = main.o                                            \
       dealerships/concessionarias.o                     \
       dealerships/vehicles/veiculos.o                   \
       dealerships/vehicles/automobiles/automoveis.o     \
       dealerships/vehicles/automobiles/list/caminhoes.o \
       dealerships/vehicles/automobiles/list/motos.o					

#regra de construção do executável
$(PROG):$(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)			

#regra de construção dos arquivos objetos
main.o:
	$(CC) $(CPPFLAGS) -c main.cpp

concessionarias.o : concessionarias.h
	$(CC) $(CPPFLAGS) -c concessionarias.cpp

veiculos.o : vehicles/estoque.h vehicles/veiculos.h 
	$(CC) $(CPPFLAGS) -c vehicles/veiculos.cpp

automoveis.o : vehicles/automobiles/automoveis.h
	$(CC) $(CPPFLAGS) -c vehicles/automoveis.cpp

caminhoes.o : vehicles/automobiles/list/caminhoes.h
	$(CC) $(CPPFLAGS) -c vehicles/automobiles/list/caminhoes.cpp

motos.o : vehicles/automobiles/list/motos.h
	$(CC) $(CPPFLAGS) -c vehicles/automobiles/list/motos.cpp

#regra de limpeza dos arquivos
clean:
	rm -rf core $(PROG) $(OBJS)