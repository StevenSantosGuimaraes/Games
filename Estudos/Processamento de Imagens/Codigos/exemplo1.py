from PIL import Image

imagem = Image.open('./doge.jpg')

print(imagem.size)

imagem.show('./doge.jpg')
