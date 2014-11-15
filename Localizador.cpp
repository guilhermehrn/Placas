/*
 * Localizador.cpp
 *
 *  Created on: Nov 6, 2014
 *      Author: guilherme
 */

#include "Localizador.hpp"

Localizador::Localizador() {
	//padrao
}

/**
 * Costrutor que recebe como parametro uma imagem objeto do tipo Mat
 */
Localizador::Localizador(cv::Mat imagem) {
	this->imagem = imagem;
}

/**
 * retorna a imagem corrente dentro do objeto
 * return: imagem corrente.
 */
cv::Mat Localizador::getImagem() {
	return this->imagem;
}

/**
 * Muda a imagem corrente dentro do objeto.
 */
void Localizador::setImagem(cv::Mat imagem) {
	this->imagem = imagem;
}

/**
 * Fucão que realiza a operação de fechemento
 * param. nucleo: tipo elemento que estruturante que vai ser usado no fechamento
 * param. tamanho: tamanho do elemento estruturante.
 * return: a imagem resultante apos o fechamento. Retorna no proprio atributo do objeto (imagem).
 */
void Localizador::fazerFechamento(int nucleo, int tamanhoLin, int tamanhoCol) {
	cv::Mat img_fechada;
	cv::Mat elemento = cv::getStructuringElement(nucleo,
			cv::Size(2*tamanhoLin, 2*tamanhoCol),
			cv::Point(tamanhoLin, tamanhoCol));

	cv::morphologyEx(this->imagem, img_fechada, 3, elemento);
	this->imagem = img_fechada;
}

/**
 * Fucão que realiza a operação de Abertura da imagem corrente no objeto.
 * param. nucleo: tipo elemento que estruturante que vai ser usado no fechamento
 * param. tamanho: tamanho do elemento estruturante.
 * return: retorna no proprio objeto (no atributo "imagem"), a imagem resultante.
 */
void Localizador::fazerAbertura(int nucleo, int tamanhoLin, int tamanhoCol) {

	cv::Mat img_aberta;
	cv::Mat elemento = cv::getStructuringElement(nucleo,
			cv::Size(2 * tamanhoLin, 2 * tamanhoCol),
			cv::Point(tamanhoLin, tamanhoCol));

	cv::morphologyEx(imagem, img_aberta, 2, elemento);
	this->imagem = img_aberta;
}

/**
 * Funcão que marca ou circula o local da placa.
 * param. imagem: imagem onde sera feita a marcação.
 * param. super: ponto da diagonal superior do retangulo a ser formado.
 * param. infer: ponto da diagonal inferior do retangulo a ser formado.
 * param. cor: cor do retangulo a ser formado.
 */
cv::Mat Localizador::marcarPlaca(cv::Mat imagem, cv::Point super,
		cv::Point infer, cv::Scalar cor) {
	cv::rectangle(this->imagem, super, infer, cor, 3);
	return this->imagem;
}

/**
 * Destruido do padrão da clase.
 */
Localizador::~Localizador() {
	// TODO Auto-generated destructor stub
}

