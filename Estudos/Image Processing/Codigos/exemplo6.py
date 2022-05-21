from PIL import Image

imagem = Image.open('../Imagens/2x2px.jpg')

print(imagem.size)
print(imagem.mode)
print(imagem.bits)
print(2**8)
