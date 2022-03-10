from PIL import Image

angulo = -45

imagem = Image.open('./doge_menor.jpg')

imagem.transpose(Image.FLIP_LEFT_RIGHT).save('./doge_flipar_horizontal.jpg')
imagem.transpose(Image.FLIP_TOP_BOTTOM).save('./doge_flipar_vertical.jpg')

imagem.transpose(Image.ROTATE_90).save('./doge_girar_90.jpg')
imagem.transpose(Image.ROTATE_180).save('./doge_girar_180.jpg')
imagem.transpose(Image.ROTATE_270).save('./doge_girar_270.jpg')

imagem.transpose(Image.TRANSPOSE).save('./doge_transpose.jpg')
imagem.transpose(Image.TRANSVERSE).save('./doge_transverse.jpg')

imagem.rotate(angulo, expand = True).save('./doge_menor_rodar.png')
