from PIL import Image, ImageEnhance

imagem = Image.open('../Imagens/doge.jpg')

def filtro_personalizado(imagem):
    contrastado = ImageEnhance.Contrast(imagem).enhance(1.25)
    brilho = ImageEnhance.Brightness(imagem).enhance(1.05)
    saturado = ImageEnhance.Color(imagem).enhance(1.5)
    saturado.save('../Imagens/doge_filtrado.jpg')
    
filtro_personalizado(imagem)
