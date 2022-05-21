from PIL import Image

imagem = Image.open('../Imagens/doge.jpg')

print(imagem.size)

imagem.save('../Imagens/doge2.jpg')

imagem.show('../Imagens/doge.jpg')
