vowels = {"a", "e", "i", "o", "u"}
text = input()

forwards = [ch for ch in text if ch in vowels]
backwards = forwards[::-1]

if forwards == backwards:
    print("S")
else:
    print("N")
