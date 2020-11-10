import pytesseract
from PIL import Image
img = Image.open("verifycode.jpg")
result = pytesseract.image_to_string(img)
print(result)