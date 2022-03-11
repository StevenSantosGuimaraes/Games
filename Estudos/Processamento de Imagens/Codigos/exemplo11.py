from PIL import Image, ImageDraw

tamanho = 512, 512
cor_fundo = 'blue'
modo = 'RGB'
local_texto = 128, 64
conteudo_texto = 'Teste de criação de imagens'

imagem = Image.new(modo, tamanho, cor_fundo)

draw = ImageDraw.Draw(imagem)
draw.text(local_texto, conteudo_texto)

imagem.save('../Imagens/doge_editadao.jpg')
imagem.show('../Imagens/doge_editadao.jpg')
