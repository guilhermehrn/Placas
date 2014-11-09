/*
 * ProcImagem.cpp
 *
 *  Created on: Nov 4, 2014
 *      Author: guilherme
 */
#include "ProcImagem.hpp"

	/**
     *Contrutor que instacia a um obijeto do tipo ProcImagem, a parti de uma imagem passada como parametro.
	 *Param:Caminho da imagem no disco.
	 */
	ProcImagem::ProcImagem(char *imagem){
		this->imgColor = cv::imread(imagem);
		this->imgCinza = transformarCinza();
	}

	/**
	 * Construtor padrão do tipo ProcImagem.
	 */
	ProcImagem::ProcImagem(){

	}

	/**
	 * Retorna a imagem colorido no obijeto.
	 * return.: retorna um objeto do tipo Mat, a imagem propriamente dita.
	 */
	cv::Mat ProcImagem::getImgColor(){
		return this->imgColor;
	}


	/**
	 * Altera a imagem colorida do objeto.
	 * param. imgColor: nova imagem a ser iserida no objeto.
	 */
	void ProcImagem::setImgColor(cv::Mat imgColor){
		this->imgColor = imgColor;
	}

	/**
	 * Retorna a imagem em escala de cinza. (ATENCÂO!) Não usar antes fazer uma
	 * transformação em escala de cinza com o metodo "transformarCinza()".
	 * return.: retorna um objeto do tipo Mat, a imagem propriamente dita.
	 */
	cv::Mat ProcImagem::getImgCinza(){
		return this->imgCinza;
	}


	/**
	 * Converte uma imagem colorida em uma imagem de escala de cinza.
	 * return.: retorna um objeto do tipo Mat, a imagem em cinza propriamente dita.
	 */
	cv::Mat ProcImagem::transformarCinza(){
		cv::Mat saida;
		cv::cvtColor(this->imgColor,saida , CV_BGR2GRAY);
		return saida;
	}

	/**
	 * Faz o realce das bordas atravez da tecnica boton-hat por fechamento. Essa
	 * função ressalta as variações na imagem.
	 * param. morph_elem: tipo de elemento.
	 * param. morph_size: Tamanho do elemento estruturante
	 * return.: retorna um objeto do tipo Mat, a imagem com as bordas realçadas propriamente dita.
	 */
	cv::Mat ProcImagem::realcarBordas(int morph_elem, int morph_size){

		cv::Mat img_botton_hat;

		cv::Mat element = cv::getStructuringElement(morph_elem,
					cv::Size(2 * morph_size + 1, 2 * morph_size + 1),
					cv::Point(morph_size, morph_size));

		cv::Mat mat_img_cinza(this->imgCinza);
		cv::morphologyEx(mat_img_cinza, img_botton_hat,5, element);

		return img_botton_hat;
	}

	/**
	 * Faz a Binarização de uma imagem pelo método de Otsu.
	 * param. img_entrada: imagem a ser binarizada.
	 * return.: retorna um objeto do tipo Mat, a imagem binarizada propriamente dita.
	 */
	cv::Mat ProcImagem::binarizarImagem (cv::Mat img_entrada){
		cv::Mat	img_saida;
		cv::threshold (img_entrada, img_saida,0.0,255.0,CV_THRESH_OTSU); //CV_THRESH_OTSU CV_THRESH_BINARY
		return img_saida;
	}

	/**
	 * Destrutor do objeto.
	 */
	ProcImagem::~ProcImagem(){

	}




