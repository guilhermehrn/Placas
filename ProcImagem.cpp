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
		this->imagem = cv::imread(imagem);

	}

	/**
	 * Construtor padrão do tipo ProcImagem.
	 */
	ProcImagem::ProcImagem(){

	}

	/**
	 * Retorna a imagem colorido no objeto.
	 * return.: retorna um objeto do tipo Mat, a imagem propriamente dita.
	 */
	cv::Mat ProcImagem::getImagem(){
		return this->imagem;
	}


	/**
	 * Altera a imagem colorida do objeto.
	 * param. imagem: nova imagem a ser iserida no objeto.
	 */
	void ProcImagem::setImagem(cv::Mat imagem){
		this->imagem = imagem;
	}

	/**
	 * Converte uma imagem colorida corrente no objeto em uma imagem de escala de cinza.
	 * return.: retorna a imagem no propio objento no atributo Imagem.
	 */
	void ProcImagem::transformarCinza(){
		cv::Mat saida;
		cv::cvtColor(this->imagem,saida , CV_BGR2GRAY);
		this->imagem = saida;
	}

	/**
	 * Faz o realce das bordas atravez da tecnica boton-hat por fechamento. Essa
	 * função ressalta as variações na imagem.
	 * param. morph_elem: tipo de elemento.
	 * param. morph_size: Tamanho do elemento estruturante
	 * retorna dentro do proprio objeto (Atributo imagem), a imagem com as bordas realçadas
	 * propriamente dita.
	 */
	void ProcImagem::realcarBordas(int morph_elem, int morph_size){

		cv::Mat img_botton_hat;

		cv::Mat element = cv::getStructuringElement(morph_elem,
					cv::Size(morph_size + 1, morph_size + 1),
					cv::Point(morph_size, morph_size));

		cv::Mat mat_img_cinza(this->imagem);

		cv::morphologyEx(mat_img_cinza, img_botton_hat,5, element);

		this->imagem = img_botton_hat;
		cv::morphologyEx(img_botton_hat,this->imagem,6,element);

	}

	/**
	 * Faz a Binarização de uma imagem pelo método de Otsu.
	 * param. img_entrada: imagem a ser binarizada.
	 * return.: retorna dentro do proprio objeto (Atributo imagem), a imagem binarizada propriamente dita.
	 */
	void ProcImagem::binarizarImagem (){
		cv::Mat	img_saida;
		cv::threshold (this->imagem, img_saida,150.0,255.0,CV_THRESH_OTSU); //CV_THRESH_OTSU CV_THRESH_BINARY
		this->imagem =  img_saida;
	}

	/**
	 * Destrutor do objeto.
	 */
	ProcImagem::~ProcImagem(){

	}




