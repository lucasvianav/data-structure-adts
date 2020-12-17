# Script to generate random "movies"

import random
import string

size = 50000 # Número de filmes
intList = [] # Lista com as chaves dos filmes
strList = [] # Lista com os nomes dos filmes

def randInt(): # Função que vai criar uma chave única aleatória para o filme
    while True: # Vai repetir o processo até encontrar uma chave única
        e = random.randint(0,size*1.5) # Cria um int aleatório
        if intList.count(e) == 0: # Caso a chave ainda não exista na lista (seja única)
            intList.append(e) # Adiciona-a a lista
            break

    return e

def randStr(): # Função que vaicriar uma string única aleatória para ser o nome do filme
    while True: # Vai repetir o processo até encontrar uma string única
        e = ''.join(random.choices(string.ascii_letters + string.punctuation, k = random.randint(3,19))) # Cria uma string aleatória contendo entre 3 e 19 caracteres, incluindo letras minúsculas e maiúsculas e caracteres especiais
        if strList.count(e) == 0: # Caso o nome ainda não exista na lista (seja único)
            strList.append(e) # Adiciona-o na lista
            break
    
    return e

fIn = open('./test-cases/29.in','w') # Arquivo de input do programa em C
fOut = open('./test-cases/29.out','w') # Arquivo do output esperado do programa em C

fIn.write("3 %d\n" % size) # Inserir 'size' elementos
for i in range(size):
    fIn.write("%d %s %d\n" % (randInt(), randStr(), (i+1)))
    fOut.write("1\n")

fIn.write("6\n9\n8\n") # Printar todos os elementos e checar se a lista está vazia ou cheia
for i in range(size): fOut.write("%d %s\n" % (intList[i], strList[i]))
fOut.write("0\n0\n")

fIn.write("5 %d\n" % size) # Buscar todos os elementos de um por um, na ordem
for i in range(size):
    fIn.write("%d\n" % intList[i])
    fOut.write("%d\n" % (i+1))

fIn.write("5 %d\n" % round(size*0.75)) # Buscar aleatoriamente 3/4 dos elementos da lista
for i in range(round(size*0.75)):
    index = i+random.randint(-i,size-1-i)
    fIn.write("%d\n" % intList[index])
    fOut.write("%d\n" % (index+1))

fIn.write("7\n") # Checar o tamanho da lista
fOut.write("%d\n" % size)

fIn.write("4 %d\n" % round(size*0.25)) # Remover aleatoriamente 1/4 dos elementos da lista
indexList = [] # Lista que vai conter os índices na intList das chaves dos elementos a serem removidos
for i in range(round(size*0.25)):
    while True: # Repete o processo até encontrar um elemento que ainda não foi removido
        index = i+random.randint(-i,size-1-i) # Decide aleatoriamente qual elemento remover
        if indexList.count(index) == 0: # Verifica se o elemento já foi removido (se está na indexList)
            indexList.append(index) # Caso não, adiciona-o na indexList
            break

    fIn.write("%d\n" % intList[index])
    fOut.write("1\n")

newSize = size - round(size*0.25) # Novo tamanho da lista

fIn.write("7\n") # Checa o tamanho da lista
fOut.write("%d\n" % newSize)

fIn.write("5 %d\n" % round(size*0.25)) # Tenta remover de novo todos os elementos que acabaram de ser removidos
for i in range(round(size*0.25)):
    fIn.write("%d\n" % intList[indexList[i]])
    fOut.write("-32000\n")

fIn.write("2\n") # Apaga a lista
fOut.write("1\n")

fIn.write("7\n8\n9\n0\n") # Checa o tamanho da lista, se ela está cheia ou vazia e encerra a execução do programa
fOut.write("0\n0\n1\n")

fIn.close() # Fecha os arquivos
fOut.close()