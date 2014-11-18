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
	 * retorna a imagem corrente dentro do objeto
	 * return: imagem corrente.
	 */
	cv::Mat getImagem();

	/**
	 * Muda a imagem corrente dentro do objeto.
	 */
	void setImagem(cv::Mat imagem);

	/**
	 * Fucão que realiza a operação de fechemento
	 * param. nucleo: tipo elemento que estruturante que vai ser usado no fechamento
	 * param. tamanho: tamanho do elemento estruturante.
	 * return: a imagem resultante apos o fechamento. Retorna no proprio atributo do objeto (imagem).
	 */
	void fazerFechamento(int nucleo, int tamanhoLin, int tamanhoCol);


	/**
	 * Fucão que realiza a operação de Abertura da imagem corrente no objeto.
	 * param. nucleo: tipo elemento que estruturante que vai ser usado no fechamento
	 * param. tamanho: tamanho do elemento estruturante.
	 * return: retorna no proprio objeto (no atributo "imagem"), a imagem resultante.
	 */
	void fazerAbertura(int nucleo, int tamanhoLin, int tamanhoCol);

	/**
	 * Funcão que faz a operação de dilatação de uma região da imagem.
	 */
	cv::Mat fazerDilatacaoregiao();

	void LocalizarPosicao(int &x, int &y);

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
