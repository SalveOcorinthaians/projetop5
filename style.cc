let chanceDeErrar = 0;

//sons do jogo
let raquetada;
let ponto;
let trilha;

//placar
let meusPontos = 0;
let pontosDoOponente = 0;

//variaveis do oponente 
let xRaqueteOponente = 585;
let yRaqueteOponente = 150;
let velocidadeYOponente;

let colidiu = false;

//variaveis da raquete
let xRaquete = 5;
let yRaquete = 150;
let raqueteComprimento = 10;
let raqueteAltura = 90;

//variaveis da bolinha
let xBolinha = 300;
let yBolinha = 200;
let diametro = 13;
let raio = diametro /2;

//velocidade da bolinha
let velocidadeXBolinha = 6;
let velocidadeYBolinha = 6;


function mostraBolinha () {
  circle (xBolinha, yBolinha, diametro);
  }

function movimentaBolinha () {
  xBolinha += velocidadeXBolinha;
  yBolinha += velocidadeYBolinha;
  }

function verificaColisaoBorda () {

  if (xBolinha + raio > width || xBolinha - raio < 0) {
  velocidadeXBolinha *= -1;
  }

  if (yBolinha + raio > height || yBolinha - raio < 0) {
  velocidadeYBolinha *= -1;
  }
}

function mostraRaquete() {
  rect(xRaquete, yRaquete, raqueteComprimento, raqueteAltura )
}

function movimentaMinhaRaquete() {
  if(keyIsDown(UP_ARROW)) {
    yRaquete -= 10;
  }
  if(keyIsDown(DOWN_ARROW)) {
    yRaquete += 10;
  }
}

function verificaColisaoRaquete() {
    if (xBolinha - raio < xRaquete + raqueteComprimento && yBolinha - raio < yRaquete + raqueteAltura && yBolinha + raio > yRaquete) {
        velocidadeXBolinha *= -1;
    }
}

function colisaoMinhaRaqueteBiblioteca(){
colidiu = collideRectCircle(xRaquete, yRaquete, raqueteComprimento, raqueteAltura, xBolinha, yBolinha, raio);
if (colidiu) {
velocidadeXBolinha *= -1;
raquetada.play();
} 

}

function mostraRaqueteOponente(){
rect(xRaqueteOponente, yRaqueteOponente, raqueteComprimento, raqueteAltura)
}

function movimentaRaqueteOponente() {
  velocidadeYOponente = yBolinha - yRaqueteOponente - raqueteComprimento / 2 - 30;
 yRaqueteOponente += velocidadeYOponente
 calcularChanceDeErrar()
}

function verificaColisaoRaquete(x, y) {
  colidiu = collideRectCircle(xRaqueteOponente, yRaqueteOponente, raqueteComprimento, raqueteAltura, xBolinha, yBolinha, raio);
 if(colidiu){
  velocidadeXBolinha *= -1;
  raquetada.play();
 }
}

function incluirPlacar(){
  stroke(255);
 textAlign(CENTER);
 textSize(16);
 fill(color(255,140, 0));
 rect(150, 10, 40, 20);
 fill(255);
 text(meusPontos, 170, 26);
 fill(color(255,140, 0));
 rect(450, 10, 40, 20);
 fill(255);
 text(pontosDoOponente,470,26);
}

function marcarPontos() {
 if (xBolinha > 590) {
  ponto.play();
   }
if (xBolinha < 10){
  pontosDoOponente += 1;
  ponto.play();
   }
}

function preload(){
trilha = loadSound("trilha.mp3");
ponto = loadSound("ponto.mp3");
raquetada = loadSound("raquetada.mp3");
}

function setup() {
  createCanvas(600, 400);
 //trilha.loop();
  }

function draw(){
  background(0);
  bolinhaNaoFicaPresa();
  calcularChanceDeErrar();
  mostraBolinha();
  movimentaBolinha();
  verificaColisaoBorda();
  mostraRaquete(xRaquete, yRaquete);
  mostraRaqueteOponente(xRaqueteOponente, yRaqueteOponente);
  movimentaMinhaRaquete();

  verificaColisaoRaquete(xRaquete, yRaquete);
  verificaColisaoRaquete(xRaqueteOponente, yRaqueteOponente);
  movimentaRaqueteOponente();
  incluirPlacar();
  marcarPontos();
}

function calcularChanceDeErrar() {
  if (pontosDoOponente >= meusPontos) {
   chanceDeErrar += 1
  if (chanceDeErrar >= 39) {
   chanceDeErrar = 40
    }
  } else {
   chanceDeErrar -= 1
  if (chanceDeErrar <= 35){
  chanceDeErrar = 35
    }
  }
}

function bolinhaNaoFicaPresa() {
  if (xBolinha - raio <0){
    }
} 