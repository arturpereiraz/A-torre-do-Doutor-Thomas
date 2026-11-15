# A-torre-do-Doutor-Thomas
Projeto para disciplina de Programação
# RPG: A Torre do Dr. Thomas

## 1. Identificação

- **Aluno:** [Seu nome completo]
- **Matrícula:** [Sua matrícula]
- **Linguagem de programação:** C
- **Tipo de jogo:** RPG de aventura e combate por turnos.

---

## 2. História do jogo

O mundo está ameaçado por uma experiência científica que saiu do controle.

O Dr. Thomas, um cientista responsável por pesquisas envolvendo o desenvolvimento de um soro capaz de potencializar as capacidades humanas, acabou criando algo muito mais perigoso do que imaginava. O experimento provocou mutações e deu origem a diversas criaturas monstruosas.

Com a humanidade em perigo, o jogador recebe a missão de invadir a torre do Dr. Thomas, enfrentar as criaturas que surgiram dos experimentos, derrotar o cientista e conseguir o antídoto necessário para salvar a população.

A aventura acontece em três fases, nas quais o jogador precisa percorrer um tabuleiro, enfrentar inimigos, encontrar recursos e sobreviver até chegar ao confronto final.

**Objetivo principal:** derrotar o Dr. Thomas e impedir que suas experiências continuem ameaçando a humanidade.

---

## 3. Personagens

O jogador pode escolher entre três personagens, cada um com atributos e habilidades especiais diferentes.

### 3.1 Soldado – Patrick

Especialista em combate direto, possui a maior quantidade de vida inicial e boa força de ataque.

- **Vida máxima:** 120
- **Força:** 15
- **Defesa:** 10
- **Agilidade:** 8
- **Inteligência:** 6
- **Equipamento:** Fuzil
- **Habilidade especial:** Rajada Pesada – adiciona 10 pontos ao dano do ataque.

### 3.2 General – Red Jhon

Personagem estratégico, possui alta defesa e inteligência. Sua habilidade especial permite recuperar pontos de vida durante os combates.

- **Vida máxima:** 100
- **Força:** 9
- **Defesa:** 13
- **Agilidade:** 6
- **Inteligência:** 14
- **Equipamento:** Pistola Tática
- **Habilidade especial:** Ordem de Recuo – recupera 30 pontos de vida, respeitando o limite máximo.

### 3.3 Agente – Lisbon

Personagem ágil, equilibrado e especializado em ataques rápidos e eficientes.

- **Vida máxima:** 110
- **Força:** 12
- **Defesa:** 11
- **Agilidade:** 14
- **Inteligência:** 12
- **Equipamento:** Pistola Silenciada
- **Habilidade especial:** Golpe Corpo a Corpo – realiza um ataque com dano dobrado.

**Observação:** os equipamentos são apresentados na descrição dos personagens, mas não possuem mecânicas próprias implementadas no combate.

---

## 4. Monstros e fases

O jogo possui três fases, com diferentes criaturas e níveis de dificuldade.

### 4.1 Fase 1 – Entrada da torre

**Missão:** chegar à torre do Dr. Thomas, enfrentando as primeiras criaturas resultantes do experimento.

Monstros disponíveis:

| Monstro | Vida | Ataque | Defesa |
|---|---:|---:|---:|
| Zumbi Mutante | 20 | 6 | 3 |
| Cão Infectado | 25 | 7 | 2 |
| Guarda Mutante | 30 | 8 | 4 |

**Características:**
- Zumbi Mutante: humano infectado pelo soro.
- Cão Infectado: antigo cão de guarda que sofreu mutações.
- Guarda Mutante: segurança da torre transformado pelo experimento.

### 4.2 Fase 2 – Interior da torre

**Missão:** avançar pelo interior da torre e superar criaturas mais resistentes.

Monstros disponíveis:

| Monstro | Vida | Ataque | Defesa |
|---|---:|---:|---:|
| Cientista Mutante | 40 | 9 | 5 |
| Aranha Experimental | 40 | 10 | 4 |
| Guardião Blindado | 60 | 11 | 8 |

**Características:**
- Cientista Mutante: assistente do Dr. Thomas que sofreu mutações.
- Aranha Experimental: aranha gigante desenvolvida em laboratório.
- Guardião Blindado: soldado protegido por uma armadura.

### 4.3 Fase 3 – Confronto final

**Missão:** entrar na parte final da torre, enfrentar as criaturas mais poderosas e derrotar o Dr. Thomas.

Monstros disponíveis:

| Monstro | Vida | Ataque | Defesa |
|---|---:|---:|---:|
| Quimera | 70 | 12 | 7 |
| Golem de Soro | 80 | 12 | 8 |

