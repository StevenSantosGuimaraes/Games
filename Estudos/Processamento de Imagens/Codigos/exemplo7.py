from PIL import Image

Image.open('../Imagens/doge.jpg').convert('1').save('../Imagens/doge_bin.jpg')
Image.open('../Imagens/doge.jpg').convert('L').save('../Imagens/doge_pb.jpg')
Image.open('../Imagens/doge.jpg').convert('P').save('../Imagens/doge_P.png')
