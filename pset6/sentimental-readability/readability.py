from cs50 import get_string
import math
import nltk
#nltk.download('punkt')

def countletter(x):
    letters = 0
    for i in range(len(x)):
        if x[i].isalpha():
            letters += 1
    return letters
def countword(sentence):
    if sentence:
        x = sum(1 for c in sentence if c in ' \t\n')
        return (x+1)
s = get_string("Text: ")
Let = countletter(s)
words = countword(s)
sentences= len(nltk.sent_tokenize(s))
L = (100*Let)/words
S = (100*sentences)/ words
index = int(round(0.0588 * L - 0.296 * S - 15.8))
if index < 1:
    print("Before Grade 1")
elif index >= 1 and index < 16:
    print("Grade %i" %index);
else:
    print("Grade 16+");