**Características:**
- Quimera: criatura formada pela fusão de diferentes animais.
- Golem de Soro: criatura formada por soro endurecido.

### Chefe final – Dr. Thomas

O Dr. Thomas é o responsável pela criação do soro e o principal antagonista do jogo.

| Atributo | Valor |
|---|---:|
| Vida | 100 |
| Ataque | 15 |
| Defesa | 10 |

O confronto contra o cientista representa o desafio final da aventura.

---

## 5. Dinâmica do jogo

### 5.1 Movimentação

A movimentação acontece por meio de um dado virtual de seis lados.

- O jogador inicia na posição 0 do tabuleiro.
- Para movimentar o personagem, deve digitar `1`.
- O sistema sorteia um número entre 1 e 6.
- O resultado determina quantas casas o personagem avança.
- Caso ultrapasse a última posição, o personagem permanece na casa 11.

Cada fase utiliza um tabuleiro com 12 posições, numeradas de 0 a 11.

### 5.2 Tipos de casas

O tabuleiro possui cinco tipos de eventos:

| Tipo de casa | Funcionamento |
|---|---|
| Vazia | Nenhum evento acontece. |
| Combate | O jogador enfrenta um monstro aleatório da fase atual. |
| Cura | O personagem recupera 20 pontos de vida. |
| Tesouro | O jogador recebe 10 pontos de experiência (XP). |
| Armadilha | O personagem perde 15 pontos de vida. |
| Fim | Representa a última posição do tabuleiro. |

A distribuição das casas é definida previamente no vetor `tabuleiro`.

### 5.3 Sistema de combate

O combate acontece por turnos. Quando encontra um monstro, o jogador pode escolher uma das quatro ações:

1. **Atacar:** realiza um ataque normal.
2. **Defender:** reduz pela metade o próximo dano recebido.
3. **Habilidade:** utiliza a habilidade especial do personagem.
4. **Fugir:** tenta escapar do combate por meio de um dado.

O combate continua enquanto o jogador e o monstro possuírem pontos de vida.

### 5.4 Fórmulas de ataque e dano

O dano do jogador em um ataque normal é calculado pela fórmula:

`Dano = D20 + Força do jogador - Defesa do monstro`

O valor mínimo de dano é 1.

O D20 utilizado no jogo é um número aleatório entre 1 e 20.

**Dano das habilidades especiais:**

- **Soldado:** D20 + Força + 10 - Defesa do monstro.
- **General:** recupera 30 pontos de vida, limitado à vida máxima.
- **Agente:** (D20 + Força - Defesa do monstro) × 2.

No caso do Agente, o dano mínimo da habilidade especial é 2.

**Dano causado pelo monstro:**

`Dano = D20 + Ataque do monstro - Defesa do jogador`

O dano mínimo é 1.

Quando o jogador escolhe defender, o dano recebido do monstro é dividido por 2.

### 5.5 Sistema de fuga

Para fugir de um combate, o jogador precisa lançar um dado de seis lados.

- Resultado igual ou superior a 4: fuga bem-sucedida.
- Resultado inferior a 4: a fuga falha e o monstro pode atacar.

### 5.6 Recompensas

Durante a aventura, o jogador pode encontrar:

- **Kit médico:** recupera 20 pontos de vida.
- **Tesouro:** concede 10 pontos de experiência.
- **Vitória em combate:** permite continuar a aventura sem a ameaça daquele monstro.

Os pontos de experiência são armazenados no personagem, mas o sistema de evolução de nível ainda não está implementado.

### 5.7 Condições de vitória e derrota

**Vitória:**
- Avançar pelas três fases.
- Chegar ao confronto contra o Dr. Thomas.
- Derrotar o chefe final para concluir a missão de salvar a humanidade.

**Derrota:**
- O personagem perde todos os seus pontos de vida.
- Quando a vida chega a zero, o jogo apresenta a mensagem `Game-over!`.

---

## 6. Tutorial de compilação e execução

O jogo foi desenvolvido na linguagem C e utiliza bibliotecas padrão, como `stdio.h`, `stdlib.h`, `time.h` e `string.h`.

### 6.1 Pré-requisitos

Para compilar e executar o jogo, é necessário possuir:

- Um compilador C, como o GCC.
- Um terminal ou prompt de comando.
- O arquivo `main.c`.

### 6.2 Linux

**1. Verificar se o GCC está instalado:**

```bash
gcc --version
```

Caso não esteja instalado, em distribuições Ubuntu ou Debian, execute:

```bash
sudo apt update
sudo apt install build-essential
```

