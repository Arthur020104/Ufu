
tabuleiro = []
for i in range(9):
    tabuleiro.append([0]*9)

tabuleiro[0][0]=3
tabuleiro[0][6]=8
tabuleiro[1][1]=9
tabuleiro[1][5]=6
tabuleiro[2][2]=6
tabuleiro[2][4]=2
tabuleiro[2][6]=1
tabuleiro[2][8]=7
tabuleiro[3][0]=5
tabuleiro[3][3]=4
tabuleiro[4][2]=9
tabuleiro[4][4]=1
tabuleiro[4][6]=6
tabuleiro[4][8]=2
tabuleiro[5][7]=3
tabuleiro[6][1]=4
tabuleiro[6][3]=1
tabuleiro[6][6]=7
tabuleiro[6][8]=3
tabuleiro[7][2]=7
tabuleiro[7][7]=8
tabuleiro[8][4]=3
tabuleiro[8][7]=9

def segura(c,l,n):
    for i in range(9):
        if tabuleiro[c][i] == n or tabuleiro[i][l] == n :
            return False
    instanceOfL = l - (l % 3)
    instanceOfC = c - (c % 3)
    for i in range(instanceOfC,instanceOfC+3):
        for j in range(instanceOfL,instanceOfL+3):
            if tabuleiro[i][j] == n :
                return False
        
    return True
def main(c,l):
    if c >= 9:
       return main(0, l + 1)
   
    if l >= 9:
       return True
   
    if tabuleiro[c][l] != 0:
        return main(c + 1, l)
    
    for i in range(1,10):
        if segura(c,l,i):
            tabuleiro[c][l] = i
        
            if main(c + 1, l):
                return True
        tabuleiro[c][l] = 0
   
    return False

if __name__ == "__main__":
    for tab in tabuleiro:
        print(tab)
    print()
    main(0,0)
    for tab in tabuleiro:
        print(tab)