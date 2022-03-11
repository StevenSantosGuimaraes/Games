from PIL import Image, ImageEnhance

imagem = Image.open('../Imagens/doge.jpg')

contrast = ImageEnhance.Contrast(imagem)

imagem_contraste = contrast.enhance(2.0)

imagem_contraste.save('../Imagens/doge_contraste-20.jpg')
