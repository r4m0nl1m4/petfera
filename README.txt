
README for "petfera" C++ application

Created by:
  Gustavo Batista de Araújo Gorgônio (ggorg03)
  Paulo Ramon Oliveira de Lima (r4m0nl1m4)

Date: 26/11/2019

No terminal, chame o makefile.

  Para compilação:	

    <user_name>@<host_name>$ make

  Para limpeza dos arquivos de compilação:

    <user_name>@<host_name>$ make clean

Exemplo de execução:
    <user_name>@<host_name>$ ./petferaAPP

    + main: O nosso programa começa na main.
      #1-> A main vai criar um objeto da classe Petfera, quando o objeto petfera é construido ele vai abrir e ler arquivo 
      petfera.txt e vai criar os objetos Animal e os Objetos Funcionario e adiciona-los no objeto Petfera.
      
      #2-> Depois a main vai acessar o método show_menu do objeto Petfera, o método show_menu é um tipo de interface criada para
      ajudar o usuário do programa de maneira intuitiva ultilizar os principais métodos da classe Petfera, e paraa ter essas caracteirsticas
      de interface faz uso de funções implementadas na biblioteca ui.h.
      #3-> A main chega ao fim, nesse momento o destrutor do objeto Petfera é chamado, e isso faz com o objeto Petfera salvar seus
      objetos da classe Animal e Funcionario naquele mesmo arquivo no inicio ele leu, esse manipulação de arquivos é feita uso das
      funções da biblioteca dados_manip.

    
    +Petfera: A classe Petfera foi criada no intuito de servir como uma interface para o usuário, mas ao mesmo tempo como
      para que usuário possa adiministra-lá, como já falamos do contrutor e do destrutor dessa classe e também falamos do método
      show_menu, vamos falar agora sobre  os demais métodos.
      
      #1 adicionar_animal-> Esse método guia o usuário a criar um objeto da classe animal e através de regular expressions que estão
      na biblioteca rexpressions e de  algumas outras funções minimiza a chance de que um objeto da classe animal seja criado de maneira 
      errada e no fim adiciona essa objeto da classe Animal no objeto vetor de animais da classe Petfera.

      #2 adicionar_funcionario -> Similar ao adicionar animal com a diferença que estamos adicionanado um Funcionario.

      #3 buscar_animal -> Por meio de filtros ajuda o usuário a encontrar um certo animal ou até um grupo de animais que atendem
      a uma mesma carateristica.

      #4 buscar_funcionario -> Nesse caso queremos analizar um certo Funcionaria, primeiro vamos selecionar se queremos analizar um
      Veterinario ou um Tratador, depois vamos filtar os funcionarios e ficar apenas com um grupo formado apenas por veterinarios
      ou apenas por tratadores, feito isso, se quisermos podemos escolher nesso grupo qual funcionario queremos analizar mais os 
      animais com que ele trabalha, podemos inclusive usar filtros para analizar ainda mais esses animais.

      #5 remover_animal -> Selecionando um animal do nosso vetor pela id dele, removemos o animal do nosso objeto Petfera.

      #6 remover_funcionario -> Similar ao remover_animal.

      -- Os métodos abaixo não são principas e o usuário não os usa a partir do método show_menu --

      #7 get_animais -> retorna um vertor de animais com os mesmos elementos do vetor de animais doobjeto Petfera

      #8 get_funcionarios -> retorna um vetor de funcionarios com os mesmos elementos do vetor de funcionarios objeto Petfera

      #9 get_veterinarios -> retorna um vetor de funcionarios, mas que só possui veterinarios

      #10 get_tratadores -> retorna um vetor de fnucionarios, mas que só possui tratadores

    + Classe Funcionario:
        A classe Funcionario é uma classe abstrata da qual as classes Veterinario e Tratador são derivadas.
        Essa classe foi pensanda dessa forma para dar mais polimorfismo para evitar que pecisemos nos preocupar se estamos usando
      um objeto da classe veterinario ou um objto da classe tratador.
        Nessa classe foram sobrecarregados os operadores << e =, para facilitar o uso desse tipo de objeto.

    + Classe Animal:
      A classe Animal, feita pra abstrairmos de maneira geral o que seria um animal, também é uma classe abstrata criada no intuito 
      de melhorar a maneira com que programamos melhorando o polimorfismo, e dela se derivam as classes Anfibio, Anfibio_Nativo, 
      Anfibio_Exotico, Ave, Ave_Nativo, Ave_Exotico, Mamifero ,Mamifero_Nativo, Mamifero_Exotico, Reptil, Reptil_Nativo e Reptil_Exotico.
      Nessa classe também sobrecarregamos o operador << para diminuir a complexidade do programa.

    + Classe Animal_Silvestre:
        Mais uma classe, mas essa se preocupa com os aspectos burocraticos de um animal, dessa classe derivamos as classe animais_exoticos
      , Animais_Nativos, e também as classes Anfibio_Nativo, Anfibio_Exotico, Ave_Nativo, Ave_Exotico, Mamifero_Nativo, Mamifero_Exotico,
    Reptil_Nativo e Reptil_Exotico.

    + E finalmetne, as classes Anfibio_Nativo, Anfibio_Exotico, Ave_Nativo, Ave_Exotico, Mamifero_Nativo, Mamifero_Exotico, Reptil_Nativo
    e Reptil_Exotico: Essas classes de multiherança, e são elas as que vamos contruir no quando estamos lendo um arquivo ou construindo usando
    o método adicionar_animal, mas não vamos utilizar seus métodos diretamento, vamos quase sempre como objetos da classe Animal, o que é
    ótimo.