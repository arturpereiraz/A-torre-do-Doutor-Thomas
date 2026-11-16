#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void limpartela(){
  system("clear");
}

//CRIAÇÃO DE PERSONAGENS
typedef enum{
  SOLDADO,
  GENERAL,
  AGENTE
  
}Classe;

typedef enum {
  VAZIA,
  COMBATE,
  CURA,
  TESOURO,
  ARMADILHA,
  FIM
  
}casas;

casas tabuleiro[12] = {
  VAZIA,      
  COMBATE,   
  TESOURO,   
  COMBATE,    
  CURA,       
  ARMADILHA,  
  COMBATE,    
  VAZIA,      
  TESOURO,    
  COMBATE,    
  CURA,       
  FIM        
};

int lancar_dados(){
  int jogada= rand() % 6 + 1;
  return jogada;
}


int dado_dano(){
  int dano=rand() % 20 + 1;
  return dano;
}

typedef struct{
  char nome [30];
  Classe classe;
  int vida, vidaMax;
  int forca,defesa,agilidade, inteligencia;
  int xp,nivel;
}Personagem;


typedef struct{
  char nome[30];
  char descricao[100];
  int vida,ataque,defesa;
}Monstro;

void criarPersonagem(Personagem *p,Classe classe){
  p->classe=classe;
  p->xp=0;
  p->nivel=1;
  switch(classe){
    case SOLDADO:
      strcpy(p->nome, "Patrick");
      p->vidaMax = 120;
      p->forca = 15;
      p->defesa = 10;
      p->agilidade = 8;
      p->inteligencia = 6;
        p->vida = p->vidaMax;
      break;

    case GENERAL:
      strcpy(p->nome, "Red Jhon");
      p->vidaMax = 100;
      p->forca = 9;
      p->defesa = 13;
      p->agilidade = 6;
      p->inteligencia = 14;
      p->vida = p->vidaMax;
      break;

    case AGENTE:
      strcpy(p->nome, "Lisbon");
      p->vidaMax = 110;
      p->forca = 12;
      p->defesa = 11;
      p->agilidade = 14;
      p->inteligencia = 12;
      p->vida = p->vidaMax;
      break;
  }
}


void andar(int *posicao,int dado){
  *posicao+=dado;
  if(*posicao>11){
    *posicao=11;
  }
}

void monstrosFase1(Monstro *m, int numero){
  if (numero == 0){
    strcpy(m->nome, "Zumbi Mutante");
    strcpy(m->descricao, "Humano infectado pelo soro");
    m->vida = 20;
    m->ataque = 6;
    m->defesa = 3;
  }
  else if (numero == 1){
    strcpy(m->nome, "Cão Infectado");
    strcpy(m->descricao, "Cão de guarda mutado");
    m->vida = 25;
    m->ataque = 7;
    m->defesa = 2;
  }
  else{
    strcpy(m->nome, "Guarda Mutante");
    strcpy(m->descricao, "Segurança da torre");
    m->vida = 30;
    m->ataque = 8;
    m->defesa = 4;
  }
}

void monstrosFase2(Monstro *m, int numero){
  if (numero == 1){
    strcpy(m->nome, "Cientista Mutante");
    strcpy(m->descricao, "Assistente do Dr. Thomas");
    m->vida = 40;
    m->ataque = 9;
    m->defesa = 5;
  }
  else if (numero == 2){
    strcpy(m->nome, "Aranha Experimental");
    strcpy(m->descricao, "Aranha gigante de laboratório");
    m->vida = 40;
    m->ataque = 10;
    m->defesa = 4;
  }
  else{
    strcpy(m->nome, "Guardião Blindado");
    strcpy(m->descricao, "Soldado de armadura");
    m->vida = 60;
    m->ataque = 11;
    m->defesa = 8;
  }
}

void monstrosFase3(Monstro *m, int numero){
  if (numero == 1){
    strcpy(m->nome, "Quimera");
    strcpy(m->descricao, "Fusão de vários animais");
    m->vida = 70;
    m->ataque = 12;
    m->defesa = 7;
  }
  else{
    strcpy(m->nome, "Golem de Soro");
    strcpy(m->descricao, "Criatura de soro endurecido");
    m->vida = 80;
    m->ataque = 12;
    m->defesa = 8;
  }
} 

void criar_monstro(Monstro*m,int fase,int numero){
  if(fase==1){
    monstrosFase1(m,numero);
  }
  else if(fase==2){
    monstrosFase2(m,numero);
  }
  else {
    monstrosFase3(m,numero);
  }
}

void criardoutor(Monstro *d){
  strcpy(d->nome, "Dr. Thomas");
  strcpy(d->descricao, "O criador do soro (chefe)");
  d->vida = 100;
  d->ataque = 15;
  d->defesa = 10;
}   

