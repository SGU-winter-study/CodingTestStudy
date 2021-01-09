n=int(input())
books={}
for _ in range(n):
    book=input()
    if book in books:
        books[book]+=1
    else:
        books[book]=1

books=list(books.items())
books.sort(key=lambda k : (-k[1],k[0]))
print(books[0][0])
