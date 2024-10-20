import qrcode

img = qrcode.make("https://anthony-mendoza-reitor.github.io/tic-tac-toe-ToP/")
img.save("tic-tac-toe.png", "PNG")
