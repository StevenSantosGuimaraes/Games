from PIL import Image

img1 = Image.open('../image/image1.jpg')
img1 = img1.convert("L")
img1.show()
