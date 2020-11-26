import pytesseract
from PIL import Image

img = Image.open("verifycode.jpg")
tmpImage = img.convert('L')

threshold = 140
table = []
for i in range(256):
    if i < threshold:
        table.append(0)
    else:
        table.append(1)

out = tmpImage.point(table, '1')
out.show()

result = pytesseract.image_to_string(out)
print(result)