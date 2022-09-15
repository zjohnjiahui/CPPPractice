#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "Product.h"
#include <memory>

//�������� �� Product�������Ӧ
class Factory
{
public:
  virtual ~Factory() {}
  virtual std::unique_ptr<Product> CreateProduct() = 0;
};

//���幤��  ��  �����Ʒ���Ӧ
class ConcreteFactory :public Factory
{
public:
  std::unique_ptr<Product> CreateProduct() {
    return std::make_unique<ConcreteProduct>();
  }
};

/*
����ģʽ�����ã�
1.�ṩ��������Ľӿ�
2.�������ʵ�����ӳٵ�������ʵ��

Ҫ��������⣺
1.һ������ָ��ָ��������󣬻������������࣬��������ʱ��Ҫ֪��ʵ���������Ʋ��ܽ���new
2.��һ����A��ʹ��B, AB��Ϊ�������, �����ҪA������B���������
  ��ô�Ͳ�֪���ô���ʲô������ʱ���Դ��빤������������
  �������Ҫֱ�Ӵ����Ļ���Ҳ��ֱ�Ӵ���B���������

���1��
ÿ��Product�����Ӧһ��Factory,��Factory��ʵ�����о���Product�Ĵ���������
ȱ�㣺Factory����Զ�����ܷ��

���2��
ÿ��Product�����Ӧһ��Factory,ÿ������Product��Ӧһ������Factory��
�ɾ���Factory��������Product��
ȱ�㣺�Զ�̬�ķ�ʽ�������һ������ķ�ʽʵ�ַ�ա�

���ۣ�����������,ģ�幤��
*/




#endif //~_FACTORY_H