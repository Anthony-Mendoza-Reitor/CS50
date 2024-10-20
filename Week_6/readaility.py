from cs50 import get_string

Text = get_string("Text: ")
numLetters = 0
numSentence = 0
numWords = 1
textLen = len(Text)
for l in Text:
    if l != " " and l != "," and l != "." and l != "!" and l != "?":
        numLetters += 1
    if l == "." or l == "?" or l == "!":
        numSentence += 1
    if l == " " or l == "'":
        numWords += 1
print(f"Letters: {numLetters}, Sentence: {numSentence}, Words: {numWords}")
L = float((numLetters * 100.0000) / numWords)
S = float((numSentence * 100.0000) / numWords)
C_LI = float((0.0588 * L) - (0.296 * S) - 15.8)
index = (round(C_LI))
if (index < 1):
    print("Before Grade 1")
elif (index > 16):
    print("Grade 16+")
else:
    print(f"Grade {index}")
