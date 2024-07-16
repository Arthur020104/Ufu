from nRainhas import segura
tabuleiro = []
for i in range(8):
    tabuleiro.append([])
    for j in range(8):
        tabuleiro[i].append(0)
def Res(n,l):
    if l > 7:
        return True
    for c in range(n):
        if segura(tabuleiro,l,c):
            tabuleiro[l][c] = 1
            if Res(n,l+1):
                return True
            tabuleiro[l][c]=0
    return False

if __name__ == "__main__":
    for l in tabuleiro:
        print(l)
    print()
    Res(8,0)
    for l in tabuleiro:
        print(l)