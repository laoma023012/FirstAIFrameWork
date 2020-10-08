#include "myNet.hpp"
#include "myBlob.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

int ReverseInt(int i)  ////�Ѵ������ת��Ϊ���ǳ��õ�С������ ����С��ģʽ��ԭ��
{
	unsigned char ch1, ch2, ch3, ch4;  //һ��int��4��char
	ch1 = i & 255;
	ch2 = (i >> 8) & 255;
	ch3 = (i >> 16) & 255;
	ch4 = (i >> 24) & 255;
	return ((int)ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
}

//http://yann.lecun.com/exdb/mnist/
void ReadMnistData(string path, shared_ptr<Blob> &images)
{
	ifstream file(path, ios::binary);
	if (file.is_open())
	{
		//mnistԭʼ�����ļ���32λ������ֵ�Ǵ�˴洢��C/C++������С�˴洢�����Զ�ȡ���ݵ�ʱ����Ҫ������д�С��ת��!!!!
		//1.���ļ��л�֪ħ�����֣�һ�㶼���𵽱�ʶ�����ã����������ж�����ļ��ǲ���MNIST�����train-labels.idx1-ubyte�ļ�����ͼƬ������ͼƬ�����Ϣ
		int magic_number = 0;
		int number_of_images = 0;
		int n_rows = 0;
		int n_cols = 0;
		file.read((char*)&magic_number, sizeof(magic_number));
		magic_number = ReverseInt(magic_number);  //�ߵ��ֽڵ���
		cout << "magic_number=" << magic_number << endl;
		file.read((char*)&number_of_images, sizeof(number_of_images));
		number_of_images = ReverseInt(number_of_images);
		cout << "number_of_images=" << number_of_images << endl;
		file.read((char*)&n_rows, sizeof(n_rows));
		n_rows = ReverseInt(n_rows);
		cout << "n_rows=" << n_rows << endl;
		file.read((char*)&n_cols, sizeof(n_cols));
		n_cols = ReverseInt(n_cols);
		cout << "n_cols=" << n_cols << endl;

		//2.��ͼƬתΪBlob�洢��
		for (int i = 0; i<number_of_images; ++i)  //��������ͼƬ
		{
			for (int h = 0; h<n_rows; ++h)   //������
			{
				for (int w = 0; w<n_cols; ++w)   //������
				{
					unsigned char temp = 0;
					file.read((char*)&temp, sizeof(temp));      //����һ������ֵ��		
					//-----��temp�е�����д��Blob��------
					(*images)[i](h, w, 0) = (double)temp / 255;
					//-----------------------------------

				}
			}
		}
	}
	else
	{
		cout << "no data file found :-(" << endl;
	}

}
void ReadMnistLabel(string path, shared_ptr<Blob> &labels)
{

	ifstream file(path, ios::binary);
	if (file.is_open())
	{
		//1.���ļ��л�֪ħ�����֣�ͼƬ����
		int magic_number = 0;
		int number_of_images = 0;
		file.read((char*)&magic_number, sizeof(magic_number));
		magic_number = ReverseInt(magic_number);
		cout << "magic_number=" << magic_number << endl;
		file.read((char*)&number_of_images, sizeof(number_of_images));
		number_of_images = ReverseInt(number_of_images);
		cout << "number_of_Labels=" << number_of_images << endl;
		//2.�����б�ǩתΪBlob�洢������д����ʶ��0~9��
		for (int i = 0; i<number_of_images; ++i)
		{
			unsigned char temp = 0;
			file.read((char*)&temp, sizeof(temp));
			//-----��temp�е�����д��Blob��------
			(*labels)[i](0, 0, (int)temp) = 1;

			//-----------------------------------
		}
	}
	else
	{
		cout << "no label file found :-(" << endl;
	}
}



void trainModel(string configFile, shared_ptr<Blob> X, shared_ptr<Blob> Y)
{
	//0. ���벢�������ǵ�����ṹ����
	NetParam net_param;
	net_param.readNetParam(configFile);

	//1. ��60000��ͼƬ��59:1�ı�������Ϊѵ������59000�ţ�����֤����1000�ţ�
	shared_ptr<Blob> X_train(new Blob(X->subBlob(0,59000)));  //����ҿ����䣬��[ 0, 59000 )
	shared_ptr<Blob> Y_train(new Blob(Y->subBlob(0, 59000)));
	shared_ptr<Blob> X_val(new Blob(X->subBlob(59000, 60000)));
	shared_ptr<Blob> Y_val(new Blob(Y->subBlob(59000, 60000)));

	vector<shared_ptr<Blob>> XX{ X_train, X_val };
	vector<shared_ptr<Blob>> YY{ Y_train, Y_val };

	//2. ��ʼ������ṹ
	Net myModel;
	myModel.initNet(net_param, XX, YY);

	//3. ��ʼѵ��
	cout << "------------ step3. Train start... ---------------" << endl;
	myModel.trainNet(net_param);
	cout << "------------ Train end... ---------------" << endl;

}

int main(int argc, char** argv)
{
	//��������Blob����һ�������洢ͼƬ����ֵ�����ݣ�����һ�������洢��ǩֵ
	shared_ptr<Blob> images(new Blob(60000, 1, 28, 28, TZEROS));
	shared_ptr<Blob> labels(new Blob(60000, 10, 1, 1, TZEROS));  //����one-hot����ı�ǩֵ
	ReadMnistData("mnist_data/train/train-images.idx3-ubyte", images);  //��ȡdata
	ReadMnistLabel("mnist_data/train/train-labels.idx1-ubyte", labels);   //��ȡlabel
	trainModel("./myModel.json", images, labels);

	system("pause");
}