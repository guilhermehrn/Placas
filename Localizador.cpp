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
 * Fucão que realiza a operação de fechemento
 * param. imagem: imagem onde sera feita a operação de fechamento
 * param. nucleo: tipo elemento que estruturante que vai ser usado no fechamento
 * param. tamanho: tamanho do elemento estruturante.
 * return: objeto do tipo Mat, a imagem resultante.
 */
cv::Mat Localizador::fazerFechamento(cv::Mat imagem, int nucleo, int tamanho) {
	cv::Mat img_fechada;
	cv::Mat elemento = cv::getStructuringElement(nucleo,
			cv::Size(2 * tamanho, 2 * tamanho), cv::Point(tamanho, tamanho));

	cv::morphologyEx(imagem, img_fechada, 3, elemento);
	return img_fechada;
}

/**
 * Fucão que realiza a operação de Abertura da imagem de entrada.
 * param. imagem: imagem onde sera feita a operação de abertura
 * param. nucleo: tipo elemento que estruturante que vai ser usado no fechamento
 * param. tamanho: tamanho do elemento estruturante.
 * return: objeto do tipo Mat, a imagem resultante.
 */
cv::Mat Localizador::fazerAbertura(cv::Mat imagem, int nucleo, int tamanho) {

	cv::Mat img_aberta;
	cv::Mat elemento = cv::getStructuringElement(nucleo,
			cv::Size(2 * tamanho, 2 * tamanho), cv::Point(tamanho, tamanho));

	cv::morphologyEx(imagem, img_aberta, 2, elemento);
	return img_aberta;
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
	cv::rectangle(imagem, super, infer, cor, 3);
	return imagem;
}

/**
 * Destruido do padrão da clase.
 */
Localizador::~Localizador() {
	// TODO Auto-generated destructor stub
}

