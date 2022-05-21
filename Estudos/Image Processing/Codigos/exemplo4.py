from PIL import Image

angulo = -45

imagem = Image.open('../Imagens/doge_menor.jpg')

imagem.rotate(angulo, expand = True).save('../Imagens/doge_menor_rodar.png')
