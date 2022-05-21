from PIL import Image, ImageOps

cor_borda = 'red'
tamanho_borda = 10

imagem = Image.open('../Imagens/doge.jpg')

nova_imagem = ImageOps.expand(imagem, border = tamanho_borda, fill = cor_borda)

nova_imagem.save('../Imagens/doge_com_bordas.jpg')
