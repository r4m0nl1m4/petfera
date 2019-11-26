
#Makefile for "petfera" C++ application
#Created by r4m0nl1m4 29/10/2019

#
#variáveis de controle
#

#executável
PROG = petferaAPP								
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
OBJS = main.o                                             \
			 petfera/dados/dados_manip.o                        \
			 petfera/funcionario/funcionario.o                  \
			 petfera/funcionario/tratador/tratador.o            \
			 petfera/funcionario/veterinario/veterinario.o      \
			 petfera/animal/classes/anfibio/anfibio.o           \
			 petfera/animal/classes/anfibio/anfibio_nativo.o    \
			 petfera/animal/classes/anfibio/anfibio_exotico.o   \
			 petfera/animal/classes/ave/ave.o                   \
			 petfera/animal/classes/ave/ave_nativo.o            \
			 petfera/animal/classes/ave/ave_exotico.o           \
			 petfera/animal/classes/mamifero/mamifero.o         \
			 petfera/animal/classes/mamifero/mamifero_nativo.o  \
			 petfera/animal/classes/mamifero/mamifero_exotico.o \
			 petfera/animal/classes/reptil/reptil.o             \
			 petfera/animal/classes/reptil/reptil_nativo.o      \
			 petfera/animal/classes/reptil/reptil_exotico.o

#
#regra de construção do executável
#
$(PROG):$(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)			

#
#regra de construção dos arquivos objetos
#

main.o:
	$(CC) $(CPPFLAGS) -c main.cpp

#dados

dados_manip.o : dados/dados_manip.h
	$(CC) $(CPPFLAGS) -c dados/dados_manip.cpp

#funcionarios

funcionarios.o : funcionario/funcionario.h
	$(CC) $(CPPFLAGS) -c funcionario/funcionario.cpp

tratador.o : funcionario/tratador/tratador.h
	$(CC) $(CPPFLAGS) -c funcionario/tratador/tratador.cpp

veterinario.o : funcionario/veterinario/veterinario.h
	$(CC) $(CPPFLAGS) -c funcionario/veterinario/veterinario.cpp

#anfibio

anfibio.o : animal/classes/anfibio/anfibio.h
	$(CC) $(CPPFLAGS) -c animal/classes/anfibio/anfibio.cpp

anfibio_nativo.o : animal/classes/anfibio/anfibio_nativo.h
	$(CC) $(CPPFLAGS) -c animal/classes/anfibio/anfibio_nativo.cpp

anfibio_exotico.o : animal/classes/anfibio/anfibio_exotico.h
	$(CC) $(CPPFLAGS) -c animal/classes/anfibio/anfibio_exotico.cpp

#ave

ave.o : animal/classes/ave/ave.h
	$(CC) $(CPPFLAGS) -c /animal/classes/ave/ave.cpp

ave_nativo.o : animal/classes/ave/ave_nativo.h
	$(CC) $(CPPFLAGS) -c animal/classes/ave/ave_nativo.cpp

ave_exotico.o : animal/classes/ave/ave_exotico.h
	$(CC) $(CPPFLAGS) -c animal/classes/ave/ave_exotico.cpp

#mamífero

mamifero.o : animal/classes/mamifero/mamifero.h
	$(CC) $(CPPFLAGS) -c animal/classes/mamifero/mamifero.cpp

mamifero_nativo.o : petfera/animal/classes/mamifero/mamifero_nativo.h
	$(CC) $(CPPFLAGS) -c animal/classes/mamifero/mamifero_nativo.cpp

mamifero_exotico.o : petfera/animal/classes/mamifero/mamifero_exotico.h
	$(CC) $(CPPFLAGS) -c animal/classes/mamifero/mamifero_exotico.cpp

#réptil

reptil.o : petfera/animal/classes/reptil/reptil.h
	$(CC) $(CPPFLAGS) -c animal/classes/reptil/reptil.cpp

reptil_nativo.o : petfera/animal/classes/reptil/reptil_nativo.h
	$(CC) $(CPPFLAGS) -c animal/classes/reptil/reptil_nativo.cpp

reptil_exotico.o : petfera/animal/classes/reptil/reptil_exotico.h
	$(CC) $(CPPFLAGS) -c animal/classes/reptil/reptil_exotico.cpp

#
#regra de limpeza dos arquivos
#
clean:
	rm -rf core $(PROG) $(OBJS)