**2. Acessar a pasta do projeto:**

```bash
cd caminho/da/pasta
```

**3. Compilar o jogo:**

```bash
gcc main.c -o jogo
```

**4. Executar:**

```bash
./jogo
```

### 6.3 Windows

Com o GCC instalado por meio do MinGW-w64 ou MSYS2:

**1. Abrir o terminal na pasta do projeto.**

**2. Compilar:**

```bash
gcc main.c -o jogo.exe
```

**3. Executar:**

```bash
.\jogo.exe
```

**Observação:** a função responsável por limpar a tela utiliza o comando `clear`, próprio de ambientes Linux/macOS. Para execução adequada no Windows, é necessário adaptar essa função para utilizar `cls` no Windows.

### 6.4 macOS

Com o compilador Clang instalado pelas ferramentas de linha de comando do Xcode:

**1. Compilar:**

```bash
clang main.c -o jogo
```

**2. Executar:**

```bash
./jogo
```

---

## 7. Estrutura do código

O código foi organizado em estruturas, enumerações e funções para facilitar a organização e o funcionamento do jogo.

### 7.1 Bibliotecas utilizadas

| Biblioteca | Finalidade |
|---|---|
| `stdio.h` | Entrada e saída de dados, utilizando `printf` e `scanf`. |
| `stdlib.h` | Geração de números aleatórios e execução de comandos do sistema. |
| `time.h` | Inicialização da geração aleatória com base no horário. |
| `string.h` | Manipulação de textos, utilizando `strcpy`. |

### 7.2 Enumerações

**Classe**

Define as três classes disponíveis para o jogador:

- `SOLDADO`
- `GENERAL`
- `AGENTE`

**casas**

Define os tipos de posições existentes no tabuleiro:

- `VAZIA`
- `COMBATE`
- `CURA`
- `TESOURO`
- `ARMADILHA`
- `FIM`

### 7.3 Estruturas (struct)

**Personagem**

Armazena as informações do personagem escolhido:

- Nome;
- Classe;
- Vida atual e vida máxima;
- Força;
- Defesa;
- Agilidade;
- Inteligência;
- Experiência (XP);
- Nível.

**Monstro**

Armazena as informações dos inimigos:

- Nome;
- Descrição;
- Vida;
- Ataque;
- Defesa.

### 7.4 Principais variáveis globais

**tabuleiro[12]**

Vetor global que armazena a sequência de casas percorridas pelo jogador durante as fases.

### 7.5 Principais funções

| Função | Responsabilidade |
|---|---|
| `limpartela()` | Limpa a tela do terminal. |
| `lancar_dados()` | Gera um número aleatório entre 1 e 6. |
| `dado_dano()` | Gera um número aleatório entre 1 e 20 para os cálculos de dano. |
| `criarPersonagem()` | Inicializa os atributos do personagem escolhido. |
| `andar()` | Atualiza a posição do jogador no tabuleiro. |
| `monstrosFase1()` | Define os monstros da primeira fase. |
| `monstrosFase2()` | Define os monstros da segunda fase. |
| `monstrosFase3()` | Define os monstros da terceira fase. |
| `criar_monstro()` | Seleciona e inicializa um monstro de acordo com a fase. |
| `criardoutor()` | Inicializa os atributos do chefe final. |
| `combate()` | Controla o sistema de combate entre personagem e monstro. |
| `combatefinal()` | Executa o confronto contra o Dr. Thomas. |
| `evento_casa()` | Identifica e executa o evento da casa em que o jogador caiu. |
| `primeira_fase()` | Controla a primeira etapa da aventura. |
| `segunda_fase()` | Controla a segunda etapa da aventura. |
| `terceira_fase()` | Controla a terceira etapa da aventura e o confronto final. |
| `descricao_personagens()` | Exibe as características dos personagens disponíveis. |
| `Escolher_personagem()` | Permite selecionar a classe do jogador. |
| `MensagemInicial()` | Apresenta a história e inicia a aventura. |
| `main()` | Inicializa o jogo e controla o fluxo principal da execução. |

---

## 8. Considerações finais

O projeto tem como objetivo desenvolver um jogo de RPG em linguagem C, aplicando conceitos fundamentais de programação, como estruturas de dados, enumerações, funções, estruturas condicionais, laços de repetição, ponteiros e geração de números aleatórios.

A organização do jogo em personagens, monstros, fases e eventos permite trabalhar diferentes conceitos de lógica de programação em uma aplicação interativa.

O jogador precisa tomar decisões estratégicas durante os combates e administrar seus pontos de vida para conseguir chegar ao desafio final: derrotar o Dr. Thomas e salvar a humanidade.
