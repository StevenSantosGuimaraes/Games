from PIL import Image

imagem = Image.open('./doge.jpg')
formato = imagem.format
altura = imagem.height
largura = imagem.width

print("Formato da Cor: ", imagem.mode, ", Formato do Arquivo: ", formato)
print("Altura: ", altura, ", Largura: ", largura)

#Padrao: largura x altura
tamanho = (512, 256)

imagem_menor = imagem.resize(tamanho)

imagem_menor.save('./doge_menor.jpg')
