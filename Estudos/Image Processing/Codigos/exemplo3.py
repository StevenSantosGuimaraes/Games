from PIL import Image

imagem = Image.open('../Imagens/doge.jpg')

formato = imagem.format
altura = imagem.height
largura = imagem.width

print("Formato da Cor: ", imagem.mode, ", Formato do Arquivo: ", formato)
print("Altura: ", altura, ", Largura: ", largura)

#Padrao: largura x altura
tamanho1 = (int(largura / 2) , int(altura / 2))
tamanho2 = (largura * 2, altura * 2)

imagem_menor = imagem.resize(tamanho1)
imagem_menor.save('../Imagens/doge_menor.jpg')

imagem_maior = imagem.resize(tamanho2)
imagem_maior.save('../Imagens/doge_maior.jpg')