int combate(Personagem *p, Monstro *m){
  int acao,dano;
  int defender;
  printf("Um monstro apareceu!\n");
  printf("%s\n",m->nome);
  printf("%s\n",m->descricao);
  
  while(p->vida > 0 && m->vida > 0){
    printf("\nSua vida: %d | Vida do monstro: %d\n", p->vida, m->vida);
    printf("[1] Atacar  [2] Defender  [3] Habilidade  [4] Fugir\n");
    printf("Escolha: ");
    scanf("%d", &acao);
    defender=0;
    if (acao == 1){
      int jogada=dado_dano();
      dano = jogada+ p->forca - m->defesa;
      if (dano < 1){
        dano = 1;
      }
      m->vida = m->vida - dano;
      printf("Você atacou e causou %d de dano!\n", dano);
    }
    else if (acao == 2){
      defender= 1;
      printf("Você se defendeu\n");
    }
    else if (acao == 3){
      if (p->classe == SOLDADO){
        int jogada=dado_dano();
        dano = jogada+ p->forca + 10 - m->defesa;
        if (dano < 1){
          dano = 1;
        }
        m->vida = m->vida - dano;
        printf("RAJADA PESADA! Você causou %d de dano!\n", dano);
      }
      else if (p->classe == GENERAL){
        p->vida = p->vida + 30;
        if (p->vida > p->vidaMax){
          p->vida = p->vidaMax;
        }
        printf("ORDEM DE RECUO! Você recuperou vida.\n");
      }
      else{
        int jogada=dado_dano();
        dano = (jogada + p->forca - m->defesa) * 2;
        if (dano < 2){
          dano = 2;
        }
        m->vida = m->vida - dano;
        printf("GOLPE CORPO A CORPO! Você causou %d de dano!\n", dano);
      }
    }
    else if (acao == 4){
      printf("Você precisa jogar um dado e tirar 4 ou +\n");
      printf("Digite enter para jogar dado:\n");
      while (getchar() != '\n'); 
      getchar();
      int jogada= lancar_dados();
      if (jogada>= 4){
        printf("Você conseguiu fugir!\n");
        return 0;
      }
      printf("A fuga falhou!\n");
    }
    else{
      printf("Opção inválida!\n");
      continue; 
    }

    if (m->vida > 0){
      int jogada=dado_dano();
      dano = jogada+ m->ataque - p->defesa;
      if (dano < 1){
        dano = 1;
      }
      if (defender == 1){
        dano = dano / 2;
      }
      p->vida = p->vida - dano;
      printf("%s atacou e causou %d de dano em você!\n", m->nome, dano);
    }
  }
  if (p->vida <= 0){
    p->vida = 0;
    return 0;
  }
  if(p->vida > 0){
    printf("\nVocê derrotou %s\n", m->nome);
    return 1;
  }
}
    
int combatefinal(Personagem *p){
  Monstro m;
  criardoutor(&m);
  int jogada = combate(p, &m);
  return jogada;
}


void evento_casa(Personagem *p, casas posicao,int fase){
  Monstro m;
  switch (posicao){
    case VAZIA:
      printf("Nada por perto!\n");
      break;
    case COMBATE:
      criar_monstro(&m,fase,rand()%3);
      combate(p,&m);
      break;
    case CURA:
      printf("Você encontrou um kit médico, pode aumentar sua vida  em 20 pontos\n");
      p->vida = p->vida + 20;
      if (p->vida > p->vidaMax){
        p->vida = p->vidaMax;
      }
      break;
    case TESOURO:
      printf("Você encontrou um tesouro!\n");
      p->xp = p->xp + 10;
      break;
    case ARMADILHA:
      printf("Armadilha! Você perdeu 15 de vida.\n");
      p->vida = p->vida - 15;
      if (p->vida < 0){
        p->vida = 0;
      }
      break;
    case FIM:
      break;
  }
}

int primeira_fase(Personagem *p){
  int posicao=0;
  printf("---FASE 1---\n"
  "Sua primeira missão é chegar na Torre do Dr.Thomas\n"
  );
  
  while (posicao<11 &&  p->vida>0){  
    int comando;
    printf("Você está na casa %d\n",posicao);
    printf("Digite 1 para lançar o dado:\n");
    scanf("%d",&comando);
    
    if (comando==1){
      int dado=lancar_dados();
      printf("Você tirou %d \n",dado);
  
      andar(&posicao,dado);
      
      evento_casa(p,tabuleiro[posicao],1);
    }
    else{
      printf("Opção inválida\n");
    }
  } 

  if (p->vida<=0){
    printf("Game-over!\n");
    return 0;
  }
  else{
    printf("\nFASE UM CONCLUÍDA!\n");
    sleep(3); // Pausa de 3 segundos
    limpartela(); 
    return 1;
  }
}

