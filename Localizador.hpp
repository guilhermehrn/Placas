/*
 * Localizador.hpp
 *
 *  Created on: Nov 6, 2014
 *      Author: guilherme
 */

#ifndef LOCALIZADOR_HPP_
#define LOCALIZADOR_HPP_

#include "ProcImagem.hpp"

/**
 * Classe que representa o localizador de placa, ele recebe uma imagem pre-processada e
 * localiza na imagem a placa de um carro.
 */
class Localizador {

private:
	cv::Mat imagem;
public:
	/**
	 * Costrutor padrão
	 */
	Localizador();

	/**
	 * Costrutor que recebe como parametro uma imagem objeto do tipo Mat
	 */
	Localizador(cv::Mat imagem);

	/**
	 * Fucão que realiza a operação de fechemento
	 * param. imagem: imagem onde sera feita a operação de fechamento
	 * param. nucleo: tipo elemento que estruturante que vai ser usado no fechamento
	 * param. tamanho: tamanho do elemento estruturante.
	 * return: objeto do tipo Mat, a imagem resultante.
	 */
	cv::Mat fazerFechamento(cv::Mat imagem, int nucleo, int tamanho);

	/**
	 * Fucão que realiza a operação de Abertura da imagem de entrada.
	 * param. imagem: imagem onde sera feita a operação de abertura
	 * param. nucleo: tipo elemento que estruturante que vai ser usado no fechamento
	 * param. tamanho: tamanho do elemento estruturante.
	 * return: objeto do tipo Mat, a imagem resultante.
	 */
	cv::Mat fazerAbertura(cv::Mat imagem, int nucleo, int tamanho);

	/**
	 * Funcão que faz a operação de dilatação de uma região da imagem.
	 */
	cv::Mat fazerDilatacaoregiao();

	cv::Mat fazerSeguimentacao();

	/**
	 * Funcão que marca ou circula o local da placa.
	 * param. imagem: imagem onde sera feita a marcação.
	 * param. super: ponto da diagonal superior do retangulo a ser formado.
	 * param. infer: ponto da diagonal inferior do retangulo a ser formado.
	 * param. cor: cor do retangulo a ser formado.
	 */
	cv::Mat marcarPlaca(cv::Mat imagem, cv::Point super, cv::Point infer,
			cv::Scalar cor);

	/**
	 * Destruido do padrão da clase.
	 */
	virtual ~Localizador();
};

#endif /* LOCALIZADOR_HPP_ */
