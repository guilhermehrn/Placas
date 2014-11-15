/*
 * ProcImagem.hpp
 *
 *  Created on: Nov 4, 2014
 *      Author: guilherme
 */

#ifndef PROCIMAGEM_HPP_
#define PROCIMAGEM_HPP_

#include <iostream>
#include <math.h>

#include <cv.h>
#include <cvaux.h>
#include <highgui.h>
#include <cxcore.h>
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;

/**
 * Essa classe representa uma dada imagem a ser processada. E inclui algumas ferramentas para
 * manipulação da mesma.
 */
class ProcImagem {
private:

	cv::Mat imagem; // Representa uma imagem dentro do objeto.

public:

	/**
	 *Contrutor que instacia a um obijeto do tipo ProcImagem, a parti de uma imagem passada como parametro.
	 *Param.imagem:Caminho da imagem no disco.
	 */
	ProcImagem(char *imagem);

	/**
	 * Construtor padrão do tipo ProcImagem.
	 */
	ProcImagem();

	/**
	 * Retorna a imagem colorido no obijeto.
	 * return.: retorna um objeto do tipo Mat, a imagem propriamente dita.
	 */
	cv::Mat getImagem();

	/**
	 * Altera a imagem colorida do objeto.
	 * param. imgColor: nova imagem a ser iserida no objeto.
	 */
	void setImagem(cv::Mat imgColor);

	/**
	 * Converte uma imagem colorida corrente dentro do objeto (no atributo imagem)
	 * em uma imagem de escala de cinza.
	 */
	void transformarCinza();

	/**
	 * Faz o realce das bordas atravez da tecnica boton-hat por fechamento. Essa
	 * função ressalta as variações na imagem.
	 * param. morph_elem: tipo de elemento.
	 * param. morph_size: Tamanho do elemento estruturante
	 * retorna dentro do proprio objeto (Atributo imagem), a imagem com as bordas realçadas
	 * propriamente dita.
	 */
	void realcarBordas(int morph_elem, int morph_size);

	/**
	 * Faz a Binarização de uma imagem pelo método de Otsu.
	 * param. img_entrada: imagem a ser binarizada.
	 * return.: retorna dentro do proprio objeto (Atributo imagem), a imagem binarizada propriamente dita.
	 */
	void binarizarImagem();

	/**
	 * Destrutor do objeto
	 */
	~ProcImagem();
};

#endif /* PROCIMAGEM_HPP_ */
