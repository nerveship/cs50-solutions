from cs50 import get_string
text = get_string("Text: ")

letters = 0
for i in text:
    if (i >= 'a' and i <= 'z') or (i >= 'A' and i <= 'Z'):
        letters += 1

words = 1
for i in text:
    if (i == " "):
        words += 1

sentences = 0
for i in text:
    if (i == "!" or i == "." or i == "?"):
        sentences += 1

l = letters / words * 100
s = sentences / words * 100

index = round(((0.0588 * l) - (0.296 * s) - 15.8))

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade:", round(index))
