/*
 * Localizador.hpp
 *
 *  Created on: Nov 6, 2014
 *      Author: guilherme
 */

#ifndef LOCALIZADOR_HPP_
#define LOCALIZADOR_HPP_

#include"ProcImagem.hpp";

class Localizador {

private:
	cv::Mat imagem;
public:
	Localizador();
	Localizador(cv::Mat imagem);
	cv::Mat fazerFechamento(cv::Mat imagem, int nucleo,int tamanho);
	cv::Mat fazerAbertura(cv::Mat imagem, int nucleo,int tamanho);
	cv::Mat fazerDilatacaoregiao();
	cv::Mat fazerSeguimentacao();
	cv::Mat marcarPlaca();

	virtual ~Localizador();
};

#endif /* LOCALIZADOR_HPP_ */
