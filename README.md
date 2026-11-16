# 🎮 A Torre do Dr. Thomas

## 1. Identificação

- **Aluno:** Artur Pereira Lino
- **Matrícula:** 20260010534
- **Linguagem:** C
- **Gênero:** RPG de aventura e combate.

## 2. História do jogo

O Dr. Thomas desenvolveu um soro capaz de aumentar as capacidades humanas. Porém, seu experimento saiu do controle e acabou criando diversos monstros.

O jogador recebe a missão de invadir a torre, enfrentar as criaturas, derrotar o cientista e salvar a humanidade.

O jogo possui três fases e um chefe final.

## 3. Personagens

O jogador pode escolher entre três personagens, cada um com características e habilidades especiais.

### Patrick – Soldado
- **Vida:** 120
- **Força:** 15
- **Defesa:** 10
- **Agilidade:** 8
- **Inteligência:** 6
- **Equipamento:** Fuzil.
- **Habilidade especial:** Rajada Pesada, adiciona 10 pontos de dano ao ataque.

### Red Jhon – General
- **Vida:** 100
- **Força:** 9
- **Defesa:** 13
- **Agilidade:** 6
- **Inteligência:** 14
- **Equipamento:** Pistola Tática.
- **Habilidade especial:** Ordem de Recuo, recupera 30 pontos de vida.
- 
### Lisbon – Agente
- **Vida:** 110
- **Força:** 12
- **Defesa:** 11
- **Agilidade:** 14
- **Inteligência:** 12
- **Equipamento:** Pistola Silenciada.
- **Habilidade especial:** Golpe Corpo a Corpo, causa dano dobrado.

## 4. Monstros e fases

### Fase 1 – Entrada da torre

**Missão:** chegar à torre do Dr. Thomas.

- **Zumbi Mutante:** humano infectado pelo soro.
- **Cão Infectado:** cão de guarda que sofreu mutações.
- **Guarda Mutante:** segurança da torre transformado pelo experimento.

### Fase 2 – Interior da torre

**Missão:** avançar pelo interior da torre.

- **Cientista Mutante:** assistente do Dr. Thomas.
- **Aranha Experimental:** aranha gigante de laboratório.
- **Guardião Blindado:** soldado protegido por uma armadura.

### Fase 3 – Confronto final

**Missão:** enfrentar as últimas criaturas e derrotar o cientista.

- **Quimera:** fusão de vários animais.
- **Golem de Soro:** criatura formada por soro endurecido.

### Final – Dr. Thomas

O responsável pela criação do soro e principal inimigo do jogo.

- **Vida:** 100
- **Ataque:** 15
- **Defesa:** 10

## 5. Como funciona o jogo

### Movimentação

- O jogador utiliza um dado de 6 lados para avançar.
- Cada fase possui um tabuleiro com 12 casas.
- O objetivo é chegar ao final do percurso.

### Tipos de casas

- **Vazia:** nada acontece.
- **Combate:** aparece um monstro.
- **Cura:** recupera 20 pontos de vida.
- **Tesouro:** ganha 10 pontos de experiência.
- **Armadilha:** perde 15 pontos de vida.
- **Fim:** última posição do tabuleiro.

### Combate

Durante as batalhas, o jogador pode escolher:

1. Atacar.
2. Defender.
3. Usar habilidade especial.
4. Fugir.

O dano do jogador é calculado por:

`Dano = D20 + Força - Defesa do monstro`

O dano dos monstros é calculado por:

`Dano = D20 + Ataque do monstro - Defesa do jogador`

O D20 representa um número aleatório entre 1 e 20.

Ao defender, o jogador recebe metade do dano do próximo ataque inimigo.

### Sistema de fuga

Para fugir, o jogador precisa lançar um dado de seis lados:

- Resultado igual ou superior a 4: consegue fugir.
- Resultado inferior a 4: a fuga falha.

### Vitória e derrota

- **Vitória:** derrotar o Dr. Thomas.
- **Derrota:** perder todos os pontos de vida.

## 6. Como executar o jogo
**Como Compilar e Jogar**
-Instale o gcc ( ‘ sudo apt install build - essential ‘)
-Compile : ‘ gcc - Wall - Wextra -o jogo src / main . c - lm ‘
-Execute : ‘ ./ jogo ‘

## 7. Estrutura do código

O projeto utiliza os seguintes elementos:

### Structs

- **Personagem:** armazena os dados dos personagens.
- **Monstro:** armazena os dados dos inimigos.

### Enums

- **Classe:** define as classes dos personagens.
- **casas:** define os tipos de casas do tabuleiro.

### Principais funções

- `criarPersonagem()`: cria o personagem escolhido.
- `lancar_dados()`: realiza a movimentação.
- `criar_monstro()`: define os inimigos de cada fase.
- `combate()`: controla as batalhas.
- `evento_casa()`: executa os eventos do tabuleiro.
- `primeira_fase()`, `segunda_fase()` e `terceira_fase()`: controlam as fases.
- `main()`: inicia e controla o jogo.

## 9. GamePlay
**Link:**https://youtu.be/V1wOoWX2d6o

## 8. Considerações finais

O projeto foi desenvolvido com a linguagem C, utilizando structs, enums, funções, vetores, ponteiros, condicionais e estruturas de repetição.