int segunda_fase(Personagem *p){
  int posicao=0;
  printf("---FASE 2---\n"
  "Você chegou no térreo da Torre do Dr.Thomas\n"
  );
  
  while (posicao<11 &&  p->vida>0){  
    int comando;
    printf("Você está na casa %d\n",posicao);
    printf("Digite 1 para lançar o dado:\n");
    scanf("%d",&comando);
    
    if (comando==1){
      int dado=lancar_dados();
      printf("Você tirou %d \n",dado);
  
      andar(&posicao,dado);
      
      evento_casa(p,tabuleiro[posicao],2);
    }
    else{
      printf("Opção inválida\n");
    }
  } 

  if (p->vida<=0){
    printf("Game-over!\n");
    return 0;
  }
  else{
    printf("\nFASE DOIS CONCLUÍDA!\n");
    sleep(3); // Pausa de 3 segundos
    limpartela(); 
    return 1;
  }
}

int terceira_fase(Personagem *p){
  int posicao=0;
  printf("---FASE 3---\n"
  "Você entrou na Torre do Dr.Thomas. Encontre ele e salve o mundo!\n"
  );
  
  while (posicao<11 &&  p->vida>0){  
    int comando;
    printf("Você está na casa %d\n",posicao);
    printf("Digite 1 para lançar o dado:\n");
    scanf("%d",&comando);
    
    if (comando==1){
      int dado=lancar_dados();
      printf("Você tirou %d \n",dado);
  
      andar(&posicao,dado);
      if (posicao==11){
        printf("Chegou a hora de enfrentar o doutor Thomas e salvar o mundo\n");
        int progresso=combatefinal(p);
        if (progresso==1){
          printf("Você salvou o mundo das mãos do Doutor Thomas\n");
        }
      }
      evento_casa(p,tabuleiro[posicao],3);
    }
    else{
      printf("Opção inválida\n");
    }
  } 

  if (p->vida<=0){
    printf("Game-over!\n");
    return 0;
  }
}

//FUNÇÕES INTERATIVAS
void descricao_personagens(){
  limpartela();
  printf("--SOLDADO|0--\n");
  printf("Vida Máxima:120\n");
  printf("Força:15 \n");
  printf("Defesa:10\n");
  printf("Agilidade:8\n");
  printf("Inteligência:6\n");
  printf("Equipamento:Fuzil\n");
  printf("Habilidade Especial:Rajada Pesada (+10 de dano)\n\n");
  
  printf("--GENERAL|1--\n");
  printf("Vida Máxima:100\n");
  printf("Força:9\n");
  printf("Defesa:13\n");
  printf("Agilidade:6\n");
  printf("Inteligência:14\n");
  printf("Equipamento:Pistola Tática\n");
  printf("Habilidade Especial:Ordem de Recuo (cura 30+ da vida máxima)\n\n");
  
  printf("--AGENTE|2--\n");
  printf("Vida Máxima:110\n");
  printf("Força:12 \n");
  printf("Defesa:11\n");
  printf("Agilidade:14\n");
  printf("Inteligência:12\n");
  printf("Equipamento:Pistola Silenciada\n");
  printf("Habilidade Especial:Golpe corpo a corpo (dano dobrado)\n");
}


int Escolher_personagem(){
  int escolha;
  printf("Antes de começar nossa missão, escolha um personagem para jogo\n");
  descricao_personagens();
  do{
    printf("\nDigite o número do personagem (0: Soldado, 1: General, 2: Agente, 3-sair):\n");
    scanf("%d", &escolha);
    switch(escolha){
      case SOLDADO:
        return 0;
          
      case GENERAL:
        return 1;

      case AGENTE:
        return 2;

      case 3:
        return -1;

      default:
        printf("Opção inválida!\n");
        break;
        }
    }while(escolha != 3);
    return -1;
}

int MensagemInicial(){
  int comando;
  printf("Seja Bem-vindo(a) a essa grande aventura!\n"
         "Você agora tem a grande missão de salvar a humanidade das mãos do Dr. Thomas\n"
         "Em um dos seus experimentos ele criou um soro que potencializa todas as capacidades humanas\n"
         "Porém... Isso saiu do seu controle e criou monstros\n"
         "Você precisa invadir a torre do doutor, detê-lo e gaseificar o antídoto para salvar a população\n"
  );
  
  printf("\nDigite '1' para começar: ");
  scanf("%d",&comando);
  
  if (comando==1){
    return 1;
  }
  else{
    return 0;
  }
}

int main(){
  srand(time(NULL));
  int comecar;
  
  comecar=MensagemInicial();
  
  if (comecar==1){
      int escolha=Escolher_personagem();
      if(escolha == -1) {
          printf("Você desistiu do jogo.\n");
          return 0;
      }
      Personagem heroi;
      criarPersonagem(&heroi,escolha);
      limpartela();
      int progresso=primeira_fase(&heroi);
      if(progresso==1){
          progresso+=segunda_fase(&heroi);
          if (progresso==2){
            progresso+=terceira_fase(&heroi);
          }
      }
  }
  else{
    printf("Você deixou o Dr. Thomas dominar o mundo\n");
  }
  return 0;
}
