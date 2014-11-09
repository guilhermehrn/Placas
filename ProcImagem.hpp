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
class ProcImagem{
private:

	cv::Mat imgColor;// Representa uma imagem colorida
	cv::Mat imgCinza;//Armasena uma imagem em tom de cinza.

public:

	/**
	 *Contrutor que instacia a um obijeto do tipo ProcImagem, a parti de uma imagem passada como parametro.
	 *Param:Caminho da imagem no disco.
	 */
	ProcImagem(char *imagem);


	/**
	 * Construtor padrão do tipo ProcImagem.
	 */
	ProcImagem();

	/**
	 * Retorna a imagem colorido no obijeto.
	 */
	cv::Mat getImgColor();


	/**
	 * Altera a imagem colorida do objeto.
	 */
	void setImgColor(cv::Mat imgColor);

	/**
	 * Retorna a imagem em escala de cinza. (ATENCÂO!) Não usar antes fazer uma transformação em escala de cinza
	 * com o metodo "transformarCinza()";
	 */
	cv::Mat getImgCinza();


	/**
	 * Converte uma imagem colorida em uma imagem de escala de cinza.
	 */
	cv::Mat transformarCinza();

	/**
	 * Faz o realce das bordas atravez da tecnica boton-hat por fechamento. Essa função ressalta as variações na imagem.
	 */
	cv::Mat realcarBordas(int morph_elem, int morph_size);


	/**
	 * Faz a Binarização de uma imagem pelo método de Otsu.
	 */
	cv::Mat binarizarImagem (cv::Mat img_entrada);

	/**
	 * Destrutor do objeto
	 */
	~ProcImagem();
};

#endif /* PROCIMAGEM_HPP_ */