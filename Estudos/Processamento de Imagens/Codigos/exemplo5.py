from PIL import Image

imagem = Image.open('../Imagens/doge_menor.jpg')

imagem.transpose(Image.FLIP_LEFT_RIGHT).save('../Imagens/doge_flipar_horizontal.jpg')
imagem.transpose(Image.FLIP_TOP_BOTTOM).save('../Imagens/doge_flipar_vertical.jpg')

imagem.transpose(Image.ROTATE_90).save('../Imagens/doge_girar_90.jpg')
imagem.transpose(Image.ROTATE_180).save('../Imagens/doge_girar_180.jpg')
imagem.transpose(Image.ROTATE_270).save('../Imagens/doge_girar_270.jpg')

imagem.transpose(Image.TRANSPOSE).save('../Imagens/doge_transpose.jpg')
imagem.transpose(Image.TRANSVERSE).save('../Imagens/doge_transverse.jpg')
